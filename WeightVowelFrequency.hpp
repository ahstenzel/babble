#pragma once
/*
* WeightVowelFrequency.hpp
*
* This class weighs letters based on the most recent vowel in the word.
* The further away the most recent vowel is, the more heavily vowels will
* be weighed; same with consonants.
*/
#include "Defines.hpp"
#include "WeightModifier.hpp"

class WeightVowelFrequency : public WeightModifier {
public:
	WeightVowelFrequency() {}
	~WeightVowelFrequency() {}
	int getWeightForLetter(char c, const std::string& word, unsigned int targetLength) override;
};

