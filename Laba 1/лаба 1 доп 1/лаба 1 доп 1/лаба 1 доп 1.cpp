//Функция, которая находит все простые числа из нескольких интервалов. Интервалы задаются границами a и b.
//Программа должна содержать функцию пользователя с переменным числом параметров и не менее трех обращений к ней с различным количеством параметров.

#include <iostream>
using namespace std;
bool checkprost(int);
void diapazon1(int, int);
void prost(int, int*, ...);
int main()
{
	setlocale(LC_CTYPE, "Russian");
	int k;
	cout << "Введите количество интервалов для проверки (не более 6): ";
	cin >> k;
	if (k <= 0 || k > 6)
	{
		cout << "Введенные данные некорректны. ";
		return 0;
	}
	int** A = new int* [k];
	for (int i = 0; i < k; i++) A[i] = new int[2];
	for (int i = 0; i < k; i++)
	{
		cout << "Введите левую границу " << i + 1 << " интервала: ";
		cin >> A[i][0];
		cout << "Введите правую границу " << i + 1 << " интервала: ";
		cin >> A[i][1];
	}
	if (k == 1) prost(1, A[0]);
	else if (k == 2) prost(2, A[0], A[1]);
	else if (k == 3) prost(3, A[0], A[1], A[2]);
	else if (k == 4) prost(4, A[0], A[1], A[2], A[3]);
	else if (k == 5) prost(5, A[0], A[1], A[2], A[3], A[4]);
	else if (k == 6) prost(6, A[0], A[1], A[2], A[3], A[4], A[5]);

	//высвободим динамическую память
	for (int i = 0; i < k; i++) delete[] A[i];
	delete[] A;
	return 0;
}
bool checkprost(int q)
{
	//проверяет, является ли число простым, возвращает р-т проверки 
	bool result = true;
	for (int i = 2; i <= sqrt(q); i++)
	{
		if (q % i == 0)
		{
			result = false;
			break;
		}
	}
	return result;
}
void diapazon1(int a, int b)
{
	//выводит все простые числа на интервале [a;b]
	for (int p = a; p <= b; p++)
	{
		if (checkprost(p)) cout << p << " ";
	}
	cout << endl;
}
void prost(int n, int* p1, ...)
{
	//первым параметром принимает количество интервалов для проверки
	int** pp = &p1;
	for (int i = 1; i <= n; i++)
	{
		diapazon1((*pp)[0], (*pp)[1]);
		pp++;
	}
}