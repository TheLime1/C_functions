#include <stdio.h>
#include <stdlib.h>

// define the Date structure
typedef struct
{
    int jour;
    int mois;
    int annee;
} Date;

// function to compare two dates and return 1 if date1 is newer,
// -1 if date2 is newer, and 0 if the dates are the same
int compare_dates(Date date1, Date date2)
{
    // first compare the years
    if (date1.annee > date2.annee)
        return 1;
    else if (date1.annee < date2.annee)
        return -1;
    else
    {
        // if the years are the same, compare the months
        if (date1.mois > date2.mois)
            return 1;
        else if (date1.mois < date2.mois)
            return -1;
        else
        {
            // if the months are the same, compare the days
            if (date1.jour > date2.jour)
                return 1;
            else if (date1.jour < date2.jour)
                return -1;
            else
                // if all fields are the same, the dates are the same
                return 0;
        }
    }
}

int main()
{
    // create two dates to compare
    Date date1 = {14, 5, 2022};
    Date date2 = {15, 5, 2022};

    // compare the dates and print the result
    int result = compare_dates(date1, date2);
    if (result == 1)
        printf("Date1 is newer.\n");
    else if (result == -1)
        printf("Date2 is newer.\n");
    else
        printf("The dates are the same.\n");

    return 0;
}
