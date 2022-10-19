#include <iostream>
#include <cmath>

using namespace std;

double func1(double);
double func2(double);
void task1(double (*)(double), double, double);

int main()
{
    task1(func1, -10, 0);
    task1(func2, 0, 2);
}

void task1(double (*func)(double), double a, double b)
{
    double e = 1e-5;
    double x = 0;
    while (abs(a - b) > 2 * e)
    {
        x = (a + b) / 2;
        if (func(x) * func(a) <= 0)
        {
            b = x;
        }
        else
        {
            a = x;
        }
    }
    cout << x << endl;
}

double func1(double x)
{
    return x * x + 4 * x - 2;
}
double func2(double x)
{
    return sin(x) + 0.1;
}