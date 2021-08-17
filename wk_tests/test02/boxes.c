//Prpgram reads in a number and draws that many square boxes 
//Drawn using the integer 1

//Written by Len Au 26/06/20 (z5308653@ad.unsw.edu.au)
//unable to complete within time


// edited - below is the test solution 13-08-2020
// previous attempt has been commented out
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50

int main (void) {


    printf("How many boxes: ");
    int numBoxes;
    if (scanf("%d", &numBoxes) != 1) {
        printf("Unable to read number");
        exit(0);
    }

    // Each box has a gap in the middle
    // so the width & height are
    int size = numBoxes * 4 - 1;

    int y = 0;
    while (y < size) {

        // Vertical loop
        int x = 0;
        while (x < size) {
            int xInverse = (size - 1) - x;
            int yInverse = (size - 1) - y;

            if ((y == x) || (y == xInverse)) {
                // On diagonals
                if (y % 2 == 0) {
                    printf("1");
                } else {
                    printf("0");
                }
            } else if ((y > x) && (y < xInverse) && (x % 2 == 0)) {
                // left side
                printf("1");
            } else if ((y < x) && (y > xInverse) && (x % 2 == 0)) {
                // right side
                printf("1");
            } else if ((x > y) && (x < yInverse) && (y % 2 == 0)) {
                // top side
                printf("1");
            } else if ((x < y) && (x > yInverse) && (y % 2 == 0)) {
                // bottom side
                printf("1");
            } else {
                printf("0");
            }
            x = x + 1;
        }

        printf("\n");
        y = y + 1;
    }
    /*int num_boxes; 
    //int box[MAX_SIZE][MAX_SIZE] = {0};
    
    //Read user number
    printf ("How many boxes: ");
    scanf ("%d", &num_boxes);
    //Change array grid to 1 to create boxes
    int row = 0;
    int col = 0;
    int box_length = num_boxes + 2;
    //box[row][col] = 1;
    //row++;
    //col++;

    

    
    while (row < box_length) {
        while (col < box_length) {
            //box[row][col] = 1;
            if (row + col >= 0) {
                printf ("1");
            }
            
            //if (row % col == 0 && row > 0 && col > 0) {
                //printf ("1");
            //}
            else {
                printf ("0");
            }
            col++;
           } 
             
        }row++;
        printf ("\n");
        
        //if (row == col) {
            //printf ("1");
        //}
        //else {
            //printf ("0");
        //}
        
        
        
    //}
    //printf ("%d", box[box_length][box_length]);
*/
    return 0;
}
