#include <iostream>
#include <cmath>

using namespace std;

double func(double x)
{
    double result =x*x*x-3;
    return result;
}

double func2(double x)
{
    double result =x*x*x+x-3;
    return result;
}


void first()
{
    int a=1,b=3,n=200;
    double h=0.001;
    double s=0;
    int i=0;
    for(double x=a;x<b-h;x+=h)
    {
        s+=h*(func(x)+func(x+h))/2;
        i++;
    }
    cout <<s<<" "<<i;

}

void second()
{
    int a=1,b=3,n=200;
    double h=0.005;
    double s=0;
    double x=a+2*h;
    double s1=0,s2=0;

    for (double i = 1; i < n; i++)
    {
        s2+=func(x);
        x+=h;
        s1+=func(x);
        x+=h;
    }
    double S=(h/3)*(func(a)+4*func(a+b)+4*s1+2*s2+func(b));
    cout <<S;

}

void third()
{
    double a=0;
    double b=3;
    double e=1e-5;
    double x=0;
    while (abs(a-b)>2*e)
    {
        x=(a+b)/2;
        if (func2(x)*func2(a)<=0)
        {
            b=x;
        }
        else
        {
            a=x;
        }
    }
    cout <<x;
}

int main()
{
    

}