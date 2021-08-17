// Assignment 2 20T2 COMP1511: Castle Defense
//
// This program was written by Len Au (z5308653)
// on 20/07/20 - 9/08/20
//
// Version 1.0.0 (2020-07-20): Assignment released.
// Version 1.0.1 (2020-07-21): Add return value to main.
// Version 1.1.0 (2020-07-23): Add test_apply_buff to main.

// Program tests the add_location function in realm.c
// Program tests the print_realm function in realm.c
// Program tests the new_enemy function in realm.c
// Program tests the new_tower function in realm.c
// Program tests the apply_damage function in realm.c

#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "realm.h"
#include "test_realm.h"
#include "capture.h"

#define ADDED_LOCATION " ^                          Cession [____________________]\n ^                             Lair [____________________]\n"

#define DESTROY_ENEMY_TEST " ^                             Eden [pow:   5 | uses:   2] {n}\n ^                             Lair [____________________]\n"

#define TOWER_TO_LAND " ^                     Titans_Tower [____________________]\n ^                             Lair [____________________]\n"

////////////////////////////////////////////////////////////////////
//                        Function Protoypes                      //
////////////////////////////////////////////////////////////////////

// TODO: Add your own prototypes here, if necessary.

////////////////////////////////////////////////////////////////////
//                         Helper Functions                       //
////////////////////////////////////////////////////////////////////

// Find the string 'needle' in 'haystack'
int string_contains(char *haystack, char *needle) {
    return strstr(haystack, needle) != NULL;
}

// NOTE: You should not declare any structs from realm.c here.
// Declaring structs from realm.c in this function is against the
// rules of the assignment. 

// Main function: this function will not be used in testing, you do not
// need to change it.
// If you want to write your own tests, add them in `extra_tests`.
int main(int argc, char *argv[]) {
    printf("\n================== Castle Defense Tests ==================\n");

    test_add_location();
    test_print_realm();
    test_new_enemy();
    test_new_tower();
    test_apply_damage();
    test_apply_buff();
    extra_tests();

    return 0;
}

// NOTE: These tests are explained in `test_realm.h`

void test_add_location(void) {
    printf("Test whether this add_location follows the spec: ");

    // Test 1: Does add_location's return value count the Castle & Lair?

    Realm test_realm = new_realm();

    int num_locations = add_location(test_realm, "Location");
    if (num_locations != 3) {
        printf(DOES_NOT_FOLLOW_SPEC);
        // since we don't want to print FOLLOWS_SPEC at the end,
        // we just return to the main function here.
        return;
    }

    // Test 2: Does add_location return the correct amount for multiple locations?
    //Create new test_realm to test multiple locations
    Realm test_realm2 = new_realm();
    
    int num_places = 0;

    num_places = add_location(test_realm2, "Salineas");
    num_places = add_location(test_realm2, "Etheria");
    num_places = add_location(test_realm2, "Thaymor");
    num_places = add_location(test_realm2, "Fright_Zone");
    num_places = add_location(test_realm2, "Arxia");
    num_places = add_location(test_realm2, "Brightmoon");
    

    if (num_places != 8) {
        printf(DOES_NOT_FOLLOW_SPEC);
        return;
    }
    
    //Test 3: Does add_location return correct value for 2 locations?
    
    //Tests how whether add_location is inserted in the correct location

    
    //Create new test_realm to test these locations
    Realm test_realm3 = new_realm();
    
    int some_locations = 0;
    
    some_locations = add_location(test_realm3, "Cession");
    
    char print_text[10000];
    CAPTURE(print_realm(test_realm3), print_text, 10000);
    
    if (!string_contains(print_text, ADDED_LOCATION)) {
        printf(DOES_NOT_FOLLOW_SPEC);
        return;
    }

    printf(FOLLOWS_SPEC);
}

void test_print_realm(void) {
    printf("Test whether this print_realm follows the spec: ");

    // Test 1: Does print_realm show the Castle?

    Realm test_realm = new_realm();

    char print_text[10000];
    CAPTURE(print_realm(test_realm), print_text, 10000);

    if (!string_contains(print_text, "Castle")) {
        printf(DOES_NOT_FOLLOW_SPEC);
        // since we don't want to print FOLLOWS_SPEC at the end,
        // we just return to the main function here.
        return;
    }

    // Test 2: Does print_realm show the correct HP of the castle?

    if (!string_contains(print_text, "100")) {
        printf(DOES_NOT_FOLLOW_SPEC);
        return;
    }

    // Test 3: Does print_realm show the added location? 

    Realm test_realm2 = new_realm();
    
    int new_location = add_location(test_realm2, "Earp_Ranch");
    
    CAPTURE(print_realm(test_realm2), print_text, 10000);
    
    // Set variable to 0 as new_location is no longer being used
    new_location = 0;
    
    // Read output from terminal
    // If new location is not printed, print_realm fails to print
    // added location
    if (!string_contains(print_text, "Earp_Ranch")) {
        printf(DOES_NOT_FOLLOW_SPEC);
        return;
    }
    
    
    
    printf(FOLLOWS_SPEC);
}

