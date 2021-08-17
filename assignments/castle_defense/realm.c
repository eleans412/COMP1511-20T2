// Assignment 2 20T2 COMP1511: Castle Defense
//
// This program was written by Len Au (z5308653)
// on 20/07/20 - 9/08/20
//
// Realm.c is called by main to create a realm
// User can create the realm and add locations
// User can create enemies within each location struct
// User can create towers which are added to locations
// Enemies advance when 'n' is input into terminal
// Realm.c frees malloc'd memory before ending the program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "realm.h"
///////////////////////////////////////////////////////////////////////

// `struct realm` represents a realm, which represents the state of the
// entire program. It is mainly used to point to a linked list of 
// locations, though you may want to add other fields to it.
//
// You may need to add fields to struct realm.
// Struct with pointers to castle and lair
struct realm {
    struct location *castle;
    struct location *lair;
};

// `struct location` represents a location, which could be a land,
// a tower, or a castle. Each of those places has a different type
// of information that this struct will need to store.
//
// You will need to add fields to struct location.
// Struct with fields name, power, uses, enemy pointer and a next pointer
// for the next location in the realm
struct location {
    char name[MAX_NAME_LENGTH];
    int power;
    int uses;
    struct enemy *enemies;
    struct location *next;

};

// `struct enemy` represents an enemy, which will move through the
// realm (to each location). Towers can deal damage to it, and
// it can deal damage to the Castle.
//
// You will need to add fields to struct enemy.
// Struct with fields name, hp and a next pointer to the next enemy
struct enemy {
    char name[MAX_NAME_LENGTH];
    int hp;
    struct enemy *next;
};

// Add any other structs you define here.

///////////////////////////////////////////////////////////////////////

// Function prototypes for helper functions
static Location new_location(char *name);
static void print_tower(char *name, int power, int uses, Effect effect);
static void print_land(char *name);
static void print_castle(char *name, int defense);
static void print_enemy(char *name, int cur_hp, int max_hp);

// Add prototypes for any extra functions you create here.
static struct enemy *create_enemy (char *name, int hp);
static struct location *create_tower(char *name, int power, int uses);
static void enemy_print(struct enemy *enemy_location);
static struct enemy *enemy_loop(struct location *location_find);
static void destroy_enemy(struct location *free_location);
static int count_enemies(Realm realm);

///////////////////////////////////////////////////////////////////////

// You need to implement the following 9 functions.
// In other words, write code to make the function work as described 
// in realm.h.

// Create a new realm, and return a pointer to it.
// You may need to change this function in later stages.
Realm new_realm(void) {
    struct realm *realm = malloc(sizeof(struct realm));
    realm->castle = new_location("Castle");
    realm->lair = new_location("Lair");

    if (realm->castle != NULL && realm->lair != NULL) {
        realm->castle->next = realm->lair;
    }
    
    return realm;
}


// Return a new location created with malloc.
static Location new_location(char *name) {

    // Creates a pointer to the new_location struct to be created
    struct location *new_location = malloc(sizeof(struct location));
    
    // Copies the input name of the location into the struct
    strcpy(new_location->name, name);
    
    // Fills out the information needed to complete the struct
    // Set power and use to 0 to be set only if location is not land
    new_location->power = 0;
    new_location->uses = 0;
    new_location->next = NULL;
    new_location->enemies = NULL;
    
    // Returns the new_location pointer to realm 
    return new_location;
}
    
////////////////////////////////////////////////////////////////////////
//                         Stage 1 Functions                          //
////////////////////////////////////////////////////////////////////////

// Add a new location to the realm, and return the total locations 
// in the realm.
int add_location(Realm realm, char *name) {

    // Set input_position pointer to equal new_location
    // Input position will be inserted into linked list 
    // before realm->lair
    struct location *input_position = new_location(name);
    
    //Counter for locations in realm
    int num_locations = 0;
    
    //Set "head" pointer to be at the beginning of the linked list 
    struct location *head = realm->castle;
    struct location *current = head;
    
    // Set previous to NULL to be set when inputing new location
    struct location *previous = NULL;
    
    // Current continues looping through the list until tail
    while (current != NULL) {
    
        // If at tail, insert location
        if (current == realm->lair) {
        
            input_position->next = realm->lair;
            previous->next = input_position;
            
            // End while loop
            current = NULL;
            // Add realm->lair for total location count
            num_locations++;
        }
        // Continue looping through the list
        if (current != NULL) {
            previous = current;
            current = current->next;
            
        }
        // Add to num_locations for each location that has been looped
        // through (excluding lair)
        num_locations++;

    }

    // Returns total number of locations in the realm
    return num_locations; 
}

