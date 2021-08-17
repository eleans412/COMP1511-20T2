//Program reads characters from input and converts the case of the letters
//to the opposite of which they were input
//prints converted input back to the terminal

//by Len Au (z5308653)

#include <stdio.h>

int swap_case(int character);

int main (void) {
    //getchar loops until EOF
    int character = getchar();
    
    while (character != EOF) {
        
        int changed_char = swap_case(character);
        putchar(changed_char);
        
        character = getchar();
    }

    return 0;
}

//returns the character to lower case if upper case letter
//returns the character in upper case if lower case letter
//returns the character unchanged otherwise
int swap_case(int character) {
    
    //make upper case
    if (character >= 'a' && character <= 'z') {
        int make_upper_case = character - 'a';
        return 'A' + make_upper_case; 
    }
    
    
    //make lower case
    if (character >= 'A' && character <= 'Z') {
        int make_lower_case = character - 'A';
        return 'a' + make_lower_case;
    }
    
    return character;
}
