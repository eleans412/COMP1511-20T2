//Program that scans in commands until EOF 
//Prints output 
//Written by Len Au 21/06/20 at 10:30 (z5308653@ad.unsw.edu.au)


#include <stdio.h>
#include <stdlib.h> 
#include <math.h> 

int main (void) {
    int user_num[3] = {0};
    
    printf ("Enter instruction: ");
    int result = scanf ("%d", &user_num[0]);
    //scan users numbers
    //scans initial command
    
    while (result == 1) {
         
        //if instruction is 1, only take 2 inputs
        //if first number in command is 1
        if (user_num[0] == 1) {
            scanf ("%d", &user_num[1]);
            user_num[2] = 0;
            int squared_num = user_num[1] * user_num[1];
            printf ("%d\n", squared_num);

        }
        //if first number in command is 2
        else if (user_num [0] == 2) {
            scanf("%d", &user_num[1]);
            scanf ("%d", &user_num[2]);
            int raised_num = pow(user_num[1], user_num[2]);
            printf ("%d\n", raised_num);

        }
       

        printf ("Enter instruction: ");
        result = scanf ("%d", &user_num[0]);
    } 
        
    return 0; 
}
