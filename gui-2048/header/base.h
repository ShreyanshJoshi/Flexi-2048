/**
 * @file base.h
 * @author Shreyansh Joshi
 * @brief File containing function declarations for the functions in core.cpp as well as helper.cpp.
 *
 */
#pragma once
#include <bits/stdc++.h>

/** @def SIZE
 * The size of the board
 */
#define SIZE 4
using namespace std;

/** @brief A struct that holds the state of the board in form of a vector, and the points corresponding
 * to that state. It's pushed onto a stack that keeps track of all states of the board achieved till current 
 * move.
 */
struct State {
	vector<vector<int>>v;
	int points;
};

/** @brief Copies the current state of the board to a vector.
 */
void load_vector(vector<vector<int>>&v, int board[SIZE][SIZE]);

/** @brief Returns the position (x,y coordinates) of an empty tile so that a new value can be assigned to it.
 */
pair<int,int> get_loc(int board[SIZE][SIZE]);

/** @brief Clears out the board game, and so the entire board consists of zeroes (empty tiles).
 */ 
void clear_board(int board[SIZE][SIZE]);

/** @brief Checks if there are possible moves left on the game board. If not, then the player has lost.
 */
bool is_game_over(int board[SIZE][SIZE]);

/** @brief Calculates the current score/points after a move is made.
 */
int calculate_score(int board[SIZE][SIZE], char c);

/** @brief Clears the stack, and assigns either 2 or 4 randomly on a cleared out board.
 */
void initialize_game(int board[SIZE][SIZE], stack<State>&s);

/** @brief Checks if any tile has the value 2048. If yes, the player has won.
 */
bool is_2048(int board[SIZE][SIZE]);

/** @brief Compares the current state of the board with the vector passed as a parameter.
 */
bool compare(int board[SIZE][SIZE], vector<vector<int>>v);

/** @brief Assigns either 2 or 4 randomly in an available space (empty tile)
 */
void assign_random_number(int board[SIZE][SIZE]);