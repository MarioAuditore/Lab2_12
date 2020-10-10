#include "Header.h"

// Функция InputM осуществляет ввод переменной оператора выбора switch и проверяет корректность ввода.В случае некорректного ввод повторяется
int InputM()
{
	int n;
	while (!(std::cin >> n) or n != 1 and n != 2 and n != 3 and n != 0 or getchar() != '\n') {
		cout << "Такого действия не существует.Попробуйте ввести еще раз: ";// При некорректном вводе
		cin.clear(); // Очищаем поток
		cin.ignore(10000, '\n'); // Пропускаем все символы до символа новой строки
	}
	return n;
}
int InputF()
{
	int n;
	while (!(std::cin >> n) or n != 1 and n != 0 or getchar() != '\n') {
		cout << "Такого действия не существует.Попробуйте ввести еще раз: ";// При некорректном вводе
		cin.clear(); // Очищаем поток
		cin.ignore(10000, '\n'); // Пропускаем все символы до символа новой строки
	}
	return n;
}

// Функция InputN осуществляет ввод числа , определяющего кол-во объектов сортировки(от 1 до 6000) и в случае некорректного ввод повторяется
int InputN()
{
	int n;
	while (!(std::cin >> n) or n < 0 or n > 60000 or getchar() != '\n') {
		cout << "Некорректный ввод.Вы должны вводить только целые числа от 1 до 60000.Попробуйте еще раз: "; // При некорректном вводе
		cin.clear(); // Очищаем поток
		cin.ignore(10000, '\n'); // Пропускаем все символы до символа новой строки
	}
	return n;
}

int ClassInitialization(team* obj, int N)
{
	ifstream MyFile; // Объект для обравотки файла(файловый ввод)
	string temp; // Временная переменная для чтения строки названий столбцов
	MyFile.open("C:\\Users\\Elf\\Desktop\\файлы\\C++\\Лабы\\лаба1_12вар\\DataBase.csv", ios_base::in); // Открываем файл для чтения
	if (!MyFile.is_open()) // Проверка существования файла DataBase.csv
	{
		cout << "Файл с базой данных DataBase.csv не был найден." << endl; 
		return 1;
	}

	getline(MyFile, temp, '\n'); // Считываем строку названий столбцов
	for (int i = 0; i < N; i++) {
		getline(MyFile, obj[i].team_data.club_name, ';'); // Считываем последовательно ячейки csv файла(для это и ставились разделители ';')
		getline(MyFile, obj[i].team_data.city, ';');
		getline(MyFile, obj[i].team_data.score, ';');
		getline(MyFile, obj[i].team_data.couch.f, ';');
		getline(MyFile, obj[i].team_data.couch.i, ';');
		getline(MyFile, obj[i].team_data.couch.o, '\n');
	}
	MyFile.close(); // Закрываем файл
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
inline bool operator!=(team& a, team& b)// можно сделать еще как отрицание ==
{
	if (a.team_data.score != b.team_data.score)
		return true;
	else
		return false;
}
bool operator<=(team& a, team& b)//отрицание оператора >
{
	if (!(operator>(a, b)))
		return true;
	else
		return false;
}
bool operator<(team& a, team& b)//отрицание > и отрицание ==
{
	if (!(operator>(a, b)) && (!(operator==(a, b))))
		return true;
	else
		return false;
}
bool operator>=(team& a, team& b)// отрицание <
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
	int left = 0, right = N - 1; // левая и правая границы сортируемой области массива
	int flag = 1;  // флаг наличия перемещений
	// Выполнение цикла пока левая граница не сомкнётся с правой и пока в массиве имеются перемещения
	while ((left < right) && flag > 0)
	{
		flag = 0;
		for (int i = left; i < right; i++)  //двигаемся слева направо
		{
			if (operator>(object[i], object[i + 1]))// если следующий элемент меньше текущего,
			{             // меняем их местами
				team t = object[i];
				object[i] = object[i + 1];
				object[i + 1] = t;
				flag = 1;      // перемещения в этом цикле были
			}
		}
		right--; // сдвигаем правую границу на предыдущий элемент
		for (int i = right; i > left; i--)  //двигаемся справа налево
		{
			if (operator>(object[i - 1], object[i])) // если предыдущий элемент больше текущего,
			{            // меняем их местами
				team t = object[i];
				object[i] = object[i - 1];
				object[i - 1] = t;
				flag = 1;    // перемещения в этом цикле были
			}
		}
		left++; // сдвигаем левую границу на следующий элемент
	}
	EndTime = clock();
	return EndTime - StartTime;
}

void siftDown(team* ar, int root, int bottom)// создание кучи
{
	int maxChild; // индекс максимального потомка
	int done = 0; // флаг того, что куча сформирована
	// Пока не дошли до последнего ряда
	while ((root * 2 <= bottom) && (!done))
	{
		if (root * 2 == bottom) // если мы в последнем ряду,
			maxChild = root * 2; // запоминаем левый потомок
			// иначе запоминаем больший потомок из двух
		else if (ar[root * 2] > ar[root * 2 + 1])
			maxChild = root * 2;
		else
			maxChild = root * 2 + 1;
		// если элемент вершины меньше максимального потомка
		if (ar[root] < ar[maxChild])
		{
			team temp = ar[root]; // меняем их местами
			ar[root] = ar[maxChild];
			ar[maxChild] = temp;
			root = maxChild;
		}
		else // иначе
			done = 1; // пирамида сформирована
	}
}
double PyramidSort(team* arr, int array_size)// Функция сортировки на куче
{
	double StartTime, EndTime;//отсчет времени
	StartTime = clock();
	// Формируем нижний ряд пирамиды
	for (int i = (array_size / 2) - 1; i >= 0; i--)
		siftDown(arr, i, array_size - 1);
	// Просеиваем через пирамиду остальные элементы
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
	ofstream NewFile; // Объект для обработки файла(файловый вывод)
	string filename; // Переменная для ввода имени файла
	cout << "Введите имя нового файла: ";
	getline(cin, filename); // Ввод имени файла
	while (filename == "\0") { // Обработка при пустом вводе
		cout << "Название файла не может быть пустым.Попробуйте еще раз" << endl;
		cout << "Введите имя нового файла: ";
		getline(cin, filename); // Ввод имени файла
	}

	filename += ".csv"; // Добавляем в имя файла .csv для создания файла типа csv
	NewFile.open(filename, ios_base::out); // Создаем(открываем файл, если он уже существует) для записи

	for (int i = 0; i < N; i++) // Заполняем столбцы данными из сортированного массива и ставим разделители для корректного отображения в csv файле,а так же '\n' для разделение объектов на строки в файле
	{
		NewFile << obj[i].team_data.club_name + ';';
		NewFile << obj[i].team_data.city + ';';
		NewFile << obj[i].team_data.score + ';';
		NewFile << obj[i].team_data.couch.f + ';';
		NewFile << obj[i].team_data.couch.i + ';';
		NewFile << obj[i].team_data.couch.o + '\n';
	}
	cout << "Файл был создан" << endl; // Вывод надписи об окончании создании файла
	NewFile.close(); // Закрываем файл
}
