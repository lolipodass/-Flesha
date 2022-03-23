#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct contract
{
    string name;
    double price;
    short amount;
    short workExp;
};

void ReadFromFile();
void FullContract(contract *);
void WriteToFile(contract *);
void Choosing(contract *, short, short);

int main()
{

    short size;
    cout << "Array size: ";
    cin >> size;
    contract *con = new contract[size];

    short value;

    while (1)
    {
        cout << "1 вручную\n2 чтение из файла\n3 запись в файл\n";
        cin >> value;
        if (value != 1 || value != 2 || value != 3 || value != 4 || value != 5 || value != 6)
        {
            break;
        }
    }
}

void Choosing(contract *arr, short choice, short size)
{

    switch (choice)
    {
    case 1:
    {
        cout << "сколько элементов заполнить?(0=all)";
        int amount;
        cin >> amount;
        (amount > size) || (amount == 0) ? amount = size : 0;
        for (short i = 0; i < size; i++)
        {
            FullContract(&arr[i]);
        }
    }
    break;

    case 2:
        ReadFromFile();
        break;
    case 3:
        WriteToFile(&arr[1]);
        break;
    default:

        break;
    }
}

// void findChoice(contract arrContracts)
// {
//     cout << "What field u want to find: \n1 name\n2 price\n3 amount\n4 work experience\n-1 back";
//     short choice;
//     switch (choice)
//     {
//     case 1:

//         break;

//     default:
//         break;
//     }
// }
void FullContract(contract *cont)
{
    cout << "Имя\n";
    cin >> cont->name;
    cout << "Стоимость\n";
    cin >> cont->price;
    cout << "Количество концертов\n";
    cin >> cont->amount;
    cout << "Опыт работы\n";
    cin >> cont->workExp;
}

void ReadFromFile()
{
    ifstream file;
    string line;
    string name;
    cout << "название файла: ";
    cin >> name;
    file.open(name);
    getline(file, line);

    if (!file.is_open())
    {
        cout << "wrong file";
        return;
    }

    short startName = line.find("NAME:") + 5;
    short startPrice = line.find("PRICE:", startName) + 6;
    short startAmount = line.find("AMOUNT:", startPrice) + 7;
    short startExperience = line.find("EXPERIENCE:", startAmount) + 11;

    short npos = static_cast<short>(string::npos);
    if (startName == npos || startPrice == npos || startAmount == npos || startExperience == npos)
    {
        cout << "bad file\n";
        return;
    }

    cout << '\n'
         << line.substr(startName, startPrice - startName - 7) << "\n";
    cout << line.substr(startPrice, startAmount - startPrice - 7) << "\n";
    cout << line.substr(startAmount, startExperience - startAmount - 11) << "\n";
    cout << line.substr(startExperience, line.size()) << "\n";
}

void WriteToFile(contract *con)
{
    ofstream file;
    file.open("out");
    file << "NAME:" << con->name << "PRICE:" << con->price << "AMOUNT:" << con->amount << "EXPERIENCE:" << con->workExp;
}

// !В соответствии со своими заданиями из лабораторной работы №2, составить массив структур для своей БД и реализовать
// !функции считывания с файла и вывод
// !структуры на экран, записи в файл и добавления данных в массив. Для функций считывание и записи должен быть выбор (в виде меню),
// ! в котором пользователь
// !может сам ввести название файла с клавиатуры либо использовать уже заготовленный файл.
