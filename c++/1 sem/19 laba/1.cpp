#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin;
    fin.open("1.txt");

    int row1 = 3, row2 = 3, col1 = 3, col2 = 3;
    int **a, **b, **c;
    int buff;

    // Ввод элементов первой матрицы
    a = new int *[row1];
    for (int i = 0; i < row1; i++)
    {
        a[i] = new int[col1];
        for (int j = 0; j < col1; j++)
        {
            fin >> buff;
            a[i][j] = buff;
            cout << buff << endl;
            cout << a[i][j] << endl;
        }
    }
    fin.close();
    ifstream fin2;
    fin2.open("2.txt");
    // Ввод элементов второй матрицы
    b = new int *[row2];
    for (int i = 0; i < row2; i++)
    {
        b[i] = new int[col2];
        for (int j = 0; j < col2; j++)
        {
            fin2 >> b[i][j];
            cout << b[i][j];
        }
    }
    fin2.close();
    ofstream fout;
    fout.open("3.txt");

    // Умножение матриц
    c = new int *[row1];
    for (int i = 0; i < row1; i++)
    {
        c[i] = new int[col2];
        for (int j = 0; j < col2; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < col1; k++)
                c[i][j] += a[i][k] * b[k][j];
        }
    }
    // Вывод матрицы произведения
    cout << "answer" << endl;
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col2; j++)
            fout << c[i][j] << " ";
        fout << endl;
    }
}