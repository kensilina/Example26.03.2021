﻿#include <iostream>
using namespace std;

/*
Адрес - это число длиной 4 Байта,
означающий порядковый номер Байта в оперативной памяти
-------------------------------------------------------------------------------------
Указатель (Pointer) - переменная, которая содержит адрес другой переменной/
-------------------------------------------------------------------------------------
& - оператор взятия адреса (Address - of operator).
Это унарный оператор, который возвращает адрес своего операнда. 
Оператор это оператор значения над которым производят действия
У & есть только префиксная форма записи (всегда ставится перед операндом).
-------------------------------------------------------------------------------------
* - оператор разыменования (Dereference operator).
* Это унарный оператор, который возвращает значение по адресу.
* - только при объявлении показывает, что объявляемая переменная - это указатель,
* во всех остальных случаях она разыменовывает указатель.
-------------------------------------------------------------------------------------
*/

//#define POINTERS_BASICS  // директива. Основа указателей
#define POINTERS_AND_ARRAYS //указатели и массивы

/*
define - определить
definietion - определение
директива #define создает макроопределение, и показывает что заменить, и чем заменить.
(Наприемер если указать #define PI 3.14 перед функцией, и в функции указать вывод PI, при компиляции выыведется
3.14)
#define что_заменить чем_заменить
или
#define имя значение

Директива - это указание компилятору на выполнение некторых действий.

*/

void main()
{
	setlocale(LC_ALL, "ru");
#if defined POINTERS_BASICS
// если определено Pointers_basics, то нижеследующий код будет виден компилятору

	int a = 2; // обьявление переменной
	int* pa = &a; // обьявление указателя
	cout << a << endl; // выводим на экран значение переменной 'а'
	cout << &a << endl; // получаем адрес переменной 'a' прямо привыводе
	cout << pa << endl; // вывод адреса переменной 'а' хранящегося в указателе 'pa'
	cout << *pa << endl; // разыменовываем указатель 'pa' и получаем значение по адресу

	int* pb;
	int b = 3;
	pb = &b;
	cout << *pb << endl;

	/*
	-------------------------------------------------------------------------------------
	int - int
	int* - указатель на int
	char - char
	char* - указатель на char
	-------------------------------------------------------------------------------------
	*/


#endif // POINTERS_BASICS

#if defined POINTERS_AND_ARRAYS
	/*
	----------------------------------------------------------------
	Имя массива является указателем на массив, поскольку содержит адрес
	нулевого элемента массива,
	а следовательно и всего массива/
	Используя  Арифметику указателей можно вычислить адрес любого
	элемента массива.
	----------------------------------------------------------------
					АРИФМЕТИКА УКАЗАТЕЛЕЙ

	Компилятор всегда должен знать на какой тип данных указывает указатель.
	Это нужно для того , чтобы понимать сколько байт памяти нужно считать или записать по адресу.
	Так же это нужно для арифметики указателей.
	Над указателями можно применять арифметические операции:
	+,-,++,--
	и результат операции будет зависеть от типа данных, на которые указывает указатель:
	Если указателю на char прибавить 1, то адрес изменится на 1 Байт
	Если указателю на int прибавить 1, то адрес изменится на 4 Байт
	Если указателю на double прибавить 1, то адрес изменится на 8 Байт
	----------------------------------------------------------------
	*/

	const int n = 5;
	int arr[n] = { 3, 5, 8, 13, 21 };
	cout << *arr << endl;
	for (int i = 0; i < n; i++)
	{
		// обращение к элементам массива через арифметику указателей и оператор разыменования
		cout << *(arr + i ) << "\t";
	}
	cout << endl;

	/*
	------------------------------------------------------------------
	Доступ к элементам массива осуществляется за константное время,
	поскольку сводится к операции сложения, а операция сложения
	всегда выполнятеся за константное время, то есть, процессор
	на операция сложения всегда тратит одно и то же количество тактов.
	------------------------------------------------------------------
	*/

	for (int i = 0; i < n; i++)
	{
		// [] - Оператор индексирования. Он так же вычисляет адрес массива,
		// и разыменовывает его.
		cout << arr[i] << "\t";
	}
	cout << endl;

#endif

}
