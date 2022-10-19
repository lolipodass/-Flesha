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

int main()
{
    short size;
    cout << "Array size: ";
    cin >> size;
    contract cfon[size];
    contract *con = new contract[size];
}

void findChoice(contract arrContracts)
{
    cout << "What field u want to find: \n1 name\n2 price\n3 amount\n4 work experience\n-1 back";
    short choice;
    switch (choice)
    {
    case 1:

        break;

    default:
        break;
    }
}
void FullContract(contract *cont)
{
    cout << "Имя";
    cin >> cont->name;
    cout << "Стоимость";
    cin >> cont->price;
    cout << "Количество концертов";
    cin >> cont->amount;
    cout << "Опыт работы";
    cin >> cont->workExp;
}

//! Для вашей БД (из лабораторной работы №2) создать индексы для каждой структуры
// !и линейный поиск данных по индексу (при вводе индекса, выводило всю структуру).