#include <iostream>

using namespace std;
int main()
{
    cout <<"vvedi 3 chisla: ";
    int x,y,z;
    cin >> x >> y >> z;
    if(x<y)
    {
        swap(x,y);
    }
    if (y<z) 
    {
        swap(y,z);
    }
    if(x<y)
    {
        swap(x,y);
    }
    cout <<x<<" "<<y<<" "<<z<<endl;
}