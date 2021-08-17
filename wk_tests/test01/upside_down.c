//Program to read 3 numbers and indicate whether they are increasing or decreasing

//Written by Len Au 19/06/20 (z5308652@unsw.edu.au)

#include <stdio.h>

int main (void) {
    
    double num_one;
    double num_two;
    double num_three;
    
    //reads the numbers
    printf ("Please enter three numbers: ");
    scanf ("%lf", &num_one);
    scanf ("%lf", &num_two);
    scanf ("%lf", &num_three);
    
    //if strictly increasing
    if (
        num_one < num_two && num_two < num_three && num_one < num_three
    ) {
        printf ("up\n");
        return 0;
      
    } //if strictly decreasing
    else if (num_one > num_two && num_two > num_three) {
        printf ("down\n");
    }
    // neither
    else {
        printf ("neither\n");
    }
    
    return 0;
}
