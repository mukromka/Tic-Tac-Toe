#pragma once
#include "enum.h"
#include "board.h"
#include <string>
#include <iostream>

using namespace std;

class Board;

class Player
{
	private:
		char playerID1;
		char playerID2;
		char currentPlayer;
		string namePlayerX;
		string namePlayerO;

	public:
		void playerTurn(Board& B);
		void choosePlayer(string one,string two);
		void changePlayer();
		void setNameX(string p) {
			namePlayerX = p;
		}
		void setNameO(string p) {
			namePlayerO = p;
		}
		string getNameX() {
			return namePlayerX;
		}
		string getNameO() {
			return namePlayerO;
		}
		char getplayerID1()
		{
			return playerID1;
		}
		char getplayerID2()
		{
			return playerID2;
		}

};
