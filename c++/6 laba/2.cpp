#include <iostream>
#include <cmath>

using namespace std;
int main()
{
    cout << "vvedi chislo"<< endl;
    short i=0;
    double shit=0;
    while (shit <=1.7)
    {
        double c=2.1,r=4e-4,m=7;
        double h=(10*r-shit)/(c*c+exp(-m));
        double y=(h*m-shit*shit)+pow((0.1*c),2);
        cout << h << " " << y << endl;
        shit+=0.1;
    }
}