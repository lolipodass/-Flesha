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
void WriteToFile(contract *);
contract *Choosing(contract *, short);
contract *Delete(contract *);
void ShowStruct(contract *);
void SortPrice(contract *);
void SortAmount(contract *);

int main()
{

    cout << "Array size: ";
    cin >> arraySize;
    contract *con = new contract[arraySize];

    short value;

    while (1)
    {
        cout << "\n1 вручную\n2 чтение из файла\n3 запись в файл\n4 удаление записей\n5 показ структуры\n6 сортировка цене\n7 по количеству\n";
        cin >> value;
        if (!(value == 1 || value == 2 || value == 3 || value == 4 || value == 5 || value == 6 ||value==7))
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
        WriteToFile(arr);
        break;
    case 4:
        return Delete(arr);

        break;
    case 5:
        ShowStruct(arr);
        break;
    case 6:
        SortPrice(arr);
        break;
    case 7:
        SortAmount(arr);
        break;
    default:
        break;
    }
    return arr;
}

void ShowStruct(contract *cont)
{
    cout << "size: " << arraySize;
    for (short i = 0; i < arraySize; i++)
    {
        cout << "\n\t\t\t"
             << i + 1 << " контракт\n";
        cout << "\tИмя\t"
             << cont[i].name;
        cout << "\n\tСтоимость\t" << cont[i].price;
        cout << "\n\tКонцерты\t" << cont[i].amount;
        cout << "\n\tОпыт\t" << cont[i].workExp;
    }
}

contract *Delete(contract *cont)
{
    cout << "\n Сколько элементов удалить(0=all)\n";
    int amount = 0;
    cin >> amount;
    cout << "\n Начиная с какого элемента\n";
    int position;
    cin >> position;
    (amount > arraySize) ? amount = arraySize : 0;
    (position > arraySize) ? position = arraySize : 0;

    contract *arr = new contract[arraySize - amount];

    for (short i = 0; i < position; i++)
    {
        arr[i] = cont[i];
    }

    for (short i = position + amount, j = position; i < arraySize; i++, j++)
    {
        arr[j] = cont[i];
    }
    arraySize-=amount;
    delete[] cont;

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

void WriteToFile(contract *con)
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
        file << "NAME:" << con[i].name << " PRICE:" << con[i].price << " AMOUNT:" << con[i].amount << " EXPERIENCE:" << con[i].workExp<<'\n';
}

void SortPrice(contract *arrContracts)
{
    bool sorting;
    cout<<"по возрастанию(1) убыванию(0)";
    cin>>sorting;

    for(int i=0;i<arraySize;i++)
    {

        for (short j = 0; j < arraySize; j++)
        {
        if (arrContracts[i].price>arrContracts[j].price&&sorting)
            swap(arrContracts[i],arrContracts[j]); 

        if (arrContracts[i].price<arrContracts[j].price&&!sorting)
            swap(arrContracts[i],arrContracts[j]); 
        }
    }
}
void SortAmount(contract *arrContracts)
{

        bool sorting;
    cout<<"по возрастанию(1) убыванию(0)";
    cin>>sorting;

    for(int i=0;i<arraySize;i++)
    {

        for (short j = 0; j < arraySize; j++)
        {
        if (arrContracts[i].amount>arrContracts[j].amount&&sorting)
            swap(arrContracts[i],arrContracts[j]); 

        if (arrContracts[i].amount<arrContracts[j].amount&&!sorting)
            swap(arrContracts[i],arrContracts[j]); 
        }
    }
}
