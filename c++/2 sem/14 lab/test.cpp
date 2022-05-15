
#include <iostream>
struct Object
{
    void **data;
    Object(int, int (*)(void *));
    int size;
    int N;
    int (*getKey)(void *);
    bool insert(void *);
    int searchInd(int key);
    void *search(int key);
    void *deleteByKey(int key);
    bool deleteByValue(void *);
    void scan(void (*f)(void *));
};
static void *DEL = (void *)(void *)-1;
Object create(int size, int (*getkey)(void *));

using namespace std;
struct AAA
{
    int key;
    char *mas;
    AAA(int k, char *z)
    {
        key = k;
        mas = z;
    }
    AAA() {}
};
//-------------------------------
int key(void *d)
{
    AAA *f = (AAA *)d;
    return f->key;
}
//-------------------------------
void AAA_print(void *d)
{
    cout << " ключ " << ((AAA *)d)->key << " - " << ((AAA *)d)->mas << endl;
}
//-------------------------------
int main()
{
    int size = 10, choice, k;
    cout << "Введите размер хеш-таблицы" << endl;
    cin >> size;
    Object hashTable = create(size, key);
    while (true)
    {
        cout << "1 - вывод хеш-таблицы" << endl;
        cout << "2 - добавление элемента" << endl;
        cout << "3 - удаление элемента" << endl;
        cout << "4 - поиск элемента" << endl;
        cout << "0 - выход" << endl;
        cout << "сделайте выбор" << endl;
        cin >> choice;
        switch (choice)
        {
        case 0:
            exit(0);
        case 1:
            hashTable.scan(AAA_print);
            break;
        case 2:
        {
            AAA *a = new AAA;
            char *str = new char[20];
            cout << "введите ключ" << endl;
            cin >> k;
            a->key = k;
            cout << "введите строку" << endl;
            cin >> str;
            a->mas = str;
            if (hashTable.N == hashTable.size)
                cout << "Таблица заполнена" << endl;
            else
                hashTable.insert(a);
        }
        break;
        case 3:
        {
            cout << "введите ключ для удаления" << endl;
            cin >> k;
            hashTable.deleteByKey(k);
        }
        break;
        case 4:
        {
            cout << "введите ключ для поиска" << endl;
            cin >> k;
            if (hashTable.search(k) == NULL)
                cout << "Элемент не найден" << endl;
            else
                AAA_print(hashTable.search(k));
        }
        break;
        }
    }
    return 0;
}

int HashFunction(int key, int size, int i) //Хеш-функция
{
    if (key == i)
    {
        return 7.9555 * i + 6.2611 * i * i;
    }
    double key2 = HashFunction(key, size, key) + 7.9555 * i + 6.2611 * i * i;
    return (int)(i + key) % size;
}
//-------------------------------
int Next_hash(int hash, int size, int p)
{
    return (hash + 5 * p + 3 * p * p) % size;
}
//-------------------------------
Object create(int size, int (*getkey)(void *))
{
    return *(new Object(size, getkey));
}
//-------------------------------
Object::Object(int size, int (*getkey)(void *))
{
    N = 0;
    this->size = size;
    this->getKey = getkey;
    this->data = new void *[size];
    for (int i = 0; i < size; ++i)
        data[i] = NULL;
}
//-------------------------------
bool Object::insert(void *d)
{
    bool b = false;
    if (N != size)
        for (int i = 0, t = getKey(d), j = HashFunction(t, size, 0);
             i != size && !b; j = Next_hash(j, size, ++i))
            if (data[j] == NULL || data[j] == DEL)
            {
                data[j] = d;
                N++;
                b = true;
            }
    return b;
}
//-------------------------------
int Object::searchInd(int key)
{
    int t = -1;
    bool b = false;
    if (N != 0)
        for (int i = 0, j = HashFunction(key, size, 0); data[j] != NULL && i != size && !b; j = HashFunction(key, size, ++i))
            if (data[j] != DEL)
                if (getKey(data[j]) == key)
                {
                    t = j;
                    b = true;
                }
    return t;
}
//-------------------------------
void *Object::search(int key)
{
    int t = searchInd(key);
    return (t >= 0) ? (data[t]) : (NULL);
}
//-------------------------------
void *Object::deleteByKey(int key)
{
    int i = searchInd(key);
    void *t = data[i];
    if (t != NULL)
    {
        data[i] = DEL;
        N--;
    }
    return t;
}
//-------------------------------
bool Object::deleteByValue(void *d)
{
    return (deleteByKey(getKey(d)) != NULL);
}
//-------------------------------
void Object::scan(void (*f)(void *))
{
    for (int i = 0; i < this->size; i++)
    {
        std::cout << " Элемент" << i;
        if ((this->data)[i] == NULL)
            std::cout << "  пусто" << std::endl;
        else if ((this->data)[i] == DEL)
            std::cout << "  удален" << std::endl;
        else
            f((this->data)[i]);
    }
}
