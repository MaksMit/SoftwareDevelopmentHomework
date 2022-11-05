#include <iostream>
#include <iomanip>
using namespace std;

/*******************************************

Maksims Mitiakins (mm22184)

===  B10  =======================================
Create program in C++ by making use of described or other functions.
See published detailed requirements.

B10. Given three natural numbers which denote date (day, month, year).
Create function which returns weekday for that date.
The solution should also contain an auxiliary function for leap year checking.


Program created: 2022/10/15
Program improved: 2022/10/23

*******************************************/

// Checking for leap year
int checkYear(int year)
{
    if (year % 400 == 0)
    {
        return 366;
    }
    else if (year % 100 == 0)
    {
        return 365;
    }
    else if (year % 4 == 0)
    {
        return 366;
    }
    else
    {
        return 365;
    }
}

// Returns the number of days in that month
int monthDays(int month, int year)
{
    switch (month)
    {
    case 2:
        if (checkYear(year) == 365)
            return 28;
        else
            return 29;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
        break;
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
        break;
    default:
        return 0;
    }
}

// Counts all days from the 1st year (Gregorian calendar)
// and calculates the day of the week for the entered date
string dayCounter(int day, int month, int year)
{
    int dayCount = 0;

    for (int y = 1; y < year; y++)
    {
        dayCount += checkYear(y);
    }

    for (int m = 1; m < month; m++)
    {
        dayCount += monthDays(m, year);
    }

    string days[] = {
        "Monday",
        "Tuesday",
        "Wednesday",
        "Thursday",
        "Friday",
        "Saturday",
        "Sunday"};

    dayCount += day - 1;
    int weekday = dayCount % 7;

    return days[weekday];
}

// Program entry point
int main()
{
    int loop;
    do
    {
        int day, month, year;

        cout << "Enter year: ";
        while (true)
        {
            cin >> year;
            if (year > 0)
                break;
            cout << "Invalid year. Enter a valid year: ";
        }

        cout << "Enter month: ";
        while (true)
        {
            cin >> month;
            if (month >= 1 && month <= 12)
                break;
            cout << "Invalid month. Enter a valid month: ";
        }

        cout << "Enter day: ";
        while (true)
        {
            cin >> day;
            if (day > 0 && day <= monthDays(month, year))
                break;
            cout << "Invalid day. Enter a valid day: ";
        }

        cout << day << "/" << month << "/" << year;
        cout << " is " << dayCounter(day, month, year);
        cout << "\nContinue (1) or quit (0)" << endl;
        cin >> loop;
    } while (loop == 1);
}

/* TEST Data

----------------------------------------------------------
|      Date      |      Result      |  Passed / Failed  |
+---------------------------------------------------------
 -2022               Invalid year               +
 2022 13             Invalid month              +
 2022 -12            Invalid month              +
 2022 11 31          Invalid day                +
 2022 10 -22         Invalid day                +
 22/10/2022            Saturday                 +
 23/10/2022             Sunday                  +
 23/6/2023              Friday                  +
 1/1/2023               Sunday                  +
 29/2/2024             Thursday                 +
*/