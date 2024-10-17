# Game-2048
PDS PRROJECT 
Professor: Dr.Devashree Tripathy
Built by - Patel Hetvi Kantibhai
            24CE01068

Library Use - stdio.h,stdlib.h,time.h
Functions:
findlen(): To calculate the number of digits in an integer.
output(): Print the current state of the game grid, score, and high score.
shiftvalue(int k): Moves non-zero values to the rightmost side in an array.
randomadd(): Adds a random number (2 or 4) to a random empty cell iN ARRAY.
updatearr(): Combines adjacent equal values in a row.
createhis(int ***p): Creates a record of the current game state to maintain a history of previous states.
updatetoprev(int ***p): Updates the game grid to a previous state.
resetgame(): Resets the game by clearing the grid, resetting the score, and adding a new random number.
main() Function: Initializes the game, handles user input, updates the game state based on the input, and checks for game over conditions. 
                Additionally, file handling functions are used to read and write high scores and maintain a history of game states.
