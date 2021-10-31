#include <iostream>

using namespace std;

int main()
{
    int kol=0;
    cout <<"vvedi";
    cin >> kol;
    int *arr = new int[kol];
    int sum = 1;
    int maxsum = 0;
    for(int i=0; i<kol; i++)
    {
        //arr[i] =rand()%10;
        cin>>arr[i];
    }
    for(int i=1; i<kol; i++)
    {

        if (arr[i-1]==arr[i])
        {
            sum++;
        }
        else
        {
            sum=1;
        }
        if (maxsum<sum)
        {
            maxsum = sum;
        }
        
    }
    cout <<"sum " <<maxsum; 
}