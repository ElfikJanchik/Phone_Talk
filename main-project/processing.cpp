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

bool cmpByDuration(phone_talk* a, phone_talk* b)
{
	if (a->duration.hour > b->duration.hour)
	{
		return true;
	}
	else if (a->duration.hour < b->duration.hour)
	{
		return false;
	}
	else if(a->duration.minute > b->duration.minute)
	{
		return true;
	}
	else if (a->duration.minute < b->duration.minute)
	{
		return false;
	}
	else
	{
		return a->duration.second > b->duration.second;
	}
}

bool cmpByPhone(phone_talk* a, phone_talk* b)
{
	int n = strcmp(a->number, b->number);
	if (n < 0)
	{
		return false;
	}
	else if (n > 0)
	{
		return true;
	}
	else
	{
		return a->cost < b->cost;
	}
}
 
void heapify(phone_talk* arr[], int n, int i, bool (*cmp)(phone_talk* a, phone_talk* b))
{
	int largest = i;
	// Инициализируем наибольший элемент как корень
	int left = 2 * i + 1; // левый = 2*i + 1
	int right = 2 * i + 2; // правый = 2*i + 2

	// Если левый дочерний элемент больше корня
	if (left < n && cmp(arr[left], arr[largest]))

		largest = left;

	// Если правый дочерний элемент больше, чем самый большой элемент на данный момент
	if (right < n && cmp(arr[right], arr[largest]))

		largest = right;

	// Если самый большой элемент не корень
	if (largest != i)
	{

		swap(arr[i], arr[largest]);
		// Рекурсивно преобразуем в двоичную кучу затронутое поддерево
		heapify(arr, n, largest, cmp);
	}
}
// Основная функция, выполняющая пирамидальную сортировку
void Heapsort(phone_talk* arr[], int n, bool (*cmp)(phone_talk* a, phone_talk* b))
{
	// Построение кучи (перегруппируем массив)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i, cmp);

	// Один за другим извлекаем элементы из кучи
	for (int i = n - 1; i >= 0; i--)
	{
		// Перемещаем текущий корень в конец
		swap(arr[0], arr[i]);

		// вызываем процедуру heapify на уменьшенной куче
		heapify(arr, i, 0, cmp);
	}
}
void Quicksort(phone_talk* array[], int size, bool(*cmp)(phone_talk* a, phone_talk* b))
{
}
/* Вспомогательная функция для вывода на экран массива размера n*/
void printArray(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
	cout << arr[i] << " ";
	cout << "\n";
}

void Quicksort(phone_talk* arr[], int first, int last)
{
	phone_talk* mid;
	phone_talk* count;
	//Индексы начала и конца массива
	int f = first, l = last;
	//Центральный элемент массива
	mid = arr[(f + l) / 2];
	//Делим массив
	do 
	{
		//Пробегаем элементы, ищем те, которые нужно перекинуть в другую часть
		//В левой части массива пропускаем(оставляем на месте) элементы, которые меньше центрального
		while (mid > arr[f]) f++;
		//В правой части пропускаем элементы, которые больше центрального
		while (arr[l] > mid) l--;
		//Меняем элементы местами
		if (f <= l)
		{
			count = arr[f];
			arr[f] = arr[l];
			arr[l] = count;
			f++;
			l--;
		}
	} while (f < l);
	//Рекурсивные вызовы, если осталось, что сортировать
	if (first < l) Quicksort(arr, first, l);  //"Левый кусок"
	if (f < last) Quicksort(arr, f, last); //"Првый кусок"
}

void Quicksort(phone_talk* arr[], int size)
{
	Quicksort(arr, 0, size - 1);
}
