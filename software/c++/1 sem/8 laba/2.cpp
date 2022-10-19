#include <iostream>

using namespace std;

int main()
{
    int m=4;
    double c=-4.5e-2,b[4]={0.9,0.5,-2,-0.1};
    double g=c;
    for (short i = 0; i < m; i++)
    {
        g*=(b[i]+1)*(b[i]+1);
    }
    cout <<g<<" ";

    double y[5]={1,2.7,4.7,6,10};
    double t=y[0];

    for (short i = 0; i < m; i++)
    { 
        if (t>y[i])
        {
            t=y[i];
        }
    }

    double q=t;

    for (short i = 0; i < m; i++)
    {
        q*=(y[i]+1)*(y[i]+1);
    }
    cout<<q;
}