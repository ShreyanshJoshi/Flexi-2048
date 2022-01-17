# 2048-Game
2048 is a single-player sliding block puzzle game designed by Italian web developer Gabriele Cirulli. Based purely on math and instinct, the game is one of the most exciting games available to play. The game sucks you in by making it seem easy to hit the magic number of 2048. As quoted by it's creator, *"The amount of man-hours spent playing this game will never be returned to humanity."*

First, the rules of the game - 
* The game is played on a 4x4 grid. The game starts with 2 randomly positioned numbers (can be either 2 or 4).
* 4 types of moves are possible - up, down, left, right. These moves are done by their respective arrow keys.
* After each turn, a new tile (either 2 or 4) appears at any 1 of the empty spots on the board.
* Tiles slide as far as possible in the chosen direction until they are stopped by either another tile or the edge of the grid. If two tiles of the same number collide while moving, they will merge into a tile with the total value of the two tiles that collided. The resulting tile cannot merge with another tile again in the same move.


* If a move causes three consecutive tiles of the same value to slide together, only the two tiles farthest along the direction of motion will combine. If all four spaces in a row or column are filled with tiles of the same value, a move parallel to that row/column will combine the first two and last two.

* A scoreboard on the upper-right keeps track of the user's score. The user's score starts at zero, and is increased whenever two tiles combine, by the value of the new tile.
* The game is won when a tile of value 2048 is attained. After reaching the 2048 tile, players can continue to play (beyond the 2048 tile) to reach higher scores. When the player has no legal moves (there are no empty spaces and no adjacent tiles with the same value), the game ends.

## Additional Features 
The source code in this repository is my version of this game. Apart from all the above rules, I have incorporated some more features that might ensure a better gameplay. The additional features include - 
* Since the game is command line based (needs to be played on terminal), keys 'a', 's', 'd', 'w', 'u', 'h' should be used to play the game for left, down, right, up, undo and hint moves respectively. Each such character needs to be followed by 'Enter' key.

* 2 other functions namely **undo** and **hint** have been added. Undo function displays the board (and score of the player) before the latest move. It can be used at max twice in my version, but can be tweaked if required. Hint function displays the state of the board after all the 4 possible moves (up,down,left,right). This would help the player make a more informed choice.

* The game prompts user to enter a correct character, if a wrong character is entered or multiple characters are entered at once. The character 'q' can be used to quit the game.

* I have also included some optional features that show the maximum tile on the board currently, sum of all tiles at present, the maximum score a person can achieve from the current state of the board in 1 move. The commented lines in driver.cpp should be uncommented if you want to incorporate these functions in the game. 

The implementation of game by me has been done in C++ and using *procedural & modular* paradigm of programming. This simply means that the entire code has been split into multiple files for better readibility, better reusability, better debugging and better collaboration.

The source code includes 1 driver file (that calls all other functions) and 4 other implementation files (or .cpp files)  (that have function definitions in them). Functions serving similar purposes have been grouped together into a single implementation file. Each .cpp file also has a corresponding .h file (header file). Header files only contain the  definition of abstract data types (such as a struct) and function prototypes used anywhere in the program, and must be included in the files where those things are being used for the code to compile correctly. The linker takes care of the function body (by finding it in some implementation file).

## How to play on your machine ?
To play the game locally, clone the repository and download the source files. Store them in a designated folder on your local machine. From that directory, if you are a linux/mac user, run the command `make` on terminal. Just doing this will run the makefile and produce the executable. If you are a windows user using cmd, run `g++ driver.cpp basic_functions.cpp helper_functions.cpp moves.cpp operations.cpp`.

## To do
Design a GUI for this command line game, so that it is much more appealing to play. I also plan to host it for public use after that by creating a website for the same. 
