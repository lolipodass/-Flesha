#include <iostream>
#include <string>
#include <windows.h>
#include <cctype>

using namespace std;

int main()
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string str;
    getline(cin, str);
    int pos;
    int fpos = 0;
    string letter;
    string nun = ". ";

    for (short i = 0; i < str.length(); i++)
    {
        pos = str.find(nun, fpos);
        pos += 2;
        fpos = pos;

        letter = toupper(str[pos]);
        // cout << letter << " " << pos << " " << fpos << endl;
        str.replace(pos, 1, letter);
    }
    cout << str;
}
