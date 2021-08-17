// COMP1511 Week 7 Test: Interject
//
// This program was written by Len Au (z5308653)
// on 17/06/20
//
// This program adds interjections to strings.

#include <stdio.h>
#include <string.h>


#define MAX_SIZE 1002

// Modify str so that it contains interject at the given index.
void interject(char *str, char *interject, int index) {
    // Copy string into a new string to account for interject   
    char copy_str[MAX_SIZE];
    
    // Coppy from the point of insertion to save the characters
    // that were previously there, if any
    int i = index;

    // Loop until index
    // Copy what was in the initial string
    while (str[i] != '\0') {
        copy_str[i - index] = str[i];
        i++;
    }
    // So we can mark where this string has been stopped
    // Null terminator at the end of this first string section
    copy_str[i - index] = '\0';

    // Loop to insert interject string
    i = index;

    // i - index as we were copying the string from the index position
    // This gives the position we want to insert from
    while (interject[i - index] != '\0') {
        str[i] = interject[i - index];
        i++;
    }
    // Ensure there is a null terminator at the end of the string
    // Paste the copied letters back into the string
    int save_i = 0;
    while (copy_str[save_i]) {
        str[i] = copy_str[save_i];
        i++;
        save_i++;
    }
    str[i] = '\0';
}


// This is a simple main function that you can use to test your interject
// function.
// It will not be marked - only your interject function will be marked.
//
// Note: the autotest does not call this main function!
// It calls your interject function directly.
// Any changes that you make to this function will not affect the autotests.

int main(void) {
    char str1[MAX_SIZE] = "Comp Science";
    printf("%s -> ", str1);
    interject(str1, "uter", 4);
    printf("%s\n", str1);

    char str2[MAX_SIZE] = "Beginnings";
    printf("%s -> ", str2);
    interject(str2, "New ", 0);
    printf("%s\n", str2);

    char str3[MAX_SIZE] = "The End!";
    printf("%s -> ", str3);
    interject(str3, " Is Nigh", 7);
    printf("%s\n", str3);

    char str4[MAX_SIZE] = "UNSW Other Unis";
    printf("%s -> ", str4);
    interject(str4, "> ", 5);
    printf("%s\n", str4);

    return 0;
}
