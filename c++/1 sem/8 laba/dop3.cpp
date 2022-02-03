#include <iostream>

using namespace std;

int main()
{
    int kolElements;
    cout <<"sos ";
    cin >>kolElements;
    int kol=kolElements;
    double chislo;
    int min =10000, max=-10000;
	short minD=0,maxD=0;
    for (int i = 0; i < kolElements; i++)
    {
        cin >>chislo;
        if (min>chislo)
        {
            min = chislo;
			kol=kol+minD-1;
			minD=1;
        }
        
        if (max<chislo)
        {
            max = chislo;
			kol=kol+maxD-1;
			minD=1;
        }

        if (chislo==max)
        {
            kol--;
			maxD++;
		}
		if (chislo==min)
		{
			kol--;
			minD++;
		}
	}
    cout <<kol;
    
}
// 11
// 23 94 -32 32 84 843 9 -43 -43 843 4
