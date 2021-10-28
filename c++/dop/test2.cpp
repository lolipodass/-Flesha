#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;
int main()
{
    int key;
    cout <<"Введите ключ";
    cin >>key;
    srand(key);
    int b=rand()%10;
    int c=rand()%10;
    cout<<b<<endl<<c;
}