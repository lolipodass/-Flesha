#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    
    int sdvig=20;

//files link
    char name[100];
    ifstream fin;
    cout <<"Введи название входного файла ";
    cin>>name;
    fin.open(name);

//checking file
    if(!fin.is_open())
    {
        cout<<"файл "<<name<<" не существует";
        exit(0);
    }

    cout<<"Введи название выходного файла ";
    cin>>name;
    ofstream fout(name);



//choice mode
    cout<<"зашифровать(1) или расшифровать(0)"<<endl;
    bool state=0;
    cin>>state;


    char line[200];
    
    if (state)
//encrypt
    {
        fin.getline(line,200);
        for(int i=0;i<200;i++){
            line[i] +=sdvig;
        }
        fout<<line;
        fout.close();
        exit(0);
    }
//decrypt
    else
    {
        fin.getline(line,200);
        for(int i=0;i<200;i++) {
            line[i] -=sdvig;
        }
        fout<<line;
    }
    

}