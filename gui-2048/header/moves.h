/**
 * @file moves.h
 * @author Shreyansh Joshi
 * @brief File containing function declarations for the move related functions.
 *
 */
#pragma once
#include "base.h"

/** @brief Moves tiles in up direction, merging according to the rules whenever possible.
 */
void move_up(int board[Y_DIM][X_DIM]);

/** @brief Moves tiles in left direction, merging according to the rules whenever possible.
 */
void move_left(int board[Y_DIM][X_DIM]);

/** @brief Moves tiles in down direction, merging according to the rules whenever possible.
 */
void move_down(int board[Y_DIM][X_DIM]);

/** @brief Moves tiles in right direction, merging according to the rules whenever possible.
 */
void move_right(int board[Y_DIM][X_DIM]);