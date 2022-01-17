#include "base.h"
#include <bits/stdc++.h>

void restore(int copy[4][4], int board[4][4]) {

	int i,j;
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			copy[i][j] = board[i][j];
}

void load_vector(vector<vector<int>>&v, int board[4][4]) {

	int i,j;
	for(i=0;i<4;i++) {
		vector<int>w;
		for(j=0;j<4;j++) 
			w.push_back(board[i][j]);
		
		v.push_back(w);
	}
}

pair<int,int> get_loc(int board[4][4]) {

	int i,j,row,col,temp;
	vector<int>v;
	for(i=0;i<4;i++) {
		for(j=0;j<4;j++) 
			if(board[i][j]==0)
				v.push_back(4*i+j);
		
	}
	if(v.size()==0)	{							// no empty slot available for new number. Player has lost basically.
		pair<int,int>p = {-1,-1};	
		return p;
	}

	temp = rand();
	temp = temp % v.size();
	row = v[temp]/4;
	col = v[temp]%4;

	pair<int,int>p = {row,col};
	return p;
}