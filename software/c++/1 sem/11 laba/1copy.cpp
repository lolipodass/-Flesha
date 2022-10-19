#include <iostream>

using namespace std;
int main()
{
    char bit[33];
    int a = 8111;
    int b = 4080;

    _itoa_s(a, bit, 2);
    cout << bit << endl;

    int kol = 11;

    int pos = 2;

    unsigned int num = ~0;
    num >>= 32 - kol;
    num <<= pos;
    a ^= num;

    _itoa_s(a, bit, 2);
    cout << bit << endl;
}
