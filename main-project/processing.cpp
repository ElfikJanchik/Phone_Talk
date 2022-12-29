#include "processing.h"
#include "phone_talk.h"
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
	// Èíèöèàëèçèðóåì íàèáîëüøèé ýëåìåíò êàê êîðåíü
	int left = 2 * i + 1; // ëåâûé = 2*i + 1
	int right = 2 * i + 2; // ïðàâûé = 2*i + 2

	// Åñëè ëåâûé äî÷åðíèé ýëåìåíò áîëüøå êîðíÿ
	if (left < n && cmp(arr[left], arr[largest]))

		largest = left;

	// Åñëè ïðàâûé äî÷åðíèé ýëåìåíò áîëüøå, ÷åì ñàìûé áîëüøîé ýëåìåíò íà äàííûé ìîìåíò
	if (right < n && cmp(arr[right], arr[largest]))

		largest = right;

	// Åñëè ñàìûé áîëüøîé ýëåìåíò íå êîðåíü
	if (largest != i)
	{

		swap(arr[i], arr[largest]);
		// Ðåêóðñèâíî ïðåîáðàçóåì â äâîè÷íóþ êó÷ó çàòðîíóòîå ïîääåðåâî
		heapify(arr, n, largest, cmp);
	}
}
// Îñíîâíàÿ ôóíêöèÿ, âûïîëíÿþùàÿ ïèðàìèäàëüíóþ ñîðòèðîâêó
void Heapsort(phone_talk* arr[], int n, bool (*cmp)(phone_talk* a, phone_talk* b))
{
	// Ïîñòðîåíèå êó÷è (ïåðåãðóïïèðóåì ìàññèâ)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i, cmp);

	// Îäèí çà äðóãèì èçâëåêàåì ýëåìåíòû èç êó÷è
	for (int i = n - 1; i >= 0; i--)
	{
		// Ïåðåìåùàåì òåêóùèé êîðåíü â êîíåö
		swap(arr[0], arr[i]);

		// âûçûâàåì ïðîöåäóðó heapify íà óìåíüøåííîé êó÷å
		heapify(arr, i, 0, cmp);
	}
}
void Quicksort(phone_talk* array[], int size, bool(*cmp)(phone_talk* a, phone_talk* b))
{
}
/* Âñïîìîãàòåëüíàÿ ôóíêöèÿ äëÿ âûâîäà íà ýêðàí ìàññèâà ðàçìåðà n*/
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
	//Èíäåêñû íà÷àëà è êîíöà ìàññèâà
	int f = first, l = last;
	//Öåíòðàëüíûé ýëåìåíò ìàññèâà
	mid = arr[(f + l) / 2];
	//Äåëèì ìàññèâ
	do 
	{
		//Ïðîáåãàåì ýëåìåíòû, èùåì òå, êîòîðûå íóæíî ïåðåêèíóòü â äðóãóþ ÷àñòü
		//Â ëåâîé ÷àñòè ìàññèâà ïðîïóñêàåì(îñòàâëÿåì íà ìåñòå) ýëåìåíòû, êîòîðûå ìåíüøå öåíòðàëüíîãî
		while (mid > arr[f]) f++;
		//Â ïðàâîé ÷àñòè ïðîïóñêàåì ýëåìåíòû, êîòîðûå áîëüøå öåíòðàëüíîãî
		while (arr[l] > mid) l--;
		//Ìåíÿåì ýëåìåíòû ìåñòàìè
		if (f <= l)
		{
			count = arr[f];
			arr[f] = arr[l];
			arr[l] = count;
			f++;
			l--;
		}
	} while (f < l);
	//Ðåêóðñèâíûå âûçîâû, åñëè îñòàëîñü, ÷òî ñîðòèðîâàòü
	if (first < l) Quicksort(arr, first, l);  //"Ëåâûé êóñîê"
	if (f < last) Quicksort(arr, f, last); //"Ïðâûé êóñîê"
}

void Quicksort(phone_talk* arr[], int size)
{
	Quicksort(arr, 0, size - 1);
}
int process(phone_talk* array[], int size) {
	double x = 0;
	int h = 0;
	for (int i = 0;i < size;i++) {
		x += (array[i]->cost);
		h += array[i]->duration.hour * 3600 + array[i]->duration.minute * 60 + array[i]->duration.second;
	}
	double f = x / h;
	return f;
}
