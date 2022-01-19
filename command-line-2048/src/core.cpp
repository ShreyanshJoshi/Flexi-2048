#include "../header/core.h"
#include "../header/helper.h"
#include <bits/stdc++.h>
using namespace std;

void initialize_game(int a[4][4]) {				
	assign_random_number(a);
	assign_random_number(a);
}

void display_board(int a[4][4], int points, bool flag) {
	for(int i=0;i<4;i++) {
		for(int j=0;j<4;j++) {
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
	for(int i=0;i<4;i++) {
		for(int j=0;j<4;j++)
			if(a[i][j]==2048)
				return true;
	}
	return false;
}

bool compare(int a[4][4], vector<vector<int>>v) {
	for(int i=0;i<4;i++) {
		for(int j=0;j<4;j++)
			if(a[i][j]!=v[i][j])
				return false;
	}
	return true;
}

bool is_game_over(int a[4][4]) {
	for (int x=0; x<3; x++) {
		for (int y=0; y<3; y++) {
			if (a[x][y] == a[x][y+1] || a[x][y] == a[x+1][y] || a[x][y] == -1)
				return false;			
		}
		if (a[x][3] == a[x+1][3] || a[x][3] == -1)
			return false;
		
		if (a[3][x] == a[3][x+1] || a[3][x] == -1)
			return false;
	}
	return true;
}

void assign_random_number(int a[4][4]) {
	int random = rand();
	pair<int,int>p = get_loc(a);
	int row = p.first;
	int col = p.second;

	if(random % 2 ==0) 						// 2 is generated
		a[row][col] = 2;
	
	else 								 	// 4 is generated
		a[row][col] = 4;
	
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