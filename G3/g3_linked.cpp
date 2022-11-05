#include <fstream>
#include <iostream>

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

struct Element
{
    int num;
    Element *next;
};

void deleteFromLinkedList(Element *list)
{
    Element *curr, *next;
    curr = list;
    next = list->next;
    while (next != NULL)
    {
        if (curr->num > next->num)
        {
            next = next->next;
            delete curr->next;
            curr->next = next;
            continue;
        }
        curr = next;
        next = curr->next;
    };
}

void printLinkedList(Element *first)
{
    Element *p;

    for (p = first; p != NULL; p = p->next)
    {
        cout << p->num << " ";
    };

    cout << endl;
}

int main()
{
    Element *first = NULL, *last = NULL, *p;
    int i;
    cout << "Enter a number or 0 to end:";
    cin >> i;
    /// input until 0 is encountered
    while (i != 0)
    {
        p = new Element;
        p->num = i;
        p->next = NULL;
        if (first == NULL)
        {
            first = last = p;
        }
        else
        {
            last->next = p;
            last = last->next;
        };
        cout << "Enter a number or 0 to end:";
        cin >> i;
    };

    if (first == NULL)
    {
        cout << "No digits were entered" << endl;
        return 1;
    }

    printLinkedList(first);

    deleteFromLinkedList(first);

    printLinkedList(first);

    /// destroying the list
    p = first;
    while (p != NULL)
    {
        first = first->next;
        delete p;
        p = first;
    };

    return 0;
}


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