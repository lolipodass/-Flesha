#include <iostream>
#include <bitset>
#include <string>

using namespace std;

struct bitfield
{
    unsigned int 
};


struct account
{
    string name;
    string spec;
    int division;
    int position;
    bitset<int> date;
};

int main()
{
    bitset<4> jopa;
}

// *Отдел кадров.
//! Ф.И.О. работника, образование, специальность, подразделение, должность, оклад, дата поступления на предприятие.
// !Выбор по стражу работы. Даты реализовать с помощью битового поля, должность - с помощью перечисления.