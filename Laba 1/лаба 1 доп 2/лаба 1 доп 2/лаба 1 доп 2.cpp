/* Написать функцию, проверяющую есть ли отрицательные элементы в заданном одномерном массиве размерностью n.
 Удалить из массива все отрицательные элементы, удаленный элемент заполняется нулем и переносится в конец массива.
 Программа должна содержать функцию пользователя с переменным числом параметров и не менее трех обращений к ней с различным количеством параметров.*/

#include <iostream>
#include <stdio.h>
using namespace std;
#define ARRAYSIZE 100
int* delminarray(int*, int);
int delminarrays(int, ...);
int main()
{
	setlocale(LC_CTYPE, "Russian");
	cout << "Введите одномерный массив целых чисел (CTRL+Z - завершение ввода): ";
	int arr[ARRAYSIZE];
	int i = 0;
	int sc = 0; //результат выполнения scanf_s
	while ((sc = scanf_s("%d", &(arr[i++]))) != EOF)
	{
		if (sc == 0) break; //Принудительное завершение при вводе данных не типа int
		if (i >= ARRAYSIZE) break; //принудительное завершение считывания на достижении верхней границы массива
	}
	if (i != ARRAYSIZE) i--; //отбрасываем считанный EOF
	cout << "Введенный одномерный массив: ";
	int n = 0; //счетчик отрицательных элементов в массиве
	for (int j = 0; j < i; j++)
	{
		printf("%d%s", arr[j], " ");
		if (arr[j] < 0) n++;
	}

	if (i == 0) delminarrays(1); //если массив пуст
	else if (n) delminarrays(4, i, arr, n);
	else delminarrays(3, i, arr);

	cout << endl;

	for (int j = 0; j < i; j++)
		printf("%d%s", arr[j], " ");

	return 0;
}
int* delminarray(int* myarray, int sz)
{
	/*
	функция удаляет отрицательные элементы массива, удаленный элемент заполняется нулем и переносится в конец массива
	первым параметром принимает адрес массива, вторым размер - массива в элементах,
	возвращает адрес массива, NULL в случае некорректных параметров
	*/
	if (sz <= 0 || myarray == NULL) return NULL;
	for (int i = 0; i < sz; i++)
	{
		if (myarray[i] < 0)
		{
			for (int j = i + 1; j < sz; j++)
			{
				myarray[j - 1] = myarray[j];
			}
			myarray[sz - 1] = 0;
			i--; //повторная проверка одной и той же позиции на случай, если влево свдинулся отрицательный элемент
		}
	}
	return myarray;
}
int delminarrays(int k, ...)
{
	/* первый параметр - общее количество параметров, передаваемых в функцию,
	равен 1, если передаваемый массив пуст;
	равен 3, когда передается размер массива и сам массив;
	равен 4, когда передаются размер массива, сам массив и количество в нем отрицательных элементов
	*/

	if (k == 1)
	{
		cout << "Передаваемый массив пуст.";
		return 0;
	}

	if (k == 3)
	{
		int* pk = &k;
		int* psizearray = ++pk; //получили адрес, по которому располагается размер массива
		int** pparray = (int**)(psizearray + 1);
		delminarray(*pparray, *psizearray);
	}
	if (k == 4)
	{
		int* pk = &k;
		int* psizearray = ++pk; //получили адрес, по которому располагается размер массива
		int** pparray = (int**)(psizearray + 1);
		int* pnegative = (int*)(pparray + 1);
		if (pnegative == 0) return 0;
		else delminarray(*pparray, *psizearray);
	}
	return 0;
}
