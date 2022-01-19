/**
 * @file driver.cpp
 * @author Shreyansh Joshi
 * @brief File containing main function, that begins the game and hands over the control to the functions that keep the game running.
 *
 */
#include "gui.h"
#include "base.h"
#include <time.h>
#include <bits/stdc++.h>
#include <SDL2/SDL_mixer.h>

/**
 * @brief The standard main function
 * 
 * Starts the game
 * 
 * @param argc Number of arguments
 * @param argv Arguments
 */
int main(int argc, char **argv) {

	// Set up the seed for random number generation
	srand(time(NULL));

	// Initialize the game board, the stack and the vector containing list of background music available.
	stack<State>s;
	int board[SIZE][SIZE];
	vector<string> bg_music = {"apocalypse-CAS.mp3", "drift-kuyani.mp3", "truth-alexander.mp3"};

	clear_board(board);
	initialize_game(board, s);

	// Init the SDL GUI variables
	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;
	if (!initSDL(&window, &renderer))
		exit(EXIT_FAILURE);
	
	game_loop(board, s, renderer, bg_music);

	// Releases all resources
	closeSDL(&window);

	return EXIT_SUCCESS;
}