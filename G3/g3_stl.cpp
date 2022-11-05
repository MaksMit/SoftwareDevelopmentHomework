#include <fstream>
#include <iostream>
#include <list>

using namespace std;

/*******************************************

Maksims Mitiakins (mm22184)

===  G3  =======================================
Create two programs in C++ to process sequences of values in two ways:
  1) implementing it through a linked list, using dynamic data structures,
  2) using STL::list.
In both implementations,a specific function to process values should be created
and presented in action (showing both initial and resulting values).
In the case of linked-list, also auxiliary functions should be created
and allocated memory for the structure should be freed.

G3. Create function to delete all elements in list with value less than value of previous element.

Program created: 2022/10/23

*******************************************/

void deleteFromSTLList(list<int> &num)
{
    auto curr = num.begin();
    auto next = ++num.begin();
    while (next != num.end())
    {
        if (*curr > *next)
        {
            next = num.erase(next);
            continue;
        }

        curr = next;
        next++;
    }
}

void printSTLList(list<int> &num)
{
    for (auto it : num)
    {
        cout << it << " ";
    }

    cout << endl;
}

int main()
{
    list<int> num;
    int i;
    cout << "Enter a number or 0 to end:";
    cin >> i;
    /// input until 0 is encountered
    while (i != 0)
    {
        num.push_back(i);
        cout << "Enter a number or 0 to end:";
        cin >> i;
    };

    if (num.size() == 0)
    {
        cout << "No digits were entered" << endl;
        return 1;
    }

    printSTLList(num);

    deleteFromSTLList(num);

    printSTLList(num);

    return 0;
}
9

/* TEST Data

----------------------------------------------------------
|            Initial            |            Result            |  Passed / Failed  |
+---------------------------------------------------------
 1 2 3 4 5 6 7 8 9 8 7 6 5 4 3 2 1      1 2 3 4 5 6 7 8 9                +
 1 9 2 8 3 7 4 6 5                      1 9                              +
 3 7 2 9 4 8 5 7 3                      3 7 9                            +
 0                                      No digits were entered           +
 a                                      No digits were entered           +
*/