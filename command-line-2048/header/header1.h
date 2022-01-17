#ifndef HEADER_GUARD_1				
#define HEADER_GUARD_1

#include<vector>
using namespace std;

struct State {
	vector<vector<int>>v;
	int points;
};
void restore(int b[4][4], int a[4][4]);
void load_vector(vector<vector<int>>&v, int a[4][4]);
pair<int,int> get_loc(int a[4][4]);

#endif