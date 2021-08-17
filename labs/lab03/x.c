//Program that reads an integer 'n' and prints 'n x n' pattern of astrisks
//and dashes in the shape of an "X"
//Written by Len Au 15/06/20 at 10:42 (z5308653@ad.unsw.edu.au)

#include <stdio.h>

int main (void) {
   
    int size;    
    //Asks user to input n value
    printf ("Enter size: ");
    scanf ("%d", &size);
    //Set up for the X design
    int xcounter = 0;
    int xseparator = 0;
    while (size % 2 == 0) {//only odd numbers permitted
        return 1;
    }
    
    while (xcounter < size) {
        xseparator = 0;
        while (xseparator < size) {
            if (
                xseparator == xcounter || xcounter == (size - 1)
                - xseparator
                ) {
                printf ("*");
            }
            else {
                printf ("-");
            }//increment counter 
            xseparator++;
        }
        printf ("\n"); //spacing shown on lab activity
        //increment counter
        xcounter++;
    }

    return 0;
}
