#include <iostream>

using namespace std;
int main()
{
    cout <<"vvedi razmer uchastka x,y: ";
    int x,y,x1,x2,y1,y2,buffArea=0;
    cin >> x >> y;
    cout <<"vvedi razmer pervogo doma x,y: ";
    cin >> x1 >> x2;
    cout <<"vvedi razmer vtorogo doma x,y:  ";
    cin >> y1 >> y2;

    int areaUch=x*y;
    int areaFirst=x1*x2;
    int areaSecond=y1*y2;
    if  ((x<x1 || x<x2 || x<y1 || x<y2 ) || (y<x1 || y<x2 || y<y1 || y<y2))
    {
        cout <<"ur u realy idiot";
    }
    else
    {
        if (areaUch>areaFirst+areaSecond)
        {
            if (x==x1 || y==x1)
                buffArea=areaFirst+x2;
            else if (x==x2 || y==x2)
                buffArea=areaFirst+x1;
            else 
                buffArea=areaFirst+x1+x2;            
             
            if (areaUch-buffArea>=areaSecond)
                cout<<"vlese";
            else 
                cout<<"ne vlese";
        }
        else 
            cout <<"bb lox";
    }
}