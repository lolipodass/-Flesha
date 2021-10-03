#include <iostream>
#include <cmath>

using namespace std;
int main()
{
    cout << "vvedi 3 chisla: ";
    int a,b,c;  
    cin >> a>>b>>c;
    int srmatch=(a+b+c)/3;
    int sraref=sqrt(a*b*c);
    cout << srmatch<<" "<<sraref<<endl;
}