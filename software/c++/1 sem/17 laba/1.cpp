#include <iostream>

using namespace std;

int **createArr(short, short);
void fullArr(int **, short, short);
void showArr(int **, short, short);
void sum(int **, short, short, short, short);
void find(int **, short, short);

int main()
{
    cout << "vvedi razmernost";
    short sizeX, sizeY;
    cin >> sizeX >> sizeY;
    int **arr = createArr(sizeX, sizeY);
    cout << "vvedite elementi";
    fullArr(arr, sizeX, sizeY);
    showArr(arr, sizeX, sizeY);
    find(arr, sizeX, sizeY);
}

int **createArr(short sizeX, short sizeY)
{
    int **arr = new int *[sizeX];
    for (short i = 0; i < sizeX; i++)
    {
        arr[i] = new int[sizeY];
    }
    return arr;
}

void fullArr(int **arr, short sizeX, short sizeY)
{
    for (short i = 0; i < sizeX; i++)
    {
        for (short j = 0; j < sizeY; j++)
        {
            // !Вывод красивый масива когда нибуть будет😢

            cin >> arr[i][j];
        }
        cout << "next row";
    }
}

void showArr(int **arr, short sizeX, short sizeY)
{
    for (short i = 0; i < sizeX; i++)
    {
        cout << endl;

        for (short j = 0; j < sizeY; j++)
        {
            cout << arr[i][j] << "\t";
        }
    }
}

void find(int **arr, short sizeX, short sizeY)
{
    int max = arr[0][0];
    int min = arr[0][0];

    short minX = 0, minY = 0;
    short maxX = 0, maxY = 0;

    for (short i = 0; i < sizeX; i++)
    {
        for (short j = 0; j < sizeY; j++)
        {
            if (arr[i][j] > max)
            {
                max = arr[i][j];
                maxX = i;
                maxY = j;
                // cout << endl
                //  << i << " " << j;
            }
            if (arr[i][j] <= min)
            {
                min = arr[i][j];
                minX = i;
                minY = j;

                // cout << endl
                //      << i << " " << j;
            }
        }
    }

    sum(arr, minX, minY, maxX, maxY);
}

void sum(int **arr, short minX, short minY, short maxX, short maxY)
{
    cout << endl
         << minX << " " << minY << " " << maxX << " " << maxY;

    int sum = 0;
    for (short i = maxX; i < minX; i++)
    {
        for (short j = maxY; j < minY; j++)
        {
            sum += arr[i][j];
            cout << " " << arr[i][j] << " ";
        }
    }
    cout << endl
         << sum;
}
