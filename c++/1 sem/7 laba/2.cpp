#include <iostream>

using namespace std;

void check(short i)
{
    short wrtime =i,sh=0;
    short n[3];
    for (short g = 0; g < 3; g++)
    {
        n[g]=i%10;
        i/=10;
    }

    if (n[0] !=n[1]&&n[1] !=n[2] && n[2] !=n[0])
    {
        cout<<wrtime<<" ";
        sh++;
        if (sh==10)
        {
            cout<<endl;
            sh=0;
        }
    }
}

using namespace std;
int main()
{

    for (short i=100; i < 1000; i++)
    {
        check(i);
    }
}

