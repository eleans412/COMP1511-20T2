//Program that reads 3 integers adn prints them from smallest to largest
//Written by Len Au 14/06/20 at 21:40 (z5308653@ad.unsw.edu.au)

#include <stdio.h>

int main (void) {

    //asking and reading the integers input by the user
    int first_number;
    int second_number;
    int third_number;
    
    printf ("Enter integer: ");
    scanf ("%d", &first_number);
    printf("Enter integer: ");
    scanf ("%d", &second_number);
    printf ("Enter integer: ");
    scanf ("%d", &third_number);

    //if first number is lowest, and second number is 2nd lowest
    
    if (
        first_number < second_number && first_number < third_number 
        && second_number < third_number
    ) {
        printf (
            "The integers in order are: %d %d %d\n", first_number,
            second_number, third_number
        );
        
        return 0;
    } else if (
        first_number < second_number && first_number < third_number 
        && third_number <  second_number
        ) { //if first number is lowest and third number is 2nd lowest
        printf (
            "The integers in order are: %d %d %d\n", 
            first_number, third_number, second_number
            );
        
        return 0;
    } else if (//if second number is lowest and first number is 2nd lowest
        second_number < first_number && second_number < third_number 
        && first_number < third_number
        ) { 
        printf (
         "The integers in order are: %d %d %d\n", 
         second_number, first_number, third_number
        );
        return 0;
    } else if (// if second number is lowest and third number is 2nd lowest
        second_number < first_number 
        && second_number < third_number 
        && third_number < first_number
    ) {
        printf (
            "The integers in order are: %d %d %d\n", 
            second_number, third_number, first_number
        );
        return 0;
    } else if (//if third number is lowest and first number is 2nd lowest
        third_number < first_number && 
        third_number < second_number
        && first_number < second_number
    ) {
        printf (
            "The integers in order are: %d %d %d\n", 
            third_number, first_number, second_number
        );
        return 0;
    } else if (//if third number is lowest and second number is 2nd lowest
        third_number < first_number && third_number < second_number
        && second_number < first_number
    ) {
        printf (
            "The integers in order are: %d %d %d\n", 
            third_number, second_number, first_number
        );
        return 0;
    } else if (// if numbers are all the same
        first_number == second_number && second_number == third_number
        && third_number == first_number
    ) {
        printf (
            "The integers in order are: %d %d %d\n",
            first_number, second_number, third_number
            );
        return 0;
    } else if (//if first and second number are the same 
                //and lower than third
    first_number == second_number && third_number > first_number
        && third_number > second_number
    ) {
        printf (
            "The integers in order are: %d %d %d\n",
            first_number, second_number, third_number
        );
        return 0;
    } else if (//if first and second same and higher than third
        first_number == second_number && third_number < first_number
        && third_number < second_number
    ) {
        printf (
            "The integers in order are: %d %d %d\n", 
            third_number, first_number, second_number
        );
        return 0;//if first and third same and lower than second
    } else if (
        first_number == third_number && second_number > first_number
        &&second_number > third_number
        ) {
        printf (
        "The integers in order are: %d %d %d\n", 
        first_number, third_number, second_number
        );
        return 0;
    } else if (//if first and third same and higher than second
        first_number == third_number && second_number < first_number
        && second_number < third_number
    ) {
        printf (
            "The integers in order are: %d %d %d\n",
            second_number, first_number, third_number
        );
        return 0;
    }
    
    return 0;
}
