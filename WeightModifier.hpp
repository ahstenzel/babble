#pragma once
/*
* WeightModifier.hpp
* 
* Base class for all letter frequency modifiers.
*/
#include <string>

class WeightModifier {
public:
	WeightModifier() {}
	virtual ~WeightModifier() {}
	virtual int getWeightForLetter(char c, const std::string& word, unsigned int targetLength) = 0;
};

