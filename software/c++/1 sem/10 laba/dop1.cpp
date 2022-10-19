#include <iostream>

using namespace std;

int main()
{
    int kol=0;
    cout <<"vvedi";
    cin >> kol;
    int *arr = new int[kol];
    int sum=0;
    int maxsum=0;
    for(int i=0; i<kol; i++)
    {
        arr[i] =rand()%10;
        cout << arr[i]<<" ";
        if (i%7==6)
        {   
            cout<<endl;
            sum =arr[i]+arr[i-1]+arr[i-2]+arr[i-3]+arr[i-4]+arr[i-5]+arr[i-6];
            if (sum>maxsum)
            {
                maxsum = sum;
            }
        }
        
    }
    cout <<"max sum " <<maxsum <<endl; 
}