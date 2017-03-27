#include "../include/Board.h"
#include <iostream>

using namespace std;

Board::Board()
{
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            space[i][j] = 0;
        }
    }
    victory = 0;
}

Board::~Board()
{
    //dtor
}

void Board::PrintBoard()
{
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            cout << space[i][j] << ' ';
        }
        cout << endl;
    }
}


bool Board::MakeMove(int place, int player)
{
    bool isGoodMove = false;
    for (int i = 5; i >= 0; i--)
    {
        //cout << "position [" << place << ',' << i << "] is: " << space[place][i] << endl;
        if (space[i][place] == 0)
        {
            space[i][place] = player;
            isGoodMove = true;
            break;
        }
    }
    return isGoodMove;
}


int Board::CheckState(int player)
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (space[i][j] == player)
            {
                if (IsVictory(i, j, player))
                {
                    //cout << "Victory!" << endl;
                    victory = player;
                }
            }
        }
    }
    return victory;
}

bool Board::IsVictory(int i, int j, int p)
{
    //cout << "Testing position: " << j << ',' << i << " for " << p << endl;
    if (i<3)
    {
        if (space[i+3][j] == p)
        {
            if (space[i+2][j] == p)
            {
				if (space[i + 1][j] == p)
                    return true;
            }
        }
    }
    if (j<4)
    {
        if (space[i][j+3] == p)
        {
            if (space[i][j+2] == p)
            {
                if (space[i][j+1] == p)
                    return true;
            }
        }
    }
    if (j<4 && i < 3)
        if(space[i+3][j+3] == p)
    {
        if (space[i+2][j+2] == p)
        {
            if (space[i+1][j+1] == p)
                return true;
        }
    }
    if (j<4 && i > 3)
    {
        if (space[i-3][j+3] == p)
        {
            if (space[i-2][j+2] == p)
            {
                if (space[i-1][j+1] == p)
                    return true;
            }
        }
    }
	//cout << "Bad Test" << endl;
    return false;
}

bool Board::IsFull()
{
    int count = 0;
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (space[i][j] != 0)
                count++;
        }
    }
    return (count == 42);
}
