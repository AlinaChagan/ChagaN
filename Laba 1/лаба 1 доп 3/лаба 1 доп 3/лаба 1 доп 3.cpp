﻿// Функция, которая находит минимальное значение матрицы. Найти минимальные значения в n матрицах.
// Программа должна содержать функцию пользователя с переменным числом параметров и не менее трех обращений к ней с различным количеством параметров.

#include <iostream>
using namespace std;
int minmatrix(int, ...);
int** A; //глобальная переменная - адрес рабочей матрицы
int main()
{
	setlocale(LC_CTYPE, "Russian");
	int k, row, col; //количество обрабатываемых матриц, row - количество строк, col - столбцов
	cout << "Сколько матриц вы будете обрабатывать?" << endl;
	cin >> k;
	if (k <= 0)
	{
		cout << "Введенные данные некорректны.";
		return 0;
	}
	for (int i = 1; i <= k; i++)
	{

		cout << "Введите количество строк " << i << " матрицы: ";
		cin >> row;
		cout << "Введите количество столбцов " << i << " матрицы: ";
		cin >> col;
		if (row <= 0 || col <= 0)
		{
			minmatrix(1); //вызов функции с одним параметром! 
			return 0;
		}
		//выделяем динамическую память под матрицу
		A = new int* [row];
		for (int i = 0; i < row; i++) A[i] = new int[col];
		//ввод данных матрицы
		cout << endl;
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
			{
				cout << "Введите элемент " << i + 1 << " строки и " << i + 1 << " столбца: ";
				cin >> A[i][j];
			}
		//вывод матрицы
		cout << endl << "Введенная матрица: " << endl;
		for (int i = 0; i < row; i++)
		{
			cout << endl;
			for (int j = 0; j < col; j++)
			{
				cout << A[i][j] << "\t";
			}
		}
		//найдем минимальное значение матрицы
		int minimalv = 0;
		if (row == col) minimalv = minmatrix(2, row); //вызов функции с двумя параметрами
		else minimalv = minmatrix(3, row, col); //вызов функции с тремя параметрами
		cout << endl << "Минимальное значение матрицы: " << minimalv << endl;

		//высвободим динамическую память 
		for (int i = 0; i < row; i++) delete[] A[i];
		delete[] A;
	}

	return 0;
}


int minmatrix(int qpar, ...)
{
	/* функция возвращает минимальное значение матрицы,
	первым параметром передается количество всех параметров при данном вызове:
	qpar=1 для некорректных входных данных;
	вторым параметров - количество строк; третьим - количество столбцов матрицы;
	для квадратной матрицы достаточно 2х параметров */
	if (qpar == 1)
	{
		cout << "Данные характеристики матрицы некорректны. ";
		return 0;
	}
	int col = 0, row = 0, minvalue;
	if (qpar >= 2)
	{
		int* p = &qpar; //берем адрес первого параметра
		p++; //переходим к адресу второго параметра
		row = *p;
		if (qpar == 3)
		{
			p++; //переходим к адресу 3 параметра
			col = *p;
		}
		else col = row; //квадратная матрица
	}
	minvalue = A[0][0];
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
		{
			if (A[i][j] < minvalue) minvalue = A[i][j];
		}

	return minvalue;
}