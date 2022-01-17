/* Across all files in this project, I have tried to minimize the use of global variables as much as possible, for the simple reason that
   it's a bad practice. Global variables make it very difficult to debug the code by tracking down where the variable was modified */

#include<bits/stdc++.h>
#include "header1.h"
#include "header2.h"
#include "header3.h"
#include "header4.h"
using namespace std;

int main() {
	
	int i,j,temp,flag = 0, count = 0, points = 0, undoed = 0, hinted = 0, wc = 0, same = 0;
	char c,d;
	string str;

	srand(time(0));		// seed for random number generator - ensures values are generated randomly on each run or program		 

	int a[4][4];	

	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			a[i][j] = -1;

	initialize_game(a);
	stack<State>s;						

	while(1) {

		/* Before every move, the current state of board is shown to the player, based on which he/she makes the move.
		   The board is shown in all cases except then the last move was a hint, undo or a wrong character, each denoted by
		   hinted,undoed and wc respectively */

		if(wc==1 || hinted==1 || undoed==1);

		else if(same==1)
			display_board(a,points,true);

		else {
			vector<vector<int>>v;

			display_board(a,points,true); 
			load_vector(v,a);

			State st;
			st.v = v;
			st.points = points;
			s.push(st);
		}

		// list_count(a);
		// cout<<"Max tile value currently is "<<max_tile(a)<<"\n";
		// cout<<"Sum of all tiles currently is "<<sum_tiles(a)<<"\n";
		// cout<<"Maximum possible tile value attainable in one move is "<<max_possibleval_in1move(a)<<"\n\n";

		undoed = 0;
		hinted = 0;
		wc = 0;
		same = 0;

		cin>>str;
		if(str.size()>1) {
			cout<<"Enter only 1 character.\n";
			wc = 1;
			continue;
		}
		c = str[0];
		if(c=='q') {
			cout<<"You have ended the game.\n";
			break;
		}

		if(c=='w' || c=='a' || c=='s' || c=='d')
			points += score(a,c);

		if(c=='w') 
			move_up(a);

		else if(c=='a')
			move_left(a);

		else if(c=='s')
			move_down(a);

		else if(c=='d')
			move_right(a);

		else if(c=='h' && count<2) {
			hint(a);
			count++; 
			hinted = 1;
			continue;
		}
		else if(c=='h' && count>=2) {
			cout<<"U have used all the hints. Try a different character.\n";
			hinted = 1;
			continue;
		}

		else if(c=='u') {
			if(s.size() < 2) {
				cout<<"Can't undo now.\n";
				undoed = 1;
				continue;
			}
			points = undo(a,s);
			undoed = 1;
			continue;					
		}

		else {
			cout<<"Wrong character entered.\n";
			wc = 1;
			continue;
		} 

		if(is_2048(a)) {							// check after each move, if game is over or not.						
			flag = 1;
			break;
		}
		if(s.size()>=1 && compare(a, s.top().v)){ 
			same = 1;
			continue;
		}

		// after each move, we need to generate a random number (2 or 4) that has to be placed at some vacant position on the board
		bool var = assign_random_number(a);
		if(var==false)
			break;

	}
	if(flag==0)
		cout<<"GAME OVER!"<<endl;

	else {
		display_board(a,points,true);
		cout<<"YOU WIN !!"<<endl;
	}
}