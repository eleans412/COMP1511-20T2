#include <stdio.h>

int main (void) {
    int c;
    
    c = getchar();
    while (c != EOF) {
        //ignores what is a vowel and prints that to screen
        if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u') {
            putchar(c);
        }
        
        c = getchar();
    
    }
    
    return 0; 
}
