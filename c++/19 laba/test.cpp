#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin;
    fin.open("1.txt");
    int a;
    fin >> a;
    cout << a;
    fin >> a;
    cout << a;
    fin >> a;
    cout << a;
    fin >> a;
    cout << a;
}