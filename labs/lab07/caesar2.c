//Program reads characters from input and changes output witih ceaser cipher
//Number of positions to shift each letter will be given as first line
//of input.

// by Len Au (z5308653)

#include <stdio.h>

int encrypt(int character, int shift);

int main (void) {
    int shift; 
    
    //how many positions to shift
    scanf("%d", &shift);

    
    int character = getchar();
    while (character != EOF) {
        
        int encrypted_char = encrypt(character, shift);
        putchar(encrypted_char);
        
        character = getchar(); 
    }

    return 0; 
}

int encrypt(int character, int shift) {

}
