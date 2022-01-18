#include "../header/helper.h"
#include <bits/stdc++.h>

void restore(int b[4][4], int a[4][4]) {
	int i,j;
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			b[i][j] = a[i][j];
}

void load_vector(vector<vector<int>>&v, int a[4][4]) {
	int i,j;
	for(i=0;i<4;i++) {
		vector<int>w;
		for(j=0;j<4;j++) 
			w.push_back(a[i][j]);
		
		v.push_back(w);
	}
}

pair<int,int> get_loc(int a[4][4]) {
	int i,j,row,col,temp;
	vector<int>v;

	for(i=0;i<4;i++) {
		for(j=0;j<4;j++) 
			if(a[i][j]==-1)
				v.push_back(4*i+j);
		
	}
	if(v.size()==0)	{				
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