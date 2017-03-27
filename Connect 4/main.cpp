#include "./include/Board.h"
#include "./include/MiniMax.h"
#include <iostream>
#include <queue>
using namespace std;

int ChangePlayer(int player);
Board PlayTurn(int player, Board gameboard);
Board ComputerPlay(Board gameboard);

int main()
{
    int winner = 0;
    int player;
    Board gameboard;

    cout << "who plays first?";
    cin >> player;

    while(winner == 0)
    {
        gameboard = PlayTurn(player, gameboard);
        winner = gameboard.CheckState(player);
        player = ((player % 2) + 1);
    }
    gameboard.PrintBoard();
    cout << "Player " << winner << " wins!" << endl;
}


Board PlayTurn(int player, Board gameboard)
{
    int play;
    if (player == 1)
    {
        cout << "Player 1:" << endl;
        gameboard.PrintBoard();
		do
		{
			cout << "make move:";
			cin >> play;
		} while (!gameboard.MakeMove(play, 1) && play > 7 && play < 0);
        return gameboard;
    }
    else
    {
        return ComputerPlay(gameboard);
    }
}
