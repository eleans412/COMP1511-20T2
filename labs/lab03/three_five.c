//Program that reads a positive integer 'n' and prints all positive integers
// < n divisible by 3 or 5 
//These will be printed in ascending order
//Written by Len Au 14/06/20 at 22:49 (z5308653@ad.unsw.edu.au)

#include <stdio.h> 

int main (void) {

    //Ask user to input integer and scan this number
    int users_integer;
    printf ("Enter number: ");
    scanf ("%d", &users_integer);
    
    //Print all positive integers < n divisible by 3 or 5
    int counter = 1;
    while (counter < users_integer) {
        if (counter % 3 == 0 || counter % 5 == 0)
        //Prints integers
        printf ("%d\n", counter);
        //increment counter
        counter++; 
        
    }

    return 0;
}
