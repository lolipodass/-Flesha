#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ofstream output;
    output.open("gog");
    cout << "Введите текст;\n";
    string str;
    getline(cin, str);
    output << str;
}