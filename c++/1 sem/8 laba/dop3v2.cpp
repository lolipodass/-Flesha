#include <iostream>

using namespace std;

int main()
{
    int kolElements;
    cout <<"sos ";
    cin >>kolElements;

    double chislo;
    cin >>chislo;
    int min =chislo, max=chislo;
    int minN=0,maxN=0;
    for (int i = 1; i < kolElements; i++)
    {
        cin >>chislo;
        if (min>chislo)
        {
            min = chislo;
            minN = i;
        }
        
        if (max<chislo)
        {
            max = chislo;
            maxN = i;
        }
	}
    cout <<abs(maxN-minN)-1;
    
}