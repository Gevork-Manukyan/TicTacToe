#pragma once

class Board {
public:
	Board(int x, int y, int win);
	bool update(int x, int y, char symbol);

private:
	int _xSize;
	int _ySize;
	int _winAmount;
	char _board[17][17];
	void printBoard(int x, int y);
	void initBoard();
	char getBoardValue(int x, int y);
	int getWinAmount();
	int checkSurroundings(int n, int m, char symbol);
	int cLeft(int x, int y, char symbol);
	int cRight(int x, int y, char symbol);
	int cUp(int x, int y, char symbol);
	int cBot(int x, int y, char symbol);
	int cUpRight(int x, int y, char symbol);
	int cUpLeft(int x, int y, char symbol);
	int cBotRight(int x, int y, char symbol);
	int cBotLeft(int x, int y, char symbol);
};