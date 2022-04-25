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


void ReadFromFile(contract *,size_t);
void FullContract(contract *);
void WriteToFile(contract *, size_t);
contract *Choosing(contract *,size_t, short);
void ShowStruct(contract *, size_t);
contract *deleteElements(contract *, size_t, int, int);
contract *copyArray(contract *, size_t);
void sorting(contract*,size_t, int ,bool );
void findValue(contract *,size_t);
int InterpolSearch(contract *,size_t,int);
int binarySeacrh(contract *, size_t, int);

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
        if (!(value == 1 || value == 2 || value == 3 || value == 4 || value == 5 || value == 6 || value == 7||value==8))
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
        cin >> sort;
        cout << "по возрастанию(1), убыванию(0): ";
        bool sortingDirection;
        cin >> sortingDirection;
        sorting(arr,length ,sort,sortingDirection);

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
    sorting(arr,length,2,0);
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
    cout<<"значение: "<<found;
    
}

int InterpolSearch(contract *arr,size_t length,int key)
{
    int mid, left=0,right=length-1;
    while (arr[left].amount<=key&&arr[right].amount>=key)
    {

        mid=left+((key-arr[left].amount)*(right-left))/(arr[right].amount-arr[left].amount);
        if (arr[mid].amount<key)
            left=mid+1;
            else if(arr[mid].amount>key)
            right=mid-1;
            else
            return mid;
    }
    if(arr[left].amount==key)
    return left;
    else return -1;
}

int binarySeacrh(contract *arr, size_t length, int key)
{
    bool flag = false;
    int left = 0, right = length - 1, mid;
    while ((left <= right) && (flag != true))
    {
        mid = (left + right) / 2;
        if (arr[mid].amount == key)
            flag = true;
        arr[mid].amount > key ? right = mid - 1 : left = mid + 1;
    }

    return (flag ? mid : -1);
}

void sorting(contract* arr,size_t length , int sortingValue,bool sortingDirection)
{
    for (int i = 0; i < length; i++)
    {
        for (short j = 0; j < length; j++)
        {
            if (!sortingValue && compare(arr[i].price, arr[j].price, sortingDirection))
                swap(arr[i], arr[j]);
            else if (sortingValue && compare(arr[i].amount, arr[j].amount, sortingDirection) )
                swap(arr[i], arr[j]);
            else if (!sortingValue==2 && compare(arr[i].workExp, arr[j].workExp, sortingDirection) )
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

void ReadFromFile(contract *cont,size_t length)
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

    for (short i = 0; i < length; i++)
    {
        int startName = line.find("NAME:") + 5;
        int startPrice = line.find("PRICE:", startName) + 6;
        int startAmount = line.find("AMOUNT:", startPrice) + 7;
        int startExperience = line.find("EXPERIENCE:", startAmount) + 11;

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

void WriteToFile(contract *arr, size_t length)
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
    for (short i = 0; i < length; i++)
        file << "NAME:" << arr[i].name << " PRICE:" << arr[i].price << " AMOUNT:" << arr[i].amount << " EXPERIENCE:" << arr[i].workExp << '\n';
}

contract *copyArray(contract *arr, size_t length)
{
    contract *newArray = new contract[length];
    for (int i = 0; i < length; i++)
        newArray[i] = arr[i];
    return newArray;
}

