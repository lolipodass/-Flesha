#include <iostream>
using namespace std;

int main()
{
    int arr1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[10] = {0, 0, 0, 0, 0, 10, 0, 0, 9, 0};
    int arrSum[10];

    bool da = 0;

    for (int i = 0; i < 10; i++)
    {
        arrSum[i] = arr1[i] + arr2[i];
    }

    for (int i = 0; i < 10; i++)
    {
        cout << arrSum[i] << " ";
    }
}