/**
 * @file driver.cpp
 * @author Shreyansh Joshi
 * @brief File containing main function, that begins the game and hands over the control to corresponding functions.
 *
 */
#include "gui.h"
#include "base.h"
#include <time.h>
#include <bits/stdc++.h>
#include <SDL2/SDL_mixer.h>

/** The pointer to the background music.*/
Mix_Music *g_background_music;

/** The pointer to the mix music chunk.*/
Mix_Chunk *g_mix_music;

/**
 * @brief The standard main function
 * 
 * Starts the game
 * 
 * @param argc Number of arguments
 * @param argv Arguments
 */
int main(int argc, char **argv) {
	//Set up the seed
	srand(time(NULL));

	//Set up the game board: clear it and initialize it with 2 random numbers.
	stack<State>s;
	int board[SIZE][SIZE];
	clear_board(board);
	initialize_game(board, s);

	//Init the SDL gui variables
	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;
	if (!initSDL(&window, &renderer))
		exit(EXIT_FAILURE);

	//Load Music Files
	g_background_music = Mix_LoadMUS("background.mp3");             // The path to the background music.
	g_mix_music = Mix_LoadWAV("mix.wav");                           // The path to the sound that plays when tiles combine or appear.

	if (g_background_music == NULL || g_mix_music == NULL) {
		fprintf(stderr, "Music files couldn't be loaded.");
		exit(EXIT_FAILURE);
	}

	Mix_PlayMusic(g_background_music, -1);
	
	game_loop(board, s, renderer, g_mix_music);

	//Releases all resources
	closeSDL(&window);
	Mix_FreeMusic(g_background_music);
	Mix_FreeChunk(g_mix_music);

	return EXIT_SUCCESS;
}