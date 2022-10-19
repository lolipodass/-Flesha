#include <iostream>
#include <cmath>

int P(int m, int n)
{
    if (m == 1 || n == 1)
        return 1;
    if (n > m)
        return P(m, m);
    if (n == m)
        return P(m, m - 1) + 1;
    if (n < m)
        return (P(m, n - 1) + P(m - n, n));
    return 0;
}

int X(int a)
{
    return P(a, a);
}

double virai(int n, int b)
{
    if (n < b)
        return 1;

    return sqrt(1 + (n + b)) * virai(n, b + 1);
}

double vir(int n)
{
    return virai(n, 1);
}

int main()
{

    std::cout << X(4) << " test\n";
    std::cout << vir(5);
}