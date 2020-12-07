#pragma once
#define _CRT_SECURE_NO_WARNINGS //чтобы работала си функция посчета даты
#include <string>
#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;
struct People //заданная структура с полями соотвественно заданию
{
	string Surname;
	string lifeplace;
	int birthyear;
};
//дальше идут объявления функций. Определения смотри в cpp
void read_from_file(People*& _array);

void output_array_data(People* _array);

void correction_array_data(int num,People* _array);

double middle_age(People* _array);

int output_into_file_array_data(People* _array, string& output);