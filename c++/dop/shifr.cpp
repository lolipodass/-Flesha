#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    //generate key for crypting
    srand(time(NULL));
    int sdvig=0;


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

//надежда что файл меньше 200 символов
    char line[200];
    
//encrypt
    if (state)
    {
        int key=rand();
        cout <<"ключ для расшифровки "<<key;
        srand(key);

        fin.getline(line,200);
        for(int i=0;i<200;i++){
            sdvig=rand();
            line[i] +=sdvig;
        }
        fout<<line;
        fout.close();
        exit(0);
    }
//decrypt
    else
    {
//key
        int key;
        cout <<"Введите ключ";
        cin >>key;
        srand(key);

        fin.getline(line,200);
        for(int i=0;i<200;i++) {
            sdvig=rand();
            line[i] -=sdvig;
        }
        fout<<line;
    }
    

}