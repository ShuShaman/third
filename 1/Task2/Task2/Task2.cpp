#include <iostream>
#include <iomanip> 
#include <cstdlib>

int Factorial(int i)
{
	if (i == 0) return 1;
	else return i * Factorial(i - 1);
}

void InitializeArray(int** arr2d, size_t n, size_t m)
{
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			arr2d[i][j] = Factorial(i + j);
		}
	}
}

void PrintArray2D(int** arr2d, size_t n, size_t m)
{
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			std::cout << std::setw(8) << arr2d[i][j];
		}
		std::cout << "\n" << std::endl;
	}
}

int* MakeArray1D(int** arr2d, size_t len, size_t n, size_t m)
{
	int* a1d = new int[len];
	int k = 0;
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			if (i % 2 == 0)
			{
				a1d[k] = arr2d[i][j];
			}
			else
			{
				continue;
			}
			k++;
		}
	}
	return a1d;
}

void PrintArray1D(int* arr1d, size_t len)
{
	for (size_t i = 0; i < len; i++)
	{
		std::cout << std::setw(8) << arr1d[i];
	}
}

void FreeArray1D(int* arr1d)
{
	delete[] arr1d;
}

void FreeArray2D(int** arr2d, size_t n)
{
	for (size_t i = 0; i < n; i++)
	{
		delete[] arr2d[i];
	}
	delete[] arr2d;
}

int main()
{
	const size_t LEN = 15;
	const size_t N = 5;
	const size_t M = 5;

	int** a2d = new int* [N];
	for (size_t i = 0; i < N; i++)
	{
		a2d[i] = new int[N];
	}

	InitializeArray(a2d, N, M);
	PrintArray2D(a2d, N, M);

	int* a1d = MakeArray1D(a2d, LEN, N, M);

	PrintArray1D(a1d, LEN);

	FreeArray1D(a1d);
	FreeArray2D(a2d, N);
	return 0;
}
