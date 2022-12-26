#include "file_reader.h"
#include "constants.h"

#include <fstream>
#include <cstring>

date convertDate(char* str)
{
    date result;
    char* context = NULL;
    char* str_number = strtok_s(str, ".", &context);
    result.day = atoi(str_number);
    str_number = strtok_s(NULL, ".", &context);
    result.month = atoi(str_number);
    str_number = strtok_s(NULL, ".", &context);
    result.year = atoi(str_number);
    return result;
}

Time convertTime(char* str) {
    Time result;
    char* context = NULL;
    char* str_number = strtok_s(str, ":", &context);
    result.hour = atoi(str_number);
    str_number = strtok_s(NULL, ":", &context);
    result.minute = atoi(str_number);
    str_number = strtok_s(NULL, ":", &context);
    result.second = atoi(str_number);
    return result;
}

void read(const char* file_name, phone_talk* array[], int& size)
{
    std::ifstream file(file_name);
    if (file.is_open())
    {
        size = 0;
        char tmp_buffer[MAX_STRING_SIZE];
        while (!file.eof())
        {
            phone_talk* item = new phone_talk;
            file >> item->number;
            file >> tmp_buffer;
            item->date = convertDate(tmp_buffer);
            file >> tmp_buffer;
            item->time = convertTime(tmp_buffer);
            file >> tmp_buffer;
            item->duration = convertTime(tmp_buffer);
            file >> item->rate;
            file >> item->cost;
            array[size++] = item;
        }
        file.close();
    }
    else
    {
        throw "Ошибка открытия файла";
    }
}