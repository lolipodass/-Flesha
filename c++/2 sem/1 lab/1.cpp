#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream input;
    input.open("gog");
    ofstream output;
    output.open("output.txt");
    string str;

    bool i = 0;
    do
    {
        input >> str;
        i = !i;
        if (i)
            output << str << '\n';
    } while (!input.eof());

    input.close();
    input.open("input.txt", ios_base::trunc);
    cout << input.tellg();
}

// !1. Скопировать в файл FILE2 только четные строки из FILE1. Подсчитать размер файлов FILE1 и FILE2 (в байтах).

// !2. Ввести с клавиатуры строку символов, состоящую из цифр и слов, разделенных пробелами, и записать ее в файл.
// !Прочитать из файла данные и вывести нечетные числа строки.
