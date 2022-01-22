/**
 * @file helper.cpp
 * @author Shreyansh Joshi
 * @brief File containing implementation of the helper functions (functions that are of no practical use in themselves
 * and just help the core functions).
 *
 */
#include "base.h"
#include <bits/stdc++.h>

void load_vector(vector<vector<int>>&v, int board[Y_DIM][X_DIM]) {
	for(int i=0;i<Y_DIM;i++) {
		vector<int>w;
		for(int j=0;j<X_DIM;j++) 
			w.push_back(board[i][j]);
		
		v.push_back(w);
	}
}

pair<int,int> get_loc(int board[Y_DIM][X_DIM]) {
	vector<int>v;
	for(int i=0;i<Y_DIM;i++) 
		for(int j=0;j<X_DIM;j++) 
			if(board[i][j]==0)
				v.push_back(X_DIM*i+j);	
	
	if(v.size()==0)	{						
		pair<int,int>p = {-1,-1};	
		return p;
	}

	int temp = rand();
	temp = temp % v.size();
	int row = v[temp]/X_DIM;
	int col = v[temp]%X_DIM;

	pair<int,int>p = {row,col};
	return p;
}