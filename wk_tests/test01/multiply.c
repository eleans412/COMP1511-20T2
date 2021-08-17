//Program to read 2 integers and prints their absolute multiple
//If the absolute value is zero, prints the word 'zero'
//Written by Len Au 19/06/20 (z5308652@unsw.edu.au)

#include <stdio.h>

int main (void) {
    
    int multiple1;
    int multiple2;
    
    
    //reads the input numbers
    scanf ("%d", &multiple1);
    scanf ("%d", &multiple2);
    
    int total = multiple1 * multiple2;
    //if number is zero, print 'zero
    if (total == 0) {
        printf ("zero\n");
        return 0;
    }
    //if multiple gives negative result
    else if (total < 0){
        printf ("%d\n", total * -1);
        return 0;
    } //multiply figures together
    else {
        printf ("%d\n", total);
    }
    return 0;
}
