#include "WeightOccuranceFrequency.hpp"

const int WeightOccuranceFrequency::letterOccuranceTable[] = {
	82,
	15,
	28,
	43,
	127,
	22,
	20,
	61,
	70,
	1,
	7,
	40,
	24,
	67,
	75,
	19,
	1,
	60,
	63,
	91,
	28,
	9,
	24,
	1,
	2,
	0
};

int WeightOccuranceFrequency::getWeightForLetter(char c, const std::string& word, unsigned int targetLength) {
	unsigned int i = (unsigned int)(c - 'a');
	assertm(i >= 0 && i < 26, "Letter is out of range!");
	return letterOccuranceTable[i];
}