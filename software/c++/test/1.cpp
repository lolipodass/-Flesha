#include <iostream>
#include <stdio.h>
#include <iomanip>
using namespace std;

int sum(int a, int b)
{
    return a + b;
}

int main()
{
    int a{5};
    int b = {6}, d{10};
    int c = {b};
    b = 10;

    // Output even and odd numbers.
    for (int i{}, j{1}; i < 51; i += 2, j += 2)
    {
        cout << setw(10) << i << " ..... " << j << endl;
    }
}