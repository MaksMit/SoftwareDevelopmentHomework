#include <iostream>
#include <fstream>
#include <sstream>

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
Program improved: 2022/11/5

*******************************************/

int main()
{
    fstream fin;
    ofstream fon;
    string keyWord, line;
    int found = 0;

    fin.open("../F5/input.txt");
    fon.open("../F5/output.txt");

    cout << "Please, enter a key word: " << endl;
    cin >> keyWord;

    if (keyWord.length() < 40)
    {
        while (getline(fin, line))
        {
            // Processing from the beginning of each line.
            if (line.find(keyWord) != string::npos)
            {
                fon << line << "\n";
                found = 1;
            }
        }
        if (found == 0)
        {
            cout << "Error. Input text file doesn't have the mentioned word." << endl;
        }
    }
    else
    {
        cout << "Error. Entered key word exceed 40 symbols." << endl;
    }

    fin.close();
    fon.close();
    return 0;
}

/* TEST Data

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
|               Input                      |                                     Output                                                       |  Passed / Failed  |
+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
dolor                                           Lorem ipsum dolor sit amet,                                                                            +
                                                sed eiusmod tempor incidunt ut labore et dolore magna aliqua.
                                                Quis aute iure reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur.

ut                                              sed eiusmod tempor incidunt ut labore et dolore magna aliqua.                                          +
                                                ut enim ad minim veniam,
                                                nisi ut aliquid ex ea commodi consequatur.
                                                quis aute iure reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur.


aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa         Error. Input text doesn't have the mentioned word.                                                     +
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab        Error. Entered key word exceed 40 symbols.                                                             +
*/