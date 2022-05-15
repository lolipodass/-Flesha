//Вариант 9
//Ввести с клавиатуры строку символов, состоящую из слов, разделенных пробелами, и записать ее в файл.
//Прочитать из файла данные и вывести на экран порядковый номер слова минимальной длины. Посчитать количество символов в слове.
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string In(string *pIn);
string Out(string *pOut);

int main()
{
    string sOut, sIn;
    string *pOut = &sOut, *pIn = &sIn;
    cout << "Введите группы цифр, разделенные пробелом:\n";
    getline(cin, sOut);
    Out(pOut);
    In(pIn);
}

string Out(string *pOut)
{
    ofstream first("one.txt");
    first << *pOut;
    first.close();
    return *pOut;
}

string In(string *pIn)
{
    string SsIn, min = "0000000";
    int counter = 1, order;
    ifstream second("one.txt");
    while (second)
    {
        second >> SsIn;
        if (SsIn.length() < min.length())
        {
            min = SsIn;
            order = counter;
        }
        counter++;
    }

    cout << "Порядковый номер самого короткого слова: " << order << '\n';
    cout << "Количество символов в нём: " << min.length() << '\n';
    second.close();
    return SsIn;
}