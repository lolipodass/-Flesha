#include <iostream>
#include <cmath>

using namespace std;
int main()
{
    double a=1.774,m=5;
    double x[3]={3,0.2,5};
    for (int i = 0; i < 3; i++)
    {
        double y=sqrt(a+m*m*x[i]*x[i]);
        y=y/(a+x[i])*m;
        y = abs(y);
        double z=0;
        if (y>=1)
        {
            z=sin(y)*sin(y);
        }
        else{
            z=y+1;
        }
        cout << y <<" " <<z << endl;
    }
    

}