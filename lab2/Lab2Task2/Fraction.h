#pragma once
#include <iostream>
using namespace std;

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	static int counterOfFractions;

	Fraction();
	Fraction(int numerator, int denomirator);
	~Fraction();

	void setNumerator(const int numerator);
	void setDenomirator(const int denomirator);
	int getNumerator()const;
	int getDenomirator()const;

	Fraction operator + (Fraction& num2);
	Fraction operator - (Fraction& num2);
	Fraction operator * (Fraction& num2);
	Fraction operator / (Fraction& num2);

	void PrintOperation(Fraction& num1, Fraction& num2, string sign);

	void reduce();

	static int gcd(int a, int b);

	static void printAsFraction(double decimal);
	static void printAsFraction(char* decimal);
};
//ostream& operator<<(ostream& out, Fraction& num);