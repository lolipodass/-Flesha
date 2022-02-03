#include <iostream>
#include <iomanip>

using namespace std;
int main()
{

    char your, probel=' ';
    cout << "Bвдитe чиcлo: ";
    cin >> your;
    cout << setw(33)<<setfill(probel)<<probel;
    cout<<setw(7) << setfill(your)<< your<<endl;
    cout << setw(30)<<setfill(probel)<<probel;
    cout<<setw(13) << setfill(your)<< your<<endl;
    cout << setw(27)<<setfill(probel)<<probel;
    cout<<setw(19) << setfill(your)<< your<<endl;
    cout << setw(25)<<setfill(probel)<<probel;
    cout<<setw(23) << setfill(your)<< your<<endl;
    cout << setw(24)<<setfill(probel)<<probel;
    cout<<setw(25) << setfill(your)<< your<<endl;

}