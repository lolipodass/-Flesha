#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int shet=0;
    for (int i = 0; i <= 2; i++)
    {
        for (int j = 0; j <=5;j++)
        {
            for (int l = 0; l <=20;l++)
            {
                for (int m = 0; m <= 50; m++)
                {
                    if ((i*50+j*20+l*5+m*2)==100)
                    {
                        shet++;
                    }
                }
            }
        }
    }
    cout<<shet;
    
}
