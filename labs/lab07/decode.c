//Program decrypts text encrypted by substitution.c

//by Len Au (z5308653)

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1024
#define ALPHABET_SIZE 28


int decrypt(char key[ALPHABET_SIZE], int message);

int main (void) {
    char key[ALPHABET_SIZE];
    int message; 
    
    //gets alphabet input from user
    fgets(key, ALPHABET_SIZE, stdin);
    key[strlen(key) - 1] = '\0';
    //fputs(alphabet, stdout);
    //message received then call on decrypt 
    message = getchar();
    while (message != EOF) {
        putchar(decrypt(key, message));
        message = getchar();
    }


    return 0;
}

//takes encrypted message and decodes using alphabet key provided
//returned decrypted message
int decrypt(char key[ALPHABET_SIZE], int message) {
    int j = 0;
    char lower_case_alphabet[ALPHABET_SIZE] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x' ,'y', 'z'};
    
    char capital_alphabet[ALPHABET_SIZE] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M','N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    
    //for lower case letters
    if (message >= 'a' && message <= 'z') {
        j = 0;
        //loops the whole alphabet, excludes terminator and new line
        while (j < 26) {
            if (message == key[j]) {
                message = lower_case_alphabet[j];
                //exits loop once letter is switched
                j = 26; 
            }
            j++;
        }
    }
    //for Capital letters
    if (message >= 'A' && message <= 'Z') {
        j = 0; 
        //loops the whole alphabet, excludes terminator and new line
        while (j < 26) {
            //Adds to change to lower case letter
            if (message + 32 == key[j]) {
                message = capital_alphabet[j]; 
                //exits loop once letter is switched
                j = 26;
            }
            j++;
        }
    
   }
    return message;
}

