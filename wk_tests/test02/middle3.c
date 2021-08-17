//Program that reads 3 integers and prints the middle integer
// by Len Au 25/06/20 (z5308653@ad.unsw.edu.au)

#include <stdio.h>

int main (void) {

    int num_one;
    int num_two;
    int num_three;    
    
    //User inputs integers
    printf ("Enter integer: ");
    
    printf ("Enter integer: ");
    
    printf ("Enter integer: ");
   
    //Scans integers inputs
    scanf ("%d", &num_one);
    scanf ("%d", &num_two);
    scanf ("%d", &num_three);
    
    //Reads through integers to find which is the middle integers
    //Prints middle integer
    if (num_one < num_two && num_two < num_three) {//num_two is middle
        printf ("Middle: %d\n", num_two);
    }
    if (num_three < num_two && num_two < num_one) {
        printf ("Middle: %d\n", num_two);
    }
    //num_one is middle
    if (num_two < num_one && num_one < num_three) {
        printf ("Middle: %d\n", num_one);
    }
    if (num_three < num_one && num_one < num_two) {
        printf ("Middle: %d\n", num_one);
    }
    //num_three is middle
    if (num_one < num_three && num_three < num_two) {
        printf ("Middle: %d\n", num_three);
    }
    if (num_two < num_three && num_three < num_one) {
        printf ("Middle: %d\n", num_three);
    }
    //if all numbers the same
    if (num_one == num_two && num_one == num_three) {
        printf ("Middle: %d\n", num_one);
    }
    //if two numbers the same
    if (num_one == num_two && num_three < num_two) {
        printf ("Middle: %d\n", num_two);
    }
    if (num_one == num_three && num_two < num_three) {
        printf ("Middle: %d\n", num_three);
    }
    if (num_two == num_three && num_one < num_three) {
        printf ("Middle: %d\n", num_three);
    }
    if (num_one == num_two && num_three > num_two) {
        printf ("Middle: %d\n", num_two);
    }
    if (num_one == num_three && num_two > num_three) {
        printf ("Middle: %d\n", num_three);
    }
    if (num_two == num_three && num_one > num_two) {
        printf ("Middle: %d\n", num_two);
    }   
    
    
    
    return 0;
}
