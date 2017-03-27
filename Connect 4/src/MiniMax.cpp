#include "../include/MiniMax.h"
#include "../include/Board.h"
#include <stack>
using namespace std;


Board ComputerPlay(Board gameboard)
{
    int moveset [7] = {0, 0, 0, 0, 0, 0, 0};
    Board newboard = gameboard;
    int movetomake = 3;
    stack<Board> boardstack;
    for (int i = 0; i < 7; i++)
    {
        newboard.MakeMove(i,2);
        boardstack.push(newboard);
        moveset[i] = MiniMax(boardstack, 3, false);
        newboard = gameboard;
    }
	cout << '[';
	for (int i = 0; i < 7; i++)
		cout << moveset[i] << ", ";
	cout << ']' << endl;
	do
	{
		for (int i = 0; i < 7; i++)
		{
			if (moveset[movetomake] < moveset[i])
				movetomake = i;
		}
		moveset[movetomake] = -500;
	} while (!gameboard.MakeMove(movetomake, 2));
    return gameboard;
}


int MiniMax(stack<Board> boardstack, int depth, bool isMe)
{
	if (boardstack.empty())
	{
		cout << "EMPTY STACK!" << endl;
		return 0;
	}
    Board board = boardstack.top();
    Board tboard = board;
    boardstack.pop();
    int bestval, v;
    if (depth == 0 || (board.CheckState(1) != 0 || board.CheckState(2) != 0 ) || board.IsFull())
    {
        //cout << endl;
        //board.PrintBoard();
        if (board.CheckState(1) == 1)
            return -1;
        else if (board.CheckState(2) == 2)
            return 1;
        else
            return 0;
    }
    if (isMe)
    {
        bestval = -200;
        for (int i = 0; i < 7; i++)
        {
            if(tboard.MakeMove(i,2))
                boardstack.push(tboard);
            tboard = board;
            v = MiniMax(boardstack, depth-1, !isMe);
            bestval = max(bestval, v);
        }
        return bestval;
    }

    else
    {
        bestval = 200;
                for (int i = 0; i < 7; i++)
        {
            if(tboard.MakeMove(i,1))
                boardstack.push(tboard);
            tboard = board;
            v = MiniMax(boardstack, depth-1, !isMe);
            bestval = min(bestval, v);
        }
        return bestval;
    }
}
