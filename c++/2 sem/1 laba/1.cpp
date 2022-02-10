//*4. В соответствии со своим вариантом разработать программу для данных, приведенных в таблице ниже.  Определить структурированный тип, разработать меню для работы с массивом структур.
//! В программу должны войти функции:
// 	 ввод элементов структуры с клавиатуры;
// 	 вывод элементов структуры в консольное окно;
// 	TODO удаление заданной структурированной переменной;
// 	поиск информации;
// 	запись информации в файл;
// 	чтение данных из файла.
// !Горожанин. Ф.И.О., дата рождения, адрес, пол (м, ж). Реализовать выборку по году рождения.

#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>

using namespace std;

struct citizen
{
    string name;
    unsigned int age = 0;
    string address;
    bool sex;
    bool uses = 0;
};

void structWrite(citizen *);
void structRead(citizen *);
void findStuct(citizen *, short, int);
void choose(citizen *, short, short);
void FileRead(citizen *, short, short);
void decode(citizen *, string, short);
string encode(citizen *);

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
        cout << "1 input struct\n2 console log struct\n3 find element with date\n4 read from file\n5 write to file\n6 delete element\n-1 break\n";

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
        cout << "what year u need?";
        short find;
        cin >> find;
        findStuct(arr, size, find);
    }
    break;
    case 4:
        FileRead(arr, 0, size);
        break;
    case 5:
    {
        ofstream file;
        cout << "\nType file name(with ext)";
        char fileName[50];
        do
        {
            cin >> fileName;
            file.open(fileName);
            if (!file.is_open())
            {
                cout << "with " << fileName << " some problem, choose different ";
                continue;
            }
            break;
        } while (1);

        for (short i = 0; i < size; i++)
        {
            // string line = encode(&arr[i]);

            file << "NAME:" << arr[i].name << " AGE:" << arr[i].age << " STREET: " << arr[i].address << " GENDER: ";
            if (arr[i].sex == 1)
                file << "m\n";
            else
                file << "w\n";
        }
        file.close();
    }
    break;
    case 6:
    {
        short pos;
        do
        {
            cout << "what element u want to delete? ";
            cin >> pos;
            if (pos > size)
            {
                cout << "\n wrong number, try again ";
                continue;
            }
            break;
        } while (1);
        arr[pos].uses = 0;
    }
    default:
        break;
    }
}

void findStuct(citizen *arr, short size, int date)
{
    for (short i = 0; i < size; i++)
    {
        if (arr[i].age == date && arr[i].uses == 1)
        {
            structRead(&arr[i]);
        }
    }
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

    do
    {
        cin >> buf;
        if (buf != 'm' && buf != 'w')
        {
            cout << "wrong input,try again: ";
            continue;
        }
        if (buf == 'm')
            cit->sex = 1;
        if (buf == 'w')
            cit->sex = 0;
        break;
    } while (1);
    cit->uses = 1;
}

void structRead(citizen *cit)
{
    if (!cit->uses)
    {
        return;
    }

    cout << "Full name: " << cit->name << ",Age: " << cit->age << ",address: " << cit->address << ", gender: ";
    if (cit->sex)
        cout << "Male\n";
    else
        cout << "Female\n";
}

void FileRead(citizen *cit, short start, short size)
{

    // *file check
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

    short kol;
    cout << "how many strings read? ";
    do
    {
        if (kol > size)
        {
            cout << "array smaller, try again ";
            continue;
        }
        break;
    } while (1);

    cin >> kol;
    for (short i = 0; i < kol; i++)
    {
        string line;
        getline(fin, line);
        decode(cit, line, i + start);
    }
    fin.close();
}

void decode(citizen *cit, string line, short pos)
{
    // *string check
    short startName = line.find("NAME:");
    short startAge = line.find("AGE:", startName);
    short startStreet = line.find("STREET:", startAge);
    short startGender = line.find("GENDER:", startStreet);
    short npos = static_cast<short>(string::npos);
    if (startName == npos && startAge == npos && startStreet == npos && startGender == npos)
    {
        cout << "\nbad file, try again: ";
        return;
    };

    startName += 5;
    cit[pos].name = line.substr(startName, startAge - startName);
    cit[pos].age = stoi(line.substr(startAge + 4, startStreet - startAge - 4));
    cit[pos].address = line.substr(startStreet + 7, startGender - startStreet - 7);

    if (line.substr(startGender + 7, line.size() - startGender - 7) == "m")
        cit[pos].sex = 1;
    if (line.substr(startGender + 7, line.size() - startGender - 7) == "w")
        cit[pos].sex = 0;
    cit[pos].uses = 1;
}

string encode(citizen *cit)
{
    string line;
    line = "NAME:" + cit->name + " AGE:" + static_cast<char>(cit->age) + " STREET: " + cit->address + " GENDER: " + static_cast<char>(cit->sex);
    return line;
}