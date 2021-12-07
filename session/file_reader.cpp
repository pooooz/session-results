#include "file_reader.h"
#include "constants.h"

#include <fstream>
#include <cstring>

date convert(char* str)
{
    date result;
    char* context = NULL;
    char* str_number = strtok_s(str, ".", &context);
    result.day = atoi(str_number);
    str_number = strtok_s(NULL, ".", &context);
    result.month = atoi(str_number);
    str_number = strtok_s(NULL, ".", &context);
    result.year = atoi(str_number);
    return result;
}

void read(const char* file_name, exam_info* array[], int& size)
{
    std::ifstream file(file_name);
    if (file.is_open())
    {
        size = 0;
        char tmp_buffer[MAX_STRING_SIZE];
        while (!file.eof())
        {
            exam_info* item = new exam_info;
            file >> item->student.last_name;
            file >> item->student.first_name;
            file >> item->student.middle_name;
            file >> tmp_buffer;
            item->exam_day = convert(tmp_buffer);
            
            file >> item->mark;
            file.read(tmp_buffer, 1); // чтения лишнего символа пробела
            file.getline(item->discipline, MAX_STRING_SIZE);
            array[size++] = item;
        }
        file.close();
    }
    else
    {
        throw "Ошибка открытия файла";
    }
}