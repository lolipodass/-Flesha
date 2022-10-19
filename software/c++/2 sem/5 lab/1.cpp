#include <iostream>
#include <fstream>

using namespace std;

struct Stack
{
    char data;   //информационный элемент
    Stack *next; //указатель на следующий элемент
};

void show(Stack *&myStk);
int pop(Stack *&myStk);
void push(int x, Stack *&myStk);
void toFile(Stack *&myStk);
void fromFile(Stack *&myStk);
void sort(Stack *&myStk);

int main()
{
    int choice;
    int x;
    Stack *myStk = new Stack; //выделение памяти для стека
    myStk = NULL;             //инициализация первого элемента
    while (true)
    {
        cout << "Выберите команду:" << endl;
        cout << "1 - Добавление элемента в стек" << endl;
        cout << "2 - Извлечение элемента из стека" << endl;
        cout << "3 - Запись в файл" << endl;
        cout << "4 - Чтение из файла" << endl;
        cout << "5 - Вывод стека с очисткой" << endl;
        cout << "6 - сортировка" << endl;
        cout << "7 - Выход" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Введите элемент: " << endl;
            cin >> x;
            push(x, myStk);
            break;
        case 2:
            x = pop(myStk);
            if (x != -1)
                cout << "Извлеченный элемент: " << x << endl;
            break;
        case 3:
            toFile(myStk);
            break;
        case 4:
            fromFile(myStk);
            break;
        case 5:
            cout << "Весь стек: " << endl;
            show(myStk);
            break;
        case 6:
            sort(myStk);
            break;
        case 7:
            return 0;
            break;
        }
    }
    return 0;
}

void push(int x, Stack *&myStk) //Добавление элемента х в стек
{
    Stack *e = new Stack; //выделение памяти для нового элемента
    e->data = x;          //запись элемента x в поле data
    e->next = myStk;      //перенос вершины на следующий элемент
    myStk = e;            //сдвиг вершины на позицию вперед
}

int pop(Stack *&myStk) //Извлечение (удаление) элемента из стека
{
    if (myStk == NULL)
    {
        cout << "Стек пуст!" << endl;
        return -333333; //если стек пуст - возврат (-1)
    }
    else
    {
        Stack *e = myStk;    //е-переменная для хранения адреса элемента
        int x = myStk->data; //запись элемента из поля data в перем. x
        if (myStk)
            myStk = myStk->next; //перенос вершины
        delete e;
        return x;
    }
}

void toFile(Stack *&myStk) //Запись в файл
{
    Stack *e = myStk;
    Stack buf;
    ofstream frm("mStack.dat");
    if (frm.fail())
    {
        cout << "\n Ошибка открытия файла";
        exit(1);
    }
    while (e)
    {
        buf = *e;
        frm.write((char *)&buf, sizeof(Stack));
        e = e->next;
    }
    frm.close();
    cout << "Стек записан в файл mStack.dat\n";
}

void fromFile(Stack *&myStk) //Считывание из файла
{
    Stack buf, *p = nullptr, *e = nullptr;
    ifstream frm("mStack.dat");
    if (frm.fail())
    {
        cout << "\n Ошибка открытия файла";
        exit(1);
    }
    frm.seekg(0);
    frm.read((char *)&buf, sizeof(Stack));
    while (!frm.eof())
    {
        push(buf.data, e);
        frm.read((char *)&buf, sizeof(Stack));
    }
    frm.close();
    while (e != NULL)
    {
        buf.data = pop(e);
        push(buf.data, p);
        myStk = p;
    }
    cout << "\nСтек считан из файла mStack.dat\n\n";
}

void show(Stack *&myStk) //Вывод стека с очисткой
{
    Stack *e = myStk;
    if (e == NULL)
        cout << "Стек пуст!" << endl;
    while (e != NULL)
        cout << pop(e) << " ";
    cout << endl;
}

void sort(Stack *&myStack)
{
    Stack *stc = myStack;
    Stack *pos = new Stack;
    Stack *neg = new Stack;
    int elem = 0;
    do
    {
        elem = pop(myStack);
        if (elem > 0)
            push(elem, pos);
        else
            push(elem, neg);
    } while (elem != -333333);

    cout << "\nположительные:";
    show(pos);
    cout << "\nотрицательные:";
    show(neg);
}