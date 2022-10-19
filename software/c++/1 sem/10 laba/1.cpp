#include <iostream>
#include <vector>


using namespace std;

int main()
{
    vector<int> arr;
    int kol=0;
    cout<<"vvedi";
    cin>> kol;
    cout<<"znack";
    int znack=0;
    cin>> znack;
    for (int i = 0; i <kol; i++)
    {
        int b=rand() % 20;
        cout <<b<<" ";
        if (b!=znack)
        {
            if (b%2==0&&b!=0)
            {
                arr.push_back(1);
            }
            
            arr.push_back(b);
        }
    }
    cout <<endl;
    for (int i = 0; i < kol; i++)
    {
        cout << arr[i]<<" ";
    }
}