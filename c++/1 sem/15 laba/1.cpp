#include <iostream>

using namespace std;

int main()
{
    int kol;
    bool znak = 0;
    short kolMInus = 0;
    double min = 100;
    short index = 0;
    double sum = 1;

    cout << "vvedi razmer ";
    cin >> kol;
    double arr[kol];

    for (short i = 0; i < kol; i++)
    {
        arr[i] = rand();
        arr[i] /= 1000;
        znak = rand() % 2;

        if (arr[i] < min)
        {
            index = i;
            min = arr[i];
        }

        arr[i] *= znak ? 1 : -1;

        if (znak)
        {
            kolMInus++;
        }
    }

    for (short i = index + 1; i < kol; i++)
    {
        sum *= arr[i];
    }

    for (short i = 0; i < kol; i++)
    {
        cout << arr[i] << " ";
    }

    sum = abs(sum);
    cout << endl
         << min << " " << sum;
}