#ifndef MINIMAX_H
#define MINIMAX_H
#include "Board.h"
#include <stack>
using namespace std;
Board ComputerPlay(Board gameboard);

int MiniMax(stack<Board> boardstack, int depth, bool isMe);

#endif
