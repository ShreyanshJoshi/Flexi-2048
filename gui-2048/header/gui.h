/**
 * @file gui.h
 * @author Shreyansh Joshi
 * @brief File containing function declarations for the game GUI.
 *
 */
#pragma once
#include "base.h"
#include <chrono>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

using namespace std::chrono;

/**
 * @brief Initializes the SDL window. When two pointers to the pointer of window and renderer are provided,
 * the function initializes both values with the values of created window and renderer. 
 * 
 * If initialization is failed it may display error to stderr but does not exit inside the function.
 * 
 * @param window The window of the game.
 * @param renderer The renderer for the game.
 */
bool initSDL(SDL_Window **window, SDL_Renderer **renderer);

/**
 * @brief Destroys and closes the SDL window and closes SDK_ttk. Frees up resource by destroying the SDL window.
 * 
 * @param window The window of the game.
 */
void closeSDL(SDL_Window **window);

/**
 * @brief Draws text centered inside the rect. When two pointers to the pointer of window and renderer are provided, 
 * the function initializes both values with the values of created window and renderer. If initialization is failed it 
 * may display error to stderr but does not exit.
 * 
 * @param renderer The renderer for the game.
 * @param font The font for the text.
 * @param text The text to write.
 * @param rect The SDL_Rect object inside which text is written.
 * @param color The color of the text.
 */
void draw_text(SDL_Renderer *renderer, TTF_Font *font, const char *text, SDL_Rect rect, SDL_Color color);

/**
 * @brief Draws white text centered inside a rect. 
 * 
 * @param renderer The renderer for the game.
 * @param font The font for the text.
 * @param text The text to write.
 * @param rect The SDL_Rect object inside which text is written.
 */
void draw_white_text(SDL_Renderer *renderer, TTF_Font *font, const char *text, SDL_Rect rect);


/**
 * @brief Draws grey text centered inside a rect. Used when values in a tile are either 2 or 4. 
 * 
 * @param renderer The renderer for the game.
 * @param font The font for the text.
 * @param text The text to write.
 * @param rect The SDL_Rect object inside which text is written.
 */
void draw_grey_text(SDL_Renderer *renderer, TTF_Font *font, const char *text, SDL_Rect rect);

/**
 * @brief Clears the window screen. Fills a color to entire screen.
 * 
 * @param renderer The renderer for the game.
 */
void clear_screen(SDL_Renderer *renderer);

/**
 * @brief Draws black text centered inside the window.
 *  
 * @param renderer The renderer for the game.
 * @param size The size for the text.
 * @param text The text to write.
 * @param s The stack containing states of board and the corresponding points (scores).
 * @param start Represents a point when the timer is started.
 * @param stop Represents a point when timer is stopped. This is when the game is over.
 * @param over Whether the game is over or not (either via loss or win of the player). Default: false.
 * @param moves Number of moves made by the user in the current game. Default: 0
 */
void display_text(SDL_Renderer *renderer, const char *text, int size, stack<State>s, time_point<system_clock>start, 
                  time_point<system_clock> stop, bool over=false, int moves=0);

/**
 * @brief Draws the game tiles. It draws the Y_DIM * X_DIM game tiles to the window.
 * 
 * @param renderer The renderer for the game.
 * @param board The game board.
 */
void draw_board(SDL_Renderer *renderer, const int board[Y_DIM][X_DIM]);

/**
 * @brief Draws the New Game button. It draws the button on the bottom left corner.
 * 
 * @param renderer The renderer for the game.
 * @param font The font for the button.
 * @param game_over Whether the game is over or not (either via loss or win of the player). Default: false.
 */
void draw_button(SDL_Renderer *renderer, TTF_Font *font, bool game_over=false);

/**
 * @brief Handles the action of the New Game button. Resets the game board for a new game, changes the music, if the 
 * correct mouse event has occured. Function is executed if left mouse button is released. 
 * 
 * @param e The mouse event.
 * @param board The game board.
 * @param bg_music A vector of strings containing the paths to various bg music songs (from which one is chosen randomly).
 * @param game_over Whether the game is over or not (either via loss or win of the player).
 * @param new_game Whether a new game has to be started or not.
 * @param start Represents a point when the timer is started.
 * @param moves Number of moves made by the user in the current game.
 */
void button_handler(SDL_Event e, int board[Y_DIM][X_DIM], vector<string>bg_music, bool game_over, bool &new_game, int &moves, 
                    time_point<system_clock>&start);

/**
 * @brief Draws the current game score, as well as the best score in this run of the game at the bottom of the window.
 * 
 * @param renderer The renderer for the game.
 * @param font The font for the tiles.
 * @param points The current score/points.
 * @param best_score Best score achieved in this run of the game.
 */
void draw_score(SDL_Renderer *renderer, TTF_Font *font, int points, int best_score);

/**
 * @brief Draws everything for the game and renders it to screen. It calls clear_screen(), draw_board(), draw_score() 
 * and draw_button(), before rendering.
 * 
 * @param renderer The renderer for the game.
 * @param font The font for the tiles.
 * @param board The game board.
 * @param points The current points/score in the game.
 * @param best_score Best score achieved in this run of the game.
 */
void render_game(SDL_Renderer *renderer, const int board[Y_DIM][X_DIM], TTF_Font *font, int points, int best_score);

/**
 * @brief This is the main game loop that handles all events and drawing. 
 * 
 * @param renderer The renderer for the game.
 * @param board The game board.
 * @param s The stack containing states of board and their corresponding points.
 * @param bg_music A vector of strings containing the paths to various bg music songs (from which one is chosen randomly).
 */
void game_loop(int board[Y_DIM][X_DIM], stack<State>&s, SDL_Renderer *renderer, vector<string>bg_music);

/**
 * @brief Handles keyboard presses. It transforms the game board according to the keypresses by making the corresponding
 * moves. It also stores the current state of the game on a stack.
 * 
 * @param renderer The renderer for the game
 * @param e A Keyup event.
 * @param board The game board.
 * @param s The stack containing states of board and their corresponding points.
 * @param moves Number of moves made by the user in the current game.
 * @param undo Whether the current move is undo move or not.
 * @param invalid  Whether some other key was pressed, rendering the current move invalid.
 */
void handle_move(SDL_Event e, int board[Y_DIM][X_DIM], SDL_Renderer *renderer, stack<State>&s, int &moves, int &undo, bool &invalid);
