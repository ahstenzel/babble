#pragma once
/*
* WeightOccuranceFrequency.hpp
*
* This class weighs letters based on how common they are in general.
*/
#include "Defines.hpp"
#include "WeightModifier.hpp"

class WeightOccuranceFrequency : public WeightModifier {
public:
	WeightOccuranceFrequency() {}
	~WeightOccuranceFrequency() {}
	int getWeightForLetter(char c, const std::string& word, unsigned int targetLength) override;
private:
	static const int letterOccuranceTable[26];
};