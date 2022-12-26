#include <iostream>
#include "constants.h"
#include "phone_talk.h"
#include "file_reader.h"

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
        for (int i = 0; i < size; i++)
        {
            std::cout << talks[i]->number << '\n';
            dateOutput(talks[i]->date);
            std::cout << '\n';
            std::cout << "Время звонка: ";
            timeOutput(talks[i]->time);
            std::cout << '\n';
            std::cout << "Продолжительность звонка: ";
            timeOutput(talks[i]->duration);
            std::cout << '\n';
            std::cout << talks[i]->rate << '\n';
            std::cout << "Стоимость звонка: " << talks[i]->cost << '\n';
            std::cout << '\n';
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