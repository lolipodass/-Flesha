#include <iostream>

using namespace std;
int main()
{
    cout <<"vvedi 3 chisla: ";
    int x,y,z,i=0;
    cin >> x >> y >> z;
    if(x<0)
    {
        i++;
    }
    if (y<0) 
    {
        i++;
    }
    if(z<0)
    {
        i++;
    }
    cout <<i<<endl;
}