#include <iostream>

using namespace std;

int main()
{
    char bit[33];
    int a = 4097;
    int b = 4080;

    _itoa_s(a, bit, 2);
    cout << "a " << bit << endl;
    _itoa_s(b, bit, 2);
    cout << "b " << bit << endl;

    int kol = 5;
    int kol2 = 5;

    int pos = 2;
    int pos2 = 4;

    unsigned int num = ~0;
    num >>= 32 - kol;
    num <<= pos;
    num &= a;
    num <<= 1;
    _itoa_s(num, bit, 2);
    cout << "num " << bit << endl;

    unsigned int buff = 3;
    buff &= b;
    b >>= 7;
    b <<= 7;

    b += num + buff;

    _itoa_s(b, bit, 2);
    cout << bit << endl;

    //! part 2

    _itoa_s(a, bit, 2);
    cout << "part two, a " << bit << endl;
    unsigned int num2 = ~0;

    num2 <<= 32 - kol2;
    num2 >>= (31 - pos2);
    a |= num2;
    _itoa_s(a, bit, 2);
    cout << "a " << bit << endl;
    _itoa_s(num2, bit, 2);
    cout << "num " << bit << endl;
}