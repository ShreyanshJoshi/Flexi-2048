#ifndef HEADER_GUARD_2				
#define HEADER_GUARD_2

#include<vector>
using namespace std;

void initialize_game(int a[4][4]);
void display_board(int a[4][4], int points, bool flag);
bool is_2048(int a[4][4]) ;
bool compare(int a[4][4], vector<vector<int>>v) ;
bool assign_random_number(int a[4][4]);

#endif