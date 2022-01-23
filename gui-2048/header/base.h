/**
 * @file base.h
 * @author Shreyansh Joshi
 * @brief File containing function declarations for the functions in core.cpp as well as helper.cpp.
 *
 */
#pragma once
#include <bits/stdc++.h>

/** @def X_DIM
 * The number of tiles in horizontal direction of the board
 */
#define X_DIM 9

/** @def Y_DIM
 * The number of tiles in vertical direction of the board
 */
#define Y_DIM 9

using namespace std;

/** @brief A struct that holds the state of the board in form of a vector, and the points corresponding
 * to that state. It's pushed onto a stack that keeps track of all states of the board achieved till current 
 * move.
 */
struct State {
	vector<vector<int>>v;
	int points;
};

/** @brief Copies the current state of the board to a vector. Used as state of the board is stored on the stack as a vector.
 */
void load_vector(vector<vector<int>>&v, int board[Y_DIM][X_DIM]);

/** @brief Returns the position (x,y coordinates) of an empty tile so that a new value can be assigned to it.
 */
pair<int,int> get_loc(int board[Y_DIM][X_DIM]);

/** @brief Clears out the board game, and so the entire board consists of zeroes (empty tiles).
 */ 
void clear_board(int board[Y_DIM][X_DIM]);

/** @brief Checks if there are possible moves left on the game board. If not, then the player has lost.
 */
bool is_game_over(int board[Y_DIM][X_DIM]);

/** @brief Calculates the current score/points after a move is made.
 */
int calculate_score(int board[Y_DIM][X_DIM], char c);

/** @brief Clears the stack, and assigns either 2 or 4 randomly on a cleared out board, to a randomly chosen tile.
 */
void initialize_game(int board[Y_DIM][X_DIM], stack<State>&s);

/** @brief Checks if any tile has the value 2048. If yes, the player has won.
 */
bool is_2048(int board[Y_DIM][X_DIM]);

/** @brief Compares the current state of the board with the vector passed as a parameter. Used to see if current state
 * of board is same as the previous state (before the last move).
 */
bool compare(int board[Y_DIM][X_DIM], vector<vector<int>>v);

/** @brief Assigns either 2 or 4 randomly to an empty tile.
 */
void assign_random_number(int board[Y_DIM][X_DIM]);