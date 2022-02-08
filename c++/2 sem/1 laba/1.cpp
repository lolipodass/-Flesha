//*4. В соответствии со своим вариантом разработать программу для данных, приведенных в таблице ниже.  Определить структурированный тип, разработать меню для работы с массивом структур.
//! В программу должны войти функции:
// 	TODO ввод элементов структуры с клавиатуры;
// 	TODO вывод элементов структуры в консольное окно;
// 	TODO удаление заданной структурированной переменной;
// 	TODO поиск информации;
// 	TODO запись информации в файл;
// 	TODO чтение данных из файла.
// !Горожанин. Ф.И.О., дата рождения, адрес, пол (м, ж). Реализовать выборку по году рождения.



#include <iostream>
#include <string>
#include <locale>
#include <windows.h>

using namespace std;

struct citizen
{
    string name;
    unsigned int age;
    string address; 
    bool sex;
};

void structWrite(citizen*);
void structRead(citizen*);


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    citizen *test=new citizen;
    structWrite(test);
    structRead(test);
    
}

void structWrite(citizen *cit)
{
    cout<<"Full name\n";
    getline(cin,cit->name);
    cout<<"Age\n";
    cin>>cit->age;
    cout<<"address\n";
    getline(cin,cit->address);
    cout<<"sex\n";
    cin>>cit->sex;
}

void structRead(citizen *cit)
{
    cout<<"Full name: "<<cit->name<<",Age: "<<cit->age<<", address: "<<cit->address<<", sex: "<<cit->sex<<"\n";
}