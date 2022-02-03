#include <iostream>
using namespace std;

int main()
{
    int arr1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[10] = {0, 0, 0, 0, 0, 10, 0, 0, 9, 0};

    int max = arr1[0];
    bool da = 0;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (arr1[i] == arr2[j])
            {
                da = 1;
                break;
            }
        }

        if (!da && arr1[i] > max)
        {
            max = arr1[i];
        }
        da = 0;
    }
    cout << max << endl;
}