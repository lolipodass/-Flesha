#include <iostream>

using namespace std;

int main()
{
    int m=5;
    double x[5]={-2,6,1.1,2.7,4};
    double z=8*x[3];
    for (short i = 0; i < m; i++)
    {
        z+=(x[i]-2)*(x[i]-2);
    }
    cout <<z<<" ";


    double q[5]={9,2.7,4.1,6,12};
    double max=q[9];
    double y=0;

    for (short i = 0; i < m; i++)
    { 
        if (max>q[i])
        {
            max=q[i];
        }
        y+=(q[i]+1)*(q[i]+1);
    }
    double p=y+max;

    cout<<y<<" "<<p;
}