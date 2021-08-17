//Program to read the sides on a set of dice and how many of them are being rolled
//Program will output the range of possible totals that these dice can produce
//Written by Len Au 11/06/20 at 14:17 (z5308653@ad.unsw.edu.au)

#include <stdio.h>

int main (void) {

    int dice_sides;
    int dice_rolled;
    
    //Collects how many sides on the die
    printf ("Enter the number of sides on your dice: ");
    scanf ("%d", &dice_sides);
        
    //Collects how many dice are being rolled
    printf ("Enter the number of dice being rolled: ");
    scanf ("%d", &dice_rolled);
    
       //If user gives negative values
    if (dice_sides < 1 || dice_rolled < 1) { 
        printf ("These dice will not produce a range.\n");
        return 1;
    }
    //If user gives value as 0
    if (dice_rolled == 0 || dice_sides == 0) {
        printf ("These dice will not produce a range.\n");
    return 1;
    }

    //Gives the dice range
    double dice_range_max = dice_rolled * dice_sides;
    int dice_range_min = dice_rolled;
    printf ("Your dice range is %d to %.0lf.\n", dice_range_min, dice_range_max);
    
    //Gives average value of dice rolls
    double average_value = (dice_range_max + dice_range_min) / 2;
    printf ("The average value is %lf \n", average_value); 
    return 0;
}