// Print out the realm.
void print_realm(Realm realm) {
    // To loop through the locations
    struct location *head = realm->castle;
    struct location *current = head;
    
    // To loop through the enemy linked list
    struct enemy *enemy_location = current->enemies;
    
    //Print castle first
    if (current == head) {
        print_castle(current->name, STARTING_CASTLE_HP);
        
        // If enemy at castle
        if (enemy_location != NULL) {
            enemy_print(enemy_location);
        }

    }
    // Move to the next location to begin location loop
    current = current->next;

    // Location loop
    while (current != NULL) {
        
        // Moves enemy_location along to the next location
        enemy_location = current->enemies;
        
        // For all other locations
        // If location is land
        if (current->power == 0) {
            print_land(current->name);
            
            // Print if there are enemies
            if (enemy_location != NULL) {
                enemy_print(enemy_location);
            }
            
        }
        // If location is tower
        if (current->power >= 1) {
            print_tower(current->name, current->power, current->uses, 0);
           
            // Print if there are enemies
            if (enemy_location != NULL) {
                enemy_print(enemy_location);
            }

        }

        // Move to the next location in the list
        current = current->next;
    }

}

////////////////////////////////////////////////////////////////////////
//                         Stage 2 Functions                          //
////////////////////////////////////////////////////////////////////////

// Add an enemy to the realm.
int new_enemy(Realm realm, char *location_name, char *name, int hp) {
    
    //If hp < 1, return invalid stat
    if (hp < 1) {
        return ERROR_INVALID_STAT;
    }
    
    //Loop through locations to confirm location name is in realm
    struct location *head = realm->castle;
    struct location *location_find = head;

    while (location_find != NULL) {
        
        //If location name matches location in realm
        if (strcmp(location_find->name, location_name) == 0) {
            //Call create_enemy to create the new enemy
            struct enemy *new_enemy = create_enemy(name, hp);
            
            //Add the enemy to the location
            //If enemies is empty
            if (location_find->enemies == NULL) {
                
                new_enemy->next = location_find->enemies;
                location_find->enemies = new_enemy;
                
                //Enemy has been created and implemented successfully
                return SUCCESS;
            }
            
            // If location has existing enemies
            if (location_find->enemies != NULL) {
                
                // Call enemy loop to move to the tail of enemy list
                struct enemy *current_enemy = enemy_loop(location_find);
                
                // Add new enemy
                new_enemy->next = current_enemy->next;
                current_enemy->next = new_enemy;
                
                //Enemy has been created and implemented successfully
                return SUCCESS;
            }
            // End while loop;
            location_find = NULL;
        }
        // Loop through the location linked list
        location_find = location_find->next;
    }
    
    // If location name is not in realm
    return ERROR_NO_LOCATION;
}


// Add a new tower to the realm.
int new_tower(Realm realm, char *prev_name, char *name, int power, int uses) {
    
    // If power or uses are < 1, return ERROR_INVALID_STAT
    if (power < 1 || uses < 1) {
        return ERROR_INVALID_STAT;
    }
    
    // Loop through the locations in the realm to find 
    // where tower will be inserted
    struct location *head = realm->castle;
    struct location *current = head;
    
    // For all other locations
    while (current != NULL) {
        if (strcmp(current->name, prev_name) == 0) {
            struct location *new_tower = create_tower(name, power, uses);
            
            new_tower->next = current->next;
            current->next = new_tower;
            
            current = NULL;
            return SUCCESS;
        }
        current = current->next;
    }
    return ERROR_NO_LOCATION;
}


////////////////////////////////////////////////////////////////////////
//                         Stage 3 Functions                          //
////////////////////////////////////////////////////////////////////////

// Destroy the realm, and free any associated memory.
void destroy_realm(Realm realm) {
    
    struct location *head = realm->castle;
    struct location *current = head;
    struct location *free_location = NULL;
    
    // Loop through the locations in realm until realm destroyed
    while (current != NULL) {
    
        // Set free_location to current
        free_location = current;
        
        // If there are enemies call destroy_enemy
        if (free_location->enemies) {
            destroy_enemy(free_location);  
        }
        
        // Move to the next location
        current = current->next;
        
        // Free location struct
        free(free_location);
        
    }
    // Free realm once location and enemies have been freed
    free(realm);    
}

// Advance enemies towards the castle.
int advance_enemies(Realm realm) {
    
    struct location *head = realm->castle;
    struct location *current_pos = head;
    struct location *previous_pos = NULL;

    // Counter for enemies passing Castle
    int num_enemies = 0;
    
    // Loop through locations in the realm
    while (current_pos != NULL) {
        
        // If there are enemies at castle
        // Count enemies at Castle and call count_enemies to free enemies
        if (current_pos->enemies != NULL && previous_pos == NULL) {
            num_enemies = count_enemies(realm);
            current_pos->enemies = NULL;
        }
        
        // If there are enemies at current position
        // advance the enemies
        if (current_pos->enemies != NULL) {
            previous_pos->enemies = current_pos->enemies;
            current_pos->enemies = NULL;
        }
        // Loop through the locations in realm
        previous_pos = current_pos;
        current_pos = current_pos->next;
    }
    // Return number of enemies that passed Castle
    return num_enemies;
}

// Apply damage from the enemies at each tower to that tower.
int apply_damage(Realm realm) {
    return 0;
}

