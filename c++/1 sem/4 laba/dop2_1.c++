#include <iostream>
#include <iomanip>

using namespace std;
int main()
{

    setlocale(LC_CTYPE, "Russian");
    char your, probel=' ';
    cout << "Введите число: ";
    cin >> your;
    cout << setw(32)<<setfill(probel)<<probel;
    cout<<setw(11) << setfill(your)<< your<<endl;
    cout << setw(30)<<setfill(probel)<<probel;
    cout<<setw(14) << setfill(your)<< your<<endl;
    cout << setw(27)<<setfill(probel)<<probel;
    cout<<setw(19) << setfill(your)<< your<<endl;
    cout << setw(25)<<setfill(probel)<<probel;
    cout<<setw(23) << setfill(your)<< your<<endl;
    cout << setw(24)<<setfill(probel)<<probel;
    cout<<setw(25) << setfill(your)<< your<<endl;

}