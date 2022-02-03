#include <iostream>

using namespace std;

int main()
{
    cout << "Введите:" << endl;
    cout << "1-для удаления записи" << endl;
    cout << "2-для ввода новой записи" << endl;
    cout << "3-для изменения записи" << endl;
    cout << "4-для вывода записи(ей)" << endl;
    cout << "5-для выхода" << endl;

    auto choice;

    cin >> choice;
    cout << choice;
}