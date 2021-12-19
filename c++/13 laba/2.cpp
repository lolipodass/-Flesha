#include <iostream>

using namespace std;

int main()
{
    char xux[] = "0001 32323 433 43244 23232 323 43444";
    short kol = 5;
    short ror = 0;
    short ans = 1;

    int i = 0;
    char now = xux[i];
    do
    {
        now = xux[i];
        i++;

        if (now == ' ')
        {
            if (ror == kol)
            {
                ans++;
            }

            ror = 0;
            continue;
        }
        ror++;

    } while (now != '\0');
    cout << ans;
}
