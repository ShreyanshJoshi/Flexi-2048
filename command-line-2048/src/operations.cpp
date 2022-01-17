/* Functions grouped in this file are those that perform the functionalities that user must see while playing the game. Note that all these
   functionalities are purely optional (except score function maybe), and their absence won't affect the 2048 game in any way.*/

#include "header4.h"
#include<bits/stdc++.h>
using namespace std;

int max_tile(int a[4][4]) {
	int i,j,ans = -1;
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			ans = max(ans,a[i][j]);

	return ans;
}

void list_count(int a[4][4]) {
	int i,j;
	set<int>s;

	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			if(a[i][j]!=-1)
				s.insert(a[i][j]);

	cout<<"There are currently "<<s.size()<<" different values in the matrix - ";
	for(auto it:s)
		cout<<it<<" ";

	cout<<endl;
}

int sum_tiles(int a[4][4]) {

	int i,j,sum=0;
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			if(a[i][j]!=-1)
				sum+=a[i][j];

	return sum;
}

int max_possibleval_in1move(int a[4][4]) {
	int ans = max_tile(a), i,j;

	for(i=0;i<4;i++) {							// left or right moves
		for(j=0;j<3;j++)
			if(a[i][j]==a[i][j+1])
				ans = max(ans,2*a[i][j]);
	}
	for(j=0;j<4;j++) {
		for(i=0;i<3;i++)
			if(a[i][j]==a[i+1][j])
				ans = max(ans, 2*a[i][j]);
	}
	return ans;
}

int score(int a[4][4], char c) {
	int i,j,val = 0;
	bool flag;

	if(c=='w') {								// up
		for(j=0;j<4;j++) {
			i = 1;
			flag = false;
			while(i<4) {
				if(a[i][j]==a[i-1][j] && a[i][j]!=-1) {
					val += a[i][j]*2;
					flag = true;
					i+=2;
				}
				else
					i++;
			}
			if(flag==false) {
				// now only 1 sum can be obtained from this column
				if(a[0][j]==a[2][j] && a[0][j]!=-1 && a[1][j]==-1)
					val += a[0][j]*2;

				else if(a[1][j]==a[3][j] && a[1][j]!=-1 && a[2][j]==-1)
					val += a[1][j]*2;

				else if(a[0][j]==a[3][j] && a[0][j]!=-1 && a[1][j]==-1 && a[2][j]==-1)
					val += a[0][j]*2;
			}
		}
	}
	else if(c=='a') {							// left
		for(i=0;i<4;i++) {
			j = 1;
			flag = false;
			while(j<4) {
				if(a[i][j]==a[i][j-1] && a[i][j]!=-1) {
					val += a[i][j]*2;
					flag = true;
					j+=2;
				}
				else
					j++;
			}
			if(flag==false) {
				// now only 1 sum can be obtained from this row
				if(a[i][0]==a[i][2] && a[i][0]!=-1 && a[i][1]==-1)
					val += a[i][0]*2;

				else if(a[i][1]==a[i][3] && a[i][1]!=-1 && a[i][2]==-1)
					val += a[i][1]*2;

				else if(a[i][0]==a[i][3] && a[i][0]!=-1 && a[i][1]==-1 && a[i][2]==-1)
					val += a[i][0]*2;
			}
		}
	}
	else if(c=='s') {							// down
		for(j=0;j<4;j++) {
			i = 2;
			flag = false;
			while(i>=0) {
				if(a[i][j]==a[i+1][j] && a[i][j]!=-1) {
					val += a[i][j]*2;
					flag = true;
					i-=2;
				}
				else
					i--;
			}
			if(flag==false) {
				// now only 1 sum can be obtained from this column
				if(a[3][j]==a[1][j] && a[3][j]!=-1 && a[2][j]==-1)
					val += a[3][j]*2;

				else if(a[2][j]==a[0][j]  && a[2][j]!=-1 && a[1][j]==-1)
					val += a[2][j]*2;

				else if(a[3][j]==a[0][j] && a[3][j]!=-1 && a[2][j]==-1 && a[1][j]==-1)
					val += a[3][j]*2;
			}
		}
	}
	else {										// right
		for(i=0;i<4;i++) {
			j = 2;
			flag = false;
			while(j>=0) {
				if(a[i][j]==a[i][j+1] && a[i][j]!=-1) {
					val += a[i][j]*2;
					flag = true;
					j-=2;
				}
				else
					j--;
			}
			if(flag==false) {
				// now only 1 sum can be obtained from this row
				if(a[i][3]==a[i][1] && a[i][3]!=-1 && a[i][2]==-1)
					val += a[i][3]*2;

				else if(a[i][2]==a[i][0] && a[i][2]!=-1 && a[i][1]==-1)
					val += a[i][2]*2;

				else if(a[i][3]==a[i][0] && a[i][3]!=-1 && a[i][2]==-1 && a[i][1]==-1)
					val += a[i][3]*2;
			}
		}
	}
	return val;	
}