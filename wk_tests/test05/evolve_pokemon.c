// Functions create pokemon then print their evolutions

// by Len Au (z5308653) - edited and working on 13-08-2020

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_SIZE 50

// Do not edit this struct. You may use it exactly as it is
// but you cannot make changes to it
struct pokemon {
    char name[MAX_NAME_SIZE];
    struct pokemon *evolution;
};

// Create a pokemon 
struct pokemon *create_pokemon(char name[MAX_NAME_SIZE]) {
    // PUT YOUR CODE HERE (you must change the next line!)
    struct pokemon *p = malloc(sizeof(struct pokemon));
    strcpy(p->name, name);
    p->evolution = NULL;
    return p;
}

// Link a pokemon to another that it evolves into
void evolve_pokemon(struct pokemon *base, struct pokemon *evolution) {
    // This is just asking to link 2 structs together
    
    struct pokemon *current = base;
    struct pokemon *next = evolution;
    
    next->evolution = current->evolution;
    current->evolution = next;
    
   
    
}

// Print out the evolution of a pokemon
void print_evolution(struct pokemon *p) {
    struct pokemon *current = p;

    
    while (current != NULL) {
        fputs(current->name, stdout);
        printf("\n");
        current = current->evolution;
    }
}

// This is a simple main function which could be used
// to test your pokemon functions.
// It will not be marked.
// Only your pokemon functions will be marked.

int main(void) {
    struct pokemon *pikachu = create_pokemon("Pikachu");
    struct pokemon *raichu = create_pokemon("Raichu");
    evolve_pokemon(pikachu, raichu);
    print_evolution(pikachu);
    return 0;
}
