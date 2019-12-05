#include <iostream>
#include <iomanip> 
#include <cstdlib>
#include "Vector.h"

Vector::Vector(const Vector& other)
{
	this->a1d = new int[LEN];
	for (size_t i = 0; i < LEN; i++)
	{
		this->a1d[i] = other.a1d[i];
	}
}

void Vector::PrintArray1D()
{
	for (size_t i = 0; i < LEN; i++)
	{
		//std::cout << std::setw(8) << a1d[i];
		std::cout << std::setw(8) << a1d[i];

	}
}

Vector::Vector(int** arr)
{
	this->a1d = new int[LEN];
	int k = 0;
	for (size_t i = 0; i < 5; i++)
	{
		for (auto j = 0; j < 5; j++) {
			if (i % 2 == 0) {
				a1d[k] = arr[i][j];
				//cout << *(*(arr+i)+j);
				k++;
				//cout << arr[i][j] << endl;
			}

		}
		//k++;
	}
}

int& Vector::operator [] (int i) {
	return a1d[i];
}

Vector& Vector::operator++()
{
	for (size_t i = 0; i < LEN; i++)
	{
		++a1d[i];
	}
	return *this;
}

Vector& Vector::operator--() {
	for (int i = 0; i < LEN; i++) {
		--a1d[i];
	}
	return *this;
}

Vector Vector::operator++(int) {
	//Vector tmp(*this);
	//++(*this);
	//return tmp;
	return ++(*this);
}

Vector Vector::operator--(int) {
	//Vector tmp(*this);
	//--(*this);
	//return tmp;
	return ++(*this);
}

Vector::~Vector()
{
	delete[] a1d;
}