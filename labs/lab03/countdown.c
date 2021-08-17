//Program that uses a loop to print numbers in ascending order
//Written by Len Au 14/06/20 at 22:43 (z5308653@ad.unsw.edu.au)

#include <stdio.h>

int main (void) {
    //initialise counter to 10
    int counter = 10; 
    // loop until not <= 10
    while (counter >= 0) { // Have printed all numbers between 0 and counter
        // print counter
        printf("%d\n", counter);
        // increment counter
        counter = counter - 1; 
    } // counter == 10

    return 0;
}
