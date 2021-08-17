//Program to make a hollow triangle design based on size input by user
//Written by Len Au 15/06/20 at 11:37 (z5308653@ad.unsw.edu.au)

#include <stdio.h>

int main (void) {
    int counter_one;
    int counter_two;
    int size; 
    
    //asks user to input the size
    printf ("Enter size: ");
    scanf ("%d", &size);
    
    //not taking input that is less than 3
    if (size < 3) {//inform that this is an invalid figure for program
        printf (
            "Cannot use values less than 3. Program will terminate now.\n"
            ); 
        return 1;
    }
    
    counter_one = 1;
    while (counter_one <= size) {//outer loop
        counter_two = 1;
        while (counter_two <= size) {//inner loop
            //prints the *, for each row for the whole triangle
            if (//creates the hollow inside of the triangle
                counter_two == 1 || counter_two == counter_one 
                ||counter_one == size
            ) {
                printf ("*"); //prints '*'
            } else {
                printf (" "); //prints the space between '*'
            }
            
            counter_two++;     
        } 
        counter_one++;    
        printf ("\n"); //moves the next line down for next print
    }
    
    return 0;
}
