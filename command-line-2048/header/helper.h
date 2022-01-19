/**
 * @file helper.h
 * @author Shreyansh Joshi
 * @brief File containing function declarations for the functions in helper.cpp. These functions have no 
 * intrinsic value and just help the core functions (in core.cpp) to run.
 *
 */
#pragma once
#include <vector>
using namespace std;

/** @brief A struct that holds the state of the board in form of a vector, and the points corresponding
 * to that state. It's pushed onto a stack that keeps track of all states of the board achieved till current 
 * move.
 */
struct State {
	vector<vector<int>>v;
	int points;
};

/** @brief Copies values of a into b i.e makes b equal to a.
 */
void restore(int b[4][4], int a[4][4]);

/** @brief Copies the current state of the board to a vector.
 */
void load_vector(vector<vector<int>>&v, int a[4][4]);

/** @brief Returns the position (x,y coordinates) of an empty tile so that a new value can be assigned to it.
 */
pair<int,int> get_loc(int a[4][4]);
