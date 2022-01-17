/* This file has all function definitions that serve the most fundamental purpose in creating the game. These functions are not of 
   the moves a player makes, but something even more fundamental such as displaying board, initializing board, generating random numbers for
   the next move, etc. Quite a few functions here are also called by other functions (grouped in another file). */

#include "header2.h"
#include "header1.h"
#include<bits/stdc++.h>
using namespace std;

void initialize_game(int a[4][4]) {				

	/* Initializes the board with 2 numbers (could be 2 or 4),randomly placed. Used only while starting the game. */

	bool temp1 = assign_random_number(a);
	bool temp2 = assign_random_number(a);
}

void display_board(int a[4][4], int points, bool flag) {

	/* The flag variable just indicates, whether we want to display points or not. Only case when it's not used would be in case when
	   when player opted for a hint or has entered wrong/more than 1 character. */

	int i,j;
	for(i=0;i<4;i++) {
		for(j=0;j<4;j++) {
			if(a[i][j]!=-1)  {
				if(a[i][j]==2 || a[i][j]==4 || a[i][j]==8)
					cout<<"000"<<a[i][j]<<"     ";

				else if(a[i][j]==16 || a[i][j]==32 || a[i][j]==64)
					cout<<"00"<<a[i][j]<<"     ";

				else if(a[i][j]==128 || a[i][j]==256 || a[i][j]==512)
					cout<<"0"<<a[i][j]<<"     ";

				else
					cout<<a[i][j]<<"     ";
			}

			else
				cout<<"****"<<"     ";
		}
		if(i==0 && flag)
			cout<<"POINTS: "<<points;

		cout<<"\n";
	}
}

bool is_2048(int a[4][4]) {					

	/* checks if 2048 is there anywhere in the board */
	
	for(int i=0;i<4;i++) {
		for(int j=0;j<4;j++)
			if(a[i][j]==2048)
				return true;
	}
	return false;
}

bool compare(int a[4][4], vector<vector<int>>v) {

	/* This function checks, if the board before the last move was exactly same as after the last move. If so, no new random number
	   needs to be placed anywhere onto the board. */
	
	for(int i=0;i<4;i++) {
		for(int j=0;j<4;j++)
			if(a[i][j]!=v[i][j])
				return false;
	}
	return true;
}

bool assign_random_number(int a[4][4]) {

	/* This is a crucial function to the game. It places a randomly generated number (2 or 4) at a empty position available on the
	   board. First, it finalizes the number to be placed (one of 2 or 4). Then, this function calls the above 'get_loc' function,
	   which returns a pair of integers, denoting a randomly chosen empty slot on the board. Finally, the finalized number is placed 
	   at that empty slot. */

	int row, col, random = rand();
	pair<int,int>p = get_loc(a);
	row = p.first;
	col = p.second;

	if(row==-1 && col==-1)					// no empty space available. Game Over!
		return false;

	if(random % 2 ==0) 						// 2 is generated
		a[row][col] = 2;
	
	else 								 	// 4 is generated
		a[row][col] = 4;

	return true;
	
}