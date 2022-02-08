//*4. В соответствии со своим вариантом разработать программу для данных, приведенных в таблице ниже.  Определить структурированный тип, разработать меню для работы с массивом структур.
//! В программу должны войти функции:
// 	 ввод элементов структуры с клавиатуры;
// 	 вывод элементов структуры в консольное окно;
// 	TODO удаление заданной структурированной переменной;
// 	TODO поиск информации;
// 	TODO запись информации в файл;
// 	TODO чтение данных из файла.
// !Горожанин. Ф.И.О., дата рождения, адрес, пол (м, ж). Реализовать выборку по году рождения.

#include <iostream>
#include <string>
#include <locale>
#include <windows.h>
#include <vector>

using namespace std;

struct citizen
{
    string name;
    unsigned int age;
    string address;
    bool sex;
};

void structWrite(citizen *);
void structRead(citizen *);
vector<citizen> findStuct(citizen *, short, int);
void choose(citizen, short, short);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    short size;
    cout << "Array size";
    cin >> size;
    citizen *cit = new citizen[size];

    short choice;
    while (1)
    {
        cout << "1 input struct";
        cout << "2 console log struct";
        cout << "3 find element with date";
        cout << "-1 break";

        cin >> choice;
        if (choice == -1)
            break;
        choose(cit, choice, size);
    }
}

void choose(citizen *arr, short choice, short size)
{
    switch (choice)
    {
    case 1:
        for (short i = 0; i < size; i++)
        {
            structWrite(&arr[i]);
        }
        break;
    case 2:
        for (short i = 0; i < size; i++)
        {
            structRead(&arr[i]);
        }
    case 3:
    {
        vector<citizen> buff;
        cout << "what year u need?";
        short find;
        cin >> find;
        buff = findStuct(arr, size, find);
        for (short i = 0; i < buff.size(); i++)
        {
            structRead(&arr[i]);
        }
    }
    default:
        break;
    }
}

vector<citizen> findStuct(citizen *arr, short size, int date)
{
    vector<citizen> buff;
    for (short i = 0; i < size; i++)
    {
        if (arr[i].age == date)
        {
            buff.push_back(arr[i]);
        }
    }
    return buff;
}

void structWrite(citizen *cit)
{
    cin.ignore(10, '\n');
    char buf;
    cout << "Full name\n";
    getline(cin, cit->name);
    cout << "Age\n";
    cin >> cit->age;
    cout << "address\n";
    cin.ignore(10, '\n');
    getline(cin, cit->address);
    cout << "gender(m/w)\n";

ret:
    cin >> buf;
    if (buf == 'm')
        cit->sex = 1;
    if (buf == 'w')
        cit->sex = 0;
    if (buf != 'm' && buf != 'w')
    {
        cout << "wrong input,try again: ";
        goto ret;
    }
}

void structRead(citizen *cit)
{
    cout << "Full name: " << cit->name << ",Age: " << cit->age << ",address: " << cit->address << ", sex: " << cit->sex << "\n";
}