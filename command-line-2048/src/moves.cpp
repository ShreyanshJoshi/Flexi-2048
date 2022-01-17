// All functions here are of the moves, the user is allowed to make, namely, up,down,left,right,undo,hint.

#include "header3.h"
#include "header2.h"
#include "header1.h"
#include<bits/stdc++.h>
using namespace std;

void move_up(int a[4][4]) {		
	int i,j,k,m;
	for(j=0;j<4;j++) {									
		i = 0;
		while(i<3) {									
			if(a[i][j]==-1) {
				i++;
				continue;
			}

			k = i+1;
			while(k<=2 && a[k][j]==-1)
				k++;

			if(a[k][j]==a[i][j]) {
				a[i][j] = 2*a[k][j];
				a[k][j] = -1;
				i = k+1;
			}
			else
				i = k;
		}
		for(m=1;m<4;m++) {								// Filling up empty spaces
			if(a[m][j]==-1)
				continue;

			k = m-1;
			while(k>=0 && a[k][j]==-1) 
				k--;
			
			if(k!=m-1) {
				a[k+1][j] = a[m][j];
				a[m][j] = -1;
			}
		}
	}
}
void move_left(int a[4][4]) {
	int i,j,k,m;
	for(i=0;i<4;i++) {									
		j = 0;
		while(j<3) {
			if(a[i][j]==-1) {
				j++;
				continue;
			}
			k = j+1;
			while(k<=2 && a[i][k]==-1)
				k++;

			if(a[i][k]==a[i][j]) {
				a[i][j] = 2*a[i][k];
				a[i][k] = -1;
				j = k+1;
			}
			else
				j = k;
		}

		for(m=1;m<4;m++) {
			if(a[i][m]==-1)
				continue;

			k = m-1;
			while(k>=0 && a[i][k]==-1)
				k--;

			if(k!=m-1) {
				a[i][k+1] = a[i][m];
				a[i][m] = -1;
			}
		}
	}
}
void move_down(int a[4][4]) {
	int i,j,k,m;
	for(j=0;j<4;j++) {									
		i = 3;
		while(i>=1) {									
			if(a[i][j]==-1) {
				i--;
				continue;
			}
			k = i-1;
			while(k>=1 && a[k][j]==-1)
				k--;

			if(a[k][j]==a[i][j]) {
				a[i][j] = 2*a[k][j];
				a[k][j] = -1;
				i = k-1;
			}
			else
				i = k;
		}
		for(m=2;m>=0;m--) {								// Filling up empty spaces
			if(a[m][j]==-1)
				continue;

			k = m+1;
			while(k<4 && a[k][j]==-1) 
				k++;
			
			if(k!=m+1) {
				a[k-1][j] = a[m][j];
				a[m][j] = -1;
			}
		}
	}
}
void move_right(int a[4][4]) {
	int i,j,k,m;
	for(i=0;i<4;i++) {									
		j = 3;
		while(j>=1) {								
			if(a[i][j]==-1) {
				j--;
				continue;
			}
			k = j-1;
			while(k>=1 && a[i][k]==-1) 
				k--;

			if(a[i][k]==a[i][j]) {
				a[i][j] = 2*a[i][k];
				a[i][k] = -1;
				j = k-1;
			}
			else
				j = k;
		}
		for(m=2;m>=0;m--) {
			if(a[i][m]==-1)
				continue;

			k = m+1;
			while(k<4 && a[i][k]==-1)
				k++;

			if(k!=m+1) {
				a[i][k-1] = a[i][m];
				a[i][m] = -1;
			}
		}
	}
}
void hint(int a[4][4]) {

	/* This function, (can be used atmost twice), shows the user the state of the board after each of the possible 4 moves.
	   This will allow the user to make a more informed choice in his/her attempt to reach 2048 */

	int i,j,b[4][4];
	restore(b,a);

	cout<<"If move == up:\n";
	move_up(b);
	display_board(b,-1,false);
	cout<<"\n";
	restore(b,a);

	cout<<"If move == left:\n";
	move_left(b);
	display_board(b,-1,false);
	cout<<"\n";
	restore(b,a);
	
	cout<<"If move == down:\n";
	move_down(b);
	display_board(b,-1,false);
	cout<<"\n";
	restore(b,a);

	cout<<"If move == right:\n";
	move_right(b);
	display_board(b,-1,false);
	cout<<"\n";
}

int undo(int a[4][4], stack<State>&s) {

	/* This function, shows the board (and points) before the previous move to the player. This is done, by popping the topmost
	   elements (which are the current state of board & current points) of stacks s1 and s2 and returning the topmost elements then. */

	vector<vector<int>>v;
	s.pop();			
	v = s.top().v;

	for(int i=0;i<4;i++) 
		for(int j=0;j<4;j++)
			a[i][j] = v[i][j];

	int points = s.top().points;
	
	display_board(a,points,true);	
	return points;
}