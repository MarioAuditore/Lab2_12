#include "Header.h"

// ������� InputM ������������ ���� ���������� ��������� ������ switch � ��������� ������������ �����.� ������ ������������� ���� �����������
int InputM()
{
	int n;
	while (!(std::cin >> n) or n != 1 and n != 2 and n != 3 and n != 0 or getchar() != '\n') {
		cout << "������ �������� �� ����������.���������� ������ ��� ���: ";// ��� ������������ �����
		cin.clear(); // ������� �����
		cin.ignore(10000, '\n'); // ���������� ��� ������� �� ������� ����� ������
	}
	return n;
}
int InputF()
{
	int n;
	while (!(std::cin >> n) or n != 1 and n != 0 or getchar() != '\n') {
		cout << "������ �������� �� ����������.���������� ������ ��� ���: ";// ��� ������������ �����
		cin.clear(); // ������� �����
		cin.ignore(10000, '\n'); // ���������� ��� ������� �� ������� ����� ������
	}
	return n;
}

// ������� InputN ������������ ���� ����� , ������������� ���-�� �������� ����������(�� 1 �� 6000) � � ������ ������������� ���� �����������
int InputN()
{
	int n;
	while (!(std::cin >> n) or n < 0 or n > 60000 or getchar() != '\n') {
		cout << "������������ ����.�� ������ ������� ������ ����� ����� �� 1 �� 60000.���������� ��� ���: "; // ��� ������������ �����
		cin.clear(); // ������� �����
		cin.ignore(10000, '\n'); // ���������� ��� ������� �� ������� ����� ������
	}
	return n;
}

int ClassInitialization(team* obj, int N)
{
	ifstream MyFile; // ������ ��� ��������� �����(�������� ����)
	string temp; // ��������� ���������� ��� ������ ������ �������� ��������
	MyFile.open("C:\\Users\\Elf\\Desktop\\�����\\C++\\����\\����1_12���\\DataBase.csv", ios_base::in); // ��������� ���� ��� ������
	if (!MyFile.is_open()) // �������� ������������� ����� DataBase.csv
	  cout << "���� � ����� ������ DataBase.csv �� ��� ������." << endl;

	getline(MyFile, temp, '\n'); // ��������� ������ �������� ��������
	for (int i = 0; i < N; i++) {
		getline(MyFile, obj[i].team_data.club_name, ','); // ��������� ��������������� ������ csv �����(��� ��� � ��������� ����������� ';')
		getline(MyFile, obj[i].team_data.city, ',');
		getline(MyFile, obj[i].team_data.score, ',');
		getline(MyFile, obj[i].team_data.couch.f, ',');
		getline(MyFile, obj[i].team_data.couch.i, ',');
		getline(MyFile, obj[i].team_data.couch.o, '\n');
	}
	MyFile.close(); // ��������� ����
	return 0;
}

inline bool operator>(team& a, team& b)
{
	if (stoi(a.team_data.score) == stoi(b.team_data.score))
	{
		if (a.team_data.club_name > b.team_data.club_name)
			return true;
		else
			return false;
	}
	else
		if (stoi(a.team_data.score) > stoi(b.team_data.score))
			return true;
		else
			return false;

}
inline bool operator==(team& a, team& b)
{
	if (a.team_data.score == b.team_data.score)
		return true;
	else
		return false;
}
inline bool operator!=(team& a, team& b)// ����� ������� ��� ��� ��������� ==
{
	if (a.team_data.score != b.team_data.score)
		return true;
	else
		return false;
}
bool operator<=(team& a, team& b)//��������� ��������� >
{
	if (!(operator>(a, b)))
		return true;
	else
		return false;
}
bool operator<(team& a, team& b)//��������� > � ��������� ==
{
	if (!(operator>(a, b)) && (!(operator==(a, b))))
		return true;
	else
		return false;
}
bool operator>=(team& a, team& b)// ��������� <
{
	if (!(operator<(a, b)))
		return true;
	else
		return false;

}


