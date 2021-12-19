#include <iostream>
#include <cstring>
#include <string>
#include <conio.h>

int a = 5, b = 10;
using namespace std;

void da();

int main()
{
    da();
    cout << a << " " << b;
}

void da()
{
    int buf = a;
    a = b;
    b = buf;
}