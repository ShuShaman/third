﻿#include <iostream>
#include <iomanip> 
#include <cstdlib>
#include "Matrix.h"
#include "Vector.h"


/*Task_1

Написать классы Vector и Matrix для хранения и обработки одномерных и
двумерных массивов, соответственно. Реализовать задание 2 лабораторной работы №1
с помощью созданных классов. Все функции оформить в виде методов классов.
В коде отразить следующее:
 Выделение и освобождение динамической памяти производить в конструкторах и
деструкторах классов, соответственно.
 В классе Vector перегрузить оператор индексации []. В классе Matrix добавить
методы T at(int i, int j) const и setAt(int i, int j, T val), которые
позволяют получить и установить значение элемента массива с индексом [i][j], T –
это тип элементов массива по варианту (int или double).
 Перегрузить операторы инкремента и декремента (как префиксного, так и
постфиксного). Смысл инкремента / декремента всего массива заключается в
инкременте / декременте каждого элемента массива.*/

int main()
{
	// допустим, это изменения
	// а это - изменения для второго задания



	
	//const size_t LEN = 15;
	Matrix a2d;

	a2d.InitializeArray();
	a2d.PrintArray2D();
	/*a2d++;*/
	//A1d.MakeArray1D();
	Vector a1d(a2d.GetArray());
	a1d.PrintArray1D();
	//Vector a1d(A1d);
		//MakeArray1D();
	/*for (int i = 0; i < 15; i++)
	{
		a1d[i] = A1d[i];
	}*/
	//A1d.PrintArray1D();
	
	//A1d.FreeArray1D();

	return 0;
}


