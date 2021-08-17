//Program reads characters from input and encrypts with Substitution cipher
//Prints encrypted text to output

//by Len Au (z5308653)

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1024


int encrypt(char alphabet[MAX_SIZE], int message);

int main (void) {
    char alphabet[MAX_SIZE];
    int message; 
    
    //gets alphabet input from user
    fgets(alphabet, MAX_SIZE, stdin);
    
    //message received then call on encrypt to encrypt the message
    message = getchar();
    while (message != EOF) {
        putchar(encrypt(alphabet, message));
        message = getchar();
    }
  
    return 0; 
}

//Takes input and encrypts with substitution cipher
//from the letters list subs letter with the successive letter
//returns character to main
int encrypt(char alphabet[MAX_SIZE], int message) {
    
    //For capital letters
    if (message >= 'A' && message <= 'Z') {
        //removes capital 'A' before replacing with next letter in 
        //the provided alphabet 
        //adds as ASCII values in capitals ascend in value
        return alphabet[message - 'A'] - 'a' + 'A';
    }
    //For lower case letters
    else if (message >= 'a' && message <= 'z') {
        //changes the letter in message to the letter one to the right
        return alphabet[message - 'a'];
    }
    
    return message;
    
}

