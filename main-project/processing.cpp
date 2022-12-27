#include "processing.h"
#include "phone_talk.h"
#include "file_reader.cpp"
#include "file_reader.h"
#include "constants.h"
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <iostream>

using namespace std;
 
void heapify(int arr[], int n, int i)
{
	int largest = i;
	// Инициализируем наибольший элемент как корень
	int l = 2 * i + 1; // левый = 2*i + 1
	int r = 2 * i + 2; // правый = 2*i + 2

	// Если левый дочерний элемент больше корня
	if (l < n && arr[l] > arr[largest])

		largest = l;

	// Если правый дочерний элемент больше, чем самый большой элемент на данный момент
	if (r < n && arr[r] > arr[largest])

		largest = r;

	// Если самый большой элемент не корень
	if (largest != i)
	{

		swap(arr[i], arr[largest]);
		// Рекурсивно преобразуем в двоичную кучу затронутое поддерево
		heapify(arr, n, largest);
	}
}
// Основная функция, выполняющая пирамидальную сортировку
void Heapsort(int arr[], int n)
{
	// Построение кучи (перегруппируем массив)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	// Один за другим извлекаем элементы из кучи
	for (int i = n - 1; i >= 0; i--)
	{
		// Перемещаем текущий корень в конец
		swap(arr[0], arr[i]);

		// вызываем процедуру heapify на уменьшенной куче
		heapify(arr, i, 0);
	}
}
/* Вспомогательная функция для вывода на экран массива размера n*/
void printArray(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
	cout << arr[i] << " ";
	cout << "\n";
}

void Quicksort(int* phone_talk, int first, int last)
{
	int mid, count;
	//Указатели в начало и в конец массива
	int f = first, l = last;
	//Центральный элемент массива
	mid = phone_talk[(f + l) / 2];
	//Делим массив
	do 
	{
		//Пробегаем элементы, ищем те, которые нужно перекинуть в другую часть
		//В левой части массива пропускаем(оставляем на месте) элементы, которые меньше центрального
		while (phone_talk[f] < mid) f++;
		//В правой части пропускаем элементы, которые больше центрального
		while (phone_talk[l] > mid) l--;
		//Меняем элементы местами
		if (f <= l)
		{
			count = phone_talk[f];
			phone_talk[f] = phone_talk[l];
			phone_talk[l] = count;
			f++;
			l--;
		}
	} while (f < l);
	//Рекурсивные вызовы, если осталось, что сортировать
	if (first < l) Quicksort(phone_talk, first, l);  //"Левый кусок"
	if (f < last) Quicksort(phone_talk, f, last); //"Првый кусок"
}

/*void cost_sort(phone_talk** report, int size)
{
	int i = 0;
	int buf;
	while (i < size)
	{
		int count = 0;
		char* talks = report[i]-> ;
		for (int i=0)
	}
}*/