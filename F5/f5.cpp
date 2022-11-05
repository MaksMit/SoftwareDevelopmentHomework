#include <fstream>
#include <iostream>

using namespace std;

/*******************************************

Maksims Mitiakins (mm22184)

===  F5  =======================================
Create program in C++ to process text files. 
Reading from files should be carried out line per line. 
It is no allowed to store copy of the contents of file in the memory. 
For details see Lab requirements.

F5. Create program to read given text file and print into another text file all lines containing given substring.
Length of the substring will not exceed 40 symbols.

Program created: 2022/10/15
Program improved: 2022/10/22

*******************************************/


//I'm not sure, but I hope you mean that only the first 40 symbols of each line will be printed to another text file.

int main ()
{
    ifstream fin;
    ofstream fon;
    string str;
    int filesize = 0;
    fin.open ("../F5/origin.txt");
    fon.open ("../F5/copy.txt");
    getline(fin, str);
    while (fin)
    {
        filesize++;
        fon << str.substr(0, 40) << endl;
        getline(fin, str);
    };
    fin.close ();
    fon.close ();
    return 0;
}
