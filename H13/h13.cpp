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

/* TEST Data

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
|    Input1      /    Input2         |            Output                        |  Passed / Failed  |
+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

1 Merge1              20 Merge2                  1 Merge1 files2                          +
2 both1               19 both2                   2 both1 both2
3 given1              18 given2                  3 given1 from2
4 files1              17 files2                  4 files1 saved2
5 into1               16 into2                   5 into1 are2
6 another1            15 another2                6 another1 ID2
7 text1               14 text2                   7 text1 same2
8 file1               13 file2                   8 file1 the2
9 where1              12 where2                  9 where1 with2
10 all1               11 all2                    10 all1 words2
11 words1             10 words2                  11 words1 all2
12 with1              9 with2                    12 with1 where2
13 the1               8 the2                     13 the1 file2
14 same1              7 same2                    14 same1 text2
15 ID1                6 ID2                      15 ID1 another2
16 are1               5 are2                     16 are1 into2
17 saved1             4 saved2                   17 saved1 files2
18 from1              3 from2                    18 from1 given2
19 both1              2 both2                    19 both1 both2
20 files1             1 files2                   20 files1 Merge2
-----------------------------------------------------------------------

1 Merge1              20 Merge2                  1 Merge1 files2                          +
2 both1               19 both2                   2 both1 both2
3 given1              18 given2                  3 given1 from2
18 from1              3 from2                    18 from1 given2
19 both1              2 both2                    19 both1 both2
20 files1             1 files2                   20 files1 Merge2
-----------------------------------------------------------------------
*/