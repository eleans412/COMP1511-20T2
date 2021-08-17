//Program that reads integer from 'n' from standard input
//Scans in 'n' integers from standard input
//Adds integers together and prints sum
// by Len Au 25/06/20 (z5308653@ad.unsw.edu.au)

#include <stdio.h>

int main (void) {

    int n_integers;
    //Ask user for 'n'
    printf ("How many numbers: ");
    scanf ("%d", &n_integers);
    if (n_integers < 0) {
        return 1;
    } //Scan 'n' integers from standard input
    int i = 0;
    int input_value;
    int sum = 0;
    while (i < n_integers) {
        scanf ("%d", &input_value);
        sum = sum + input_value;
        i++;
    }
    //Add sum of integers together
    //Print sum
    
    printf ("The sum is: %d\n", sum);
    
    return 0;
}
