#include <iostream>

using namespace std;
int main()
{    
    int x,y,x1,x2,y1,y2,buffArea=0;
    bool gg=0;
    cout <<"vvedi razmer uchastka x,y: ";
    cin >> x >> y;
    cout <<"vvedi razmer pervogo doma x,y: ";
    cin >> x1 >> x2;
    cout <<"vvedi razmer vtorogo doma x,y:  ";
    cin >> y1 >> y2;

    //finding bigest spacing
    // short spacing[4];
    // spacing[0]=x-x1;    
    // spacing[1]=x-x2;
    // spacing[2]=y-x1;
    // spacing[3]=y-x2;
    // short buff=spacing[0], num=0;
    // for (short i = 1; i < 4; i++)
    // {
    //     if (buff<spacing[i])
    //     {
    //         buff=spacing[i];
    //         num=i;
    //     }
    //     else if (spacing[i]<0)
    //     {
    //         gg=1;
    //         break;
    //     }
    // }

    //old checking
    // if  (gg)
    // {
    //     cout <<"ur u realy idiot";\
    // }
    // else
    // {
    //     if (areaUch>areaFirst+areaSecond)
    //     {
    //         if (x==x1 || y==x1)
    //             buffArea=areaFirst+x2;
    //         else if (x==x2 || y==x2)
    //             buffArea=areaFirst+x1;
    //         else 
    //             buffArea=areaFirst+x1+x2;                   
    //         if (areaUch-buffArea>=areaSecond)
    //             cout<<"vlese";
    //         else 
    //             cout<<"ne vlese";
    //     }
    //     else 
    //         cout <<"bb lox";
    // }

    for(short i=0; i<2;i++)
    {
        short spacing=x-x1-1;
        if (spacing>=y1 &&y>=y1)
        {   
            cout <<"vlese";
            gg=1;
            break;
        }
        swap(y1,y2);    
        if (spacing>=y1 &&y>=y1)
        {   
            cout <<"vlese";
            gg=1;
            break;
        }
        swap(x,y);
    }
    if (!gg)
    {
        cout<<"ne vlese";
    }
    

}