#include <iostream>
#include <cmath>

using namespace std;
int main()
{
    int years=0,an=0;
    double sum=0,izn=0;
    cout << "ckolko let"<< endl;
    cin >>years;
    for(int i=1;i<=years;i++)
    {
        cout<<"ckolko za "<<i<< " god ";
        cin >>an;
        sum+=an;
    }  
    cout << "% isnosa";
    cin >> izn;
    izn=1-izn/100;
    sum=sum*pow(izn,years);
    cout << "end sum "<<sum<<endl;
}