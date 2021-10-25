#include <iostream>

using namespace std;

int main()
{
    int b,shit=0;
    cout <<"sos";
    cin >>b;
    for (int i = 0; i < b; i++)
    {
        int q;
        cin >>q;
        if (q%2==0)
        {
            shit++;
        }
        
    }
        cout <<shit;
    
}