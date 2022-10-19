#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> num;
    int n = 123456789;
    int *pN = &n;
    int del = 3;
    int *pDel = &del;

    do
    {

        int g = *pN % 10;
        if (g % *pDel == 0)
        {

            num.push_back(g);
        }

        *pN /= 10;
    } while (n > 0);
    for (int i = 0; i < num.size(); i++)
    {
        cout << num[i] << endl;
    }
}
