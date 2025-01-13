#include "Defines.hpp"
#include "WeightPairFrequency.hpp"
#include "WeightVowelFrequency.hpp"
#include "WeightPositionDistribution.hpp"
#include "WeightOccuranceFrequency.hpp"

static std::string generateWord(unsigned int length) {
	// Determine word length
	unsigned int wordLength = (length >= 3 && length <= 15) ? length : getWordLength();

	// Generate word
	std::string word;
	for (unsigned int i = 0; i < wordLength; ++i) {
		// Generate weight table
		std::array<int, 26> weights({});
		std::fill(weights.begin(), weights.end(), 1);

		// Accumulate weights
		for (auto pair : weightModifiers) {
			std::shared_ptr<WeightModifier> modifier = pair.first;
			double scalar = pair.second;

			for (unsigned int j = 0; j < 26; ++j) {
				char c = (char)j + 'a';
				double weight = (double)modifier->getWeightForLetter(c, word, wordLength) * scalar;
				weights[j] += (int)round(weight);
			}
		}

		// Randomly determine based on weights
		int sum = 0;
		std::for_each(weights.begin(), weights.end(), [&](const unsigned int& n) { sum += n; });
		int distance = (int)round(Random::uniformRand() * (double)sum);
		for (unsigned int j = 0; j < 26; ++j) {
			int weight = weights[j];
			if (weight < 0) { continue; }
			distance -= weight;
			if (distance < 0) {
				char c = (char)j + 'a';
				word.push_back(c);
				break;
			}
		}
	}
	return word;
}

int main(int argc, char* argv[]) {
	// Read arguments
	unsigned int length = 0;
	unsigned int numTrials = 1;
	for (int a = 1; a < argc; ++a) {
		std::string flag(argv[a]);
		if (flag == "-l" && a < (argc - 1)) {
			std::string arg(argv[++a]);
			length = std::stoi(arg);
			if (length < 3 || length > 15) {
				std::cerr << "Length must be between 3 and 15 inclusive" << std::endl;
				return 1;
			}
		}
		else if (flag == "-n" && a < (argc - 1)) {
			std::string arg(argv[++a]);
			numTrials = std::stoi(arg);
			if (numTrials == 0) {
				std::cerr << "Number of words must be greater than zero" << std::endl;
				return 1;
			}
		}
		else if (flag == "-h") {
			std::cout << "babble [-h] [-l <word length>] [-n <number of words>]" << std::endl;
			return 0;
		}
		else {
			std::cerr << "Unknown argument (" << flag << ")" << std::endl;
			return 1;
		}
	}

	// Register all weight modifiers
	registerWeightModifier<WeightVowelFrequency>(3.0);
	registerWeightModifier<WeightPairFrequency>(2.0);
	registerWeightModifier<WeightPositionDistribution>(1.5);
	registerWeightModifier<WeightOccuranceFrequency>(1.0);

	// Create words
	for (unsigned int i = 0; i < numTrials; ++i) {
		std::cout << generateWord(length) << std::endl;
	}
	return 0;
}