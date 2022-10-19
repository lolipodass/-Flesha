#include <iostream>

using namespace std;

int main()
{
    double first=20,second=25;
    for (short i = 0; i < 3; i++)
    {
        second/=2;
        first+=second;
        first/=2;
        second+=first;
    }
    cout <<first<<" "<<second;
    
}