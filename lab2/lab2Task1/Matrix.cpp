#include "Matrix.h"


int Matrix::Factorial(int i1)
{
	if (i1 == 0) return 1;
	else return i1 * Factorial(i1 - 1);
}

Matrix::Matrix() {
	//a1d = new int[LEN];
	a2d = new int* [N];
	for (size_t i = 0; i < N; i++)
	{
		a2d[i] = new int[N];
	}
}

void Matrix::InitializeArray()
{
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			a2d[i][j] = Factorial(i + j);
		}
	}
}

int** Matrix::GetArray()
{
	return a2d;
}

void Matrix::PrintArray2D()
{
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			std::cout << std::setw(8) << a2d[i][j];
		}
		std::cout << "\n" << std::endl;
	}
}

Matrix& Matrix::operator++() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			a2d[i][j]++;
		}
	}
	return *this;
}

Matrix& Matrix::operator--() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			--a2d[i][j];
		}
	}
	return *this;
}

Matrix Matrix::operator++(int) {
	/*Matrix tmp(*this);
	++(*this);
	return tmp;*/
	return ++(*this);
}

Matrix Matrix::operator--(int) {
	Matrix tmp(*this);
	--(*this);
	return tmp;
}

int Matrix::getAt(int newN, int newM)const {
	return a2d[newN][newM];
}

void Matrix::setAt(int newN, int newM, int num) {
	if (newN > 0 && newN < N && newM>0 && newM < M) {
		a2d[newN][newN] = num;
	}
}

Matrix::~Matrix()
{
	for (size_t i = 0; i < N; i++)
	{
		delete[] a2d[i];
	}
	delete[] a2d;
};