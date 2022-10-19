#include <ctime>
#include <stdlib.h>
#include <iostream>
using namespace std;
int *sort1(int array[], int length)
{
    for (short i = 0; i < length; i++)
    {
        for (short j = 1; j < length; j++)
        {
            if (array[i] > array[j])
            {
                swap(array[i], array[j]);
            }
        }
    }
    return array;
}
//------------------------------
int getHoarBorder(int A[], int sm, int em)
{
    int i = sm - 1, j = em + 1;
    int brd = A[sm];
    int buf;
    while (i < j)
    {
        while (A[--j] > brd)
            ;
        while (A[++i] < brd)
            ;
        if (i < j)
            swap(A[j], A[i]);
    }
    return j;
}
int *sortHoar(int A[], int sm, int em)
{
    if (sm < em)
    {
        int hb = getHoarBorder(A, sm, em);
        sortHoar(A, sm, hb);
        sortHoar(A, hb + 1, em);
    }
    return A;
};
//------------------------------
int *countSort(int in[], int out[], int size)
{
    int i, j, count;
    for (i = 0; i < size; ++i)
    {
        for (count = 0, j = 0; j < size; ++j)
            if (in[j] < in[i] || (in[j] == in[i] && i < j))
                count++;
        out[count] = in[i];
    }
    return out;
}

//------------------------------
int getRandKey(int reg = 0) // генерация случайных ключей
{
    if (reg > 0)
        srand((unsigned)time(NULL));
    int rmin = 0;
    int rmax = 100000;
    return (int)(((double)rand() / (double)RAND_MAX) * (rmax - rmin) + rmin);
}
//------------------------------
int main()
{
    const int N = 25000;
    int k[N], f[N];
    clock_t t1, t2;
    getRandKey(1);
    for (int i = 0; i < N; i++)
        f[i] = getRandKey(0);

    for (int n = 5000; n <= N; n += 5000)
    {
        cout << "n = " << n << endl;
        cout << "Пузырек \t";
        memcpy(k, f, n * sizeof(int));
        t1 = clock();
        sort1(k, n);
        t2 = clock();
        cout << "Прошло " << t2 - t1 << " тактов времени\n";

        cout << "Хоар \t";
        memcpy(k, f, n * sizeof(int));
        t1 = clock();
        sortHoar(k, 0, n);
        t2 = clock();
        cout << "Прошло " << t2 - t1 << " тактов времени\n";

        cout << "подсчет сортировка \t";
        memcpy(k, f, n * sizeof(int));
        t1 = clock();
        countSort(k, k, n);
        t2 = clock();
        cout << "Прошло " << t2 - t1 << " тактов времени\n";
    }
    return 0;
}
