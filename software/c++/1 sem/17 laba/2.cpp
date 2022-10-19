#include <iostream>

using namespace std;

int main()
{
    int place = 0;
    int place2 = 0;
    int size;
    int sum = 0;
    cin >> size;
    int *arr = new int[size];
    int min = 10000;
    int max = -1000;

    for (short i = 0; i < size; i++)
    {
        cin >> arr[i];
        if (max < arr[i])
        {
            max = arr[i];
            place2 = i;
        }
        if (min >= arr[i])
        {
            min = arr[i];
            place = i;
        }
    }
    cout << place2 << " " << place << endl;
    for (short i = place2 + 1; i < place; i++)
    {
        sum += arr[i];
    }

    cout << sum;
}