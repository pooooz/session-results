#ifndef BOOK_SUBSCRIPTION_H
#define BOOK_SUBSCRIPTION_H

#include "constants.h"

struct date
{
    int day;
    int month;
    int year;
};

struct person
{
    char first_name[MAX_STRING_SIZE];
    char middle_name[MAX_STRING_SIZE];
    char last_name[MAX_STRING_SIZE];
};

struct exam_info
{
    person student;
    date exam_day;
    unsigned int mark;
    char discipline[MAX_STRING_SIZE];
};

#endif