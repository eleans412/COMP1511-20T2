//Prints the first n digits of pi, where n is specified 
// by Len Au 22/06/20 at 22:00 (z5308653@ad.unsw.edu.au)

#include <stdio.h>

#define MAX_DIGITS 10

int main(void) {
    int pi[MAX_DIGITS] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    printf("How many digits of pi would you like to print? ");
    //Read the digits to be printed
    int num_digits;
    scanf ("%d", &num_digits);
    
    //Scan through array for the digits needed
    //Print out the digits of pi desired

    //if 1 digit
    if (num_digits == 1) {
        printf ("%d", pi[0]);
    }
    //if no digits
    if (num_digits == 0) {
        printf (" ");
    }
    //else more than 1 digit
    if (num_digits > 1) { //BECAUSE PI IS INT, CANNOT PRINT LF
        //instead, start counter at 1 to print decimal place
        int i = 1;
        printf ("%d.", pi[0]);
        while (i < num_digits) {//visits i - 1 elements
            printf ("%d", pi[i]);
            i++; //increment counter
        }
           
    }
         
    printf ("\n");

    return 0;
}
