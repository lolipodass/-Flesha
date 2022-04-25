#include <iostream>
using std::cout,std::cin;

const int N = 17;
//интерполяционный поиск
int InterpolSearch(int A[], int key)
{
    int mid, left = 0, right = N - 1;
    while (A[left] <= key && A[right] >= key)
    {
        mid = left + ((key - A[left]) * (right - left)) / (A[right] - A[left]);
        if (A[mid] < key)
            left = mid + 1;
        else if (A[mid] > key)
            right = mid - 1;
        else
            return mid;
    }
    if (A[left] == key)
        return left;
    else
        return -1;
}
//главная функция
int main()
{
    int i, key;
    int A[N] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};
    cout << "Искомый элемент > ";
    cin >> key; //ввод ключа
    cout << "Исходный массив: ";
    for (i = 0; i < N; i++)
        cout << A[i] << " "; //вывод массива
    if (InterpolSearch(A, key) == -1)
        cout << "\nЭлемент не найден";
    else
        cout << "\nНомер элемента: " << InterpolSearch(A, key) + 1;
}