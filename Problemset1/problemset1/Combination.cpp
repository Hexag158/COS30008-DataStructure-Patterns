
#include "Combination.h"
#include <stdexcept>

using namespace std;

Combination::Combination(size_t aN, size_t aK) : fN(aN), fK(aK)
{}

size_t Combination::getK() const{
	return fK;
}
size_t Combination::getN() const {
	return fN;
}
unsigned long long Combination::operator()() const {
	unsigned long long result = 1;
	if (fN < fK) {
		return 0ll;
	}
	else {
		for (int i = 0; i < fK;i++) {
			result *= (fN - i);
			result /= (i + 1);
		}
	}

	return result;
}