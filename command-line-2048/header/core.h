/**
 * @file core.h
 * @author Shreyansh Joshi
 * @brief File containing function declarations for the functions in core.cpp.
 *
 */
#pragma once
#include <vector>
using namespace std;

/** @brief Assigns 2 tiles (of values either 2 or 4) randomly on a cleared out board.
 */
void initialize_game(int a[4][4]);

/** @brief Displays the current state of the board on the terminal, along with the points.
 */
void display_board(int a[4][4], int points, bool flag);

/** @brief Checks if any tile has the value 2048. If yes, the player has won.
 */
bool is_2048(int a[4][4]);

/** @brief Compares the current state of the board with the vector passed as a parameter.
 */
bool compare(int a[4][4], vector<vector<int>>v);

/** @brief Checks if there are possible moves left on the game board. If not, then the player has lost.
 */
bool is_game_over(int a[4][4]);

/** @brief Assigns either 2 or 4 randomly in an available space (empty tile).
 */
void assign_random_number(int a[4][4]);

/** @brief Calculates the current score/points after a move is made.
 */
int score(int a[4][4], char c);
