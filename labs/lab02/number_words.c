// Program to turn integers from 1-5 into its word form
// Numbers less than 1 will be identified as 'less than'
// Numbers greater than 5 will be identified as 'greater than'
// Written 08/06/20 at 17:16
// by Len Au (z5308653@ad.unsw.edu.au)

#include <stdio.h>

int main (void) {

    //Asking for the integer to be input
    int number; 
    printf ("Please enter an integer: ");
    scanf ("%d\n", &number);
    
    if (number == 1) {
        printf ("You entered one.\n"); 
        return 0;
    } 
    if (number == 2) {
        printf ("You entered two.\n");
        return 0;
    }
    if (number == 3) {
        printf ("You entered three.\n");
        return 0;
    }
    if (number == 4) {
        printf ("You entered four.\n");
        return 0;
    }
    if (number == 5) {
        printf ("You entered five.\n"); 
        return 0;
    }
    if (number < 1) {
        printf ("You entered a number less than one.\n");
        return 0;
    } else {
        printf ("You entered a number greater than five.\n");
        
    }
    return 0;
}
