#include <iostream>

using namespace std;

int main()
{
    char xux[] = "zopa";
    char yuy[] = "vstavka";
    short kol = 7;
    short pos = 1;
    int len = sizeof(xux) / sizeof(*xux) - 1;
    char ans[len + kol];

    for (short i = 0; i < pos; i++)
    {
        ans[i] = xux[i];
    }

    for (short i = pos; i < kol + pos; i++)
    {
        ans[i] = yuy[i - pos];
    }

    for (short i = 0; i < kol + pos; i++)
    {
        cout << ans[i];
    }
}
