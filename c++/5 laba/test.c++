#include <iostream>

using namespace std;

int main()
{

    int arg[10]={0};
    for (int i=0; i<10;i++)
    {
        cin>> arg[i];
    }
    int min=arg[0],ind=0;
   for(int b=0;b<5;b++) 
   {
        for (int i=1; i<10-b;i++)
        {
            if(arg[i]<min)
            {
                min=arg[i];
                ind=i;
            }
        }
        
        for(int i=ind;i<10;i++)
        {
            arg[i]=arg[i+1] ;
        }
        min=arg[0];
    }
    cout<<endl;
    //-21 4 -32 45 98 38 98
    for (int i=0; i<5;i++){
        cout << arg[i]<<" ";
    }
}