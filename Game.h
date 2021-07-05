#pragma once
#include "player.h"
#include "save.h"
#include "board.h"
#include <iostream>

using namespace std;

class Game
{
private:
	bool isDone = false;

public:
	void startGame();
	void mainMenu();
};
