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

void clear_board(int board[Y_DIM][X_DIM]) {
	for (int i=0; i<Y_DIM; i++) 
		for (int j=0; j<X_DIM; j++) 
			board[i][j] = 0;
		
}

int calculate_score(int board[Y_DIM][X_DIM], char c) {
	int i,j,k,m,val = 0;
	bool flag;

	if(c=='w') {								// up
		for(j=0;j<X_DIM;j++) {
			i = 1;
			flag = false;
			while(i<Y_DIM) {
				if(board[i][j]==board[i-1][j] && board[i][j]!=0) {
					val += board[i][j]*2;
					flag = true;
					i+=2;
				}
				else
					i++;
			}
			if(flag==false) {
				for(k=0;k<Y_DIM-2;k++) {
					for(m=k+2;m<Y_DIM;m++) {
						if(board[k][j]==board[m][j] && board[k][j]!=0) {
							// checking if all elements between these 2 are 0s or not.
							bool temp = false;
							for(int l=k+1;l<m;l++)
								if(board[l][j]!=0)
									temp = true;

							if(temp==false)
								val += board[k][j]*2;
						}
					}
				}
			}
		}
	}
	else if(c=='a') {							// left
		for(i=0;i<Y_DIM;i++) {
			j = 1;
			flag = false;
			while(j<X_DIM) {
				if(board[i][j]==board[i][j-1] && board[i][j]!=0) {
					val += board[i][j]*2;
					flag = true;
					j+=2;
				}
				else
					j++;
			}
			if(flag==false) {
				for(k=0;k<X_DIM-2;k++) {
					for(m=k+2;m<X_DIM;m++) {
						if(board[i][k]==board[i][m] && board[i][k]!=0) {
							// checking if all elements between these 2 are 0s or not.
							bool temp = false;
							for(int l=k+1;l<m;l++)
								if(board[i][l]!=0)
									temp = true;

							if(temp==false)
								val += board[i][k]*2;
						}
					}
				}
			}
		}
	}
	else if(c=='s') {							// down
		for(j=0;j<X_DIM;j++) {
			i = Y_DIM-2;
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
				for(k=Y_DIM-1;k>=2;k--) {
					for(m=k-2;m>=0;m--) {
						if(board[k][j]==board[m][j] && board[k][j]!=0) {
							// checking if all elements between these 2 are 0s or not.
							bool temp = false;
							for(int l=k-1;l>m;l--)
								if(board[l][j]!=0)
									temp = true;

							if(temp==false)
								val += board[k][j]*2;
						}
					}
				}
			}
		}
	}
	else {										// right
		for(i=0;i<Y_DIM;i++) {
			j = X_DIM-2;
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
				for(k=X_DIM-1;k>=2;k--) {
					for(m=k-2;m>=0;m--) {
						if(board[i][k]==board[i][m] && board[i][k]!=0) {
							// checking if all elements between these 2 are 0s or not.
							bool temp = false;
							for(int l=k-1;l>m;l--)
								if(board[i][l]!=0)
									temp = true;

							if(temp==false)
								val += board[i][k]*2;
						}
					}
				}
			}
		}
	}
	return val;	
}

void assign_random_number(int board[Y_DIM][X_DIM]) {
	int row, col, random = rand();
	pair<int,int>p = get_loc(board);
	row = p.first;
	col = p.second;

	if(random % 2 ==0) 						
		board[row][col] = 2;
	
	else 								 	
		board[row][col] = 4;
	
}

bool is_game_over(int board[Y_DIM][X_DIM]) {
	for (int i=0; i<Y_DIM-1; i++) {
		for (int j=0; j<X_DIM-1; j++) 
			if (board[i][j]==board[i][j+1] || board[i][j]==board[i+1][j] || board[i][j]==0)
				return false;

		if (board[i][X_DIM-1]==board[i+1][X_DIM-1] || board[i][X_DIM-1]==0)
			return false;
	}

	// checking the last row of the board
	for(int j=0; j<X_DIM-1; j++) 
		if (board[Y_DIM-1][j]==board[Y_DIM-1][j+1] || board[Y_DIM-1][j]==0)
			return false;
	
	return true;
}

void initialize_game(int board[Y_DIM][X_DIM], stack<State>&s) {				
	while(s.empty()==false) 
		s.pop();
	
	assign_random_number(board);
	assign_random_number(board);
}

bool compare(int board[Y_DIM][X_DIM], vector<vector<int>>v) {
	for(int i=0;i<Y_DIM;i++) {
		for(int j=0;j<X_DIM;j++)
			if(board[i][j]!=v[i][j])
				return false;
	}
	return true;
}

bool is_2048(int board[Y_DIM][X_DIM]) {					
	for(int i=0;i<Y_DIM;i++) {
		for(int j=0;j<X_DIM;j++)
			if(board[i][j]==2048)
				return true;
	}
	return false;
}


