# 2048-CLI

Welcome to my CLI implementation of the 2048 game. It can be played generally on any CLI, but has been tested on Windows CMD and Linux terminal. The game is a regular 2048 game, implemented in C++, in a modular fashion. 

### Key features - 
* Apart from the regular moves, I have implemented 2 other moves for the user, namely **undo** and **hint**. Undo function displays the board (and score of the player) before the latest move. Hint function displays the state of the board after each of the 4 possible moves (up,down,left,right) is made individually. This would help the player make a more informed choice. It can be used at max twice in my version, but can be tweaked if required. 
* Since the game is command line based, keys 'a', 's', 'd', 'w', 'u', 'h' should be used to play the game for left, down, right, up, undo and hint moves respectively. Each such character needs to be followed by 'Enter' key.
* The game prompts user to enter a correct character, if a wrong character is entered or multiple characters are entered at once. The character 'q' can be used to quit the game.

### How to play on your machine ?
To play the game locally, clone the repository and download the source files. From inside the `src` directory, if you are a Linux/Mac user, run the command `make` on terminal. Just doing this will run the makefile and produce the executable. If you are a windows user using cmd, run `g++ driver.cpp core.cpp helper.cpp moves.cpp`, in case you are not able to run the makefile.
