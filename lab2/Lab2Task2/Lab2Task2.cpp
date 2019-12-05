#include <iostream>
#include "Fraction.h"

/*Task_2

Написать класс Fraction для представления обыкновенных дробей (как отношения
двух целых чисел x/y). Перегрузить операторы +, -, *, / для дробей. Реализовать метод
void reduce() для сокращения дроби, а также статические методы:
 int gcd(int n, int m)
функция для нахождения наибольшего общего делителя чисел n и m;
 void printAsFraction(double decimal_fraction)
 void printAsFraction(char* decimal_fraction)
перегруженные методы вывода десятичной дроби в виде обыкновенной
(например, при значении decimal_fraction = 0.43 на экране должно
вывестись 43/100, при 0.25 – 1/4 и т.д.).
Также реализовать в виде статического члена класса счетчик всех созданных на
данный момент в программе экземпляров дробей.
Продемонстрировать работу созданного класса. Создать несколько объектов дробей.
Произвести операции сложения, вычитания, умножения и деления дробей. Вывести
на экран результаты. Показать также результаты работы статических методов класса.*/

int main()
{
	setlocale(LC_CTYPE, "rus");
	Fraction num1(2, 5);
	Fraction num2(5, 25);
	Fraction num3(8, 9);

	num2.PrintOperation(num1, num2, "+");
	Fraction res1 = num1 + num2;
	num2.PrintOperation(num1, num2, "-");
	Fraction res2 = num1 - num2;
	num2.PrintOperation(num1, num2, "*");
	Fraction res3 = num1 * num2;
	num2.PrintOperation(num1, num2, "/");
	Fraction res4 = num1 / num2;
	
	num2.PrintOperation(num1, num3, "+");
	Fraction res5 = num1 + num3;
	num2.PrintOperation(num1, num3, "-");
	Fraction res6 = num1 - num3;
	num2.PrintOperation(num1, num3, "*");
	Fraction res7 = num1 * num3;
	num2.PrintOperation(num1, num3, "/");
	Fraction res8 = num1 / num3;
	
	Fraction::printAsFraction(0.000007);
	Fraction::printAsFraction(0.43);

	char str1[] = "0.000007";
	char str2[] = "3.45";
	Fraction::printAsFraction(str1);
	Fraction::printAsFraction(str2);
	
	cout <<"На данный момент создано дробей:"<< Fraction::counterOfFractions << endl;
}

