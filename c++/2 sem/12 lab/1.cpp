#include <iostream>

using namespace std;

void show(int *arr)
{
    for (short i = 0; i < 7; i++)
    {
        cout << arr[i] << " ";
    }
    cout << '\n';
}

void selectSort(int A[], int size)
{
    int k, i, j;
    for (i = 0; i < size - 1; i++)
    {
        for (j = i + 1, k = i; j < size; j++)
            if (A[j] < A[k])
                k = j;
        int c = A[k];
        A[k] = A[i];
        A[i] = c;
    }
}

int main()
{
    int array[] = {1, 4, 6, 9, 11, 12, 54, 14, 62, 152, 15, 7, 10, 8};
    int arrayBuf[7];
    for (int i = 0, buff = 0; i < 14; i++)
    {
        if (i % 2 == 0)
        {
            arrayBuf[buff] = array[i];
            buff++;
        }
    }

    show(arrayBuf);

    for (short i = 0; i < 7; i++)
    {
        for (short j = 0; j < 7; j++)
        {
            if (arrayBuf[i] > arrayBuf[j])
            {
                swap(arrayBuf[i], arrayBuf[j]);
            }
        }
    }
    show(arrayBuf);
    selectSort(arrayBuf, 7);
    show(arrayBuf);
}
