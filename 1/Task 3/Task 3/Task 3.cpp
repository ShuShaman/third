#include <iostream>
#include <cstdlib>
#include <cstring>

 //Вариант 2
//Функция strcmp . Формат int strcmp(const char* s1, const char* s2).
//Функция сравнивает строку s1 со строкой s2 в лексикографическом порядке. 
//Если s1<s2, то результат равен -1, если s1=s2, то 0, если s1>s2, то 1.

int strCompare(const char* s1, const char* s2)
{
	while (*s1 && *s2 && (*s1 == *s2))
	{
		s1++; s2++;
	}
	if (*s1 > * s2)
	{
		return 1;
	}
	if (*s1 < *s2)
	{
		return -1;
	}
		return 0;
}

void PrintResult(int standartResult, int myResult)
{
	printf("%i\n", standartResult);
	printf("%i\n\n", myResult);
}

int main()
{
	char s[] = "function";
	char s1[] = "function";
	const char* sPtr = s;
	const char* s1Ptr = s1;
	int standartResult = strcmp(sPtr, s1Ptr);
	int myResult = strCompare(sPtr, s1Ptr);
	PrintResult(standartResult, myResult);
	
	char s2[] = "function44";
	const char* s2Ptr = s2;
	int standartResult1 = strcmp(sPtr, s2Ptr);
	int myResult1 = strCompare(sPtr, s2Ptr);
	PrintResult(standartResult1, myResult1);

	char s3[] = "func";
	const char* s3Ptr = s3;
	int standartResult2 = strcmp(sPtr, s3Ptr);
	int myResult2 = strCompare(sPtr, s3Ptr);
	PrintResult(standartResult2, myResult2);

	return 0;
}

