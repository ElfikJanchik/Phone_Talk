#ifndef FILTER_H
#define FILTER_H

#include "phone_talk.h"

phone_talk** filter(phone_talk* array[], int size, bool (*check)(phone_talk* element), int& result_size);
bool check_rate(phone_talk* element);
bool check_date(phone_talk* element);

#endif

