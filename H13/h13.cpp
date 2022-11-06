#include <map>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

/*******************************************

Maksims Mitiakins (mm22184)

===  H13  =======================================
Create program in C++ using STD map. For details see Lab requirements.

H13. Read text from given two text files.
Text in given files contains identified words.
One line in each text file is one word in format
<integer ID> <Word max 30 characters>
Merge both given files into another text file where all words with the same ID are saved from both files.
Order words in output file by ID. In output file must be unique IDs.

Program created: 2022/11/05

*******************************************/

int main()
{
    map<int, string> map;
    int id;
    string word;
    ifstream in;

    in.open("one.txt");
    while (in >> id >> word)
        map[id] = word;
    in.close();

    in.open("two.txt");
    while (in >> id >> word)
        map[id] += " " + word;
    in.close();

    ofstream out("out.txt");
    for (auto &i : map)
        out << i.first << " " << i.second << endl;
    out.close();
}