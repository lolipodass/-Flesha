#include <iostream>
using namespace std;

int main()
{
    int arr1[10] = {1, 2, 3, 4, 5, 6, 5, 8, 9, 10};

    int max = arr1[0];

    for (int i = 0; i < 10; i++)
    {
        if (arr1[i] > max)
        {
            max = arr1[i];
        }
    }
    max -= 1;

    for (int i = 0; i < 10; i++)
    {
        if (max == arr1[i])
        {
            max -= 1;
            i = 0;
        }
    }
    cout << max;
}