//Program to test different patterns with while loops
//Written by Len Au 18/06/2020 at 14:18 (z5308653@ad.unsw.edu.au)

#include <stdio.h> 

int main (void) {
    
    int input; 
    int row = 0;
    int column = 0;

    printf ("Enter input: ");
    scanf ("%d", &input);
    
    while (column < input) {//outer while for the column
        row = 0;
        while (row < input) {//this will result in a row 
            
            if (row + column >= input - 1) {//test with 5, (4,0) (2,2) (1,3), etc - all give the number 4
            
                printf ("*");
              
            } else {
                printf ("-");
            
            }
            
            row++;
            
        }
        
        printf ("\n");
        column++;   
    }
    
    return 0;
}
