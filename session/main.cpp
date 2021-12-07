#include <iostream>

using namespace std;

#include "exam.h"
#include "file_reader.h"
#include "constants.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "������������ ������ �8. GIT\n";
    cout << "������� �8. ����� ������\n";
    cout << "�����: ������� �����\n\n";
    exam_info* exams[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        read("data.txt", exams, size);
        for (int i = 0; i < size; i++)
        {
            cout << exams[i]->student.last_name << '\n';
            cout << exams[i]->student.first_name << '\n';
            cout << exams[i]->student.middle_name << '\n';
            cout << exams[i]->exam_day.day << ' ';
            cout << exams[i]->exam_day.month << ' ';
            cout << exams[i]->exam_day.year << '\n';
            cout << exams[i]->mark << "\n";
            cout << exams[i]->discipline << '\n';
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