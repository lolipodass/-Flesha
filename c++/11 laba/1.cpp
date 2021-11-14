#include <iostream>

using namespace std;
int main()
{
    int sum = 0;
    int g = 4097;
    int b = g & 1;

    g = g >> 4;

    char bit[33];
    _itoa_s(g, bit, 2);
    cout << bit << endl;

    for (int i = 0; i < 9; i++)
    {
        b = g & 1;
        if (b == 0)
        {
            sum++;
        }
        g = g >> 1;
    }
    cout << sum << endl;

    _itoa_s(g, bit, 2);
    cout << bit << endl;
}
