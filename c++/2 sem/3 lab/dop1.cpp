#include <iostream>
#include <string>
#define records 30
#define len 30
using namespace std;

void add();
void del();
void show();
void search();

int decision;

enum origin
{
    purchase = 1,
    theft,
    gift
} orig;

struct library
{
    string author;
    string title;
    string press;
    string availability;
    origin orig;
    int year;
} Book[records], zero;

union un_library
{
    char author[len];
    char title[len];
    char press[len];
    char availability[len];
    origin orig[len];
    int year;
} un_Book;

int codow = 0;

int main()
{
    cout << "Введите:\n";
    cout << "Добавить запись - 1\n";
    cout << "Удалить запись - 2\n";
    cout << "Вывести запись - 3\n";
    cout << "Поиск по году издательства - 4\n";
    cout << "Выход - 5\n";
    cin >> decision;
    do
    {
        switch (decision)
        {
        case 1:
            add();
            break;
        case 2:
            del();
            break;
        case 3:
            show();
            break;
        case 4:
            search();
            break;
        case 5:
            return 0;
        }
    } while (true);
}

void add()
{
    int o, t;
    orig = purchase;
    if (codow < records)
    {
        cout << "Автор - ";
        cin >> un_Book.author;
        Book[codow].author = un_Book.author;
        cout << "Название - ";
        cin >> un_Book.title;
        Book[codow].title = un_Book.title;
        cout << "Издательство (special literature, hobby, novelistic, fantasy)- ";
        cin >> un_Book.press;
        Book[codow].press = un_Book.press;
        cout << "Наличие - ";
        cin >> un_Book.availability;
        Book[codow].availability = un_Book.availability;
        cout << "Происхождение (Покупка - 1, кража - 2, подарок - 3) - ";
        cin >> o;
        t = (int)orig - o;
        if (t == 0)
        {
            Book[codow].orig = purchase;
        }
        else if (t == 1)
        {
            Book[codow].orig = theft;
        }
        else
        {
            Book[codow].orig = gift;
        }
        cout << "Год издательства: ";
        cin >> un_Book.year;
        Book[codow].year = un_Book.year;

        codow++;
    }
    else
    {
        cout << "Вы ввели максимальное количество записей";
    }
    cout << "Что делать дальше?\n";
    cin >> decision;
    cout << endl;
}

void del()
{
    int purge;
    cout << "Введите номер записи, которую необходимо удалить" << endl;
    cout << "Чтобы удалить все записи, введите '101'" << endl;
    cin >> purge;
    if (purge != 101)
    {
        for (int de = (purge - 1); de < codow; de++)
            Book[de] = Book[de + 1];
        codow = codow - 1;
    }
    if (purge == 101)
        for (int i = 0; i < records; i++)
        {
            Book[i] = zero;
            codow = 0;
        }
    cout << "Что делать дальше?" << endl;
    cin >> decision;
    cout << endl;
}

void show()
{
    int choice;
    int no;
    cout << "Вывести одну запись - 1\n";
    cout << "Вывести все записи - 2\n";
    cin >> choice;
    if (choice == 1)
    {
        cout << "Введите номер записи, которую хотите вывести - ";
        cin >> no;
        cout << "\nАвтор - ";
        cout << Book[no - 1].author << endl;
        cout << "Название - ";
        cout << Book[no - 1].title << endl;
        cout << "Издательство - ";
        cout << Book[no - 1].press << endl;
        cout << "Наличие - ";
        cout << Book[no - 1].availability << endl;
        cout << "Происхождение - ";
        cout << Book[no - 1].orig << endl;
        cout << "Год издательства: ";
        cout << Book[no - 1].year << endl;
    };
    if (choice == 2)
    {
        for (int i = 0; i < codow; i++)
        {
            cout << "Автор - ";
            cout << Book[i].author << endl;
            cout << "Название - ";
            cout << Book[i].title << endl;
            cout << "Издательство - ";
            cout << Book[i].press << endl;
            cout << "Наличие - ";
            cout << Book[i].availability << endl;
            cout << "Происхождение - ";
            cout << Book[i].orig << endl;
            cout << "Год издательства: ";
            cout << Book[i].year << endl;
        }
    };
    cout << "Что делать дальше?" << endl;
    cin >> decision;
    cout << endl;
}

void search()
{
    int yo;
    cout << "Введите год, по которому следует осуществить поиск - ";
    cin >> yo;
    for (int i = 0; i < codow; i++)
    {
        if (yo == Book[i].year)
        {
            cout << "Автор - ";
            cout << Book[i].author << endl;
            cout << "Название - ";
            cout << Book[i].title << endl;
            cout << "Издательство - ";
            cout << Book[i].press << endl;
            cout << "Наличие - ";
            cout << Book[i].availability << endl;
            cout << "Происхождение - ";
            cout << Book[i].orig << endl;
            cout << "Год издательства: ";
            cout << Book[i].year << endl;
        }
    }
    cout << "Что делать дальше?" << endl;
    cin >> decision;
    cout << endl;
}