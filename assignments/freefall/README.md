# Freefall

## Game Commands
1 -1	
Move the player once to the left.

1 1	
Move the player once to the right.

1 2	
Invalid. Don't make any changes.
## Game Features:

### The Map:
The map is a two dimensional array (an array of arrays) of integers that represents the space that the game is played in. In stage 1 and 2, the map will only store either a 0 or a 1. A 0 represents an empty square, and a 1 represents a stone. In the starter code there are #defines for both of these values, which we will reference for the remainder of this page.

The map is a fixed-size square-shaped grid and has SIZE rows, and SIZE columns. SIZE is another #define'd constant with the value 15.

Remember, both the rows and columns start at 0, not at 1.

The top left corner of the grid is [0][0] and the bottom right corner of the grid is [SIZE - 1][SIZE - 1]. Note that, like the array itself, we are using rows as the first coordinate in pairs of coordinates. This is the opposite order you might be used to in maths.

For example, if in a command we are given an input pair of coordinates 5 6, we will use that to find a particular square in our map by accessing the individual element in the array: map[5][6]. This represents the square in the 6th row and the 7th column (remember arrays start counting at 0).

When the program begins, all of the squares in the map should have the value EMPTY. The starter code does this part for you. You must then populate the map with stones (i.e., STONE) by scanning the locations of horizontal lines of stones (more detail on this later). After this, you must scan in commands until EOF, making the appropriate changes to the map. The format of the inputted commands and changes to the map required are specified in this page.

### Placing the Stone
The program should first ask for the number of lines of STONEs as an integer. Then, the program will scan the locations of the lines as a group of four integers in the following format:

row column length value
The row and column represent the left-most block of a horizontal line of blocks to the placed on the map. The length tells you how many stones should be in this horizontal line. For stage 1 and 2, the fourth integer will always be 1 representing a stone, however in other stages there will be other possibilities such as exploding TNT and marching blocks. This number is the value which should be placed in the array itself to make up the specified line. For example:
Command	Meaning
0 0 5 1	
Place a line of stone starting at [0][0] and ending at [0][4]. All 5 squares in the line will be set to 1 (STONE).

6 7 1 1	
Place a line of stone starting at [6][7] and ending at [6][7]. The 1 square in the line will be set to 1 (STONE).

5 0 15 1	
Place a line of stone starting at [5][0] and ending at [5][14]. All 15 squares in the line will be set to 1 (STONE).

After scanning in the inputs relating to placing lines of stone on the map, the program should then call printMap to display the map on the screen. The line of code to do this is already in the starter code. After printing the map, the program should start to scan in commands until EOF. After processing each command, your program should call printMap once again to show the changes made to the map. Details of each command that your program must implement are shown below.

In the starter code, the program currently initialises every square in the map to EMPTY then prints the map as a grid of integers.

Invalid Input and Assumptions
The first number scanned in (i.e. the number of coordinate pairs specified) will always be valid. It will always be a number greater than zero.
It is possible for the first three integers (row column length) to result in a line which is partially or wholly outside of the map. If this is the case, you should ignore this line completely and not make any changes to the map.
You can assume the third integer (length) will always be positive.
The fourth integer can be assumed to be valid. For this stage it will always be 1 (you don't have to check this).

### Moving the Player:
Command Name	"Move Player"
Command Number	1
Inputs	direction
Examples	
Command	Meaning
1 -1	
Move the player once to the left.

1 1	
Move the player once to the right.

1 2	
Invalid. Don't make any changes.

For the next part of stage 1, you will implement a command to move the player to the left or right on the screen.

The first integer of any move player command will always be a 1. The second integer represents the direction. -1 means to move the player to the left and 1 means to move the player to the right.

Information about the player's current position is given to the printMap function, so it is recommended to update the playerX variable in the main function when this command is received. This will have the effect of changing the position of the P printed by printMap the next time it is called.

Note that after each command has been scanned in and processed the map is printed once again.

### Firing the Laser
Command Name	"Fire Laser"
Command Number	2
Inputs	(none)
Examples	
Command	Meaning
2	
Fire the laser upwards.

For the final part of stage 1, you will implement a command to fire the laser and destroy some blocks directly above the player.

This time the first integer of this command will always be a 2. There will not be any additional integers after this.

This command means to fire the laser at the player's current column. The laser will destroy at most 3 stones above the player. Destroying a stone can be done by changing the value in the array from STONE to EMPTY.

If there are more than three stones in the player's current column, the closest three stones should be destroyed only.

Hint: Even though you are looping through a 2D array, only one while loop is required to complete this command as you are looping through a straight line in the array.

### Shifting everything down:
Command Name	"Shift Everything Down"
Command Number	3
Inputs	(none)
Examples	
Command	Meaning
3	
Move everything on the map down one position.

For the first part of stage 2, you will need to shift all items in the array down by one position. This should occur whenever the program reads in a command of: 3.

There are no arguments after this command, it is another single integer command.

When your program shifts the contents of the array down, the integers which were in the bottom row will disappear, and the integers in the top row will all become EMPTY.

End Conditions
There are two ways to complete a game of Freefall:

The game is won if the entire map is EMPTY.
The game is lost if there is any STONE on the last row as a 3 (shift everything down) command is given. The only case in which the game is not lost when the shift everything down command is given, is when the entire bottom row of the map is EMPTY.
In stage 2 you must add code to check for these conditions. The win conditions should be checked after every fire laser command. If the game is won, the program should print the map once and then print "Game Won!" and end.

The lose condition should be checked before the contents of the array are shifted down. If the game is lost, the program should not shift the grid down, but should still print the map once and then print "Game Lost!" and end.


Disclaimer: Is an incomplete game. 