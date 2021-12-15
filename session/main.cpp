#include <iostream>
#include <iomanip>

using namespace std;

#include "exam.h"
#include "file_reader.h"
#include "constants.h"
#include "filter.h"
#include "processing.h"

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

        bool (*check_function)(exam_info*) = NULL;
        cout << "\nВыберите способ фильтрации данных:\n";
        cout << "1) Студенты и их оценки по дисциплине ""История Беларуси""\n";
        cout << "2) Студенты, получившие отметку 7 или выше за дисциплину\n";
        cout << "3) Длительность сессии\n";
        cout << "\nВведите номер выбранного пункта: ";
        int item;
        cin >> item;
        cout << '\n';
        switch (item)
        {
        case 1:
            check_function = check_discipline; // присваиваем в указатель на функцию соответствующую функцию
            cout << "***** Студенты и их оценки по дисциплине ""История Беларуси"" *****\n\n";
            break;
        case 2:
            check_function = check_mark_value; // присваиваем в указатель на функцию соответствующую функцию
            cout << "***** Студенты, получившие отметку 7 или выше за дисциплину *****\n\n";
            break;
        case 3:
            cout << "Сессия длилась " << process(exams, size) << " дня(ей)\n\n";
            break;
        default:
            throw "Некорректный номер пункта";
        }

        if (check_function) {
            int new_size;
            exam_info** filtered = filter(exams, size, check_function, new_size);
            for (int i = 0; i < new_size; i++)
            {
                /********** вывод студента **********/
                cout << "Студент........: ";
                // вывод фамилии
                cout << filtered[i]->student.last_name << " ";
                // вывод первой буквы имени
                cout << filtered[i]->student.first_name[0] << ". ";
                // вывод первой буквы отчества
                cout << filtered[i]->student.middle_name[0] << ".";
                cout << '\n';

                // вывод дисциплины
                cout << '"' << filtered[i]->discipline << '"';
                cout << '\n';

                // вывод оценки
                cout << "Оценка.........: ";
                cout << filtered[i]->mark;
                cout << '\n';
                cout << '\n';

            }
            delete[] filtered;
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