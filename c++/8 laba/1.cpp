#include <iostream>

using namespace std;

int main()
{
    int n=5;
    double d=12.5e-4,a[5]={0.8,4,-7,2,0.91};
    double h=d;
    for (short i = 0; i < n; i++)
    {
        h+=a[i]*a[i];
    }
    cout <<h<<" ";

    double x[5]={1,2.7,4.7,6,10};
    double z=x[0];
    double y=0;

    for (short i = 0; i < n; i++)
    {
        if (z<x[i])
        {
            z=x[i];
        }
        y+=x[i]*x[i];
    }
    y*=z;
    cout<<y;
}