////////////////////////////////////////////////////////////////////////
//                         Stage 4 Functions                          //
////////////////////////////////////////////////////////////////////////

// Apply the specified buff to the relevant towers or enemies.
int apply_buff(Realm realm, char *search_term, Buff buff, int amount){
    return 0;
}

////////////////////////////////////////////////////////////////////////
//                         Stage 5 Functions                          //
////////////////////////////////////////////////////////////////////////

// Apply the specified effect to each tower whose name matches the
// specified search term.
int apply_effect(Realm realm, char *search_term, Effect effect) {
    return 0;
}

////////////////////////////////////////////////////////////////////////

// Add definitions for your own functions below.
// Make them static to limit their scope to this file.

// Creates enemy struct
// Fills in the struct fields for enemy 
// Returns pointer to enemy
static struct enemy *create_enemy (char *name, int hp) {
    struct enemy *new_enemy = malloc(sizeof(struct enemy));
    
    //Copy name to enemy name
    strcpy(new_enemy->name, name);
    
    //Enemy next set to NULL
    new_enemy->next = NULL;
   
    //Set enemy HP
    new_enemy->hp = hp;
    
    //Return enemy pointer
    return new_enemy;
}

// Function is called if there is enemies at a location
// Loops through the enemy linked list to print out enemies at location
static void enemy_print(struct enemy *enemy_location) {
    struct enemy *enemy_head = enemy_location;
    struct enemy *current_enemy = enemy_head;
    
    // Loop through and prints all enemies currently at given location
    while (current_enemy != NULL) {
        print_enemy(
            current_enemy->name, current_enemy->hp, 
            current_enemy->hp
        );
        
        // Print next enemy
        current_enemy = current_enemy->next;
    }

}

// Loops to the end of the enemy linked list
// This will return correct input position for new enemies
static struct enemy *enemy_loop(struct location *location_find) {
    
    struct enemy *head_enemy = location_find->enemies;
    struct enemy *current_enemy = head_enemy;
    
    //Loop to get to last enemy in the list
    while (current_enemy->next != NULL) {
        current_enemy = current_enemy->next;
    }
    
    // Return pointer to the end of the enemy list
    return current_enemy;
}

// Creates tower location struct
// Fills the fields for the location struct
// Sets power and use to make location a tower
// Returns a pointer to the tower
static struct location *create_tower(char *name, int power, int uses) {
    
    struct location *new_tower = malloc(sizeof(struct location));
    
    // Input information into new_tower
    strcpy(new_tower->name, name);
    new_tower->power = power;
    new_tower->uses = uses;
    new_tower->enemies = NULL;
    new_tower->next = NULL;

    // Return new_tower pointer
    return new_tower;
}

// Loops through enemy list and frees each enemy in the list
static void destroy_enemy(struct location *free_location) {
   
    struct enemy *head_enemy = free_location->enemies;
    struct enemy *current_enemy = head_enemy;
    struct enemy *free_enemy = NULL;
    
    // Loop through all enemies at given location
    while (current_enemy != NULL) {
       
        
        free_enemy = current_enemy;
        
        // Move to next enemy in the list
        current_enemy = current_enemy->next;
        
        // Free enemy
        free(free_enemy);
    }
}

// Count how many enemies are passing castle
// Frees each enemy added to the count
// Returns total enemies passing castle
static int count_enemies(Realm realm) {
    
    // Count how many enemies have passed
    struct enemy *head = realm->castle->enemies;
    struct enemy *current = head;
    struct enemy *previous = NULL;
    
    // Counter for number of enemies at this location
    int enemy_count = 0;
    
    // Loop through the enemies in the list
    while (current != NULL) {
        enemy_count++;
        previous = current;               
        current = current->next;
        free(previous);
    }
    
    return enemy_count;
}

////////////////////////////////////////////////////////////////////////
//                    Provided print functions                        //
//         NOTE: YOU SHOULD NOT MODIFY THE FOLLOWING FUNCTIONS        //
////////////////////////////////////////////////////////////////////////

void print_tower(char *name, int power, int uses, int effect) {
    printf(" ^ %32s [pow: %3d | uses: %3d]", name, power, uses);
    if (effect == EFFECT_NONE) printf(" {%c}", EFFECT_NONE_CHAR);
    if (effect == EFFECT_PORTAL) printf(" {%c}", EFFECT_PORTAL_CHAR);
    if (effect == EFFECT_ICE) printf(" {%c}", EFFECT_ICE_CHAR);
    printf("\n");
}

void print_land(char *name) {
    printf(" ^ %32s [____________________]\n", name);
}

void print_castle(char *name, int defense) {
    printf(" ^ %32s [Castle Defenses: %3d]\n", name, defense);
}

void print_enemy(char *name, int cur_hp, int max_hp) {
    printf(" ^ %40s [hp: %d/%d]\n", name, cur_hp, max_hp);
}

////////////////////////////////////////////////////////////////////////
//               End of provided print functions                      //
////////////////////////////////////////////////////////////////////////




