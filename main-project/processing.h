#ifndef PROCESSING_H
#define PROCESSING_H

#include "phone_talk.h"

bool cmpByDuration(phone_talk* a, phone_talk* b);
bool cmpByPhone(phone_talk* a, phone_talk* b);

int process(phone_talk* array[], int size);
void Heapsort(phone_talk* array[], int size, bool (*cmp)(phone_talk* a, phone_talk* b));
void Quicksort(phone_talk* array[], int size, bool (*cmp)(phone_talk* a, phone_talk* b));

#endif


