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
    cout << "������������ ������ �8. GIT\n";
    cout << "������� �8. ����� ������\n";
    cout << "�����: ������� �����\n";
    cout << "������: 14\n\n";
    
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

        bool (*check_function)(exam_info*) = NULL;
        cout << "\n�������� ������ ���������� ������:\n";
        cout << "1) �������� � �� ������ �� ���������� ""������� ��������""\n";
        cout << "2) ��������, ���������� ������� 7 ��� ���� �� ����������\n";
        cout << "3) ������������ ������\n";
        cout << "\n������� ����� ���������� ������: ";
        int item;
        cin >> item;
        cout << '\n';
        switch (item)
        {
        case 1:
            check_function = check_discipline; // ����������� � ��������� �� ������� ��������������� �������
            cout << "***** �������� � �� ������ �� ���������� ""������� ��������"" *****\n\n";
            break;
        case 2:
            check_function = check_mark_value; // ����������� � ��������� �� ������� ��������������� �������
            cout << "***** ��������, ���������� ������� 7 ��� ���� �� ���������� *****\n\n";
            break;
        case 3:
            cout << "������ ������� " << process(exams, size) << " ���(��)\n\n";
            break;
        default:
            throw "������������ ����� ������";
        }

        if (check_function) {
            int new_size;
            exam_info** filtered = filter(exams, size, check_function, new_size);
            for (int i = 0; i < new_size; i++)
            {
                /********** ����� �������� **********/
                cout << "�������........: ";
                // ����� �������
                cout << filtered[i]->student.last_name << " ";
                // ����� ������ ����� �����
                cout << filtered[i]->student.first_name[0] << ". ";
                // ����� ������ ����� ��������
                cout << filtered[i]->student.middle_name[0] << ".";
                cout << '\n';

                // ����� ����������
                cout << '"' << filtered[i]->discipline << '"';
                cout << '\n';

                // ����� ������
                cout << "������.........: ";
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