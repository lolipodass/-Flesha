#include <iostream>
#include <string>
#include <fstream>

using namespace std;
void createFile();
void readFile();
void deleteFile();
void clearFile();
void writeFile();
void choice();

int main()
{
    short choiceNum;

    while (choiceNum != -1)
    {
        choice();
        cin >> choiceNum;
        switch (choiceNum)
        {
        case 1:
            createFile();
            break;
        case 2:
            writeFile();
            break;

        case 3:
            readFile();
            break;
        case 4:
            clearFile();
            break;
        case 5:
            deleteFile();
            break;
        default:
            return 0;
            break;
        }
    }
}

void choice()
{
    cout << "\n1 создание файла\n";
    cout << "2 запись в файл\n";
    cout << "3 чтение файла output.txt\n";
    cout << "4 удаление всего содержимого файла\n";
    cout << "5 удаление файла\n";
    cout << "-1 завершение работы\n";
}

void createFile()
{
    cout << "Введите название файла: ";
    string fileName;
    cin.ignore(16, '\n');
    getline(cin, fileName);
    cout << fileName;
    ofstream file;
    file.open(fileName);
}

void readFile()
{

    ifstream output;
    output.open("output.txt");
    string file;
    getline(output, file);
    cout << "\n\n"
         << file << "\n\n";
}

void deleteFile()
{
    cout << "введите название файла который нужно удалить: ";
    string name;
    cin.ignore(256, '\n');
    cin >> name;
    remove(name.c_str());
}

void clearFile()
{
    cin.ignore(256, '\n');
    cout << "Введите название файла: ";
    string FileName;
    cin >> FileName;
    ofstream file;
    file.open(FileName, ios_base::trunc);
    file.close();
}

void writeFile()
{
    cout << "Введите название файла: ";
    string fileName;
    cin.ignore(16, '\n');
    getline(cin, fileName);

    fstream file;
    file.open(fileName, ios_base::out);
    cout << "Введите текст который нужно записать в файл: ";
    string text;
    // cin.ignore(256, '\n');
    getline(cin, text);
    cout << text;
    file << text;
}

// Написать функции:
// !1.	Создание и запись данных в файл, название которого вводится с клавиатуры;
// !2.	Чтение файла (название файла не нужно вводить с клавиатуры);
// !3.	Удаление содержимого в файле;
// !4.	Удаление файла.
