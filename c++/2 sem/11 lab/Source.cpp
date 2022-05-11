#include "Heap.h"
#include "1.cpp"
#include <iostream>
using namespace std;
heap::CMP cmpAAA(void *a1, void *a2) //Функция сравнения
{
#define A1 ((AAA *)a1)
#define A2 ((AAA *)a2)
	heap::CMP
		rc = heap::EQUAL;
	if (A1->x > A2->x)
		rc = heap::GREAT;
	else if (A2->x > A1->x)
		rc = heap::LESS;
	return rc;
#undef A2
#undef A1
}
//-------------------------------
int main()
{
	int k, choice;
	heap::Heap h1 = heap::create(30, cmpAAA); //куча №1
	heap::Heap h2 = heap::create(30, cmpAAA); //куча №2
	for (;;)
	{
		cout << "(1) Вывод кучи (№1) на экран" << endl;
		cout << "(2) Добавить элемент в кучу (№1)" << endl;
		cout << "(3) Удалить максимальный элемент" << endl;
		cout << "(4) Удалить минимальный элемент" << endl;
		cout << "(5) Удалить элемент по значению" << endl;
		cout << "(6) Добавить элемент в кучу №2" << endl;
		cout << "(7) Вывод кучи №2 на экран" << endl;
		cout << "(8) Объединить кучи" << endl;
		cout << "(0) Выход" << endl;
		cout << "Cделайте выбор" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:
			exit(0);
		case 1:
			h1.scan(0);
			break;
		case 2:
		{
			AAA *a = new AAA;
			cout << "введите ключ" << endl;
			cin >> k;
			a->x = k;
			h1.insert(a);
		}
		break;
		case 3:
			h1.extractMax();
			break;
		case 4:
			h1.extractMin(h1);
			break;
		case 5:
			int k;
			cout << "Введите элемент" << endl;
			cin >> k;
			h1.extractX(h1, k);
			break;
			break;
		case 6:
		{
			AAA *a = new AAA;
			cout << "введите ключ" << endl;
			cin >> k;
			a->x = k;
			h2.insert(a);
			h1.insert(a);
		}
		break;
		case 7:
			h2.scan(0);
			break;
		case 8:
			h1.scan(0);
			break;
		default:
			cout << endl
				 << "Введена неверная команда!" << endl;
		}
	}
	return 0;
}
