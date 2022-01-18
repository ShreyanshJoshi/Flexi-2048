/**
 * @file moves.cpp
 * @author Shreyansh Joshi
 * @brief File containing implementation of the move related functions.
 *
 */
#include "moves.h"
#include <bits/stdc++.h>
using namespace std;

void move_up(int board[SIZE][SIZE]) {		
	int i,j,k,m;
	for(j=0;j<4;j++) {									
		i = 0;
		while(i<3) {									
			if(board[i][j]==0) {
				i++;
				continue;
			}

			k = i+1;
			while(k<=2 && board[k][j]==0)
				k++;

			if(board[k][j]==board[i][j]) {
				board[i][j] = 2*board[k][j];
				board[k][j] = 0;
				i = k+1;
			}
			else
				i = k;
		}
		for(m=1;m<4;m++) {								// Filling up empty spaces
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
void move_left(int board[SIZE][SIZE]) {
	int i,j,k,m;
	for(i=0;i<4;i++) {									
		j = 0;
		while(j<3) {
			if(board[i][j]==0) {
				j++;
				continue;
			}
			k = j+1;
			while(k<=2 && board[i][k]==0)
				k++;

			if(board[i][k]==board[i][j]) {
				board[i][j] = 2*board[i][k];
				board[i][k] = 0;
				j = k+1;
			}
			else
				j = k;
		}

		for(m=1;m<4;m++) {
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
void move_down(int board[SIZE][SIZE]) {
	int i,j,k,m;
	for(j=0;j<4;j++) {									
		i = 3;
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
		for(m=2;m>=0;m--) {								// Filling up empty spaces
			if(board[m][j]==0)
				continue;

			k = m+1;
			while(k<4 && board[k][j]==0) 
				k++;
			
			if(k!=m+1) {
				board[k-1][j] = board[m][j];
				board[m][j] = 0;
			}
		}
	}
}
void move_right(int board[SIZE][SIZE]) {
	int i,j,k,m;
	for(i=0;i<4;i++) {									
		j = 3;
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
		for(m=2;m>=0;m--) {
			if(board[i][m]==0)
				continue;

			k = m+1;
			while(k<4 && board[i][k]==0)
				k++;

			if(k!=m+1) {
				board[i][k-1] = board[i][m];
				board[i][m] = 0;
			}
		}
	}
}