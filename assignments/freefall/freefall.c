// Author: Len Au (z5308653@ad.unsw.edu.au)
// Date: 21/06/20 - 12/07/20
// UNSW Freefall assignment.

// Freefall takes user inputs to process lines of stone and commands
// Player can move left and right on a map
// Player can shift the map down 
// Player fires laser until no stones remain to win


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 15
#define EMPTY 0
#define STONE 1
#define LASER 2
#define LASER_COMPLETE 3
#define MOVE_PLAYER 1
#define SHIFT 3


void printMap(int map[SIZE][SIZE], int playerX);
int movementControls(int movement, int playerX);
void stonesToMap (int map[SIZE][SIZE], int playerX);
void laser (int map[SIZE][SIZE], int playerX);
int commandControls (int map[SIZE][SIZE], int playerX);
void shiftDown (int map[SIZE][SIZE], int playerX); 
int gameLost(int map[SIZE][SIZE], int playerX);
int gameWon(int map[SIZE][SIZE], int playerX);

int main (void) {
    // This line creates our 2D array called "map" and sets all
    // of the blocks in the map to EMPTY.
    int map[SIZE][SIZE] = {EMPTY};

    // This line creates out playerX variable. The player starts in the
    // middle of the map, at position 7.
    int playerX = SIZE / 2;
    
    //Calls function to scan in the lines of blocks
    stonesToMap(map, playerX);
    
    //Calls function to process commands
    commandControls (map, playerX);

    return 0;
}

