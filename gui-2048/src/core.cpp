/**
 * @file core.cpp
 * @author Shreyansh Joshi
 * @brief File containing implementation of the core functions (basic functions).
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

int calculate_score(int board[SIZE][SIZE], char c) {
	int i,j,val = 0;
	bool flag;

	if(c=='w') {								// up
		for(j=0;j<4;j++) {
			i = 1;
			flag = false;
			while(i<4) {
				if(board[i][j]==board[i-1][j] && board[i][j]!=0) {
					val += board[i][j]*2;
					flag = true;
					i+=2;
				}
				else
					i++;
			}
			if(flag==false) {
				if(board[0][j]==board[2][j] && board[0][j]!=0 && board[1][j]==0)
					val += board[0][j]*2;

				else if(board[1][j]==board[3][j] && board[1][j]!=0 && board[2][j]==0)
					val += board[1][j]*2;

				else if(board[0][j]==board[3][j] && board[0][j]!=0 && board[1][j]==0 && board[2][j]==0)
					val += board[0][j]*2;
			}
		}
	}
	else if(c=='a') {							// left
		for(i=0;i<4;i++) {
			j = 1;
			flag = false;
			while(j<4) {
				if(board[i][j]==board[i][j-1] && board[i][j]!=0) {
					val += board[i][j]*2;
					flag = true;
					j+=2;
				}
				else
					j++;
			}
			if(flag==false) {
				if(board[i][0]==board[i][2] && board[i][0]!=0 && board[i][1]==0)
					val += board[i][0]*2;

				else if(board[i][1]==board[i][3] && board[i][1]!=0 && board[i][2]==0)
					val += board[i][1]*2;

				else if(board[i][0]==board[i][3] && board[i][0]!=0 && board[i][1]==0 && board[i][2]==0)
					val += board[i][0]*2;
			}
		}
	}
	else if(c=='s') {							// down
		for(j=0;j<4;j++) {
			i = 2;
			flag = false;
			while(i>=0) {
				if(board[i][j]==board[i+1][j] && board[i][j]!=0) {
					val += board[i][j]*2;
					flag = true;
					i-=2;
				}
				else
					i--;
			}
			if(flag==false) {
				if(board[3][j]==board[1][j] && board[3][j]!=0 && board[2][j]==0)
					val += board[3][j]*2;

				else if(board[2][j]==board[0][j]  && board[2][j]!=0 && board[1][j]==0)
					val += board[2][j]*2;

				else if(board[3][j]==board[0][j] && board[3][j]!=0 && board[2][j]==0 && board[1][j]==0)
					val += board[3][j]*2;
			}
		}
	}
	else {										// right
		for(i=0;i<4;i++) {
			j = 2;
			flag = false;
			while(j>=0) {
				if(board[i][j]==board[i][j+1] && board[i][j]!=0) {
					val += board[i][j]*2;
					flag = true;
					j-=2;
				}
				else
					j--;
			}
			if(flag==false) {
				if(board[i][3]==board[i][1] && board[i][3]!=0 && board[i][2]==0)
					val += board[i][3]*2;

				else if(board[i][2]==board[i][0] && board[i][2]!=0 && board[i][1]==0)
					val += board[i][2]*2;

				else if(board[i][3]==board[i][0] && board[i][3]!=0 && board[i][2]==0 && board[i][1]==0)
					val += board[i][3]*2;
			}
		}
	}
	return val;	
}

void assign_random_number(int board[SIZE][SIZE]) {
	int row, col, random = rand();
	pair<int,int>p = get_loc(board);
	row = p.first;
	col = p.second;

	if(random % 2 ==0) 						
		board[row][col] = 2;
	
	else 								 	
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

void initialize_game(int board[SIZE][SIZE], stack<State>&s) {				
	while(s.empty()==false) 
		s.pop();
	
	assign_random_number(board);
	assign_random_number(board);
}

bool compare(int board[SIZE][SIZE], vector<vector<int>>v) {
	for(int i=0;i<4;i++) {
		for(int j=0;j<4;j++)
			if(board[i][j]!=v[i][j])
				return false;
	}
	return true;
}

bool is_2048(int board[SIZE][SIZE]) {					
	for(int i=0;i<4;i++) {
		for(int j=0;j<4;j++)
			if(board[i][j]==2048)
				return true;
	}
	return false;
}


