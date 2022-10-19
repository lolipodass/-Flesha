#include <iostream>
using namespace std;

int main()
{
    int arr1[10] = {1, 6, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[10] = {0, 0, 0, 0, 0, 10, 0, 0, 9, 0};

    int kol1 = 0;
    int kol2 = 0;
    int t = 5;

    for (int i = 0; i < 10; i++)
    {
        if (arr1[i] < t)
        {
            kol1++;
        }
        if (arr2[i] < t)
        {
            kol2++;
        }
    }
    int b = kol1 < kol2 ? kol1 : kol2;
    cout << b << endl;
}