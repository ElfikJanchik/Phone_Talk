#ifndef PHONE_TALK_H
#define PHONE_TALK_H

#include "constants.h"

struct date
{
    int day;
    int month;
    int year;
};

struct Time
{
    int hour;
    int minute;
    int second;
};

struct phone_talk
{
    char number[MAX_STRING_SIZE];
    date date;
    Time time;
    Time duration;
    char rate[MAX_STRING_SIZE];
    double cost;
};

#endif