// Stage 2

void test_new_enemy(void) {
    printf("Test whether this new_enemy follows the spec: ");

    Realm test_realm = new_realm();

    // Test 1: Does new_enemy work if you're adding to the Lair?
    
    // New_enemy returns SUCCESS (0) when enemy is added
    int enemy_check = new_enemy(test_realm, "Lair", "Viren", 10);
    
    // If enemy_check != SUCCESS, new_enemy fails
    if (enemy_check != SUCCESS) {
        printf(DOES_NOT_FOLLOW_SPEC);
        return;
    }


    
    // Test 2: Does new_enemy work if hp < 1?
    Realm test_realm2 = new_realm();
    
    // New_enemy should not run for values below 1
    
    int enemy_hp_check = new_enemy(test_realm2, "Lair", "Ozai", -100);

    if (enemy_hp_check == SUCCESS) {
        printf(DOES_NOT_FOLLOW_SPEC);
        return;
    }
    
    //Test 3: Does new_enemy work with a location not in the realm?
    Realm test_realm3 = new_realm();
    // New_enemy should only add to existing locations
    
    int enemy_invalid_location = new_enemy(
        test_realm3, "Apocalypse", "Darkseid", 4
        );
    if (enemy_invalid_location == SUCCESS) {
        printf(DOES_NOT_FOLLOW_SPEC);
        return;
    }
    
    printf(FOLLOWS_SPEC);
}

void test_new_tower(void) {
    printf("Test whether this new_tower follows the spec: ");

    
    // Test 1: Does new_tower work if you're adding after another tower?
    Realm test_realm = new_realm();
    //Success == 0, will return 0 if adding multiple towers is a success
    int add_tower = -1;
    
    add_tower = new_tower(test_realm, "Castle", "Watchtower", 4, 8);
    add_tower = new_tower(test_realm, "Watchtower", "Olympus", 10, 2);
    
    if (add_tower != SUCCESS) {
        printf(DOES_NOT_FOLLOW_SPEC);
        return;
    }
    // Test 2: Does new tower work if power or use is less than 1?
    
    Realm test_realm2 = new_realm();
    
    // Input use less than 1, new tower should not run 
    int negative_power_check = -1;
    
    negative_power_check = new_tower(test_realm2, "Castle", "Hexide", 2, -5);
    
    if (negative_power_check == SUCCESS) {
        printf(DOES_NOT_FOLLOW_SPEC);
        return;
    }
    
    printf(FOLLOWS_SPEC);
}

// Stage 3 (2 marks)

void test_apply_damage(void) {
    printf("Test whether this apply_damage follows the spec: ");

    // Test 1: Does apply_damage actually destroy enemies?
    Realm test_realm = new_realm();
    int damage_enemy;
    
    int create_tower = new_tower(test_realm, "Castle", "Eden", 5, 3);
    
    int create_enemy = new_enemy(test_realm, "Eden", "Flyk", 2);
    
    damage_enemy = apply_damage(test_realm);

    char print_text[10000];
    CAPTURE(print_realm(test_realm), print_text, 10000);
    
    // Checks if enemy is removed from the realm after destroyed
    if (!string_contains(print_text, DESTROY_ENEMY_TEST)) {
        create_tower = 0;
        create_enemy = 0;
        printf(DOES_NOT_FOLLOW_SPEC);
        return;
    }


    // Test 2: Does apply_damage convert tower to land?
    Realm test_realm2 = new_realm();
    int attack_enemy;
    
    int add_tower = new_tower(test_realm2, "Castle", "Titans_Tower", 5, 1);
    int low_hp_enemy = new_enemy(test_realm2, "Titans_Tower", "Slade", 3);
    
    attack_enemy = apply_damage(test_realm2);
    
    CAPTURE(print_realm(test_realm2), print_text, 10000);
    
    if (!string_contains(print_text, TOWER_TO_LAND)) {
        add_tower = 0;
        low_hp_enemy = 0;
        printf(DOES_NOT_FOLLOW_SPEC);
        return;
    }

    printf(FOLLOWS_SPEC);
}

// Stage 4 (1 marks)

void test_apply_buff(void) {
    printf("Test whether this apply_buff follows the spec: ");
    // Test 1: Add your own test, and explain it below:
    // ........

    // TODO: Change Here

    // Test 2: Add your own test, and explain it below:
    // ........

    // TODO: Change Here

    printf(FOLLOWS_SPEC);
}

// Extra Tests (not worth marks, but fun!)

void extra_tests(void) {
    // TODO: add extra tests, if you'd like to.
}
