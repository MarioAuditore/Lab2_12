#pragma once
#pragma once // 5 � �
#include <iostream> // ���������� ������������ ���� �����-������
#include <fstream> // ���������� ������������ ���� ��� ������ � �������
#include <string> // ���������� ������������ ���� ��� ������ �� ��������
#include <ctime> // ���������� ������������ ���� ��� ������ �� �������� � �����
using namespace std; // ���������� ������������ ���� std

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
  string score;  //int myint1 = std::stoi(str1); ������� � �����
  fio couch;
};


class team {
public:
  info team_data;
};

// ������������� �������
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
