//Name : Ibrahim Talha ASAN
//Course:Programming for Engineers,64170019,Fall Semester,2020-2021
//Purpose:The purpose of this program,creates
// and prints this year's calendar according to the year given to it.

#include<bits/stdc++.h>
using namespace std;


//This function find day of the week.
int findingDayofWeek(int day, int month, int year)
{
    //Tomohiko Sakamoto's Algorithm
    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1,4, 6, 2, 4 };
    year -= month < 3;
    return ( year + year/4 - year/100 + year/400 + t[month-1] + day) % 7;
}

//This function return month name.
string gettingMonthName(int monthNumber){
    string months[] = {"January", "February", "March",
                       "April", "May", "June",
                       "July", "August", "September",
                       "October", "November", "December"
    };

    return (months[monthNumber]);
}

//This function returns the number of days of the month.
int numberOfDays (int monthNumber, int year)
{
    // January
    if (monthNumber == 0)
        return (31);

    // February
    if (monthNumber == 1)
    {
        // If the year is leap then February has
        // 29 days
        if (year % 400 == 0 ||
            (year % 4 == 0 && year % 100 != 0))
            return (29);
        else
            return (28);
    }
    // March
    if (monthNumber == 2)
        return (31);

    // April
    if (monthNumber == 3)
        return (30);

    // May
    if (monthNumber == 4)
        return (31);

    // June
    if (monthNumber == 5)
        return (30);

    // July
    if (monthNumber == 6)
        return (31);

    // August
    if (monthNumber == 7)
        return (31);

    // September
    if (monthNumber == 8)
        return (30);

    // October
    if (monthNumber == 9)
        return (31);

    // November
    if (monthNumber == 10)
        return (30);

    // December
    if (monthNumber == 11)
        return (31);
}

//This function prints the calculated calendar of the given year.
void printCalendar(int year)
{
    int days;

    // Index of the day from 0 to 6
    int current = findingDayofWeek(1, 1, year);

    // i --> Iterate through all the months
    // j --> Iterate through all the days of the
    //       month - i
    for (int i = 0; i < 12; i++)
    {
        days = numberOfDays (i, year);

        // Print the current month name
        printf("\n\t \t%s %d\n",gettingMonthName (i).c_str(),year);
        // Print the columns
        printf("    Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
        printf("______________________________________\n");
        // Print appropriate spaces
        int k;
        for (k = 0; k < current; k++)
            printf("     ");

        for (int j = 1; j <= days; j++)
        {
            printf("%5d", j);
            if (++k > 6)
            {
                k = 0;
                printf("\n");
            }
        }
        if (k)
            printf("\n");
        current = k;
    }
    return;
}

int main(){
    int year = 2020;
    printCalendar(year);
    return 0;
}

