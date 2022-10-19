#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct contract
{
    string name;
    double price;
    short amount;
    short workExp;
};

struct Array
{
    contract *arr;
    int length;
};

void ReadFromFile(Array *);
void FullContract(contract *);
void WriteToFile(contract *);
Array *Choosing(Array *, short);
Array *Delete(Array *);
void ShowStruct(Array *);

int main()
{

    short size;
    cout << "Array size: ";
    cin >> size;
    Array *array = new Array[size];
    array->length = size;
    // contract *con = new contract[size];

    short value;

    while (1)
    {
        cout << "\n1 вручную\n2 чтение из файла\n3 запись в файл\n4 удаление записей\n5 показ структуры\n";
        cin >> value;
        if (!(value == 1 || value == 2 || value == 3 || value == 4 || value == 5 || value == 6))
        {
            break;
        }
        array = Choosing(array, value);
    }
}

Array *Choosing(Array *fullArray, short choice)
{

    switch (choice)
    {
    case 1:
    {
        cout << "сколько элементов заполнить?(0=all)";
        int amount;
        cin >> amount;
        (amount > fullArray->length) || (amount == 0) ? amount = fullArray->length : 0;
        for (short i = 0; i < amount; i++)
        {
            FullContract(&(fullArray->arr[i]));
        }
    }
    break;

    case 2:
        ReadFromFile(fullArray);
        break;
    case 3:
        cout << "сколько элементов записать?(0=all)";
        int amount;
        cin >> amount;
        (amount > fullArray->length) || (amount == 0) ? amount = fullArray->length : 0;
        for (int i = 0; i < amount; i++)
        {
            WriteToFile(&(fullArray->arr[i]));
        }
        break;
    case 4:
        return Delete(fullArray);

        break;
    case 5:
        ShowStruct(fullArray);
        break;
    default:

        break;
    }
    return fullArray;
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

void ReadFromFile(Array *array)
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

    for (short i = 0; i < array->length; i++)
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

        contract *buf = array->arr;
        buf[i].name = line.substr(startName, startPrice - startName - 7);
        cout << "japan";
        buf[i].price = stoi(line.substr(startPrice, startAmount - startPrice - 7));
        buf[i].amount = stoi(line.substr(startAmount, startExperience - startAmount - 11));
        buf[i].workExp = stoi(line.substr(startExperience, line.size()));
        getline(file, line);
    }
}

void WriteToFile(contract *con)
{
    ofstream file;
    file.open("out");
    file << "NAME:" << con->name << "PRICE:" << con->price << "AMOUNT:" << con->amount << "EXPERIENCE:" << con->workExp << '\n';
}

Array *Delete(Array *arr)
{
    cout << "\n Сколько элементов удалить(0=all)\n";
    int amount = 0;
    cin >> amount;
    cout << "\n Начиная с какого элемента\n";
    int position;
    cin >> position;
    (amount > arr->length) ? amount = arr->length : 0;
    (position > arr->length) ? position = arr->length : 0;

    contract *arrNew = new contract[(arr->length) - amount];

    for (short i = 0; i < position; i++)
    {
        arrNew[i] = arr->arr[i];
    }

    for (short i = position + amount, j = position; i < arr->length; i++, j++)
    {
        arrNew[j] = arr->arr[i];
    }

    Array *FIN;
    FIN->arr = arrNew;
    FIN->length = arr->length - amount;
    return FIN;
}

void ShowStruct(Array *arr)
{
    cout << "size: " << arr->length;
    for (short i = 0; i < arr->length; i++)
    {

        cout << "\n\t\t\t"
             << i + 1 << " контракт\n";
        cout << "\tИмя\t"
             << arr->arr[i].name;
        cout << "\n\tCтоимость\t" << arr->arr[i].price;
        cout << "\n\tКонцерты\t" << arr->arr[i].amount;
        cout << "\n\tОпыт\t" << arr->arr[i].workExp;
    }
}
