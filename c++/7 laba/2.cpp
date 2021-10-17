#include <iostream>

using namespace std;
int main()
{

    int kol;
    cout << "vvedi kolvo elementov ";
    cin >> kol;
    int *mas = new int[kol];
    int *mas2 = new int[kol];
    int sh=0;
    for (int i = 0; i < kol; i++)
    {
        cin >> mas[i];

        if (mas[i]>99 && mas[i]<1000)
        {
            mas2[sh]=mas[i];
            sh++;
        }
    }

    for (int i = 0; i < sh; i++)
    {
        cout << mas2[i]<<" ";
    }

    mas=mas2;
}