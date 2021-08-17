//Program to ask for 2 integers and display the sum of the integers as words
//Applying to numbers between -10 to 10
//Written by Len Au 11/06/20 at 15:23 (z5308653@ad.unsw.edu.au)


//NOT FINISHED, NOT SURE IF THIS EVEN WORKS
#include <stdio.h> 

int main (void) {
    
    //Asks for the integers   
    int first_integer;
    int second_integer;
    printf ("Please enter two integers: ");
    scanf ("%d", &first_integer);
    scanf ("%d", &second_integer);
    // Convert first integer to words
    if (first_integer == 1) {
        int first_integer = "one";
    } else if (first_integer == 2) {
        int first_integer = "two";
    } else if (first_integer == 3) {
        int first_integer = "three";
    } else if (first_integer == 4) {
        int first_integer = "four";
    } else if (first_integer == 5) {
        int first_integer = "five";
    } else if (first_integer == 6) {
        int first_integer = "six";
    } else if (first_integer == 7) {
        int first_integer = "seven";
    } else if (first_integer == 8) {
        int first_integer = "eight";
    } else if (first_integer == 9) {
        int first_integer = "nine";
    } else if (first_integer == 10) {
        int first_integer = "ten";
    } else if (first_integer == -1) {
        int first_integer = "negative one";
    } else if first_integer == -2) {
        int first_integer = "negative two";
    } else if first_integer == -3) {
        int first_integer = "negative three";
    } else if first_integer == -4) {
        int first_integer = "negative four";
    } else if first_integer == -5) {
        int first_integer = "negative five";
    } else if first_integer == -6) {
        int first_integer = "negative six";
    } else if first_integer == -7) {
        int first_integer = "negative seven";
    } else if first_integer == -8) {
        int first_integer = "negative eight";
    } else if first_integer == -9) {
        int first_integer = "negative nine";
    } else if first_integer == -10) {
        int first_integer = "negative ten";
    }
    
    if (second_integer == 1) {
        int second_integer = "one";
    } else if second_integer == 2) {
        int second_integer = "two";
    } else if second_integer == 3) {
        int second_integer = "three";
    } else if second_integer == 4) {
        int second_integer = "four";
    } else if second_integer == 5) {
        int second_integer = "five";
    } else if second_integer == 6) {
        int second_integer = "six";
    } else if second_integer == 7) {
        int second_integer = "seven";
    } else if second_integer == 8) {
        int second_integer = "eight";
    } else if second_integer == 9) {
        int second_integer = "nine";
    } else if second_integer == 10) {
        int second_integer = "ten";
    } else if second_integer == -1) {
        int second_integer = "negative one";
    } else if second_integer == -2) {
        int second_integer = "negative two";
    } else if second_integer == -3) {
        int second_integer = "negative three";
    } else if second_integer == -4) {
        int second_integer = "negative four";
    } else if second_integer == -5) {
        int second_integer = "negative five";
    } else if second_integer == -6) {
        int second_integer = "negative six";
    } else if second_integer == -7) {
        int second_integer = "negative seven";
    } else if second_integer == -8) {
        int second_integer = "negative eight";
    } else if second_integer == -9) {
        int second_integer = "negative nine";
    } else if second_integer == -10) {
        int second_integer = "negative ten";
    }
    int sum = first_integer + second_integer;
     printf ("%d + %d = %d\n", first_integer, second_integer, sum); 
    

    return 0;
}
