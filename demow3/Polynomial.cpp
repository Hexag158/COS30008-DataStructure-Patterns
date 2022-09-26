#include "Polynomial.h"

using namespace std;

Polynomial :: Polynomial () : fDegree(0)
{
	for (size_t i = 0; i <= MAX_DEGREE; i++)
	{
		fCoeffs[i] = 0.0;
	}
}


Polynomial Polynomial::operator*(const Polynomial& aRHS) const //c=a*b 
{
	Polynomial result;
	
	result.fDegree = fDegree + aRHS.fDegree;
	for (size_t i = 0; i <= fDegree; i++) {
		for (size_t j = 0; j <= aRHS.fDegree; j++) {
			result.fCoeffs[i + j] += aRHS.fCoeffs[j] * fCoeffs[i];
		}
	}
	return result; 
};

bool Polynomial::operator== (const Polynomial& aRHS) const
{
	bool result = fDegree == aRHS.fDegree;
	for (size_t i = 0; result && i <= fDegree; i++)
	{
		if (fCoeffs[i] != aRHS.fCoeffs[i])
		{
			result = false;
		}
	}
	return result;
};

istream& operator>>(istream& aIStream, Polynomial& aObject) {
	// read degree
	size_t lDegree;

	aIStream >> lDegree;

	aObject.fDegree = lDegree <= MAX_POLYNOMIAL ? lDegree : MAX_POLYNOMIAL;

	// read coefficients (assume sound input)
	for (int i = static_cast<int>(aObject.fDegree); i >= 0; i--)
	{
		aIStream >> aObject.fCoeffs[i];
	}

	return aIStream;

}

ostream& operator<<(ostream& aOStream, const Polynomial& aObject) {
	
	bool lMustPrintPlus = false;

	for (int i = static_cast<int>(aObject.fDegree); i >= 0; i--)
	{
		if (aObject.fCoeffs[i] != 0.0)
		{
			if (lMustPrintPlus)
			{
				aOStream << " + ";
			}
			else
			{
				lMustPrintPlus = true;
			}

			aOStream << aObject.fCoeffs[i] << "x^" << i;
		}
	}

	return aOStream;

}
