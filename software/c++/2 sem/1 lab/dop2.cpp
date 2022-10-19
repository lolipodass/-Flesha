//Вариант 6
//Ввести с клавиатуры строку символов, состоящую из групп цифр и нулей, и записать ее в файл.
//Прочитать из файла данные и вывести на экран группы с четным количеством символов.
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string Out(string *pOut)
{
    ofstream first("first.txt");
    first << *pOut;
    first.close();
    return *pOut;
}

string In(string *pIn)
{
    string ssIn;
    ifstream second("first.txt");
    while (second)
    {
        second >> ssIn;
        if (ssIn.length() % 2 == 0)
            cout << ssIn << '\n';
    }
    second.close();
    return ssIn;
}

int main()
{
    string sOut, sIn;
    string *pOut = &sOut, *pIn = &sIn;
    cout << "Введите группы цифр, разделенные пробелом:\n";
    getline(cin, sOut);
    Out(pOut);
    In(pIn);
}