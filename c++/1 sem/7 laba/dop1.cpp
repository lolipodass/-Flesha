#include <iostream>
#include <cmath>

using namespace std;
//проверка на порядок чисел
bool checkOrder(short i)
{
    short n[3];
    for (short g = 2; g >= 0; g--)
    {
        n[g]=i%10;
        i/=10;
    }

    if (n[0] <n[1]&&n[1] <n[2])
    {
        return true;
    }
    else
        return false;
}
//проверка на натуральность
void NaturalCheck(int chislo)
{
    short da=0;
    for (short i = 2; i < chislo; i++)
    {
        if (chislo%i==0)
        {
            da++;
        }
    }
    if (da<2)
    {
        cout<<chislo*chislo<<endl;
    }
    
}

int main()
{
    for (short i=123; i <= 789; i++)
    {
        if  (checkOrder(i))
        {
            if ((double)sqrt(i)==(int)sqrt(i))
            {
                NaturalCheck(sqrt(i));
            }
        }
    }
}