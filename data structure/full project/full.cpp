#include <iostream>
#include <fstream>
#include <string>
#include "full.h"
#include "finding.cpp"
#include "filesWork.cpp"

using namespace std;


template <typename T>
bool compare(T val1, T val2, bool sorting)
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
    size_t length;
    cin >> length;
    contract *arr = new contract[length];

    short value;

    while (1)
    {
        cout << "\n1 вручную\n2 чтение из файла\n3 запись в файл\n4 удаление записей\n5 показ структуры\n6 сортировка\n7 фильтрация\n8 поиск\n";
        cin >> value;
        if (!(value == 1 || value == 2 || value == 3 || value == 4 || value == 5 || value == 6 || value == 7||value==8||value==9))
        {
            break;
        }
        arr = Choosing(arr,length, value);
    }
}

contract *Choosing(contract *arr,size_t length, short choice)
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
            FullContract(&arr[i]);
        }
    }
    break;

    case 2:
        ReadFromFile(arr,length);
        break;

    case 3:
        WriteToFile(arr, length);
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
        (amount > length) ? amount = length : 0;
        (position > length) ? position = length : 0;

        return deleteElements(arr, length, amount, position);
    }
    break;

    case 5:
        ShowStruct(arr, length);
        break;
    case 6:
    {
        cout << "\nСтоимость (0), количеству концертов(1), опыту(2): ";
        int sort;
        string value;
        cin >> sort;
        switch (sort)
        {
        case 0:value="price";break;
        case 1:value="amount";break;
        case 2:value="workExp";break;
        default:exit(1);break;
        }
        cout << "по возрастанию(1), убыванию(0): ";
        bool sortingDirection;
        cin >> sortingDirection;
        sorting(arr,length ,value,sortingDirection);

    }
    break;

    case 7:
    {
        cout << "\nВведите интересуемую строку: ";
        string index;
        cin >> index;
        contract *buffArray = copyArray(arr, length);
        int buffArraySize = length;

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
    case 8:
        findValue(arr,length);
        break;

    default:
        break;
    }
    return arr;
}

void findValue(contract *arr,size_t length)
{
    cout << "\nСтоимость (0), количеству концертов(1), опыту(2): ";
    int sort;
    string value;
    cin >> sort;
    switch (sort)
    {case 0:value="price";break;
    case 1:value="amount";break;
    case 2:value="workExp";break;
    default: exit(1);break;}

    sorting(arr,length,value,0);
    ShowStruct(arr,length);
    cout<<"element to find: ";
    int key;
    cin>>key;
    cout<<"способ поиска: (0)интерполяционный (1) бинарный";
    bool algorthim;
    cin>>algorthim;
    int found;
    if (algorthim)
        found=binarySeacrh(arr,length,key);    
    else found=InterpolSearch(arr,length,key)+1;
    if (found==-1)
        cout<<"значение не найдено\n";
    else
    cout<<"значение: "<<found+1;
    
}

void sorting(contract* arr,size_t length , string sortingValue,bool sortingDirection)
{
    for (int i = 0; i < length; i++)
    {
        for (short j = 0; j < length; j++)
        {
            if(compare( arr[i][sortingValue],arr[j][sortingValue],sortingDirection))
                swap(arr[i], arr[j]); 
        }
    }
}

void ShowStruct(contract *arr, size_t length)
{
    cout << "size: " << length;
    cout<<"\n№\tИмя \t\tСтоимость \tКоличество\tОпыт\n";
    for (short i = 0; i < length; i++)
    {
        cout <<i + 1 <<"\t"<< arr[i].name<<"\t\t"<< arr[i].price<<"\t\t" <<arr[i].amount<<"\t\t"<<arr[i].workExp<<'\n';
    }
}

contract *deleteElements(contract *array, size_t length, int amount, int position)
{
    contract *newArray = new contract[length - amount];

    for (short i = 0; i < position; i++)
        newArray[i] = array[i];

    for (short i = position + amount, j = position; i < length; i++, j++)
        newArray[j] = array[i];

    length -= amount;
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

contract *copyArray(contract *arr, size_t length)
{
    contract *newArray = new contract[length];
    for (int i = 0; i < length; i++)
        newArray[i] = arr[i];
    return newArray;
}
