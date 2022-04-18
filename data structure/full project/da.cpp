#include <iostream>

int main()
{
    const int num = 10;
    const int* p = &num;
    *p = 20;


    return 0;
}