#include "Game.h"
Save save;
void Game::mainMenu()
{
	save.LoadData();
	int option;
	cout << "Choose option : " << endl;
	cout << "1. Play" << endl;
	cout << "2. Score " << endl;
	cout << "3. Quit " << endl;
	cin >> option;
	startagain :
	if (option == 1)
	{
		startGame();
	}
	else if (option == 2)
	{
		save.showScoreboard();
	}
	else if (option == 3)
	{

	}
	else
	{
		cout << "Pick the right number!";
		goto startagain;
	}
}
void Game::startGame()
{
	Board play; 
	Player player;
	string player1, player2;
	int theWinner;
	cout << "Name Player 1 : " << endl;
	cin >> player1;
	cout << "Name Player 2 : " << endl;
	cin >> player2;
	player.choosePlayer(player1, player2);
	play.printBoard();
	while (!isDone)
	{
		player.playerTurn(play);
		play.printBoard();
		player.changePlayer();
		play.checkHorizontalWin();
		play.checkVerticalWin();
		if (play.getXwin() == true)
		{
			isDone = true;
			cout << "\nX Win";
			theWinner = 1;
		}
		if (play.getOwin() == true)
		{
			isDone = true;
			cout << "\nO Win";
			theWinner = 2;
		}
		play.isFull(isDone);
		if (play.isFull(isDone) == true) {
			isDone = true;
			theWinner = 3;
		}
	}
	save.setDataScore(player1, player2, theWinner);
	save.saveGame("null", "null");
}