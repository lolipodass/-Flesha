#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    int *a = new int;
    delete a;
    int arr[5][5];
    int p = 2;
    bool u = 0;
    short index = 0;

    srand(2);

    for (short i = 0; i < 5; i++)
    {
        for (short j = 0; j < 5; j++)
        {
            arr[i][j] = rand() % 9 - 1;
            cout << arr[i][j] << "   ";
        }
        cout << endl;
    }

    for (short i = 0; i < 5; i++)
    {
        for (short j = 0; j < 5; j++)
        {
            if (arr[i][j] < 0)
            {
                u = 1;
            }
        }

        if (!u)
        {
            index = i - 1;
            break;
        }
        u = 0;
    }
    cout << index << endl;

    if (index = 0)
    {
        cout << "nety";
        abort();
    }

    //!работает

    for (short i = 0; i < 5; i++)
    {
        arr[i][index] *= -1;
    }

    for (short i = 0; i < 5; i++)
    {
        for (short j = 0; j < 5; j++)
        {
            cout << arr[i][j] << "     ";
        }
        cout << endl;
    }
}