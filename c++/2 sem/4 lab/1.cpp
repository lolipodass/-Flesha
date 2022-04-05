// !Создать список, содержащий элементы целого типа. Найти сумму положительных элементов
// !или выдать сообщение, что положительных элементов нет.

#include <iostream>
#include <fstream>

using namespace std;

struct listing
{
    int value;
    listing *next;
};

void insert(listing *&p, int value); //Добавление символа в начало списка
void printList(listing *p);          //Вывод списка
void toFile(listing *p);             //Запись в файл
void fromFile(listing *p);           //Считывание из файла
int menu();                          //Вывод меню
void sum(listing *p);

int main()
{
    listing *first = nullptr;
    int choice = menu();

    // cout << choice;

    int value;

    while (choice != 6)
    {
        switch (choice)
        {
        case 1:
            cout << "Введите число ";
            cin >> value;
            insert(first, value);
            printList(first);
            break;
        case 2:
            toFile(first);
            break;
        case 3:
            fromFile(first);
            break;
        case 4:
            printList(first);
            break;
        case 5:
            sum(first);
        default:
            break;
        }
        choice = menu();
    }
    return 0;
}

void insert(listing *&p, int value) //Добавление символа в начало списка
{
    listing *newP = new listing;
    if (newP != NULL) //есть ли место?
    {
        newP->value = value;
        newP->next = p;
        p = newP;
    }
    else
        cout << "Операция добавления не выполнена" << endl;
}

void printList(listing *p) //Вывод списка
{
    if (p == NULL)
        cout << "Список пуст" << endl;
    else
    {
        cout << "Список:" << endl;
        while (p != NULL)
        {
            cout << "-->" << p->value;
            p = p->next;
        }
        cout << "-->NULL" << endl;
    }
}

void toFile(listing *p)
{
    listing *temp = p;
    listing buf;
    ofstream frm("mList.dat");
    if (frm.fail())
    {
        cout << "\n Ошибка открытия файла";
        exit(1);
    }
    while (temp)
    {
        buf = *temp;
        frm.write((char *)&buf, sizeof(listing));
        temp = temp->next;
    }
    frm.close();
    cout << "Список записан в файл mList.dat\n";
}

void fromFile(listing *p) //Считывание из файла
{
    listing buf, *first = nullptr;
    ifstream frm("mList.dat");
    if (frm.fail())
    {
        cout << "\n Ошибка открытия файла";
        exit(1);
    }
    frm.read((char *)&buf, sizeof(listing));
    while (!frm.eof())
    {
        insert(first, buf.value);
        cout << "-->" << buf.value;
        frm.read((char *)&buf, sizeof(listing));
    }
    cout << "-->NULL" << endl;
    frm.close();
    p = first;
    cout << "\nСписок считан из файла mList.dat\n";
}

int menu() //Вывод меню
{
    cout << "Сделайте выбор:" << endl;
    cout << " 1 - Ввод числа" << endl;
    cout << " 2 - Запись списка в файл" << endl;
    cout << " 3 - Чтение списка из файла" << endl;
    cout << " 4 - Показ списка" << endl;
    cout << " 5 - Сумма" << endl;
    cout << " 6 - Выход" << endl;
    int val;
    cin >> val;
    return val;
}

void sum(listing *p)
{
    int sum = 0;
    if (p == NULL)
        cout << "Список пуст" << endl;
    else
    {
        while (p != NULL)
        {
            sum += p->value;
            p = p->next;
        }
    }
    cout << sum << "\n";
}