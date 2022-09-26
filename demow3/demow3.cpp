#include <iostream>
#include "Polynomial.h"
using namespace std;

void runProblem2()
{
	Polynomial A;
	cout << "Specify first polynomial (degree followed by coefficients):" << endl;
	cin >> A;
	cout << "A = " << A << endl;
	Polynomial AA = A;

	if (AA == A)
	{
		cout << "Comparison successful." << endl;
	}
	else
	{
		cout << "Comparison failed." << endl;
	}
	Polynomial B;
	cout << "Specify second polynomial (degree followed by coefficients):" << endl;
	cin >> B;
	cout << "B = " << B << endl;
	Polynomial C = A * B;
	cout << "C = A * B = " << C << endl;
}

int main(int argc, char* argv[])
{
	runProblem2();
	return 0;
}
