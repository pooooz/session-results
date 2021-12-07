#include <iostream>
#include <iomanip>

using namespace std;

#include "exam.h"
#include "file_reader.h"
#include "constants.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Лабораторная работа №8. GIT\n";
    cout << "Вариант №8. Итоги сессии\n";
    cout << "Автор: Дмитрий Панин\n";
    cout << "Группа: 14\n\n";

    exam_info* exams[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        read("data.txt", exams, size);
        cout << "***** Итоги сессии *****\n\n";
        for (int i = 0; i < size; i++)
        {
            /********** вывод студента **********/
            cout << "Студент........: ";
            // вывод фамилии
            cout << exams[i]->student.last_name << " ";
            // вывод первой буквы имени
            cout << exams[i]->student.first_name[0] << ". ";
            // вывод первой буквы отчества
            cout << exams[i]->student.middle_name[0] << ".";
            cout << '\n';
            
            // вывод дисциплины
            cout << '"' << exams[i]->discipline << '"';
            cout << '\n';

            // вывод оценки
            cout << "Оценка.........: ";
            cout << exams[i]->mark;
            cout << '\n';
            /********** вывод даты сдачи **********/
            // вывод года
            cout << "Дата сдачи.....: ";
            cout << setw(4) << setfill('0') << exams[i]->exam_day.year << '-';
            // вывод месяца
            cout << setw(2) << setfill('0') << exams[i]->exam_day.month << '-';
            // вывод числа
            cout << setw(2) << setfill('0') << exams[i]->exam_day.day;
            cout << '\n';
           
            cout << '\n';
        }
        for (int i = 0; i < size; i++)
        {
            delete exams[i];
        }
    }
    catch (const char* error)
    {
        cout << error << '\n';
    }
    return 0;
}