#include "filter.h"
#include <cstring>
#include <iostream>

exam_info** filter(exam_info* array[], int size, bool (*check)(exam_info* element), int& result_size)
{
	exam_info** result = new exam_info * [size];
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

bool check_discipline(exam_info* element)
{
	return strcmp(element->discipline, "История Беларуси") == 0;
}

bool check_mark_value(exam_info* element)
{
	return element->mark >= 7;
}
