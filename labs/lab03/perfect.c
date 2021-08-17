//Program that reads a positive integer 'n' from standard input 
//Prints factors of n, their sum and indiates where 'n' is a perfect number
//Written by Len Au 15/06/20 at 10:09 (z5308653@ad.unsw.edu.au)

#include <stdio.h>

int main (void) {
    
    //Take user's number
    int perfect_number;
    printf ("Enter number: ");
    scanf ("%d", &perfect_number);
    
    //Count and print factors of 'n'
    int counter_main = 1;
    int total = 0; //why do we do this?
    int perfect_check = 0; 
    printf ("The factors of %d are: \n", perfect_number);
    while (counter_main <= perfect_number) {
        if (perfect_number % counter_main == 0) {
            //prints the factors
            printf ("%d\n", counter_main);      
            total = total + counter_main;  
            if (perfect_number != counter_main) {   
                perfect_check = perfect_check + counter_main;              
            }  
        }
        //increment counter
        counter_main++;           
    
    
    } 
    printf ("Sum of factors = %d\n", total);
    if (perfect_check == perfect_number) {
        printf ("%d is a perfect number\n", perfect_number);
        return 0;
    } else {
        printf ("%d is not a perfect number\n", perfect_number);
    }
    
    return 0;
    
}
    
