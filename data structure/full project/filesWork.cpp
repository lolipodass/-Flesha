#include <fstream>
#include <iostream>
#include <string>
#include "full.h"


using std::cout,std::cin;

void ReadFromFile(contract *cont,size_t length)
{
    std::ifstream file;
    string line;
    string name;
    cout << "название файла: ";
    cin >> name;
    file.open(name);
    getline(file, line);

    if (!file.is_open())
    {
        cout << "wrong file";
        return;
    }

    for (short i = 0; i < length; i++)
    {
        int startName = line.find("NAME:") + 5;
        int startPrice = line.find("PRICE:", startName) + 6;
        int startAmount = line.find("AMOUNT:", startPrice) + 7;
        int startExperience = line.find("EXPERIENCE:", startAmount) + 11;

        short npos = static_cast<short>(string::npos);
        if (startName == npos || startPrice == npos || startAmount == npos || startExperience == npos)
        {
            cout << "bad file\n";
            return;
        }

        cont[i].name = line.substr(startName, startPrice - startName - 7);
        cont[i].price = stoi(line.substr(startPrice, startAmount - startPrice - 7));
        cont[i].amount = stoi(line.substr(startAmount, startExperience - startAmount - 11));
        cont[i].workExp = stoi(line.substr(startExperience, line.size()));
        getline(file, line);
    }
}

void WriteToFile(contract *arr, size_t length)
{
    std::ofstream file;
    string name;
    cout << "название файла: ";
    cin >> name;
    file.open(name);
    if (!file.is_open())
    {
        cout << "wrong file";
        return;
    }
    for (short i = 0; i < length; i++)
        file << "NAME:" << arr[i].name << " PRICE:" << arr[i].price << " AMOUNT:" << arr[i].amount << " EXPERIENCE:" << arr[i].workExp << '\n';
}