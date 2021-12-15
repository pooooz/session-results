#include "processing.h"
#include "iostream"
#include "iomanip"

using namespace std;

// функци€ провер€ет, €вл€етс€ год с указанным номером високосным
bool is_leap_year(int year)
{
	if (year % 400)
	{
		if (year % 100)
		{
			return !(year % 4);
		}
		else
		{
			return false;
		}
	}
	else
	{
		return true;
	}
}

// функци€ возвращает количество дней в мес€це
// мес€ц задаЄтс€ числом от 1 до 12
// если номер мес€ца задан неверно, функци€ возвращает 0
int days(int month, bool leap_year)
{
	switch (month)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 31;
	case 2:                                                   return leap_year ? 29 : 28;
	case 4: case 6: case 9: case 11:                          return 30;
	default: return 0;
	}
}

// функци€ вычисл€ет количество дней, прошедших с 1 €нвар€ 1-го года н. э. до заданной даты
int days(date d)
{
	int result = 0;
	for (int year = 1; year < d.year; year++)
	{
		result += is_leap_year(year) ? 366 : 365;
	}
	bool leap_year = is_leap_year(d.year);
	for (int month = 1; month < d.month; month++)
	{
		result += days(month, leap_year);
	}
	result += d.day;
	return result;
}

// функци€ вычисл€ет количество дней, прошедших между указанными датами
int diff(date a, date b)
{
	int x = days(a);
	int y = days(b);
	return (x > y ? x - y : y - x) + 1;
}

int process(exam_info* exams[], int size)
{
	date max = exams[0]->exam_day;
	date min = exams[0]->exam_day;
	for (int i = 0; i < size; i++) {
		if ((exams[i]->exam_day.year > max.year) || (exams[i]->exam_day.year >= max.year && exams[i]->exam_day.month > max.month) || (exams[i]->exam_day.year >= max.year && exams[i]->exam_day.month >= max.month && exams[i]->exam_day.day > max.day)) {
			max = exams[i]->exam_day;
		}
		else if ((exams[i]->exam_day.year < max.year) || (exams[i]->exam_day.year <= max.year && exams[i]->exam_day.month < max.month) || (exams[i]->exam_day.year <= max.year && exams[i]->exam_day.month <= max.month && exams[i]->exam_day.day < max.day)) {
			min = exams[i]->exam_day;
		}
	}


	int duration = diff(min, max);

	return duration;
}
