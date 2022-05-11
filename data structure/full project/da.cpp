#include <iostream>
#include <string>
using std::cout, std::cin;

enum Type
{
    VERB,
    NOUN,
    PRONOUN,
    ADJECTIVE,
    ADVERB,
    PREPOSITION,
    CONJUNCTION,
    INTERJECTION
};

struct word
{
    std::string wordRus;
    std::string wordEng;
    Type Type;
};

word *Choosing(word *arr, size_t length, short choice);

int main()
{

    cout << "Array size: ";
    size_t length;
    cin >> length;
    word *arr = new word[length];

    int value;
    while (1)
    {
        cout << "\n1 вручную\n2 чтение из файла\n3 запись в файл\n4 удаление записей\n5 показ структуры\n6 сортировка\n7 фильтрация\n8 поиск\n";
        cin >> value;
        if (!(value == 1 || value == 2 || value == 3 || value == 4 || value == 5 || value == 6 || value == 7 || value == 8 || value == 9))
        {
            break;
        }
        arr = Choosing(arr, length, value);
    }
}

word *Choosing(word *arr, size_t length, short choice)
{

    switch (choice)
    {
    case 1:
    {
    }
    break;

    case 2:
        break;

    case 3:
        break;

    case 4:
        break;

    case 5:
        break;
    case 6:
        break;

    case 7:
        break;
    case 8:
        break;

    default:
        break;
    }
    return arr;
}
