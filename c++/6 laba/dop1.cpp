#include <iostream>
#include <cmath>

using namespace std;
int main()
{
    int vir=0,i=0;
    int sum=0;
    cout << "vvedi chislo vir"<< endl;
    cin >>vir;
    cout << "vvedi sum"<< endl;
    cin >>sum;
    while(vir<sum)
    {
        vir*=1.03;
        i++;
    }  
    cout << "den x "<<i<<endl;
    cout <<"virusha "<<vir;
}