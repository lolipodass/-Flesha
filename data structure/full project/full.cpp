#include <iostream>
#include <fstream>
#include <string>

using namespace std;

short arraySize;

struct contract
{
    string name;
    double price;
    short amount;
    short workExp;
};

void ReadFromFile(contract *);
void FullContract(contract *);
void WriteToFile(contract *, int);
contract *Choosing(contract *, short);
void ShowStruct(contract *, int);
contract *deleteElements(contract *, int, int, int);
contract *copyArray(contract *, int);

template <typename T>
bool sorting(T val1, T val2, bool sorting)
{
    if (val1 > val2 && sorting)
        return 1;
    if (val1 < val2 && !sorting)
        return 1;
    return 0;
}

int main()
{

    cout << "Array size: ";
    cin >> arraySize;
    contract *con = new contract[arraySize];

    short value;

    while (1)
    {
        cout << "\n1 вручную\n2 чтение из файла\n3 запись в файл\n4 удаление записей\n5 показ структуры\n6 сортировка\n7 фильтрация\n";
        cin >> value;
        if (!(value == 1 || value == 2 || value == 3 || value == 4 || value == 5 || value == 6 || value == 7))
        {
            break;
        }
        con = Choosing(con, value);
    }
}

contract *Choosing(contract *arr, short choice)
{

    switch (choice)
    {
    case 1:
    {
        cout << "сколько элементов заполнить?(0=all)";
        int amount;
        cin >> amount;
        (amount > arraySize) || (amount == 0) ? amount = arraySize : 0;
        for (short i = 0; i < amount; i++)
        {
            FullContract(&arr[i]);
        }
    }
    break;

    case 2:
        ReadFromFile(arr);
        break;

    case 3:
        WriteToFile(arr, arraySize);
        break;

    case 4:
    {
        cout << "\n Сколько элементов удалить(0=all)\n";
        int amount = 0;
        cin >> amount;
        cout << "\n Начиная с какого элемента\n";
        int position;
        cin >> position;
        position -= 1;
        (amount > arraySize) ? amount = arraySize : 0;
        (position > arraySize) ? position = arraySize : 0;

        return deleteElements(arr, arraySize, amount, position);
    }
    break;

    case 5:
        ShowStruct(arr, arraySize);
        break;
    case 6:
    {
        cout << "\n1 цене \n2 по количеству: ";
        int sort;
        cin >> sort;
        cout << "по возрастанию(1) убыванию(0): ";
        bool sortingMethod;
        cin >> sortingMethod;
        for (int i = 0; i < arraySize; i++)
            for (short j = 0; j < arraySize; j++)
            {
                if (sorting(arr[i].price, arr[j].price, sortingMethod) && sort)
                    swap(arr[i], arr[j]);
                if (sorting(arr[i].amount, arr[j].amount, sortingMethod) && sort == 2)
                    swap(arr[i], arr[j]);
            }
    }
    break;

    case 7:
    {
        cout << "\nВведите интересуемую строку: ";
        string index;
        cin >> index;
        contract *buffArray = copyArray(arr, arraySize);
        int buffArraySize = arraySize;

        for (int i = 0; i < buffArraySize; i++)
        {
            if (buffArray[i].name.find(index) == -1)
            {
                buffArray = deleteElements(buffArray, buffArraySize, 1, i);
                buffArraySize--;
            }
        }
        cout << "(0)записать или (1)вывести на экран отсортированный массив: ";
        bool method;
        cin >> method;
        if (method)
            ShowStruct(buffArray, buffArraySize);
        else
            WriteToFile(buffArray, buffArraySize);
        break;
    }

    default:
        break;
    }
    return arr;
}

void ShowStruct(contract *arr, int arraySize)
{
    cout << "size: " << arraySize;
    for (short i = 0; i < arraySize; i++)
    {
        cout << "\n\t\t\t"
             << i + 1 << " контракт\n";
        cout << "\tИмя\t"
             << arr[i].name;
        cout << "\n\tСтоимость\t" << arr[i].price;
        cout << "\n\tКонцерты\t" << arr[i].amount;
        cout << "\n\tОпыт\t" << arr[i].workExp;
    }
}

contract *deleteElements(contract *array, int arraySize, int amount, int position)
{
    contract *newArray = new contract[arraySize - amount];

    for (short i = 0; i < position; i++)
        newArray[i] = array[i];

    for (short i = position + amount, j = position; i < arraySize; i++, j++)
        newArray[j] = array[i];

    arraySize -= amount;
    delete[] array;

    return newArray;
}

void FullContract(contract *cont)
{
    cout << "\nИмя\n";
    cin >> cont->name;
    cout << "Стоимость\n";
    cin >> cont->price;
    cout << "Количество концертов\n";
    cin >> cont->amount;
    cout << "Опыт работы\n";
    cin >> cont->workExp;
}

void ReadFromFile(contract *cont)
{
    ifstream file;
    string line;
    string name;
    cout << "название файла: ";
    cin >> name;
    file.open(name);
    getline(file, line);

    if (!file.is_open())
    {
        cout << "wrong file";
        return;
    }

    for (short i = 0; i < arraySize; i++)
    {

        short startName = line.find("NAME:") + 5;
        short startPrice = line.find("PRICE:", startName) + 6;
        short startAmount = line.find("AMOUNT:", startPrice) + 7;
        short startExperience = line.find("EXPERIENCE:", startAmount) + 11;

        short npos = static_cast<short>(string::npos);
        if (startName == npos || startPrice == npos || startAmount == npos || startExperience == npos)
        {
            cout << "bad file\n";
            return;
        }

        cont[i].name = line.substr(startName, startPrice - startName - 7);
        cont[i].price = stoi(line.substr(startPrice, startAmount - startPrice - 7));
        cont[i].amount = stoi(line.substr(startAmount, startExperience - startAmount - 11));
        cont[i].workExp = stoi(line.substr(startExperience, line.size()));
        getline(file, line);
    }
}

void WriteToFile(contract *arr, int arraySize)
{
    ofstream file;
    string name;
    cout << "название файла: ";
    cin >> name;
    file.open(name);
    if (!file.is_open())
    {
        cout << "wrong file";
        return;
    }
    for (short i = 0; i < arraySize; i++)
        file << "NAME:" << arr[i].name << " PRICE:" << arr[i].price << " AMOUNT:" << arr[i].amount << " EXPERIENCE:" << arr[i].workExp << '\n';
}

contract *copyArray(contract *arr, int length)
{
    contract *newArray = new contract[length];
    for (int i = 0; i < length; i++)
        newArray[i] = arr[i];
    return newArray;
}