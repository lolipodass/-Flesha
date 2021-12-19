#include <iostream>
using namespace std;
int main()
{
    int row1;
    double **a, **b, **c;
    cout << "kolvo strok 1 ";
    cin >> row1;

    a = new double *[row1];
    cout << "element firs matric" << endl;
    for (int i = 0; i < row1; i++)
    {
        a[i] = new double[row1];
        for (int j = 0; j < row1; j++)
        {

            cin >> a[i][j];
            if (a[i][j] < 0)
            {
                return 0;
            }
        }
    }

    b = new double *[row1];
    cout << "element second matric" << endl;
    for (int i = 0; i < row1; i++)
    {
        b[i] = new double[row1];
        for (int j = 0; j < row1; j++)
        {
            cin >> b[i][j];
            if (b[i][j] < 0)
            {
                return 0;
            }
        }
    }

    c = new double *[row1];
    for (int i = 0; i < row1; i++)
    {
        c[i] = new double[row1];
        for (int j = 0; j < row1; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < row1; k++)
                c[i][j] += a[i][k] * b[k][j];
        }
    }
    cout << "answer" << endl;
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < row1; j++)
            cout << c[i][j] << " ";
        cout << endl;
    }
}
