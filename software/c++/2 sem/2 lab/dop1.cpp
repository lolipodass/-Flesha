#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#define len 500
#define size 500
int choice;
using namespace std;
struct students
{
    char surname[len];
    char name[len];
    char exam[len];
    int mark;
};

struct students Student[size];
struct students ex[size][5];
int curr_size = 0;

void add();
void show();
void check();
void analyze();
void record();
void reading();

int main()
{
    cout << "Введите:" << endl;
    cout << "Добавить запись - 1" << endl;
    cout << "Вывести запись - 2" << endl;
    cout << "Проверить студента - 3" << endl;
    cout << "Обработать успеваемость студентов - 4" << endl;
    cout << "Записать информацию в файл - 5" << endl;
    cout << "Прочитать данные из файла - 6" << endl;
    cout << "Выйти из программы - 7" << endl;
    cin >> choice;
    do
    {
        switch (choice)
        {
        case 1:
            add();
            break;
        case 2:
            show();
            break;
        case 3:
            check();
            break;
        case 4:
            analyze();
            break;
        case 5:
            record();
            break;
        case 6:
            reading();
            break;
        }
    } while (choice != 7);
}

void add()
{
    if (curr_size < size)
    {
        cout << endl
             << "Фамилия:  " << endl;
        cin >> Student[curr_size].surname;
        cout << "Имя:  " << endl;
        cin >> Student[curr_size].name;
        for (int i = 0; i < 5; i++)
        {
            cout << i + 1 << "-й экзамен: " << endl;
            cin >> ex[curr_size][i].exam;
            cout << "Оценка:  " << endl;
            cin >> ex[curr_size][i].mark;
        }
        curr_size++;
    }
    else
    {
        cout << "Введено максимальное кол-во строк";
    }
    cout << "Что дальше?\n";
    cin >> choice;
}

void show()
{
    int sw, n;
    cout << "Вывод одной строки - 1" << endl;
    cout << "Вывод всех строк - 2" << endl;
    cin >> sw;
    if (sw == 1)
    {
        cout << "Номер выводимой строки " << endl;
        cin >> n;
        cout << endl;
        cout << "ФИО: ";
        cout << Student[n - 1].surname << endl;
        for (int i = 0; i < 5; i++)
        {
            cout << i + 1 << "-й экзамен: ";
            cout << ex[n - 1][i].exam << endl;
            cout << "Оценка: ";
            cout << ex[n - 1][i].mark << endl;
        }
    }
    if (sw == 2)
    {
        for (int i = 0; i < curr_size; i++)
        {
            cout << "Фамилия: ";
            cout << Student[i].surname << endl;
            cout << "Имя: ";
            cout << Student[i].name << endl;
            for (int j = 0; j < 5; j++)
            {
                cout << j + 1 << "-й экзамен: ";
                cout << ex[i][j].exam << endl;
                cout << "Оценка: ";
                cout << ex[i][j].mark << endl;
                cout << endl;
            }
        }
    }
    cout << "Что дальше?\n";
    cin >> choice;
}

void check()
{
    int j, num = 0;
    char fam[30];
    cout << "Введите Фамилию - " << endl;
    cin >> fam;
    for (int k = 0; k < curr_size; k++)
    {
        if (strcmp(fam, Student[k].surname) == 0)
        {
            j = k;
            num++;
        }
    }
    if (num == 0)
        cout << "Такого студента не нашлось\n";
    else
    {
        cout << "Есть ли  4 и 5 за экзамены?" << endl;
        for (int i = 0; i < 5; i++)
        {
            if (ex[j][i].mark == 4 || ex[j][i].mark == 5)
            {
                cout << i + 1 << "-й экзамен: ";
                cout << ex[j][i].exam << endl;
                cout << "Оценка: ";
                cout << ex[j][i].mark << endl;
                cout << endl;
            }
        }
    }
    cout << "Что дальше?\n";
    cin >> choice;
}

void analyze()
{
    int a = 0;
    int kol = 0;
    for (int j = 0; j < curr_size; j++)
    {
        a = 0;
        for (int i = 0; i < 5; i++)
        {
            if ((ex[j][i].mark == 4) || (ex[j][i].mark == 5))
                a++;
        }
        if ((a % 5) == 0)
            kol++;
    }
    cout << "Количество студентов, имеющих 5 и 4 за экзамены: " << kol << endl;
    float prc = (kol * (100 / curr_size));
    cout << "Соотношение студентов с оценкой 5 и 4 ко всем студентам: " << prc << "%" << endl;
    cout << "Что дальше?\n";
    cin >> choice;
}

void record()
{
    ofstream f("text.txt");
    for (int i = 0; i < curr_size; i++)
    {
        f << "Фамилия: " << Student[i].surname << endl
          << "Имя: " << Student[i].name << endl;
        for (int j = 0; j < 5; j++)
        {
            f << j + 1 << "-й экзамен: " << ex[i][j].exam << endl
              << "Оценка:  " << ex[i][j].mark << "\n\n";
        }
    }
    f.close();
    cout << "Что дальше?\n";
    cin >> choice;
}

void reading()
{
    string line;
    ifstream f("text.txt");
    while (getline(f, line))
    {
        cout << line << endl;
    }
    f.close();
    cout << "Что дальше?\n";
    cin >> choice;
}