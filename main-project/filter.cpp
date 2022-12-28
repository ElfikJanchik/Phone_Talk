#include "filter.h"
#include <cstring>
#include <iostream>
#include <fstream>


phone_talk** filter(phone_talk* array[], int size, bool (*check)(phone_talk* element), int& result_size)
{
	phone_talk** result = new phone_talk * [size];
	result_size = 0;
	for (int i = 0; i < size; i++)
	{
		if (check(array[i]))
		{
			result[result_size++] = array[i];
		}
	}
	return result;
}
//задаЄм последовательность, где записан только тариф
bool check_rate(phone_talk* element)
{
	return strcmp(element->rate, "мобильный") == 0;
}
//задаЄм последовательность, где записаны звонки только в но€бре 2022
bool check_date(phone_talk* element)
{
	return element->date.month == 11 && element->date.year == 22;
}



