#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    short i=343;
    short n[3];
    for (short g = 3; g > 0; g--)
    {
        n[g]=i%10;
        i/=10;
    }

    if (n[0] <n[1]&&n[1] <n[2])
    {
        cout <<"залупа";
    }
    else
    cout <<"ебучая залупа";

    
    
}

