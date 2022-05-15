//Вариант 3
//Скопировать из файла FILE1 в файл FILE2 строки, начиная с к до к+3. Подсчитать количество гласных букв в FILE2.
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    int k, num = 0, counter = 0;
    cout << "Введите, с какой строки копировать:\n";
    cin >> k;
    int k1 = k + 3;
    string str;
    ifstream a("a.txt");
    ofstream b("b.txt");
    k--;
    k1--;
    int size;
    while (getline(a, str))
    {
        if (num >= k && num <= k1)
        {
            b << str << '\n';
            size = str.size();
            for (int j = 0; j < size; j++)
            {
                if (str[j] == 'a' || str[j] == 'A' || str[j] == 'o' || str[j] == 'O' || str[j] == 'e' || str[j] == 'E' || str[j] == 'y' || str[j] == 'Y' || str[j] == 'u' || str[j] == 'U' || str[j] == 'i' || str[j] == 'I')
                    counter++;
            }
        }
        num++;
    }
    cout << "В строках с k до k+3 содержится " << counter << " гласных букв.\n";
}