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
	// �������������� ���������� ������� ��� ������
	int l = 2 * i + 1; // ����� = 2*i + 1
	int r = 2 * i + 2; // ������ = 2*i + 2

	// ���� ����� �������� ������� ������ �����
	if (l < n && arr[l] > arr[largest])

		largest = l;

	// ���� ������ �������� ������� ������, ��� ����� ������� ������� �� ������ ������
	if (r < n && arr[r] > arr[largest])

		largest = r;

	// ���� ����� ������� ������� �� ������
	if (largest != i)
	{

		swap(arr[i], arr[largest]);
		// ���������� ����������� � �������� ���� ���������� ���������
		heapify(arr, n, largest);
	}
}
// �������� �������, ����������� ������������� ����������
void Heapsort(int arr[], int n)
{
	// ���������� ���� (�������������� ������)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	// ���� �� ������ ��������� �������� �� ����
	for (int i = n - 1; i >= 0; i--)
	{
		// ���������� ������� ������ � �����
		swap(arr[0], arr[i]);

		// �������� ��������� heapify �� ����������� ����
		heapify(arr, i, 0);
	}
}
/* ��������������� ������� ��� ������ �� ����� ������� ������� n*/
void printArray(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
	cout << arr[i] << " ";
	cout << "\n";
}

void Quicksort(int* phone_talk, int first, int last)
{
	int mid, count;
	//��������� � ������ � � ����� �������
	int f = first, l = last;
	//����������� ������� �������
	mid = phone_talk[(f + l) / 2];
	//����� ������
	do 
	{
		//��������� ��������, ���� ��, ������� ����� ���������� � ������ �����
		//� ����� ����� ������� ����������(��������� �� �����) ��������, ������� ������ ������������
		while (phone_talk[f] < mid) f++;
		//� ������ ����� ���������� ��������, ������� ������ ������������
		while (phone_talk[l] > mid) l--;
		//������ �������� �������
		if (f <= l)
		{
			count = phone_talk[f];
			phone_talk[f] = phone_talk[l];
			phone_talk[l] = count;
			f++;
			l--;
		}
	} while (f < l);
	//����������� ������, ���� ��������, ��� �����������
	if (first < l) Quicksort(phone_talk, first, l);  //"����� �����"
	if (f < last) Quicksort(phone_talk, f, last); //"����� �����"
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