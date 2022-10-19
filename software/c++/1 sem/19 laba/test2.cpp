#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    FILE *first = fopen("1.txt", "r");

    double buff;

    fscanf_s(first, "%c", buff);
    cout << buff;
}