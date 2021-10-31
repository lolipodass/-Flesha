#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int kol=0;
    cout <<"vvedi";
    cin>> kol;
    char *arr=new char[kol];
    vector<char> num;
    vector<char> chars;
    for (size_t i = 0; i < kol; i++)
    {
        cout<<"el ";
        cin >>arr[i];
        if (arr[i]=='0'||arr[i]=='1'||arr[i]=='2'||arr[i]=='3'||arr[i]=='4'||arr[i]=='5'||arr[i]=='6'||arr[i]=='7'||arr[i]=='8'||arr[i]=='9')
        {
            num.push_back(arr[i]);
        }
        else
        {
            chars.push_back(arr[i]);
        }
    }
    for (int i = 0; i < num.size(); i++)
    {
        cout <<num[i]<<" ";
    }
    cout<<endl;
    for (int i = 0; i < chars.size(); i++)
    {
        cout <<chars[i]<<" ";
    }
}