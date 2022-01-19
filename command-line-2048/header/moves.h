/**
 * @file moves.h
 * @author Shreyansh Joshi
 * @brief File containing function declarations for move related functions.
 *
 */
#pragma once
#include "helper.h"
#include <stack>
using namespace std;

/** @brief Moves tiles in up direction, merging according to the rules whenever possible.
 */
void move_up(int a[4][4]);

/** @brief Moves tiles in left direction, merging according to the rules whenever possible.
 */
void move_left(int a[4][4]);

/** @brief Moves tiles in down direction, merging according to the rules whenever possible.
 */
void move_down(int a[4][4]);

/** @brief Moves tiles in right direction, merging according to the rules whenever possible.
 */
void move_right(int a[4][4]);

/** @brief Shows the user the state of the board after each of the possible 4 moves. However it can be only used twice
 * in a game.
 */
void hint(int a[4][4]);

/** @brief Undoes the last move. Returns the state of the board (and the points) before the last move.
 */
int undo(int a[4][4], stack<State>&s);
