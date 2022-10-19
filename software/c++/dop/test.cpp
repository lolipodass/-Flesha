#include <iostream>
#include <cstring>
#include <string>
#include <conio.h>

int a = 5, b = 10;
using namespace std;

void da(int);
void da(int &);

int main()
{
    da(1);
}

void da(int b)
{
    cout << "1";
}
void da(int &b)
{
    cout << "2";
}