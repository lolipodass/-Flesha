#include <iostream>
#include <iomanip>

using namespace std;
int **vvod(int **arr, short size, short size2);
void check(int **arr, short size, short size2);
void outArr(int **arr, short size, short size2);

int main()
{

    int **arr;
    int size, size2;
    cout << "razmer";
    cin >> size >> size2;
    cout << "elementi";

    arr = vvod(arr, size, size2);

    check(arr, size, size2);

    outArr(arr, size, size2);
}

void outArr(int **arr, short size, short size2)
{
    for (short i = 0; i < size; i++)
    {
        cout << "|";
        for (short j = 0; j < size2; j++)
        {
            cout << arr[i][j] << "|";
        }
        cout << endl
             << setw(10) << setfill('-') << endl;
    }
}

void check(int **arr, short size, short size2)
{
    for (short i = 0; i < size; i++)
    {
        for (short j = 0; j < size2; j++)
        {
            if (i % 2 == 0)
                continue;

            if (arr[i][j] < 0)
            {
                arr[i][j] *= -1;
            }
        }
    }
}

int **vvod(int **arr, short size, short size2)
{

    arr = new int *[size];

    for (short i = 0; i < size; i++)
    {

        arr[i] = new int[size2];

        for (short j = 0; j < size2; j++)
        {

            cin >> arr[i][j];
        }
    }

    return arr;
}