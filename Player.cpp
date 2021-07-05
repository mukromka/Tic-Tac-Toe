#include "player.h"
#include "enum.h"
#include "board.h"
#include <iostream>

using namespace std;

void Player::choosePlayer(string one, string two) {
    char pilihPlayer;
    cout << "\nChoose X or O for player one : " << endl;
    bool Pass = false;
    while (!Pass) {
        cin >> pilihPlayer;
        if (pilihPlayer == 'X' || pilihPlayer == 'x') {
            playerID1 = (char)Players::Player_X;
            playerID2 = (char)Players::Player_O;
            currentPlayer = playerID1;
            namePlayerX = one;
            namePlayerO = two;
            Pass = true;
            
        }

        else if (pilihPlayer == 'O' || pilihPlayer == 'o') {
            playerID1 = (char)Players::Player_O;
            playerID2 = (char)Players::Player_X;
            currentPlayer = playerID2;
            Pass = true;
            namePlayerX = two;
            namePlayerO = one;
            Pass = true;
        }

        else {
            cout << "Invalid" << endl;
        }
    }
}

void Player::playerTurn(Board& B) {
    size_t choseNum;
    bool inputPass = false;
start :
    if (currentPlayer == (char)Players::Player_X) // ini kalo playernya x
    {
        cout << "Player " << namePlayerX << " choose a number : " << endl;
        cout << "Type 0 to exit! " << endl;
        while (!inputPass)
        {
            if (cin >> choseNum) {
                B.isEmpty(choseNum, currentPlayer, inputPass);
            }
            else {
                cout << "Invalid, (Type only number)" << endl;
                goto start;
            }
        }
    }
    else
    {
        cout << "Player " << namePlayerO << " choose a number : " << endl;
        while (!inputPass)
        {
            if (cin >> choseNum) {
                B.isEmpty(choseNum, currentPlayer, inputPass);
            }
            else {
                cout << "Invalid, (Type only number)" << endl;
                goto start;
            }
        }
    }
}

void Player::changePlayer()
{
    if (currentPlayer == playerID1)
        currentPlayer = playerID2;
    else
        currentPlayer = playerID1;
}
