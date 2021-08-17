// Program to check whether the number input is positive, negative or zero
// Written 08/06/20 at 14:13 
// by Len Au (z5308653@ad.unsw.edu.au) for COMP1511 lab02 Exercise 1

#include <stdio.h>

int main (void) {
    //Asking user to enter their number, and then scanning the number
    int number; 
    
    scanf ("%d", &number); 
    
    //Check if number is negative or positive
    if (number > 0) { // Positive number 
        printf ("You have entered a positive number.\n");
        return 0;
    }
    
    if (number == 0) { //If zero 
        printf ("You have entered zero. \n"); 
    } else { // Negative number 
        printf ("Don't be so negative! \n");
    }
    
    return 0;
}
