#include <iostream>

using namespace std;
int main()
{
    cout <<"vvedi bukvu,number: ";
    int n;
    char m;
    char cord='B';
    cin >> m >> n;
    bool ok = true;

    if (m>'H' || m<'A' || n<1 || n>10)
    {
        cout<<"BB lox";
    }
    else
    {
        for (int i = 10; i > 3; i--)
        {

            if (m==cord&&n==i)
            {
                cout <<"gg lox";
                ok = false;
                break;
            }
            cord++;        
        }
        if (ok)cout<<"killer2003";
    }

}