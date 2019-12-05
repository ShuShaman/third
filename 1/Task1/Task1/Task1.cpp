#include <iostream>
#include <cstdlib>
#include <time.h>
#include <stdio.h>
using namespace std;

/*     Вариант 2

1. Объявить массив из n=20 вещественных чисел, проинициализировать нулями.
Функция processArray() должна заполнить массив случайными числами
от -20.0 до 70.0, а затем отнормировать массив, т.е. поделить каждый
элемент массива на максимальное по модулю значение в массиве. Это значение
она также должна вернуть на выходе. Сформировать выходной вещественный массив,
в котором все элементы, стоящие до позиции максимального элемента включительно,
повторяют элементы входного массива, а остальные равны x
(число x ввести с клавиатуры).
Вывести на экран результирующие массивы. */

void PrintArray(double array[], size_t N)
{
	for (size_t i = 0; i < N; i++)
	{
		printf("%10.4f", array[i]);
	}
	printf("\n\n");
}

double  ProcessArray(double arr[], double arr1[], double& maxItem, size_t N)
{
	int index = 0;
	srand(time(NULL));
	for (size_t i = 0; i < N; i++)
	{
		arr[i] = rand() % 91 - 20;
		if (arr[i] > maxItem)
		{
			maxItem = arr[i];
			index = i;
		}
	}

	for (size_t i = 0; i < N; i++)
	{
		if (index >= i)
		{
			arr1[i] = arr[i];
		}
		arr[i] = arr[i] / maxItem;
	}

	double x = 0;
	printf("Введите число x.\n");
	while (scanf("%f", &x) == 0) {
		printf("Неверное полученное значение, попробуйте еще: ");
		while (getchar() != '\n'); 
	}

	for (size_t i = 0; i < N; i++)
	{
		if (i <= index)
		{
			continue;
		}
		else
		{
			arr1[i] = x;
		}
	}
	PrintArray(arr, N);
	PrintArray(arr1, N);

	return maxItem;
}





int main()
{

	setlocale(LC_CTYPE, "rus");
	const size_t N = 20;
	double arr[N];
	double arr1[N];
	double maxItem = 0;

	ProcessArray(arr, arr1, maxItem, N);
	printf("%s %f ", "maxItem =", maxItem);

	return 0;
}
