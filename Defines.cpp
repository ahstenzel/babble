#include "Defines.hpp"

std::vector<std::pair<std::shared_ptr<WeightModifier>, double>> weightModifiers;

std::random_device Random::device;
std::mt19937 Random::method(Random::device());
std::normal_distribution<double> Random::normalDist(0.5, 0.125);
std::uniform_real_distribution<double> Random::uniformDist(0.0, 1.0);

static const double belowOne = nexttoward(1.0, 0.0);

double Random::normalRand() {
	double val = normalDist(method);
	return (val < 0.0) ? 0.0 : ((val > belowOne ? belowOne : val));
}

double Random::uniformRand() {
	return uniformDist(method);
}

long double logn(long double b, long double x) {
	return log2(x) / log2(b);
}

double lerp(double a, double b, double t) {
	return a + t * (b - a);
}

unsigned int getWordLength() {
	double r = Random::normalRand();
	double w = logn(0.73, (r - 1) / -173.163) - 14.0;
	return std::clamp(unsigned int(std::round(w)), 3u, 15u);
}
