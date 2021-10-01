#include <iostream>
#include <math.h>
	using namespace std;
	float mdichotom(float (*) (float), float, float, float); //первым параметром передается адрес рабочей функции (прототип(описание, объявление) ф-ии mdichotom)
	float func1(float); //функция №1
	float func2(float); //функция №2
	void func3(float*, float*); //функция получения значений a и b с клавиатуры 
	int main()
	{
		setlocale(LC_CTYPE, "Russian");
		int n;
		float a, b;
		float e = 0.001f;
		cout << "Выберите функцию f(x) : \n\n 1:  e^x + 2x^2 – 3 \n 2:  x^3 + 3 " << endl;
		cin >> n;
		switch (n)
		{
		   case 1:
		   {
			func3(&a, &b);
			cout << "Отделенный корень уравнения для функции №1  = " << mdichotom(func1, e, a, b) << endl;
			break;
		   }
		   case 2:
		   {
		    func3(&a, &b);
			cout << "Отделенный корень уравнения для функции №2 = " << mdichotom(func2, e, a, b) << endl;
			break;
		   }
		   default:
		   {
			cout << "Введенные данные некорректны." << endl;
			break;
		   }
		} //switch

		return 0;
	}

	float func1(float x) //определение ф-ии func1
	{
		return sin(x) + pow(x, 3);
	}
	float func2(float x) //определение ф-ии func2
	{
		return (float)(0.4 + pow(x, 3));
	}

	float mdichotom(float (*f1) (float), float e, float a, float b)
	{
		float x;
		do
		{
			x = (a + b) / 2;
			if ((f1(x)) * (f1(a)) <= 0)
				b = x;
			else
				a = x;

		} while ((abs(a - b)) > 2 * e);
		return x;
	}
	void func3(float* var1, float* var2)
	{
		cout << "Введите a = ";
		cin >> *var1;
		cout << endl;
		cout << "Введите b = ";
		cin >> *var2;
		cout << endl;
	}



