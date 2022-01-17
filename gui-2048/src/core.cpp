/**
 * @file core.cpp
 * @author Shreyansh Joshi
 * @brief File containing implementation of the core game.
 *
 */
#include <bits/stdc++.h>
#include <time.h>
#include "base.h"

using namespace std;

void clear_board(int board[SIZE][SIZE]) {
	for (int x = 0; x < SIZE; x++) 
		for (int y = 0; y < SIZE; y++) 
			board[x][y] = 0;
		
}

int calculate_score(int a[4][4], char c) {
	int i,j,val = 0;
	bool flag;

	if(c=='w') {								// up
		for(j=0;j<4;j++) {
			i = 1;
			flag = false;
			while(i<4) {
				if(a[i][j]==a[i-1][j] && a[i][j]!=0) {
					val += a[i][j]*2;
					flag = true;
					i+=2;
				}
				else
					i++;
			}
			if(flag==false) {
				if(a[0][j]==a[2][j] && a[0][j]!=0 && a[1][j]==0)
					val += a[0][j]*2;

				else if(a[1][j]==a[3][j] && a[1][j]!=0 && a[2][j]==0)
					val += a[1][j]*2;

				else if(a[0][j]==a[3][j] && a[0][j]!=0 && a[1][j]==0 && a[2][j]==0)
					val += a[0][j]*2;
			}
		}
	}
	else if(c=='a') {							// left
		for(i=0;i<4;i++) {
			j = 1;
			flag = false;
			while(j<4) {
				if(a[i][j]==a[i][j-1] && a[i][j]!=0) {
					val += a[i][j]*2;
					flag = true;
					j+=2;
				}
				else
					j++;
			}
			if(flag==false) {
				if(a[i][0]==a[i][2] && a[i][0]!=0 && a[i][1]==0)
					val += a[i][0]*2;

				else if(a[i][1]==a[i][3] && a[i][1]!=0 && a[i][2]==0)
					val += a[i][1]*2;

				else if(a[i][0]==a[i][3] && a[i][0]!=0 && a[i][1]==0 && a[i][2]==0)
					val += a[i][0]*2;
			}
		}
	}
	else if(c=='s') {							// down
		for(j=0;j<4;j++) {
			i = 2;
			flag = false;
			while(i>=0) {
				if(a[i][j]==a[i+1][j] && a[i][j]!=0) {
					val += a[i][j]*2;
					flag = true;
					i-=2;
				}
				else
					i--;
			}
			if(flag==false) {
				if(a[3][j]==a[1][j] && a[3][j]!=0 && a[2][j]==0)
					val += a[3][j]*2;

				else if(a[2][j]==a[0][j]  && a[2][j]!=0 && a[1][j]==0)
					val += a[2][j]*2;

				else if(a[3][j]==a[0][j] && a[3][j]!=0 && a[2][j]==0 && a[1][j]==0)
					val += a[3][j]*2;
			}
		}
	}
	else {										// right
		for(i=0;i<4;i++) {
			j = 2;
			flag = false;
			while(j>=0) {
				if(a[i][j]==a[i][j+1] && a[i][j]!=0) {
					val += a[i][j]*2;
					flag = true;
					j-=2;
				}
				else
					j--;
			}
			if(flag==false) {
				if(a[i][3]==a[i][1] && a[i][3]!=0 && a[i][2]==0)
					val += a[i][3]*2;

				else if(a[i][2]==a[i][0] && a[i][2]!=0 && a[i][1]==0)
					val += a[i][2]*2;

				else if(a[i][3]==a[i][0] && a[i][3]!=0 && a[i][2]==0 && a[i][1]==0)
					val += a[i][3]*2;
			}
		}
	}
	return val;	
}

void print_board(int board[SIZE][SIZE], FILE *stream) {
	for (int x = 0; x < SIZE; x++) {
		for (int y = 0; y < SIZE; y++) {
			if (board[x][y])
				fprintf(stream, "%d,", board[x][y]);
			
			else
				fprintf(stream, "-,");
			
		}
		fprintf(stream, "\n");
	}
	fprintf(stream, "\n");
}

void assign_random_number(int board[SIZE][SIZE]) {
	int row, col, random = rand();
	pair<int,int>p = get_loc(board);
	row = p.first;
	col = p.second;

	if(random % 2 ==0) 						// 2 is generated
		board[row][col] = 2;
	
	else 								 	// 4 is generated
		board[row][col] = 4;
	
}

bool is_game_over(int board[SIZE][SIZE]) {
	for (int x = 0; x < SIZE - 1; x++) {
		for (int y = 0; y < SIZE - 1; y++) {
			if (board[x][y] == board[x][y + 1] || board[x][y] == board[x + 1][y] || board[x][y] == 0)
				return false;
			
		}
		if (board[x][SIZE - 1] == board[x + 1][SIZE - 1] || board[x][SIZE - 1] == 0)
			return false;
		
		if (board[SIZE - 1][x] == board[SIZE - 1][x + 1] || board[SIZE - 1][x] == 0)
			return false;
	}
	return true;
}

void initialize_game(int board[4][4], stack<State>&s) {				
	while(s.empty()==false) 
		s.pop();
	
	assign_random_number(board);
	assign_random_number(board);
}

bool compare(int board[4][4], vector<vector<int>>v) {
	for(int i=0;i<4;i++) {
		for(int j=0;j<4;j++)
			if(board[i][j]!=v[i][j])
				return false;
	}
	return true;
}

bool is_2048(int board[4][4]) {					
	for(int i=0;i<4;i++) {
		for(int j=0;j<4;j++)
			if(board[i][j]==2048)
				return true;
	}
	return false;
}


