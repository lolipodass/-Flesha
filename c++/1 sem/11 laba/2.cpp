#include <iostream>

using namespace std;

int main()
{
    char bit[33];
    int a = 8111;
    int b = 4080;

    _itoa_s(a, bit, 2);
    cout << bit << endl;

    int kol = 5;
    int kol2 = 5;

    int pos = 4;
    int pos2 = 4;

    unsigned int num = ~0;
    num >>= 32 - kol;
    num <<= pos;
    a ^= num;

    _itoa_s(a, bit, 2);
    cout << bit << endl
         << "b" << endl;

    //! part 2
    unsigned int num2 = a;
    _itoa_s(b, bit, 2);
    cout << bit << endl;

    num2 >>= pos2;
    num2 <<= pos2;

    num2 <<= 32 - (kol2 + pos2);
    num2 >>= 32 - (kol2 + pos2);

    unsigned int buff = b;
    buff <<= 32 - pos2;
    buff >>= 32 - pos2;
    b >>= pos2 + kol2;
    b <<= pos2 + kol2;
    b += num2 + buff;
    _itoa_s(b, bit, 2);
    cout << bit << endl;
}