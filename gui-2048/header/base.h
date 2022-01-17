/**
 * @file base.h
 * @author Shreyansh Joshi
 * @brief File containing function declarations for the core game.
 *
 */
#pragma once
#include<bits/stdc++.h>

/** @def SIZE
 * The size of the board
 */
#define SIZE 4
using namespace std;

struct State {
	vector<vector<int>>v;
	int points;
};

void restore(int b[4][4], int a[4][4]);
void load_vector(vector<vector<int>>&v, int a[4][4]);
pair<int,int> get_loc(int a[4][4]);

void clear_board(int a[4][4]);
bool is_game_over(int a[4][4]);
int calculate_score(int a[4][4], char c);
void initialize_game(int a[4][4], stack<State>&s);
bool is_2048(int a[4][4]);
bool compare(int a[4][4], vector<vector<int>>v);
void assign_random_number(int a[4][4]);