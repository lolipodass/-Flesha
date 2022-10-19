#include <bits/stdc++.h>
using namespace std;

struct tech
{
    int year;
    string name;
};

class Hash
{
    int SIZE;

    list<tech> *table;

public:
    Hash(int V);

    void insertItem(tech key);

    void deleteItem(tech key);

    int hashFunction(int key)
    {
        int i = 5.8232;
        double key2 = +7.9555 * i + 6.2611 * i * i;
        return (int)(i + key) % SIZE;
    }

    void displayHash();
};

Hash::Hash(int b)
{
    this->SIZE = b;
    table = new list<tech>[SIZE];
}

void Hash::insertItem(tech key)
{
    int index = hashFunction(key.year);
    table[index].push_back(key);
}

void Hash::deleteItem(tech key)
{

    int index = hashFunction(key.year);

    list<tech>::iterator i;
    for (i = table[index].begin();
         i != table[index].end(); i++)
    {
        if ((*i).year == key.year)
            break;
    }

    if (i != table[index].end())
        table[index].erase(i);
}

void Hash::displayHash()
{
    for (int i = 0; i < SIZE; i++)
    {
        cout << i;
        for (auto x : table[i])
            cout << " --> " << x.year << ": " << x.name;
        cout << endl;
    }
}

int main()
{
    tech a[] = {15, "test", 27, "test1", 12, "test2", 12, "test3", 15, "test4", 13, "test5", 11, "test6"};
    int n = sizeof(a) / sizeof(a[0]);

    Hash h(7);
    for (int i = 0; i < n; i++)
        h.insertItem(a[i]);

    h.displayHash();

    return 0;
}
