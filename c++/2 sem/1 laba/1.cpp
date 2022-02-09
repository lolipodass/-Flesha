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
#include <windows.h>
#include <vector>
#include <fstream>

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
void choose(citizen *, short, short);
void FileRead(citizen *, short);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    short size;
    cout << "Array size: ";
    cin >> size;
    citizen *cit = new citizen[size];

    short choice;
    while (1)
    {
        cout << "1 input struct\n2 console log struct\n3 find element with date\n4 read from file\n-1 break\n";

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
        for (short i = 1; i <= size; i++)
        {
            cout << i << " citizen\n";
            structWrite(&arr[i]);
        }
        break;
    case 2:
        for (short i = 0; i < size; i++)
        {
            structRead(&arr[i]);
        }
        break;
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
    break;
    case 4:
        FileRead(arr, 0);
        break;
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
    cout << "Full name: " << cit->name << ",Age: " << cit->age << ",address: " << cit->address << ", gender: ";
    if (cit->sex)
        cout << "Male\n";
    else
        cout << "Female\n";
}

void FileRead(citizen *cit, short start)
{
    cout << "\nType file name(with ext)";
    ifstream fin;
    char fileName[50];
back:
    cin >> fileName;
    fin.open(fileName);
    if (!fin.is_open())
    {
        cout << "file " << fileName << " not exist, try again ";
        goto back;
    }

    string line;
    getline(fin, line);
    cout << line;

    short startName = line.find("NAME:");
    short startAge = line.find("AGE:", startName);
    short startStreet = line.find("STREET:", startAge);
    short startGender = line.find("GENDER:", startStreet);
    short npos = string::npos;
    if (startName == npos && startAge == npos && startStreet == npos && startGender == npos)
    {
        cout << "\nbad file, try again: ";
        goto back;
    };

    startName += 5;
    cit[start].name = line.substr(startName, startAge - startName);
    cit[start].age = stoi(line.substr(startAge + 4, startStreet - startAge - 4));
    cit[start].address = line.substr(startStreet + 7, startGender - startStreet - 7);

    if (line.substr(startGender + 7, line.size() - startGender - 7) == "m")
        cit[start].sex = 1;
    if (line.substr(startGender + 7, line.size() - startGender - 7) == "w")
        cit[start].sex = 0;
}
