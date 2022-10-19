#include "Heap.h"
#include <iostream>
#include <iomanip>
using namespace std;
void AAA::print()
{
    cout << x;
}
int AAA::getPriority() const
{
    return x;
}
namespace heap
{
    Heap create(int maxsize, CMP (*f)(void *, void *))
    {
        return *(new Heap(maxsize, f));
    }
    int Heap::left(int ix)
    {
        return (2 * ix + 1 >= size) ? -1 : (2 * ix + 1);
    }
    int Heap::right(int ix)
    {
        return (2 * ix + 2 >= size) ? -1 : (2 * ix + 2);
    }
    int Heap::parent(int ix)
    {
        return (ix + 1) / 2 - 1;
    }
    void Heap::swap(int i, int j)
    {
        void *buf = storage[i];
        storage[i] = storage[j];
        storage[j] = buf;
    }
    void Heap::heapify(int ix)
    {
        int l = left(ix), r = right(ix), irl = ix;
        if (l > 0)
        {
            if (isGreat(storage[l], storage[ix]))
                irl = l;
            if (r > 0 && isGreat(storage[r], storage[irl]))
                irl = r;
            if (irl != ix)
            {
                swap(ix, irl);
                heapify(irl);
            }
        }
    }
    void Heap::insert(void *x)
    {
        int i;
        if (!isFull())
        {
            storage[i = ++size - 1] = x;
            while (i > 0 && isLess(storage[parent(i)], storage[i]))
            {
                swap(parent(i), i);
                i = parent(i);
            }
        }
    }
    void *Heap::extractMax()
    {
        void *rc = nullptr;
        if (!isEmpty())
        {
            rc = storage[0];
            storage[0] = storage[size - 1];
            size--;
            heapify(0);
        }
        return rc;
    }
    void *Heap::extractMin(Heap h) //удаление минимального
    {
        void *rc = nullptr;
        void *min = storage[0];
        int check = 0;
        if (!isEmpty())
        {
            rc = storage[0];
            for (int i = 0; i < size; i++)
            {
                if (isLess(storage[i], min))
                {
                    min = storage[i];
                    check = i;
                }
            }
            void *buf;
            buf = storage[size - 1];
            storage[size - 1] = storage[check];
            storage[check] = buf;
            size--;
            heapify(0);
        }
        return rc;
    }
    void Heap::scan(int i) const //Вывод значений элементов на экран
    {
        int probel = 20;
        cout << '\n';
        if (size == 0)
            cout << "Куча пуста";
        for (int u = 0, y = 0; u < size; u++)
        {
            cout << setw(probel + 10) << setfill(' ');
            ((AAA *)storage[u])->print();
            if (u == y)
            {
                cout << '\n';
                if (y == 0)
                    y = 2;
                else
                    y += y * 2;
            }
            probel /= 2;
        }
        cout << '\n';
    }
    void Heap::unionHeap(void *x)
    {
        int i;

        for (i = 0; i < size - 1; i++)
        {
            storage[i] = storage[i + 1];
        }
        heapify(0);

        storage[i = ++size - 1] = x;
        while (i > 0 && isLess(storage[parent(i)], storage[i]))
        {
            swap(parent(i), i);
            i = parent(i);
        }
    }

    void *Heap::extractX(Heap h, int xxx)
    {
        void *rc = nullptr;
        int check = 0;
        void *buf;
        if (!isEmpty())
        {
            rc = storage[0];
            for (int i = 0; i < size; i++)
            {
                if (((AAA *)storage[i])->x == xxx)
                {
                    buf = storage[size - 1];
                    storage[size - 1] = storage[i];
                    storage[i] = buf;
                    size--;
                    break;
                }
            }
            heapify(0);
        }
        return rc;
    }
}