#pragma once
#include <iostream>
#include <iomanip>
using namespace std;
//#include "Matrix.h"
//class Vector
//{
//	Vector();
//public:
//	//Vector(Matrix& A1d) : a1d(A1d.GetArray()) {}
//	Vector(const Vector& other);
//	~Vector();
//	void PrintArray1D();
//	Vector(const Matrix& other);
//
//};

class Vector
{
	const size_t LEN = 15;
	int* a1d;
    public:
	//Vector(Matrix& A1d) : a1d(A1d.GetArray()) {}
	
	Vector(const Vector& other);
	void PrintArray1D();
	Vector(int** arr);

	int& operator [] (int i);

	Vector& operator++();
	Vector& operator--();
	Vector operator++(int);
	Vector operator--(int);
	~Vector();
	
};

