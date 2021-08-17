# Castle Defense
Attention brave and noble engineers! Castle CSE is under attack by Enemies from Frankie the Fox's Lair. Queen Chicken, First of Her Name, Protector of the Realm, Lecturer in Charge for COMP1511, has commissioned you to build Her defenses and protect Her Castle.

In this assignment, you will be implementing Castle Defense, a program that simulates an imaginary Realm that is under attack. You will be creating Lands in the Realm as well as building Towers to defend a Castle.

The Enemies will spawn from their Lair and move towards the Castle through the Lands. As the Enemies move, they will be attacked by the towers, which both harms the Enemies and depletes the towers. If the Enemies reach the Castle, they will damage it.

Your program will be managing Enemy movement as they pass through the Lands. It will also be managing the use of Towers against the Enemies and any damage the Castle receives.

Note: If this assignment appears daunting, fear not! The Queen's chosen human (Marc in lectures) will be demonstrating many of the techniques necessary to begin your tasks. Her loyal subjects (the Tutors) will also be teaching some of the techniques in detail in Labs. During Week 8, a great deal of the course will be dedicated to helping you get started with this assignment.

## The Realm
The realm is a struct that contains all of the objects that will be used in this assignment. Those are: Lands, The Lair, The Castle, Towers and Enemies. Your job is to manage the Realm, and everything it contains.

The Realm struct has a pointer to the Castle, whence Queen Chicken and her Loyal subjects look down upon their kingdom. It also has a pointer to the lair, from which Frankie the Fox sends his feindish Enemies. Every location in the Realm lies on a linked list that starts at The Castle, and goes down to The Lair. Locations can have one of four types:

Castle: The Castle, which is always the first node in the linked list. If the Enemies can reach The Castle, they will deal damage to it.
Land: A place where Enemies can gather.
Tower: A defense, built by you, to attack Enemies
Lair: The place from which Enemies are sent by Frankie
Your code should ensure that at the start of the program, the Castle points to the Lair, and the Lair points to NULL. Your code should then ensure that the Castle is always connected (through other locations) to the Lair; and that the Lair points to NULL.

To ensure this is true, you will never be given a test case where you are asked to put a tower after the Lair. (More details on adding towers later)

As an additional restriction to make the assignment's rules simpler, there will never be two locations with the same name.

## Enemies
In these dark times, the realm is under attack. Fiendish Enemies regularly appear at their Lair and make their way, one location at a time, towards The Castle.

An Enemy is represented by a struct which records their name, their maximum health and their current health (as integers). These structs should also be set up so that the Enemies can be joined together in a linked list.

Enemies will always be at a location, which is represented by a linked list of Enemies at every location in The Realm. Linked lists of Enemies are always listed in alphabetical order.

An Enemy dies when it has zero or less health. It then is removed from the linked list that contained it and its memory is freed.

There will never be two enemies in the realm with the same name.

## Towers
As mentioned before, locations in the realm can be Towers. Towers are able to reduce the HP of any Enemy at their Location. They can only be used a fixed number of times. When they run out of uses, they convert back into lands.

Towers have two important properties:

Power: How much an Enemy's HP is reduced when the Tower attacks. This is a whole number, greater than zero.
Uses: A count of how many times a Tower can be used before it reverts to being a land. This is a whole number, greater than zero.

## The Castle
At the start of the list is The Castle. Enemies that manage to reach The Castle will deal damage to it; and if they move beyond the castle they are removed from the realm.

The Castle starts off with STARTING_CASTLE_HP health. If an Enemy damages The Castle, it causes The Castle's health to decrease by that Enemy's remaining health.

Note: Nothing special should happen when the castle goes below 0 HP. It can go negative if enough damage is dealt to it.

## The Game
When the game starts, two locations are automatically created - the Castle and the Lair. You will then be given a list of locations on standard input, one per line. The order of the locations as standard input is the same order they will have starting from Castle and proceeding to Lair. These locations will be strings that do not contain any spaces, dashes or square brackets. When the list of locations is complete, an empty line will be input.

After this, a prompt will appear. You will type in commands to indicate changes to the state of the Realm. These commands will all start with a character as the command, then a space, then possibly some additional information about the command. There are three special commands, which are already implemented in the Starter Code provided. They consist of:

?: Print a list of all possible commands.
q: Quit the program.
/: Do nothing, this line is treated as a comment.

## Features Implemented
### Adding to the Realm
In realm.c you have been given two function stubs (a stub is an unimplemented function):

static Location new_location(char *name) {
    return NULL;
}

int add_location(Realm realm, char *name) {
    return 42;
}
These two functions should be implemented as described below.

new_location should use malloc to allocate memory for a new Location node. It should then set up it's name (and any other fields you decide you need throughout the assignment).

