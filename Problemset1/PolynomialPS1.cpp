#include "Polynomial.h"

using namespace std;

   // call operator to calculate polynomial for a given x (i.e., aX)
double Polynomial :: operator()(double aX) const {

	double result = 0;
	for (int i = static_cast<int>(fDegree); i >= 0; i--)
	{
			result += fCoeffs[i]*pow(aX,i);
	}
	return result;
};

// compute derivative: the derivative is a fresh polynomial with degree
 // fDegree-1, the method does not change the current object
Polynomial Polynomial:: getDerivative() const{
	Polynomial result;
	if (fDegree == 0) {
		return result;
	}
	else {
		result.fDegree = fDegree - 1;
	}

	for (int i = static_cast<int>(fDegree); i > 0; i--)
	//for(size_t i = 1; i <= fDegree; i++)
	{
	    result.fCoeffs[i - 1] = fCoeffs[i] * i;
	}
	return result;
};

// compute indefinite integral: the indefinite integral is a fresh
// polynomial with degree fDegree+1
 // the method does not change the current object
Polynomial Polynomial:: getIndefiniteIntegral() const
{
	Polynomial result;
	result.fDegree = fDegree + 1;

	for (int i = static_cast<int>(fDegree); i >= 0; i--)
	{
		result.fCoeffs[i + 1] = fCoeffs[i] / (i+1);
	}
	return result;
};

// calculate definite integral: the method does not change the current
// object; the method computes the indefinite integral and then 
 // calculates it for xlow and xhigh and returns the difference
double Polynomial:: getDefiniteIntegral(double aXLow, double aXHigh) const
{
	return this->getIndefiniteIntegral()(aXHigh) - this->getIndefiniteIntegral()(aXLow);
};