// Print out the contents of the map array. Then print out the player line
// which will depends on the playerX variable.
void printMap(int map[SIZE][SIZE], int playerX) {
    
    // Print values from the map array.
    int i = 0;
    while (i < SIZE) {
        int j = 0;
        while (j < SIZE) {
            printf("%d ", map[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }    
    
    // Print the player line.
    i = 0;
    while (i < playerX) {
        printf("  ");
        i++;
    }
    printf("P\n");
}

//Scan in the lines of blocks. 
//Takes the number of lines that user inputs and prints
//the lines of stone onto map   
void stonesToMap(int map[SIZE][SIZE], int playerX) {
    int linesOfStone;
    int row;
    int col;
    int length;
    int value;
    int stoneCounter = 0;
    //User enters the number of lines of blocks
    printf("How many lines of stone? "); 
    scanf("%d", &linesOfStone);
    
    
    //Loop to scan the length of the lines of stone
    printf("Enter lines of stone:\n");

    
    while (stoneCounter < linesOfStone) {
        scanf("%d %d %d %d", &row, &col, &length, &value); 

        //if initial col value exceeds map parametres, ignore line
        if (col + length > SIZE) {
            col = EMPTY;
            length = EMPTY;
            row = EMPTY; 
        }
        //if length exceeds map, ignores whole line
        if (length > SIZE) {
            col = EMPTY;
            length = EMPTY;
            row = EMPTY;
        }
        //if row is not on map, ignores whole line
        if (row > SIZE|| row == SIZE) {
            col = EMPTY;
            length = EMPTY;
            row = EMPTY;
        }
        //if col is not on map, ignores whole line
        if (col > (SIZE - 1)) {
            col = EMPTY;
            length = EMPTY;
            row = EMPTY;
        }
        //if row, col or length values are negative, ignore the line
        if (col < 0 || length < 0 || row < 0) {
            col = EMPTY;
            length = EMPTY;
            row = EMPTY;
        }
        //Col increases until length number of STONE is printed    
        int stonePrint = col;
        while (col < (stonePrint + length)) {
            //as line is printed
            map[row][col] = STONE;
            //increment by 1 until length is printed
        
            col++;
        }
            
        //increment counter for each line read
        stoneCounter++;
    }
        
    printMap(map, playerX);

}

//Based on command will call on laser or movementControls function
//Loops user's input until EOF
int commandControls (int map[SIZE][SIZE], int playerX) {

    // Scan in commands until EOF.
    // After each command is processed, call printMap
    int command;
    int movement;
    
    //create loop to scan commands until EOF
    while (scanf("%d", &command) == 1) {
        // If command == 1, take command to move playerX
        //Call function to process commands
        if (command == MOVE_PLAYER) {
            scanf("%d", &movement);
            playerX = movementControls(movement, playerX);
        }
        //If command == 2, fire laser
        // Call on laser function
        if (command == LASER) {
            laser(map, playerX);
            command = 0;
            movement = 0;
            int value = gameWon(map, playerX);
            if (value == 0) {
                return 0;
            }
        }
        //If command == 3, shift everything down 1 place
        //Call on shiftDown function to process command
        if (command == SHIFT) {
            //Call on gameLost function to check if game lost 
            //before processing shift down command
            int val = gameLost(map, playerX);
            if (val == 0) {
                return 0;
            }
            shiftDown (map, playerX);
            command = 0;
            movement = 0;
        }
        
        printMap(map, playerX);
         
    }
    //If win/lose conditions have not been satisfied
    //continue running program    
    return 1;
}

//Moves player left if command is -1
//Moves player right if command is 1
//Returns playerX 
int movementControls(int movement, int playerX) {
    //inputs command and the movement key (direction) sent here
    //processes commands
    //playerX value will be returned
     
    //left command
    if (movement == -1) {
        playerX--;
    }
    //right command
    if (movement == 1) {
        playerX++;
    }
    //left edge
    if (playerX < 0) {
        playerX = 0;
    }
    //right edge
    if (playerX > SIZE - 1) {
        playerX = SIZE - 1;
    }
    
    //return new playerX value at the end of the function
    return playerX;
}

void laser (int map[SIZE][SIZE], int playerX) {
    // Only destroys 3 blocks above playerX
    // Destroying blocks turns the value of the stone to EMPTY
    // Print map after laser has been fired
    int i = SIZE - 1;
    int stoneCounter = 0;
    //loops from the bottom of the array up
    //ends loop when 3 stones are destroyed
    
    while (i >= 0 && stoneCounter < LASER_COMPLETE) {
        
        //destroys 3 stones, making them EMPTY
        //counter to stop loop when counter = 3
        if (map[i][playerX] == STONE) {
            map[i][playerX] = EMPTY;
            stoneCounter++; 
        }
        
        //increment counter
        i--;
    }
}

void shiftDown (int map[SIZE][SIZE], int playerX) {

    //Loops through each row to copy where STONE is 
    //Moves these stone to the next row down
    int x = SIZE - 1; //row counter
    int y = 0; //col counter
    
    //Loop from the bottom up, will copy if there is a stone to the line
    //below.
    
    while (x >= 0) {
        y = 0;
        while (y < SIZE) {
            //Copy the stone from previous row to the next one
            if (map[x][y] == STONE) {
                map[x][y] = EMPTY;
                map[x + 1][y] = STONE;
            }
            //Print EMPTY row for top row
            if (x == 0) {
                map[x][y] = EMPTY;
            }
            //counts across the elements
            y++;
        }
        //counts down the rows
        x--;
    }
}

//Checks if there are any stones on the bottom row before shiftDown
//function is called
//Ends game if there are stones on this row
//Game is lost
int gameLost(int map[SIZE][SIZE], int playerX){
    
    int j = 0;
        
    //Loop through last row to see if there is STONE on the last row
    //Don't shift map down
    //Game lost
    while (j < SIZE) { 
        if (map[14][j] > EMPTY) {
            printMap(map, playerX);
            printf("Game Lost!\n");
            //stops the while loop
            j = SIZE;
            //Returns 0 to commandControls to end program
            return 0; 
            

        }    
        //Increment counter
        j++;
    }
    //Return to commandControls, did not satisfy if statement
    //Continues the program
    return 1;
}

//Checks the 2D array for any stones
//If there are no stones left, game has been won
int gameWon(int map[SIZE][SIZE], int playerX) {
    int i = 0; //counter for the rows
    int j = 0; //counter to loop through elements
    int stoneCheck = 0; //checks if there are any stones left on map
    
    while (i < SIZE) {
        j = 0;
        while (j < SIZE) {
            
            //if there are still stones on the map
            //continue program
            if (map[i][j] == STONE) {
                map[i][j] = STONE;
            }
            //Checks if there are no stones on the map
            stoneCheck = stoneCheck + map[i][j];
            
            j++;
        }
        i++;
        
    }
    //if there are no stones on the map
    //game won
    if (stoneCheck == EMPTY) {
        printMap(map, playerX);
        printf("Game Won!\n");
        //stops the loop
        i = SIZE;
        j = SIZE;
        //Returns 0 to commandControls to end program
        return 0; 
        
    }
    //Return to commandControls, did not satisfy if statement
    //Continues the program
    return 1;
}


