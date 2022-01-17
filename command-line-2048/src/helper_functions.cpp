/* This file only consists of helper functions. Such functions are of no use to themselves, and hence form a part of other functions.
   Put simply, these functions are called by functions in other files in a bid to achieve their goal. */

#include "header1.h"
#include<bits/stdc++.h>

void restore(int b[4][4], int a[4][4]) {

	/* This function restores b, to values of a i.e makes matrix b equal to a. This function is used only when a user opts 
	   for a hint. */

	int i,j;
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			b[i][j] = a[i][j];
}
void load_vector(vector<vector<int>>&v, int a[4][4]) {

	/* This function copies the value of matrix a to vector of vectors (just another form of representation that's more convenient in C++). 
	   This function is used only while storing the current state of board on a stack (for enabling user to undo his/her current move).*/

	int i,j;
	for(i=0;i<4;i++) {
		vector<int>w;
		for(j=0;j<4;j++) 
			w.push_back(a[i][j]);
		
		v.push_back(w);
	}
}
pair<int,int> get_loc(int a[4][4]) {

	/* First, we need to store all empty positions in the matrix into a vector v. Then, we choose any position randomly from
	   v, and return it in form of a pair */

	int i,j,row,col,temp;
	vector<int>v;
	for(i=0;i<4;i++) {
		for(j=0;j<4;j++) 
			if(a[i][j]==-1)
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