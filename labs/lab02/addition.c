// Program to add two integers input by the user together
// Written 08/06/20 15:00
// by Len Au (z5308653@ad.unsw.edu.au)

#include <stdio.h>

int main (void) {

    //Ask user to input 2 figures
    int integer_one, integer_two;
    #define SUM = integer_one + integer_two
    
    printf ("Please enter two integers: "); 
    scanf ("%d", &integer_one);
    scanf ("%d", &integer_two);  
    
    //Display integers and sum
    int sum = integer_one + integer_two;
    printf ("%d + %d = %d\n", integer_one, integer_two, sum); 
    
    
    return 0;
}
