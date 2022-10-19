#include <iostream>
#include <string>
#include <fstream>
using std::cout, std::cin;

enum Type
{
    VERB = 1,
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
    int lengthRus;
    int lengthEng;
    Type Type;
};

word *Choosing(word *, size_t, short);
void fullElement(word *);
void ShowStruct(word *, size_t);
void WriteToFile(word *, size_t);
void ReadFromFile(word *, size_t);
void CalculateLength(word *, size_t);
word *deleteElements(word *, size_t, int, int);

int main()
{

    cout << "Array size: ";
    size_t length;
    cin >> length;
    word *arr = new word[length];

    int value;
    while (1)
    {
        cout << "\n1 запись в структуру\n2 показ структуры\n3 чтение из файла\n4 запись в файл\n5 удаление записей\n6 сортировка\n7 фильтрация\n8 поиск\n";
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
        cout << "сколько элементов заполнить?(0=all)";
        int amount;
        cin >> amount;
        (amount > length) || (amount == 0) ? amount = length : 0;
        for (short i = 0; i < amount; i++)
        {
            fullElement(&arr[i]);
        }
        CalculateLength(arr, length);
    }
    break;

    case 2:
        ShowStruct(arr, length);
        break;

    case 3:
        ReadFromFile(arr, length);
        CalculateLength(arr, length);
        break;

    case 4:
        WriteToFile(arr, length);
        break;

    case 5:
    {
        cout << "\n Сколько элементов удалить(0=all)\n";
        int amount = 0;
        cin >> amount;
        cout << "\n Начиная с какого элемента\n";
        int position;
        cin >> position;
        position -= 1;
        (amount > length) ? amount = length : 0;
        (position > length) ? position = length : 0;

        return deleteElements(arr, length, amount, position);
    }
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

void fullElement(word *elem)
{
    cout << "\nНазвание на английском\n";
    cin >> elem->wordEng;
    cout << "Название на русском\n";
    cin >> elem->wordRus;
    cout << "тип: \n(1)глагол\n(2)существительное\n(3) местоимение\n(4) прилагательное\n(5) наречие\n(6) предлог \n(7) союз \n(8) междометие \n";
    int type;
    cin >> type;
    elem->Type = (Type)type;
}

void ShowStruct(word *arr, size_t length)
{
    cout << "size: " << length;
    cout << "\n№\tНа английском\t\tдлина \t\tНа русском\tдлина \tтип\n";
    for (short i = 0; i < length; i++)
    {
        cout << i + 1 << "\t" << arr[i].wordEng << "\t\t" << arr[i].lengthEng << "\t\t" << arr[i].wordRus << "\t\t" << arr[i].lengthRus << "\t";
        std::string type;
        switch (arr[i].Type)
        {
        case 1:
            type = "глагол";
            break;
        case 2:
            type = "существительное";
            break;
        case 3:
            type = "местоимение";
            break;
        case 4:
            type = "прилагательное";
            break;
        case 5:
            type = "наречие";
        case 6:
            type = "предлог";
            break;
        case 7:
            type = "союз";
            break;
        case 8:
            type = "междометие";
            break;
        default:
            type = "NaN";
            break;
        }
        cout << type << "\n";
    }
    cout << "\n\n";
}

void ReadFromFile(word *arr, size_t length)
{
    std::ifstream file;
    std::string line;
    std::string name;
    cout << "название файла: ";
    cin >> name;
    file.open(name);
    getline(file, line);

    if (!file.is_open())
    {
        cout << "wrong file";
        return;
    }

    for (short i = 0; i < length; i++)
    {
        int startENG = line.find("ENG:") + 4;
        int startRUS = line.find("RUS:", startENG) + 4;
        int startTYPE = line.find("TYPE:", startRUS) + 5;

        short npos = static_cast<short>(std::string::npos);
        if (startENG == npos || startRUS == npos || startTYPE == npos)
        {
            cout << "bad file\n";
            return;
        }

        arr[i].wordEng = line.substr(startENG, startRUS - startENG - 4);
        arr[i].wordRus = line.substr(startRUS, startTYPE - startRUS - 5);
        arr[i].Type = (Type)stoi(line.substr(startTYPE, line.size()));
        getline(file, line);
    }
}

void WriteToFile(word *arr, size_t length)
{
    std::ofstream file;
    std::string name;
    cout << "название файла: ";
    cin >> name;
    file.open(name);
    if (!file.is_open())
    {
        cout << "wrong file";
        return;
    }
    for (short i = 0; i < length; i++)
        file << "ENG:" << arr[i].wordEng << " RUS:" << arr[i].wordRus << " TYPE:" << arr[i].Type << '\n';
}

word *deleteElements(word *array, size_t length, int amount, int position)
{
    word *newArray = new word[length - amount];

    for (short i = 0; i < position; i++)
        newArray[i] = array[i];

    for (short i = position + amount, j = position; i < length; i++, j++)
        newArray[j] = array[i];

    length -= amount;
    delete[] array;

    return newArray;
}

void CalculateLength(word *arr, size_t length)
{
    for (size_t i = 0; i < length; i++)
    {
        arr[i].lengthEng = arr[i].wordEng.length();
        arr[i].lengthRus = arr[i].wordRus.length();
    }
}