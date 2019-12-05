#include <iostream>
//#include <iomanip> 
#include <cstdlib>
#include "Fraction.h"

int main()
{
	Fraction num1(1, 2);
	Fraction num2(2, 6);

	Fraction res1 = num1 + num2;
	Fraction res2 = num1 - num2;
	Fraction res3 = num1 * num2;
	Fraction res4 = num1 / num2;

	Fraction::printAsFraction(0.25);
	Fraction::printAsFraction(0.43);

	cout << Fraction::counter << endl;

}