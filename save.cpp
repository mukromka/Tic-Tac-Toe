#include "player.h"
#include "enum.h"
#include "board.h"
#include "save.h"
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#define MAX_ARENA 9

using namespace std;
Board board;
Save::Save()
{
	data = "<Data>";
	xNam = "<xName>";
	oNam = "<oName>";
	win = "<win>";
	last = "<last>";
	close = "<Close>";

	fileName = "D:\\laptop hp aas yg lama\\aaaaa  TUGAS AAS PENS 2019\\semester 4\\Pemrograman 4\\Tic Tac Toe\\SaveData.txt";
	MAX = 1000;

	lastXName = "<lastXName>";
	lastOName = "<lastOName>";
	lastData = "<lastData>";
}

void Save::LoadData()
{
	int findFront = 0, findBack = 0, lenght;

	// Open txt file 
	ifstream file;
	file.open(fileName);
	// If error while opening
	if (!file) {
		cout << "Error Dalam Membuka File!!!" << endl;
		exit(0);
	}

	// Copy all data from file txt
	while (!file.eof()) {
		file.getline(temp, MAX);
		txtData = txtData + temp;
	}
	// Close txt file
	file.close();

	for (int i = 0; i < 100; i++) {
		findFront = txtData.find(xNam, findFront + 1) + 7;
		findBack = txtData.find(oNam, findBack + 1);
		lenght = findBack - findFront;
		dataScore[i].namePlayerX = txtData.substr(findFront, lenght);

		findFront = txtData.find(oNam, findFront + 1) + 7;
		findBack = txtData.find(win, findBack + 1);
		lenght = findBack - findFront;
		dataScore[i].namePlayerO = txtData.substr(findFront, lenght);

		findFront = txtData.find(win, findFront + 1) + 5;
		findBack = txtData.find(last, findBack + 1);
		lenght = findBack - findFront;
		dataScore[i].win = stoi(txtData.substr(findFront, lenght));
	}
}

void Save::setDataScore(string xN, string oN, int wN) {
	// New data will added on the top

	for (int i = 99; i > 0; i--) {
		dataScore[i].namePlayerX = dataScore[i - 1].namePlayerX;
		dataScore[i].namePlayerO = dataScore[i - 1].namePlayerO;
		dataScore[i].win = dataScore[i - 1].win;
	}
	dataScore[0].namePlayerX = xN;
	dataScore[0].namePlayerO = oN;
	dataScore[0].win = wN;

	// Move Back all data (data 2->3; data 3->4 ...)

}

void Save::saveGame(string lastXNameData, string lastONameData) {
	// Open file
	ofstream fileOut;
	fileOut.open(fileName);

	// Add new data to txt file
	fileOut << data << endl;

	// Last Match data

	fileOut << lastXName << lastXNameData;
	fileOut << lastOName << lastONameData;
	fileOut << lastData;
	for (int i = 0; i < MAX_ARENA; i++) {
		fileOut << board.exportArena(i);
	}
	fileOut << last << endl;


	// Score data
	for (int i = 0; i < 100; i++) {
		fileOut << xNam << dataScore[i].namePlayerX;
		fileOut << oNam << dataScore[i].namePlayerO;
		fileOut << win << to_string(dataScore[i].win);
		fileOut << last << endl;
	}

	fileOut << close;

	// Close txt file
	fileOut.close();

	// Reset txtData
	txtData = "";
}

void Save::showScoreboard() {
	system("cls");
	cout << "                 Scoreboard\n\n";
	cout << "     x Player            o Player            Winner\n";

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 50;) {
			if (j == 5) {
				cout << dataScore[i].namePlayerX;
				j += dataScore[i].namePlayerX.size();
			}
			else if (j == 25) {
				cout << dataScore[i].namePlayerO;
				j += dataScore[i].namePlayerO.size();
			}
			else if (j == 45) {
				if (dataScore[i].win == 1) {
					cout << "x Player\n";
				}
				else if (dataScore[i].win == 2) {
					cout << "o Player\n";
				}
				else {
					cout << "Draw\n";
				}
				j = 60;
			}
			else {
				cout << " ";
				j++;
			}
		}
	}
	cout << endl;

	system("pause");
}
