#include <iostream>
#include <bitset>
#include <string>

using namespace std;

struct bytefield
{
    unsigned day : 5;
    unsigned month : 4;
    unsigned year : 12;
};
union date
{
    long date;
    bytefield bit;
};

enum spec
{
    ISIT = 1,
    POIBMS,
    DEVI,
    POIT
};

struct account
{
    string name;
    spec spec;
    int division;
    int position;
    date date;
};

void fullStruct(account *);
void ShowStruct(account *);

int main()
{
    int size;
    cout << "size array";
    account *arr = new account[size];

    for (int i = 0; i < size; i++)
    {

        fullStruct(arr);
        ShowStruct(arr);
    }
}

void fullStruct(account *acc)
{
    int buff;
    cout << "имя: ";
    cin >> acc->name;
    cout << "специальность:\t1 исит\t2 поибмс\t 3 деви\t 4 поит";
    cin >> buff;

    acc->spec = static_cast<spec>(buff);
    cout << "division: ";
    cin >> acc->division;
    cout << "position: ";
    cin >> acc->position;

    cout << "date, year: ";
    cin >> buff;
    acc->date.bit.year = buff;
    cout << "date, mouth: ";
    cin >> buff;
    acc->date.bit.month = buff;
    cout << "date, day: ";
    cin >> buff;
    acc->date.bit.day = buff;
}

void ShowStruct(account *acc)
{
    cout << "\nName: " << acc->name << "\nSpecial: ";
    switch (acc->spec)
    {
    case ISIT:
        cout << "ISIT";
        break;
    case POIBMS:
        cout << "POIBMS";
        break;
    case DEVI:
        cout << "ISIT";
        break;
    case POIT:
        cout << "POIT";
        break;
    default:
        break;
    }
    cout << "\nDivision: " << acc->division << "\nPosition: " << acc->position << "\n";
    cout << "Date:\n\tYear\t" << acc->date.bit.year << "\n\tMouth\t" << acc->date.bit.month << "\n\tDay\t" << acc->date.bit.day;
}

// *Отдел кадров.
//! Ф.И.О. работника, образование, специальность, подразделение, должность, оклад, дата поступления на предприятие.
// !Выбор по стражу работы. Даты реализовать с помощью битового поля, должность - с помощью перечисления.
