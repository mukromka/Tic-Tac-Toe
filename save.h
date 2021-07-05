class Save {
	private:
		struct score {
			string namePlayerX, namePlayerO;
			int win;
		} dataScore[100];
		string data, xNam, oNam, win, last, close, fileName, lastXName, lastOName, lastData, txtData;
		int MAX;
		char temp[1000];
	public:
		Save();
		void LoadData(); 
		
		
		int GetLastMatchData(int x);
		void setDataScore(string xN, string oN, int wN);
		void saveGame(string lastXNameData, string lastONameData);
		void showScoreboard();
};

