/**
 * @file moves.cpp
 * @author Shreyansh Joshi
 * @brief File containing implementation of the move related functions.
 *
 */
#include "moves.h"
#include <bits/stdc++.h>
using namespace std;

void move_up(int board[Y_DIM][X_DIM]) {		
	int i,j,k,m;
	for(j=0;j<X_DIM;j++) {									
		i = 0;
		while(i<Y_DIM-1) {									
			if(board[i][j]==0) {
				i++;
				continue;
			}

			k = i+1;
			while(k<=Y_DIM-2 && board[k][j]==0)
				k++;

			if(board[k][j]==board[i][j]) {
				board[i][j] = 2*board[k][j];
				board[k][j] = 0;
				i = k+1;
			}
			else
				i = k;
		}
		for(m=1;m<Y_DIM;m++) {								// Filling up empty spaces
			if(board[m][j]==0)
				continue;

			k = m-1;
			while(k>=0 && board[k][j]==0) 
				k--;
			
			if(k!=m-1) {
				board[k+1][j] = board[m][j];
				board[m][j] = 0;
			}
		}
	}
}

void move_left(int board[Y_DIM][X_DIM]) {
	int i,j,k,m;
	for(i=0;i<Y_DIM;i++) {									
		j = 0;
		while(j<X_DIM-1) {
			if(board[i][j]==0) {
				j++;
				continue;
			}
			k = j+1;
			while(k<=X_DIM-2 && board[i][k]==0)
				k++;

			if(board[i][k]==board[i][j]) {
				board[i][j] = 2*board[i][k];
				board[i][k] = 0;
				j = k+1;
			}
			else
				j = k;
		}

		for(m=1;m<X_DIM;m++) {								// Filling up empty spaces
			if(board[i][m]==0)
				continue;

			k = m-1;
			while(k>=0 && board[i][k]==0)
				k--;

			if(k!=m-1) {
				board[i][k+1] = board[i][m];
				board[i][m] = 0;
			}
		}
	}
}

void move_down(int board[Y_DIM][X_DIM]) {
	int i,j,k,m;
	for(j=0;j<X_DIM;j++) {									
		i = Y_DIM-1;
		while(i>=1) {									
			if(board[i][j]==0) {
				i--;
				continue;
			}
			k = i-1;
			while(k>=1 && board[k][j]==0)
				k--;

			if(board[k][j]==board[i][j]) {
				board[i][j] = 2*board[k][j];
				board[k][j] = 0;
				i = k-1;
			}
			else
				i = k;
		}
		for(m=Y_DIM-2;m>=0;m--) {								// Filling up empty spaces
			if(board[m][j]==0)
				continue;

			k = m+1;
			while(k<Y_DIM && board[k][j]==0) 
				k++;
			
			if(k!=m+1) {
				board[k-1][j] = board[m][j];
				board[m][j] = 0;
			}
		}
	}
}

void move_right(int board[Y_DIM][X_DIM]) {
	int i,j,k,m;
	for(i=0;i<Y_DIM;i++) {									
		j = X_DIM-1;
		while(j>=1) {								
			if(board[i][j]==0) {
				j--;
				continue;
			}
			k = j-1;
			while(k>=1 && board[i][k]==0) 
				k--;

			if(board[i][k]==board[i][j]) {
				board[i][j] = 2*board[i][k];
				board[i][k] = 0;
				j = k-1;
			}
			else
				j = k;
		}
		for(m=X_DIM-2;m>=0;m--) {								// Filling up empty spaces
			if(board[i][m]==0)
				continue;

			k = m+1;
			while(k<X_DIM && board[i][k]==0)
				k++;

			if(k!=m+1) {
				board[i][k-1] = board[i][m];
				board[i][m] = 0;
			}
		}
	}
}