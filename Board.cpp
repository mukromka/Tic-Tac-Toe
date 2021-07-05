#include "board.h"
#include "player.h"
#include "save.h"
#include <iostream>
#define MAX_ARENA 9

using namespace std;
Player players;
Board::Board()
{
    for (int i = 0; i < MAX_ARENA; i++)
    {
        arena[i] = ' ' ;
    }

}


void Board::printBoard()
{
    {
        system("cls");
        int j = 0;
        for (int i = 0; i < MAX_ARENA / 3; i++)
        {
            cout << arena[j] << "|"; j++;
            cout << arena[j] << "|"; j++;
            cout << arena[j] << endl; j++;
        }

    }
}
void Board::isEmpty(const size_t& choseNum, char& player, bool& inputPass)
{
    Save saveGame;
    char checkNum = arena[choseNum - 1];
    cout << player;
    if (checkNum != (char)Players::Player_X && checkNum != (char)Players::Player_O)
    {
        if (choseNum >= 1 && choseNum <= 9)
        {
            arena[choseNum - 1] = player;
            inputPass = true;
        }
        else if (choseNum == 0)
        {
            saveGame.saveGame(players.getNameX(), players.getNameO());
            system("pause");
            inputPass = true;
        }

        {
            cout << "CHOOSE THE AVAILABLE NUMBER!\nTRY AGAIN: ";
        }
    }
    else
    {
        cout << "SPACE HAS ALREADY BEEN OCCUPIED\nTry again: ";
    }
}
void Board::checkHorizontalWin()
{
    if (arena[0] == (char)Players::Player_X)
    {
        if (arena[1] == (char)Players::Player_X)
            if (arena[2] == (char)Players::Player_X)
                XWin = true;
    }
    else if (arena[0] == (char)Players::Player_O)
    {
        if (arena[1] == (char)Players::Player_O)
            if (arena[2] == (char)Players::Player_O)
                OWin = true;
    }
    if (arena[3] == (char)Players::Player_X)
    {
        if (arena[4] == (char)Players::Player_X)
            if (arena[5] == (char)Players::Player_X)
                XWin = true;
    }
    else if (arena[3] == (char)Players::Player_O)
    {
        if (arena[4] == (char)Players::Player_O)
            if (arena[5] == (char)Players::Player_O)
                OWin = true;
    }
    if (arena[6] == (char)Players::Player_X)
    {
        if (arena[7] == (char)Players::Player_X)
            if (arena[8] == (char)Players::Player_X)
                XWin = true;
    }
    else if (arena[6] == (char)Players::Player_O)
    {
        if (arena[7] == (char)Players::Player_O)
            if (arena[8] == (char)Players::Player_O)
                OWin = true;
    }
}

void Board::checkVerticalWin()
{
    if (arena[0] == (char)Players::Player_X) 
    {
        if (arena[3] == (char)Players::Player_X)
            if (arena[6] == (char)Players::Player_X)
                XWin = true;
    }
    else if (arena[0] == (char)Players::Player_O)
    {
        if (arena[3] == (char)Players::Player_O)
            if (arena[6] == (char)Players::Player_O)
                OWin = true;
    }
    if (arena[1] == (char)Players::Player_X)
    {
        if (arena[4] == (char)Players::Player_X)
            if (arena[7] == (char)Players::Player_X)
                XWin = true;
    }
    else if (arena[1] == (char)Players::Player_O)
    {
        if (arena[4] == (char)Players::Player_O)
            if (arena[7] == (char)Players::Player_O)
                OWin = true;
    }
    if (arena[2] == (char)Players::Player_X)
    {
        if (arena[5] == (char)Players::Player_X)
            if (arena[8] == (char)Players::Player_X)
                XWin = true;
    }
    else if (arena[2] == (char)Players::Player_O)
    {
        if (arena[5] == (char)Players::Player_O)
            if (arena[8] == (char)Players::Player_O)
                OWin = true;
    }
}

bool Board::isFull(bool draw)
{
    int counter = 0;
    for (int i = 0; i < MAX_ARENA; i++)
    {
        if (arena[i] == (char)Players::Player_X || arena[i] == (char)Players::Player_O)
            counter++;
    }
    if (counter == 9)
    {
        cout << "Draw!";
        return draw = true;
    }
}



