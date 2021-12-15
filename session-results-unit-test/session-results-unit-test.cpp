#include "pch.h"
#include "CppUnitTest.h"
#include "../session/exam.h"
#include "../session/processing.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace sessionresultsunittest
{
	// ��������������� ������� ��� �������� ������ ��������
	// ��� ��� ��� ������ ���������� ���� ������ � �,
	// ������ � ��������, ������ � �������� �� �����������
	exam_info* build_exam(int exam_day, int exam_month, int exam_year)
	{
		exam_info* exam = new exam_info;
		exam->exam_day.day = exam_day;
		exam->exam_day.month = exam_month;
		exam->exam_day.year = exam_year;
		return exam;
	}

	// ��������������� ������� ��� �������� ������� �������� ������
	void delete_subscription(exam_info* array[], int size)
	{
		for (int i = 0; i < size; i++)
		{
			delete array[i];
		}
	}

	TEST_CLASS(unittestproject)
	{
	public:
		TEST_METHOD(TestMethod1) // ���� � �������� ������ ������
		{
			exam_info* exams[3];
			exams[0] = build_exam(2, 1, 2015); //min
			exams[1] = build_exam(5, 1, 2015); 
			exams[2] = build_exam(8, 1, 2015); //max
			Assert::AreEqual(7, process(exams, 3));
			delete_subscription(exams, 3);
		}

		TEST_METHOD(TestMethod2) // ���� ���������� ��������� ������� � �������� ������ ����
		{
			exam_info* exams[3];

			exams[0] = build_exam(22, 1, 2015); //min
			exams[1] = build_exam(25, 1, 2015); 
			exams[2] = build_exam(9, 2, 2015); //max
			Assert::AreEqual(19, process(exams, 3));
			delete_subscription(exams, 3);
		}

		TEST_METHOD(TestMethod3) // ���� ���������� ��������� ������� � �������� ������ ������������� ����
		{
			exam_info* exams[3];

			exams[0] = build_exam(27, 2, 2015); 
			exams[1] = build_exam(25, 2, 2015); // min
			exams[2] = build_exam(7, 3, 2015); // max
			Assert::AreEqual(11, process(exams, 3));
			delete_subscription(exams, 3);
		}

		TEST_METHOD(TestMethod4) // ���� ���������� ��������� ������� � �������� ������ ����������� ����
		{
			exam_info* exams[3];

			exams[0] = build_exam(25, 2, 2016); // min
			exams[1] = build_exam(26, 2, 2016); 
			exams[2] = build_exam(7, 3, 2016); // max
			Assert::AreEqual(12, process(exams, 3));
			delete_subscription(exams, 3);
		}

		TEST_METHOD(TestMethod5) // ���� ���������� ��������� ������� � �������� ������ ������������� ���� (2)
		{
			exam_info* exams[3];

			exams[0] = build_exam(25, 2, 1900); 
			exams[1] = build_exam(7, 3, 1900); //max
			exams[2] = build_exam(25, 2, 1900); //min
			Assert::AreEqual(11, process(exams, 3));
			delete_subscription(exams, 3);
		}

		TEST_METHOD(TestMethod6) // ���� ���������� ��������� ������� � �������� ������ ����������� ���� (2)
		{
			exam_info* exams[3];

			exams[0] = build_exam(7, 3, 2000); // max
			exams[1] = build_exam(25, 2, 2000); // min
			exams[2] = build_exam(27, 2, 2000); 
			Assert::AreEqual(12, process(exams, 3));
			delete_subscription(exams, 3);
		}

		TEST_METHOD(TestMethod7) // ���� ���������� ��������� ������������ ���
		{
			exam_info* exams[3];

			exams[0] = build_exam(4, 3, 2015); // max
			exams[1] = build_exam(25, 12, 2014); // min
			exams[2] = build_exam(7, 2, 2015);
			Assert::AreEqual(70, process(exams, 3));
			delete_subscription(exams, 3);
		}

		TEST_METHOD(TestMethod8) // ���� ���������� ��������� ���, � ��� ����� � ����������
		{
			exam_info* exams[3];

			exams[0] = build_exam(4, 3, 2016); // max
			exams[1] = build_exam(7, 2, 2016); 
			exams[2] = build_exam(25, 12, 2015); // min
			Assert::AreEqual(71, process(exams, 3));
			delete_subscription(exams, 3);
		}
	};
}
