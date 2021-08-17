//Program to read line from input and reads integer n from input
//Write the character at position n and print to terminal

// by Len Au (z5308653)

#include <stdio.h>

#define MAX_CHARACTERS 258

int main (void) {
    int n; 
    char user_input[MAX_CHARACTERS];
    
    //takes characters user inputs into user_input array
    fgets(user_input, MAX_CHARACTERS, stdin);
    //fputs(user_input, stdout);
    
    scanf("%d", &n);
    
    int i = 0;
    while (i < MAX_CHARACTERS) {
        if (i == n) {
            printf(
                "The character in position %d is '%c'\n", 
                n, user_input[i]
                );
            i = MAX_CHARACTERS;
        }
        i++;
    }
    



    return 0;
}
