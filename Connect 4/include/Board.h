#ifndef BOARD_H
#define BOARD_H
#include <iostream>

class Board
{
    public:
        /** Default constructor */
        Board();
        /** Default destructor */
        virtual ~Board();
        void PrintBoard();
        bool MakeMove(int, int);
        int CheckState(int);
        bool IsFull();
    protected:

    private:
        int space[6][7];
        int victory;
        bool IsVictory(int, int, int);
};

#endif // BOARD_H
