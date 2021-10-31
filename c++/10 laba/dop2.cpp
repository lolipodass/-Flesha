#include <iostream>

using namespace std;

int main()
{
    int kol=0;
    cout <<"vvedi";
    cin >> kol;
    int *arr = new int[kol];
    int sum = 0;
    for(int i=0; i<kol; i++)
    {
        arr[i] =rand()%10;
        cout << arr[i] << " ";
        if (i>0)
        {
            if (arr[i]==arr[i-1])
            {
                sum++;
            }
            
        }
        
    }
    cout <<"sum " <<sum <<endl; 
}