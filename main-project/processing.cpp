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
	// �������������� ���������� ������� ��� ������
	int left = 2 * i + 1; // ����� = 2*i + 1
	int right = 2 * i + 2; // ������ = 2*i + 2

	// ���� ����� �������� ������� ������ �����
	if (left < n && cmp(arr[left], arr[largest]))

		largest = left;

	// ���� ������ �������� ������� ������, ��� ����� ������� ������� �� ������ ������
	if (right < n && cmp(arr[right], arr[largest]))

		largest = right;

	// ���� ����� ������� ������� �� ������
	if (largest != i)
	{

		swap(arr[i], arr[largest]);
		// ���������� ����������� � �������� ���� ���������� ���������
		heapify(arr, n, largest, cmp);
	}
}
// �������� �������, ����������� ������������� ����������
void Heapsort(phone_talk* arr[], int n, bool (*cmp)(phone_talk* a, phone_talk* b))
{
	// ���������� ���� (�������������� ������)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i, cmp);

	// ���� �� ������ ��������� �������� �� ����
	for (int i = n - 1; i >= 0; i--)
	{
		// ���������� ������� ������ � �����
		swap(arr[0], arr[i]);

		// �������� ��������� heapify �� ����������� ����
		heapify(arr, i, 0, cmp);
	}
}
void Quicksort(phone_talk* array[], int size, bool(*cmp)(phone_talk* a, phone_talk* b))
{
}
/* ��������������� ������� ��� ������ �� ����� ������� ������� n*/
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
	//������� ������ � ����� �������
	int f = first, l = last;
	//����������� ������� �������
	mid = arr[(f + l) / 2];
	//����� ������
	do 
	{
		//��������� ��������, ���� ��, ������� ����� ���������� � ������ �����
		//� ����� ����� ������� ����������(��������� �� �����) ��������, ������� ������ ������������
		while (mid > arr[f]) f++;
		//� ������ ����� ���������� ��������, ������� ������ ������������
		while (arr[l] > mid) l--;
		//������ �������� �������
		if (f <= l)
		{
			count = arr[f];
			arr[f] = arr[l];
			arr[l] = count;
			f++;
			l--;
		}
	} while (f < l);
	//����������� ������, ���� ��������, ��� �����������
	if (first < l) Quicksort(arr, first, l);  //"����� �����"
	if (f < last) Quicksort(arr, f, last); //"����� �����"
}

void Quicksort(phone_talk* arr[], int size)
{
	Quicksort(arr, 0, size - 1);
}
