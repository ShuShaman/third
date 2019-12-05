#pragma once
#include <iostream>
#include <iomanip>
using namespace std;
//class Matrix
//{
//
//public:
//	void InitializeArray();
//	int Factorial(int i1);
//	void MakeArray1D();
//	int* GetArray();
//	void PrintArray2D();
//	~Matrix();
//};

class Matrix
{
	mutable int** a2d;
	mutable int i;
	mutable int j;
	const size_t N = 5;
	const size_t M = 5;
	const size_t LEN = 15;
	//int* a1d;

	//int** a2d = new int* [N];

	int Factorial(int i1); 

	/*int Factorial(int i1)
	{
		if (i1 == 0) return 1;
		else return i1 * Factorial(i1 - 1);
	}*/

public:
	Matrix();
	void InitializeArray();
	int** GetArray();
	void PrintArray2D();

	Matrix& operator++();
	Matrix  operator++(int);
	Matrix& operator--();
	Matrix  operator--(int);
	int getAt(int newN, int newM)const;
	void setAt(int newN, int newM, int num);
	~Matrix();


	//void MakeArray1D()
	//{

	//	int k = 0;
	//	for (size_t i = 0; i < N; i++)
	//	{
	//		for (size_t j = 0; j < M; j++)
	//		{
	//			if (i % 2 == 0)
	//			{
	//				a1d[k] = a2d[i][j];
	//			}
	//			else
	//			{
	//				continue;
	//			}
	//			k++;
	//		}
	//	}

	//}

	
};
