#include <algorithm>
#include <cmath>
#include <iostream>

void squareRoot(double &a, double &b, double x, double temp2, double temp3);
void printRootNeg()
int main(int argc, char* argv[])
{
	double a = 0;
	double b = 0;

	squareRoot(a, b, 1, 2, 1);


	squareRoot(a, b, 1, 4, 29);


	squareRoot(a, b, 1, 84, 1764);

	return 0;
}

void squareRoot(double &a, double &b, double temp1, double temp2, double temp3)
{
	b = (temp2 * temp2) - (4 * temp1 * temp3);

	if (b < 0)
	{
		std::cout << "No real root for " << temp1 << "x^2+";
		std::cout << temp2 << "x+" << temp3 << std::endl;
	}
	
	else
	{
		a = (-temp2 + std::sqrt(b)) / (2 * temp1);
		std::cout << "One of the roots for " << temp1 << "x^2+";
		std::cout << temp2 << "x+" << temp3;
		std::cout << " is " << a << std::endl;
	}
	
}