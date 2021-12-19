#include <iostream>

using namespace std;

int main()
{
    int arr[10][10];
    int p = 2;
    bool u = 0;
    srand(time(0));

    for (short i = 0; i < 10; i++)
    {
        for (short j = 0; j < 10; j++)
        {
            arr[i][j] = rand() % 1;
        }
    }

    for (short i = 0; i < 10; i++)
    {
        if (!arr[p][i])
            continue;
        u = 1;
    }

    for (short i = 0; i < 10; i++)
    {
        for (short j = 0; j < 10; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << u;
}