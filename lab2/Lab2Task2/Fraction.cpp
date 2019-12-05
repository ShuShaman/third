#include <iostream>
#include <cmath>
#include <string>
#include <limits>
#include "Fraction.h"
using namespace std;

int  Fraction::counterOfFractions = 0;

Fraction::Fraction() {
	numerator_ = 1;
	denominator_ = 1;
	counterOfFractions++;
}

Fraction::Fraction(const int num1, const int num2) :numerator_(num1), denominator_(num2) {
	counterOfFractions++;
}

Fraction::~Fraction() {
	counterOfFractions--;
}

void Fraction::setNumerator(const int num) {
	numerator_ = num;
}
void Fraction::setDenomirator(const int num) {
	denominator_ = num;
}
int Fraction::getDenomirator()const {
	return denominator_;
}
int Fraction::getNumerator()const {
	return numerator_;
}

Fraction Fraction::operator+(Fraction& num) {
	Fraction res;
	res.numerator_ = this->numerator_ * num.denominator_ + this->denominator_ * num.numerator_;
	res.denominator_ = this->denominator_ * num.denominator_;
	res.reduce();
	counterOfFractions++;
	return res;
}

Fraction Fraction::operator-(Fraction& num) {
	Fraction res;
	res.numerator_ = this->numerator_ * num.denominator_ - this->denominator_ * num.numerator_;
	res.denominator_ = this->denominator_ * num.denominator_;
	res.reduce();
	counterOfFractions++;
	return res;
}

Fraction Fraction::operator*(Fraction& num) {
	Fraction res;
	res.numerator_ = this->numerator_ * num.numerator_;
	res.denominator_ = this->denominator_ * num.denominator_;
	res.reduce();
	counterOfFractions++;
	return res;
}

Fraction Fraction::operator/(Fraction& num) {
	Fraction res;
	res.numerator_ = this->numerator_ * num.denominator_;
	res.denominator_ = this->denominator_ * num.numerator_;
	res.reduce();
	counterOfFractions++;
	return res;
}

void Fraction::PrintOperation(Fraction& num1, Fraction& num2, string sign)
{
	cout << "(" << num1.numerator_ << "/" << num1.denominator_ << ")" + sign + "(" << num2.numerator_ << "/" << num2.denominator_ << ") = ";
}

void Fraction::reduce() {

	if (numerator_ == 0) {
		cout << numerator_ << endl << endl;
		return;
	}
	else if (denominator_ == 0)
	{
		cout << "Ошибка: деление на 0." << endl;
		return;
	}
	else
	{
		int NOD = gcd(abs(numerator_), abs(denominator_));
		if (NOD != 1)
		{
			cout << numerator_ << "/" << denominator_ << " = ";
			numerator_ /= NOD;
			denominator_ /= NOD;
		}

		cout << numerator_ << "/" << denominator_ << endl << endl;
	}

}

void Fraction::printAsFraction(double decimal_fraction)
{
	int counter = 0;
	double decimalFr = decimal_fraction;
	int denom = 1;

	int tmp = (int)(decimal_fraction * 10);

	while (tmp == 0)
	{
		decimal_fraction *= 10;
		denom *= 10;
		tmp = (int)(decimal_fraction * 10);
		counter++;
	}
	while ((int)(decimal_fraction * 10) % 10 != 0)
	{
		decimal_fraction *= 10;//числитель
		denom *= 10;
		counter++;
	}
	cout.precision(counter);
	cout << fixed << decimalFr << " = ";
	Fraction res((int)decimal_fraction, denom);
	res.reduce();
	counterOfFractions++;
}

void Fraction::printAsFraction(char* decimal) {

	cout << decimal << " = ";

	char* dot = strchr(decimal, '.');
	dot++;

	int count = 0;
	while (*dot != '\0')
	{
		count++;
		dot++;
	}

	double num = atof(decimal);
	int denom = 1;

	for (int i = 0; i < count; i++) {
		num *= 10;
		denom *= 10;
	}

	Fraction res((int)num, denom);
	res.reduce();
	counterOfFractions++;
}


int Fraction::gcd(int n, int m) {

	while (n != 0 && m != 0) {
		if (n > m) 
		{
			n = n % m;
		}
		else
		{
			m = m % n;
		}
	}
	return  (n + m);
}