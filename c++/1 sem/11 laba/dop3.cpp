#include <iostream>
using namespace std;
int main()
{
    int A;
    char tmp[33];
    cout << "Введите число ";
    cin >> A;
    _itoa_s(A, tmp, 2);
    cout << "Число в двоичном виде = " << tmp << endl;
    if ((A & 3) == 0)
        cout << "Число кратно 4" << endl;
    else
        cout << "Число не кратно 4" << endl;
}