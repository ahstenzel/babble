#pragma once
/*
* WeightPositionDistribution.hpp
*
* This class weighs letters based on the position they would have in the word.
* Some letters are more commonly found rowards the start of a word, like w;
* meanwhile some are more common towards the end, like z.
*/
#include "Defines.hpp"
#include "WeightModifier.hpp"

class WeightPositionDistribution : public WeightModifier {
public:
	WeightPositionDistribution() {}
	~WeightPositionDistribution() {}
	int getWeightForLetter(char c, const std::string& word, unsigned int targetLength) override;
private:
	static const int letterPositionTable[16 * 26];
};