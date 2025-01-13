#include "WeightPositionDistribution.hpp"

const int WeightPositionDistribution::letterPositionTable[] = {
	12, 12, 13, 14, 16, 15, 14, 13, 12, 10, 7,  4,  3,  2,  1,  0,
	14, 13, 12, 11, 9,  8,  7,  4,  2,  1,  1,  1,  1,  0,  0,  0,
	14, 11, 9,  6,  6,  6,  5,  6,  7,  10, 11, 10, 8,  4,  2,  2,
	4,  4,  2,  2,  2,  1,  2,  2,  2,  2,  6,  11, 13, 16, 19, 20,
	2,  2,  3,  4,  5,  5,  6,  6,  7,  8,  12, 16, 17, 17, 16, 16,
	12, 11, 10, 8,  6,  4,  2,  3,  9,  14, 15, 15, 15, 15, 15, 15,
	10, 9,  7,  6,  5,  5,  6,  7,  7,  6,  6,  6,  8,  10, 15, 16,
	6,  7,  9,  10, 15, 18, 16, 13, 11, 11, 5,  1,  2,  3,  3,  3,
	9,  9,  10, 12, 13, 15, 16, 15, 12, 10, 8,  6,  4,  1,  0,  0,
	22, 21, 17, 12, 6,  3,  3,  4,  4,  3,  1,  1,  1,  0,  0,  0,
	8,  7,  6,  4,  2,  2,  4,  7,  11, 14, 13, 11, 11, 14, 16, 16,
	8,  8,  7,  7,  8,  8,  8,  9,  10, 13, 15, 15, 14, 12, 11, 11,
	16, 15, 14, 11, 8,  8,  7,  6,  7,  8,  8,  8,  8,  7,  8,  8,
	3,  4,  4,  5,  8,  10, 11, 12, 15, 16, 14, 13, 14, 14, 13, 12,
	9,  10, 11, 13, 14, 15, 15, 14, 12, 11, 10, 9,  8,  7,  6,  5,
	19, 16, 10, 9,  7,  6,  5,  5,  6,  5,  4,  4,  4,  3,  3,  3,
	21, 19, 14, 8,  10, 11, 8,  3,  3,  1,  2,  2,  1,  0,  0,  0,
	5,  5,  6,  7,  8,  10, 11, 11, 12, 12, 14, 15, 14, 14, 14, 14,
	9,  8,  6,  4,  3,  3,  4,  5,  7,  8,  10, 11, 12, 13, 16, 17,
	16, 16, 16, 15, 14, 8,  6,  6,  6,  6,  6,  7,  7,  8,  8,  9,
	4,  5,  8,  8,  9,  12, 15, 16, 15, 13, 9,  6,  5,  3,  2,  2,
	7,  7,  6,  7,  9,  11, 13, 14, 15, 16, 15, 12, 5,  3,  1,  0,
	20, 19, 18, 12, 7,  4,  3,  2,  2,  2,  3,  3,  3,  3,  3,  3,
	2,  8,  20, 14, 8,  5,  3,  4,  5,  4,  5,  6,  5,  5,  6,  6,
	4,  4,  3,  3,  2,  1,  2,  3,  4,  4,  6,  8,  11, 14, 19, 21,
	1,  1,  1,  0,  2,  2,  5,  14, 19, 15, 16, 15, 12, 7,  4,  3
};

int WeightPositionDistribution::getWeightForLetter(char c, const std::string& word, unsigned int targetLength) {
	unsigned int row = (unsigned int)(c - 'a');
	assertm(row >= 0 && row < 26, "Row is out of bounds!");

	double pos = ((double)word.length() * 16.0) / double(targetLength);
	unsigned int col_a = (unsigned int)(floor(pos));
	unsigned int col_b = (unsigned int)(ceil(pos));
	assertm(col_a >= 0 && col_a < 16, "Col_a is out of bounds!");
	assertm(col_b >= 0 && col_b < 16, "Col_b is out of bounds!");

	double val_a = (double)letterPositionTable[(row * 16) + col_a] * 10.0;
	double val_b = (double)letterPositionTable[(row * 16) + col_b] * 10.0;
	double pos_int = 0.0;
	double pos_frac = modf(pos, &pos_int);
	double val = lerp(val_a, val_b, pos_frac);

	return (unsigned int)(round(val / 2.0));
}