Note that the word "static" on this function will make it accessible within this file, but not elsewhere. We often use static on helper functions that are not part of the header file and aren't used by any other parts of the program. Static will not significantly change how you will use this function.
The new_realm function (already implemented in the starter code) uses the new_location function. The new_realm function does not need changing for this stage, but you may want to add code to it at a later stage.
add_location will be given a Realm and a Location name. It will then insert a new location node directly before the Lair in the linked list of locations. It returns the number of locations in the linked list.

### Printing out the Realm
In realm.c you have been given the function stub:

void print_realm(Realm realm) {

}
as well as four fully implemented functions:
void print_tower(char *name, int power, int uses, Effect effect);
void print_land(char *name);
void print_castle(char *name, int defense);
void print_enemy(char *name, int cur_hp, int max_hp);
print_realm will be given a realm, and will print out information about that realm. You should use the functions given in the starter code to print it out, instead of calling printf yourself.
Specifically, print_realm will list locations in order from The Castle to The Lair. If there are any enemies at a location, it will list them in order before listing the next location.

Note: the castle starts off with STARTING_CASTLE_HP, so in the early stages, you will need to pass defense as STARTING_CASTLE_HP. You will not need the print_tower and print_enemy functions until Stage 2.

### Add Enemies
When running the program, you can use the following command to add a new enemy:
e location_name name HP
// for instance
e Lair EnemyName 4
Which means "Create a new enemy, at the location location_name, called name, with maximum HP hp.

You have been given the function stub, which will be called by main.c when the above command has been given:

int new_enemy(Realm realm, char *location_name, char *name, int hp) {

}
Your job is to implement this function, such that the code does the following:
Given a realm, the name of a Location in the realm, and some stats about a new enemy, you should (in this order):

Find the Location called location_name. If one does not exist, return ERROR_NO_LOCATION
Ensure that the stats you have been given for HP are not below 1. If they are, return ERROR_INVALID_STAT.
Place a new enemy, with the given stats, directly after the last enemy at the location you found above.
Return SUCCESS to indicate success.
You are guaranteed that you will only receive enemies in sorted order, and will never receive the same enemy name twice. You do not need to check this. This means that for any list of enemies, strcmp(enemy->name, enemy->next->name) will be strictly less than zero. This guarantee will only be relevant for Stage 4

### New Towers
When running the program, you can use the following command to add a new tower:
t prev_name name power uses
// for instance
t Castle NewTower 2 2
Which means "Create a new tower, directly below the Location prev_name , called name, that causes power damage to each enemy at it, and that can be used uses times".

You have been given the function stub, which will be called by main.c:
int new_tower(Realm realm, char *prev_name, char *name, int power, int uses){

}
Your job is to implement this function, such that the code does the following:
Given a realm, the name of a Location in the realm, and some stats about a new tower, you should:

Find the Location called prev_name. If one does not exist, return ERROR_NO_LOCATION
Ensure that the stats you have been given for power and uses are not below 1. If they are, return ERROR_INVALID_STAT.
Place a new tower, with the given stats, directly after the location which you found above. This tower is inserted into the linked list, which adds an element and does not replace the Location prev_name.
Return SUCCESS to indicate success.

### Freeing memory and destroying the Realm
When you quit the program (using the special command q), the following stub function will be called to free your list.
void destroy_realm(Realm realm);
calling this function should free:

Each Enemy
Each Location
The Realm struct
Any other memory you have allocated using malloc

### Advancing Enemies
When running the program, you can use the following command to move all enemies along.
n
This is called a "tick" in game design (as in, the "tick" of a clock). You have also been given the following function stub:

int advance_enemies(Realm realm) {

}
advance_enemies will go through the realm, moving each enemy from their current Location to the Location above in the linked list. Should any enemies go above the castle, they should be removed from the realm, and destroyed. You should return the number of enemies removed this way at the end of the function. The Lair should be empty of enemies after this, all of them having moved to the next Location in the list.

### Damage
When running the program, you can use the following command to deal damage to Enemies and The Castle. It will also use up "uses" from any Towers that deal damage to enemies.

You can deal damage using the following command:

d
This will call the following function stub:

int apply_damage(Realm realm) {

}
Go through each Location in the realm, and do the following if the Location is a Tower:

Go through each Enemy at that Tower, and reduce it's HP by the Tower's power. If an enemy's HP is equal to or less than zero, remove it from the list of Enemies at that location
Reduce that Tower's number of uses left by 1, if it did damage to an enemy.
If that Tower now has no uses remaining, convert it into a Land. It should no longer have any effect on enemies that pass through it.
apply_damage should also cause the Castle's defense to decrease, by the sum of the HP of each enemy currently at the Castle. For instance, if the Castle had an enemy with 3 HP, and one with 5 HP, the Castle's defense would decrease by 8.

apply_damage returns the number of enemies damaged this way.