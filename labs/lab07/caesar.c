//Program reads characters from input and changes output witih ceaser cipher
//Number of positions to shift each letter will be given as first line
//of input.

// by Len Au (z5308653)

#include <stdio.h>


int encrypt(int character, int shift);
int shift_check(int shift, int character); 

int main (void) {
    int shift; 
    
    //how many positions to shift
    scanf("%d", &shift);
    
    
    
    int character = getchar();
    while (character != EOF) {
        //call function to check if shift is negative or too large
        shift = shift_check(shift, character);

    
        int encrypted_char = encrypt(character, shift);
        putchar(encrypted_char);
        
        character = getchar(); 
    }

    return 0; 
}

//returns the character shifted by the specific amount
int encrypt(int character, int shift) {

    int i = 0;   
    
    
    while (i < character) {
        //lower case letters
        if (character >= 'a' && character <= 'z') {
            character = character - 'a';
            character = ('a' + shift) + character;
            if (character > 'z') {
                character = character - 'z' + 'a' - 1;
            }
            return character;
        }
        
        //upper case letters
        if (character >= 'A' && character <= 'Z') {
            character = character - 'A';
            character = ('A' + shift) + character;
            if (character > 'Z') {
                character = character - 'Z' + 'A' - 1;
            }
            return character; 
        }
        
        
        i++; 
    }
    return character;
}

int shift_check(int shift, int character) {

    //if shift is negative
    if (shift < 0) {
    //need to have shifts like -1 = shift of 25
    //fix negative shift
    //need to make sure that it is positive
    //in c -100 = -22, so we add 26 to move up the next modulus
    //modulus has multiple correct numbers and c uses the smallest negative number
    //c preserves the sign when using modulus
            shift = 26 + shift % 26;
            
        //}
        //shift = shift * -1;
        
        //return shift;
    }
      
    //if shift is a massive number
    if (shift > 25) {
        shift = shift % 26;
        //shift = shift % character;
        //shift = character % shift; 
        //return shift; 
    }

    
    return shift; 
}
