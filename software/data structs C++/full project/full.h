#pragma once

#include <string>
using std::string;

struct contract
{
    string name;
    double price;
    short amount;
    short workExp;

    int operator[](string value)
    {
        if (value=="price")
            return (*this).price;
        if (value=="amount")
            return (*this).amount;
        if (value=="workExp")
            return (*this).workExp;
        else return -1;
    }
};


void ReadFromFile(contract *,size_t);
void FullContract(contract *);
void WriteToFile(contract *, size_t);
contract *Choosing(contract *,size_t, short);
void ShowStruct(contract *, size_t);
contract *deleteElements(contract *, size_t, int, int);
contract *copyArray(contract *, size_t);
void sorting(contract*,size_t, string ,bool );
void findValue(contract *,size_t);
int InterpolSearch(contract *,size_t,int);
int binarySeacrh(contract *, size_t, int);
