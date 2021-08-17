//Program reads command line arguments then prints them out
//Converts any upper case letters to lower case

//by Len Au (z5308653)

#include <stdio.h>
#include <ctype.h>

#define MAX_PHRASE_SIZE 1024

int main (int argc, char *argv[]) {

    int i = 1;
    int j = 0;
    //int c;
    while (i < argc) {
        j = 0;
        while (argv[i][j] != '\0') {
            argv[i][j] = tolower(argv[i][j]);
            j++;
        }
        printf("%s ", argv[i]);
        
        i++;
    }
    printf("\n");
    return 0; 
}
