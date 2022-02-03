#include <iostream>
#include <cmath>

using namespace std;
int main()
{
    cout << "vvedi posledovatelnost"<< endl;
    short i=0;
    int num=0;
    bool zn=0,prev=0;

    cin>>num;
    if(num>=0)
        prev=0;
    else 
        prev=1;
    do
    {
        cin>>num;

        if(num>=0)
            zn=0;
        else 
            zn=1;

        if (zn!=prev)
        {
            i++;
            prev=!prev;
        }
    }
    while(num!=0);
    cout <<i;
}