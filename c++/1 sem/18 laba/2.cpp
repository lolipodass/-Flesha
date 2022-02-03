#include <iostream>

using namespace std;

int min(int, ...);

int main()
{
    int a = min(10, 1, 2, 4, 4, 56, 67, 7, 8, -1, 1);
    cout << a;
}

int min(int kol, ...)
{
    int *pos = &kol;
    int min = *(pos);

    cout << min;
    for (short i = 1; i < kol; i++)
    {
        if (min > *(++pos))
        {
            min = *pos;
        }
    }
    return min;
}
