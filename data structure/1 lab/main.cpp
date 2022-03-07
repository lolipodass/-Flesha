#include <iostream>
#include <vector>

using std::cout, std::cin, std::vector;
int main()
{
    cout << "введите количество элементов: ";
    short kol;
    cin >> kol;
    vector<int> arr;
    for (short i = 1; i <= kol; i++)
    {
        cout << "введите " << i << " элемент: ";
        int num;
        cin >> num;
        arr.push_back(num);
    }

    long sum = 0;
    for (short i = 0; i < kol; i++)
    {
        sum += arr[i];
    }

    cout << "сумма всех элементов " << sum;
}
