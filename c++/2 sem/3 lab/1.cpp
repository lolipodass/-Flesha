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

struct account
{
    string name;
    string spec;
    int division;
    int position;
    date date;
};

int main()
{
}

// *Отдел кадров.
//! Ф.И.О. работника, образование, специальность, подразделение, должность, оклад, дата поступления на предприятие.
// !Выбор по стражу работы. Даты реализовать с помощью битового поля, должность - с помощью перечисления.

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
