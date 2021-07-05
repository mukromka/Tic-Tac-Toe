#pragma once
#include "player.h"
#include <iostream>
using namespace std;
class Board {
    private:
        char arena[999];
        bool XWin = false;
        bool OWin = false;
    public:
        Board();
        void printBoard();
        bool isFull(bool draw);
        void isEmpty(const size_t& choseNum, char& player, bool& inputPass);
        void checkHorizontalWin();
        void checkVerticalWin();
        int exportArena(int i)
        {
            return arena[i];
        }
        void setXwin(bool winner)
        {
            XWin = winner;
            cout << "X win";
        }
        void setOwin(bool winner)
        {
            OWin = winner;
            cout << "O win";
        }
        bool getXwin()
        {
            return XWin;
        }
        bool getOwin()
        {
            return OWin;
        }
};

