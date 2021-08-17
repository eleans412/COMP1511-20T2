//Program will read and print whether a year input is a leap year
// Written 08/06/20 at 17:42
// by Len Au (z5308653@ad.unsw.edu.au)

#include <stdio.h>

int main (void) {

    //Asks user to input a year and read the year
    int year;
    printf ("Enter year: ");
    scanf ("%d", &year); 

    //Not leap year and divisible by 100, not 400
    if (year % 100 == 0 && year % 400 != 0) {
        printf ("%d is not a leap year. \n", year);
        return 0;
    } 
    if (year % 4 == 0) { //Is a leap year
        printf ("%d is a leap year. \n", year);
        return 0;
    }

    else { //Not a leap year
        printf ("%d is not a leap year. \n", year); 
    }
    return 0;
}
