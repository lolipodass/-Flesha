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

void ReadFromFile(contract *, int);
void FullContract(contract *);
void WriteToFile(contract *);
contract *Choosing(contract *, short, short);
contract *Delete(contract *, int);
void ShowStruct(contract *, int);

int main()
{

    short size;
    cout << "Array size: ";
    cin >> size;
    contract *con = new contract[size];

    short value;

    while (1)
    {
        cout << "\n1 вручную\n2 чтение из файла\n3 запись в файл\n4 удаление записей\n5 показ структуры\n";
        cin >> value;
        if (!(value == 1 || value == 2 || value == 3 || value == 4 || value == 5 || value == 6))
        {
            break;
        }
        con = Choosing(con, value, size);
    }
}

contract *Choosing(contract *arr, short choice, short size)
{

    switch (choice)
    {
    case 1:
    {
        cout << "сколько элементов заполнить?(0=all)";
        int amount;
        cin >> amount;
        (amount > size) || (amount == 0) ? amount = size : 0;
        for (short i = 0; i < amount; i++)
        {
            FullContract(&arr[i]);
        }
    }
    break;

    case 2:
        ReadFromFile(arr, size);
        break;
    case 3:
        WriteToFile(&arr[1]);
        break;
    case 4:
        return Delete(arr, size);

        break;
    case 5:
        ShowStruct(arr, size);
        break;
    default:

        break;
    }
    return arr;
}

void ShowStruct(contract *cont, int size)
{
    cout << "size: " << size;
    for (short i = 0; i < size; i++)
    {
        cout << "\n\t\t\t"
             << i + 1 << " контракт\n";
        cout << "\tИмя\t"
             << cont[i].name;
        cout << "\n\tCтоимость\t" << cont[i].price;
        cout << "\n\tКонцерты\t" << cont[i].amount;
        cout << "\n\tОпыт\t" << cont[i].workExp;
    }
}

contract *Delete(contract *cont, int size)
{
    cout << "\n Сколько элементов удалить(0=all)\n";
    int amount = 0;
    cin >> amount;
    cout << "\n Начиная с какого элемента\n";
    int position;
    cin >> position;
    (amount > size) ? amount = size : 0;
    (position > size) ? position = size : 0;

    contract *arr = new contract[size - amount];

    for (short i = 0; i < position; i++)
    {
        arr[i] = cont[i];
    }

    for (short i = position + amount, j = position; i < size; i++, j++)
    {
        arr[j] = cont[i];
    }

    return arr;
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

void ReadFromFile(contract *cont, int size)
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

    for (short i = 0; i < size; i++)
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
    }
}

void WriteToFile(contract *con)
{
    ofstream file;
    file.open("out");
    file << "NAME:" << con->name << "PRICE:" << con->price << "AMOUNT:" << con->amount << "EXPERIENCE:" << con->workExp;
}