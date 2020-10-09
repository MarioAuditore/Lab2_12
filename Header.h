#pragma once 
#include <iostream> // Подключаем заголовочный файл ввода-вывода
#include <fstream> // Подключаем заголовочный файл для работы с файлами
#include <string> // Подключаем заголовочный файл для работы со строками
#include <ctime> // Подключаем заголовочный файл для работы со временем и датой
using namespace std; // Подключаем пространство имен std

struct fio
{
  string f;
  string i;
  string o;
};
struct info
{
  string club_name; 
  string city;
  string score;  
  fio couch;
};


class team {
public:
  info team_data;
};

// Îáúÿâëÿåëåíèå ôóíêöèé
int ClassInitialization(team* obj, int N);
double Shakersort(team* object,int N);
void siftDown(team* ar, int root, int bottom);
double PyramidSort(team* arr, int array_size);
int InputM();
int InputN();
int InputF();
void CreateNewFile(team* obj, int N);

bool operator>(team& a, team& b);
bool operator<(team& a, team& b);
bool operator==(team& a, team& b);
bool operator!=(team& a, team& b);
bool operator>=(team& a, team& b);
bool operator<=(team& a, team& b);
