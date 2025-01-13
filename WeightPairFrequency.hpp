#pragma once
/*
* WeightPairFrequency.hpp
* 
* This class weighs letters by their tendency to appear after certain other letters.
* For instance, 't' is more likely to be followed by 'h' than to be followed by 'q'.
*/
#include "Defines.hpp"
#include "WeightModifier.hpp"

class WeightPairFrequency : public WeightModifier {
public:
	WeightPairFrequency() {}
	~WeightPairFrequency() {}
	int getWeightForLetter(char c, const std::string& word, unsigned int targetLength) override;
private:
	static const int letterPairTable[26 * 26];
};

