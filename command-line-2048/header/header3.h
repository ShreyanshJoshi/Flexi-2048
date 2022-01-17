#ifndef HEADER_GUARD_3				
#define HEADER_GUARD_3

#include "header1.h"
#include<stack>
using namespace std;


void move_up(int a[4][4]);
void move_left(int a[4][4]);
void move_down(int a[4][4]);
void move_right(int a[4][4]);
void hint(int a[4][4]);
int undo(int a[4][4],stack<State>&s);

#endif