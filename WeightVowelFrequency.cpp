#include "WeightVowelFrequency.hpp"

static bool isVowel(char c) {
	switch (c) {
	case 'a' :
	case 'e':
	case 'i':
	case 'o':
	case 'u': return true; break;
	//case 'y': return (Random::uniformRand() < 0.5); break;
	default:  return false; break;
	};
}

int WeightVowelFrequency::getWeightForLetter(char c, const std::string& word, unsigned int targetLength) {
	unsigned int wordLength = (unsigned int)word.length();
	if (wordLength == 0) { return 0; }

	// Determine the most recent vowels and consonants
	bool noVowels = true;
	bool noConsonants = true;
	unsigned int mostRecentVowel = wordLength;
	unsigned int mostRecentConsonant = wordLength;
	for (unsigned int i = 0; i < wordLength; ++i) {
		char w = word[wordLength - i - 1u];
		if (isVowel(w) && i < mostRecentVowel) { 
			mostRecentVowel = i; 
			noVowels = false;
		}
		else if (!isVowel(w) && i < mostRecentConsonant) { 
			mostRecentConsonant = i; 
			noConsonants = false;
		}
	}

	// As the distance since the most recent letter type increases, weigh them more heavily
	if (isVowel(c)) { 
		if (noVowels) { return 200 * mostRecentVowel; }
		else { return 50 * mostRecentVowel; }
	}
	else { 
		if (noConsonants) { return 250 * mostRecentConsonant; }
		else { return 75 * mostRecentConsonant; }
	}
}