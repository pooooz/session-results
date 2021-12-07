#include <iostream>
#include <iomanip>

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
        cout << "***** ����� ������ *****\n\n";
        for (int i = 0; i < size; i++)
        {
            /********** ����� �������� **********/
            cout << "�������........: ";
            // ����� �������
            cout << exams[i]->student.last_name << " ";
            // ����� ������ ����� �����
            cout << exams[i]->student.first_name[0] << ". ";
            // ����� ������ ����� ��������
            cout << exams[i]->student.middle_name[0] << ".";
            cout << '\n';
            
            // ����� ����������
            cout << '"' << exams[i]->discipline << '"';
            cout << '\n';

            // ����� ������
            cout << "������.........: ";
            cout << exams[i]->mark;
            cout << '\n';
            /********** ����� ���� ����� **********/
            // ����� ����
            cout << "���� �����.....: ";
            cout << setw(4) << setfill('0') << exams[i]->exam_day.year << '-';
            // ����� ������
            cout << setw(2) << setfill('0') << exams[i]->exam_day.month << '-';
            // ����� �����
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