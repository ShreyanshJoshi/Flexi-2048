#include "moves.h"
#include <bits/stdc++.h>
using namespace std;

void move_up(int a[4][4]) {		
	int i,j,k,m;
	for(j=0;j<4;j++) {									
		i = 0;
		while(i<3) {									
			if(a[i][j]==0) {
				i++;
				continue;
			}

			k = i+1;
			while(k<=2 && a[k][j]==0)
				k++;

			if(a[k][j]==a[i][j]) {
				a[i][j] = 2*a[k][j];
				a[k][j] = 0;
				i = k+1;
			}
			else
				i = k;
		}
		for(m=1;m<4;m++) {								// Filling up empty spaces
			if(a[m][j]==0)
				continue;

			k = m-1;
			while(k>=0 && a[k][j]==0) 
				k--;
			
			if(k!=m-1) {
				a[k+1][j] = a[m][j];
				a[m][j] = 0;
			}
		}
	}
}
void move_left(int a[4][4]) {
	int i,j,k,m;
	for(i=0;i<4;i++) {									
		j = 0;
		while(j<3) {
			if(a[i][j]==0) {
				j++;
				continue;
			}
			k = j+1;
			while(k<=2 && a[i][k]==0)
				k++;

			if(a[i][k]==a[i][j]) {
				a[i][j] = 2*a[i][k];
				a[i][k] = 0;
				j = k+1;
			}
			else
				j = k;
		}

		for(m=1;m<4;m++) {
			if(a[i][m]==0)
				continue;

			k = m-1;
			while(k>=0 && a[i][k]==0)
				k--;

			if(k!=m-1) {
				a[i][k+1] = a[i][m];
				a[i][m] = 0;
			}
		}
	}
}
void move_down(int a[4][4]) {
	int i,j,k,m;
	for(j=0;j<4;j++) {									
		i = 3;
		while(i>=1) {									
			if(a[i][j]==0) {
				i--;
				continue;
			}
			k = i-1;
			while(k>=1 && a[k][j]==0)
				k--;

			if(a[k][j]==a[i][j]) {
				a[i][j] = 2*a[k][j];
				a[k][j] = 0;
				i = k-1;
			}
			else
				i = k;
		}
		for(m=2;m>=0;m--) {								// Filling up empty spaces
			if(a[m][j]==0)
				continue;

			k = m+1;
			while(k<4 && a[k][j]==0) 
				k++;
			
			if(k!=m+1) {
				a[k-1][j] = a[m][j];
				a[m][j] = 0;
			}
		}
	}
}
void move_right(int a[4][4]) {
	int i,j,k,m;
	for(i=0;i<4;i++) {									
		j = 3;
		while(j>=1) {								
			if(a[i][j]==0) {
				j--;
				continue;
			}
			k = j-1;
			while(k>=1 && a[i][k]==0) 
				k--;

			if(a[i][k]==a[i][j]) {
				a[i][j] = 2*a[i][k];
				a[i][k] = 0;
				j = k-1;
			}
			else
				j = k;
		}
		for(m=2;m>=0;m--) {
			if(a[i][m]==0)
				continue;

			k = m+1;
			while(k<4 && a[i][k]==0)
				k++;

			if(k!=m+1) {
				a[i][k-1] = a[i][m];
				a[i][m] = 0;
			}
		}
	}
}