double Shakersort(team* object, int N)
{
	double StartTime, EndTime;
	StartTime = clock();
	int left = 0, right = N - 1; // ����� � ������ ������� ����������� ������� �������
	int flag = 1;  // ���� ������� �����������
	// ���������� ����� ���� ����� ������� �� �������� � ������ � ���� � ������� ������� �����������
	while ((left < right) && flag > 0)
	{
		flag = 0;
		for (int i = left; i < right; i++)  //��������� ����� �������
		{
			if (operator>(object[i], object[i + 1]))// ���� ��������� ������� ������ ��������,
			{             // ������ �� �������
				team t = object[i];
				object[i] = object[i + 1];
				object[i + 1] = t;
				flag = 1;      // ����������� � ���� ����� ����
			}
		}
		right--; // �������� ������ ������� �� ���������� �������
		for (int i = right; i > left; i--)  //��������� ������ ������
		{
			if (operator>(object[i - 1], object[i])) // ���� ���������� ������� ������ ��������,
			{            // ������ �� �������
				team t = object[i];
				object[i] = object[i - 1];
				object[i - 1] = t;
				flag = 1;    // ����������� � ���� ����� ����
			}
		}
		left++; // �������� ����� ������� �� ��������� �������
	}
	EndTime = clock();
	return EndTime - StartTime;
}

void siftDown(team* ar, int root, int bottom)// �������� ����
{
	int maxChild; // ������ ������������� �������
	int done = 0; // ���� ����, ��� ���� ������������
	// ���� �� ����� �� ���������� ����
	while ((root * 2 <= bottom) && (!done))
	{
		if (root * 2 == bottom) // ���� �� � ��������� ����,
			maxChild = root * 2; // ���������� ����� �������
			// ����� ���������� ������� ������� �� ����
		else if (ar[root * 2] > ar[root * 2 + 1])
			maxChild = root * 2;
		else
			maxChild = root * 2 + 1;
		// ���� ������� ������� ������ ������������� �������
		if (ar[root] < ar[maxChild])
		{
			team temp = ar[root]; // ������ �� �������
			ar[root] = ar[maxChild];
			ar[maxChild] = temp;
			root = maxChild;
		}
		else // �����
			done = 1; // �������� ������������
	}
}
double PyramidSort(team* arr, int array_size)// ������� ���������� �� ����
{
	double StartTime, EndTime;//������ �������
	StartTime = clock();
	// ��������� ������ ��� ��������
	for (int i = (array_size / 2) - 1; i >= 0; i--)
		siftDown(arr, i, array_size - 1);
	// ���������� ����� �������� ��������� ��������
	for (int i = array_size - 1; i >= 1; i--)
	{
		team temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		siftDown(arr, 0, i - 1);
	}
	EndTime = clock();
	return  EndTime- StartTime;
}
void CreateNewFile(team* obj, int N)
{
	ofstream NewFile; // ������ ��� ��������� �����(�������� �����)
	string filename; // ���������� ��� ����� ����� �����
	cout << "������� ��� ������ �����: ";
	getline(cin, filename); // ���� ����� �����
	while (filename == "\0") { // ��������� ��� ������ �����
		cout << "�������� ����� �� ����� ���� ������.���������� ��� ���" << endl;
		cout << "������� ��� ������ �����: ";
		getline(cin, filename); // ���� ����� �����
	}

	filename += ".csv"; // ��������� � ��� ����� .csv ��� �������� ����� ���� csv
	NewFile.open(filename, ios_base::out); // �������(��������� ����, ���� �� ��� ����������) ��� ������

	for (int i = 0; i < N; i++) // ��������� ������� ������� �� �������������� ������� � ������ ����������� ��� ����������� ����������� � csv �����,� ��� �� '\n' ��� ���������� �������� �� ������ � �����
	{
		NewFile << obj[i].team_data.club_name + ';';
		NewFile << obj[i].team_data.city + ';';
		NewFile << obj[i].team_data.score + ';';
		NewFile << obj[i].team_data.couch.f + ';';
		NewFile << obj[i].team_data.couch.i + ';';
		NewFile << obj[i].team_data.couch.o + '\n';
	}
	cout << "���� ��� ������" << endl; // ����� ������� �� ��������� �������� �����
	NewFile.close(); // ��������� ����
}