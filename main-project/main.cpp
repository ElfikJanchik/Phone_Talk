#include <iostream>
#include <iomanip>
#include "constants.h"
#include "phone_talk.h"
#include "file_reader.h"
#include "filter.h"
#include "processing.h"

void dateOutput(date date) {
    static const char* months[12] = { "январь", "февраль", "март", "апрель", "май", "июнь", "июль", "август", "сентябрь", "октябрь", "ноябрь", "декабрь" };
    std::cout << date.day << ' ' << months[date.month - 1] << ' ' << date.year << " г.";
}

void timeOutput(Time time) {
    std::cout.width(2);
    std::cout.fill('0');
    std::cout << time.hour << ':';
    std::cout.width(2);
    std::cout.fill('0');
    std::cout << time.minute << ':';
    std::cout.width(2);
    std::cout.fill('0');
    std::cout << time.second;
}

void output(phone_talk* talks)
{
	std::cout << talks->number << '\n';
	dateOutput(talks->date);
	std::cout << '\n';
	std::cout << "Время звонка: ";
	timeOutput(talks->time);
	std::cout << '\n';
	std::cout << "Продолжительность звонка: ";
	timeOutput(talks->duration);
	std::cout << '\n';
	std::cout << talks->rate << '\n';
	std::cout << "Стоимость звонка: " << talks->cost << '\n';
	std::cout << '\n';
}
int main()
{
	setlocale(LC_ALL, "RU");
	std::cout << "Лабораторная работа №9. GIT\n";
	std::cout << "Вариант №9. Телефонный разговор\n";
	std::cout << "Автор: Арина Панизник\n\n";
	std::cout << "Группа: 12\n";

	phone_talk* talks[MAX_FILE_ROWS_COUNT];
	int size;
		try
		{
			
			read("data.txt", talks, size);
			std::cout << "***** Телефонные разговоры *****\n\n";
			for (int i = 0; i < size; i++)
			{
				output(talks[i]);
			}
			bool (*check_function)(phone_talk*) = NULL;
			bool (*cmp_function)(phone_talk*, phone_talk*) = NULL;
			void (*sort_function)(phone_talk * [], int, bool (*)(phone_talk*, phone_talk*)) = NULL;
			std::cout << "1) Выберите способ фильтрации или отработкиданных:\n";
			std::cout << "2) Вывести все телефонные разговоры на мобильные телефоны.\n";
			std::cout << "3) Вывести все телефонные разговоры в ноябре 2022 года.\n";
			std::cout << "\nВвдите номер выбранного пункта: ";
			int item;
			std::cin >> item;
			std::cout << '\n';
			switch (item)
			{
			case 1:
				check_function = check_rate; //       
				std::cout << "***** телефонные разговоры на мобильные телефоны *****\n\n";
				break;
			case 2:
				check_function = check_date; //       
				std::cout << "***** телефонные разговоры в ноябре 2022 года *****\n\n";
				break;
			default:
				throw " Некорректный номер пункта ";
			}

			//sort_function(talks, size, cmp_function);

			if (check_function)
			{
				int new_size;
				phone_talk** filtered = filter(talks, size, check_function, new_size);
				std::cout << "Выберите критерий";
				std::cout << "1)Пирамидальная сортировка (Heap sort) по убыванию продолжительности разговора\n";
				std::cout << "2)Быстрая сортировка (Quick sort) по убыванию продолжительности разговора\n";
				std::cout << "3)Пирамидальная сортировка (Heap sort) по возрастанию номера телефона\n";
				std::cout << "4)Быстрая сортировка (Quick sort) по возрастанию номера телефона\n";
				std::cout << "\nВведите номер выбраннного пункта: ";
				int sort;
				std::cin >> sort;
				switch (sort)
				{
				case 1:
					Heapsort(talks, size, cmpByDuration);
					break;
				case 2:
					Quicksort(talks, size, cmpByDuration);
					break;
				case 3:
					Heapsort(talks, size, cmpByPhone);
					break;
				case 4:
					Quicksort(talks, size, cmpByPhone);
					break;
				default:
					throw " Некорректный номер пункта ";
				}

				for (int i = 0; i < size; i++)
				{
					output(filtered[i]);
				}
				delete[] filtered;
			}
			for (int i = 0; i < size; i++)
			{
				delete talks[i];
			}
		}
		catch (const char* error)
		{
			std::cout << error << '\n';
		}
		
	return 0;
}
