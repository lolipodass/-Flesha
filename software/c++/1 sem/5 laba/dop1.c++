#include <iostream>
#include <cmath>

using namespace std;
int main()
{
    cout << "vvedi 3 chisla: ";
    int a,b,c;  
    cin >>a>>b>>c;
    int i=0,sh=0;
    sh+=(a%5==0)?a:0;
    sh+=(b%5==0)?b:0;
    sh+=(c%5==0)?c:0;
    (sh==0)?cout<<"error":cout<<sh;
}