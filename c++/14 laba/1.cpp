#include <iostream>

using namespace std;

int main()
{
    int arr[10][10];
    int max = arr[0][0];
    srand(time(0));

    for (short i = 0; i < 10; i++)
    {
        for (short j = 0; j < 10; j++)
        {
            arr[i][j] = rand() % 1000;
        }
    }

    for (short i = 0; i < 10; i++)
    {
        for (short j = 0; j < 10; j++)
        {
            if (arr[i][j] > max)
            {
                max = arr[i][j];
            }
        }
    }
    for (short i = 0; i < 10; i++)
    {
        for (short j = 0; j < 10; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << max;
}