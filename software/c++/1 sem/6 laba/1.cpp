#include <iostream>
#include <cmath>

using namespace std;
int main()
{
    cout << "vvedi chislo"<< endl;
    for (int i = 0; i <4;i++)
    {
        double c=2.1,r=4e-4,m=7;
        double j=0;
        cin >>j;
        double h=(10*r-j)/(c*c+exp(-m));
        double y=(h*m-j*j)+pow((0.1*c),2);
        cout << h << " " << y << endl;
    }
}