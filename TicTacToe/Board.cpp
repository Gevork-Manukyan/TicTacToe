#include <iostream>
#include <string>
#include "Board.h"


Board::Board(int xAxis, int yAxis, int win)
{
	_xSize = xAxis;
	_ySize = yAxis;
	_winAmount = win;
	initBoard();
	printBoard(_xSize, _ySize);
}

void Board::printBoard(int xAxis, int yAxis)
{
	
	//Note
	std::cout << "\n(Note: X-Coordinate is horzontal. Y-Coordinate is vertical.)\n\n";

	//print x-axis
	std::cout << "		";
	std::cout << "  |";
	for (int i = 1; i <= xAxis; i++)
	{
		if (i < 10)
			std::cout << " " << i << " |";
		if (i >= 10)
			std::cout << " " << i << "|";
	}

	//Dashed lines
	std::cout << "\n		";
	std::cout << "--";
	for (int i = 0; i < xAxis; i++)
	{
		std::cout << "----";
	}
	std::cout << "\n";

	//print rest of board	
	for (int i = 0; i < yAxis; i++)
	{
		//print y-axis
		std::cout << "		";
		if (i + 1 < 10)
			std::cout << i + 1 << " |";
		if (i + 1 >= 10)
			std::cout << i + 1 << "|";

		//Rows
		for (int j = 0; j < xAxis; j++)
		{
			std::cout << " " << _board[i+1][j+1] << " |";
		}
		
		//Dashed lines
		std::cout << "\n		";
		std::cout << "--";
		for (int i = 0; i < xAxis; i++)
		{
			std::cout << "----";
		}
		std::cout << "\n";
	}
	
}

void Board::initBoard()
{
	//init Board
	for (int y = 0; y < _ySize; y++) {
		for (int x = 0; x < _xSize; x++) {
			_board[y+1][x+1] = '.';
		}
	}
}

char Board::getBoardValue(int x, int y)
{
	return _board[y][x];
}

int Board::getWinAmount()
{
	return _winAmount;
}

bool Board::update(int x, int y, char symbol)
{
	bool loop = false;
	while (loop == false)
	{
		if (_board[y][x] == '.') {
			_board[y][x] = symbol;
			//loop = true;
			break;
		}
		else {
			std::cout << "\nThat space is occupied. Try again.\n\n";
			system("PAUSE");
			std::cout << "\nEnter the X-Coordinate of where you wish to place your marker: \n";
			std::cin >> x;
			std::cout << "\nEnter the Y-Coordinate of where you wish to palce your marker: \n";
			std::cin >> y;
		}
	}
	
	//Check if player won
	int winCounter = checkSurroundings(x, y, symbol);
	printBoard(_xSize, _ySize);
	if (winCounter == getWinAmount())
	{
		return true;
	}
	else {
		return false;
	}
}

int Board::checkSurroundings(int x, int y, char symbol)
{
	int winCounter = 1;
	//BotLeft
	if (getBoardValue(x - 1, y + 1) == symbol)
	{
		winCounter += cBotLeft(x - 1, y + 1, symbol);
		//UpRight
		if (getBoardValue(x + 1, y - 1) == symbol)
		{
			winCounter += cUpRight(x + 1, y - 1, symbol);
			return winCounter;
		}
		return winCounter;
	}
	//Left
	if (getBoardValue(x - 1, y) == symbol)
	{
		winCounter += cLeft(x - 1, y, symbol);
		//Right
		if (getBoardValue(x + 1, y) == symbol)
		{
			winCounter += cRight(x + 1, y, symbol);
			return winCounter;
		}
		return winCounter;
	}
	//UpLeft
	if (getBoardValue(x - 1, y - 1) == symbol)
	{
		winCounter += cUpLeft(x - 1, y - 1, symbol);
		//BotRight
		if (getBoardValue(x + 1, y + 1) == symbol)
		{
			winCounter += cBotRight(x + 1, y + 1, symbol);
			return winCounter;
		}
		return winCounter;
	}
	//Up
	if (getBoardValue(x, y - 1) == symbol)
	{
		winCounter += cUp(x, y - 1, symbol);
		//Bot
		if (getBoardValue(x, y + 1) == symbol)
		{
			winCounter += cBot(x, y + 1, symbol);
			return winCounter;
		}
		return winCounter;
	}
	//UpRight
	if (getBoardValue(x + 1, y - 1) == symbol)
	{
		winCounter += cUpRight(x + 1, y - 1, symbol);
		return winCounter;
	}
	//Right
	if (getBoardValue(x + 1, y) == symbol)
	{
		winCounter += cRight(x + 1, y, symbol);
		return winCounter;
	}
	//Bot
	if (getBoardValue(x, y + 1) == symbol)
	{
		winCounter += cBot(x, y + 1, symbol);
		return winCounter;
	}
	//BotRight
	if (getBoardValue(x + 1, y + 1) == symbol)
	{
		winCounter += cBotRight(x + 1, y + 1, symbol);
		return winCounter;
	}
	return winCounter;
}

int Board::cLeft(int x, int y, char symbol)
{
	if (getBoardValue(x - 1, y) != symbol)
		return 1;

	return cLeft(x - 1, y, symbol) + 1;
}

int Board::cRight(int x, int y, char symbol)
{
	if (getBoardValue(x + 1, y) != symbol)
		return 1;

	return cRight(x + 1, y, symbol) + 1;
}

int Board::cUp(int x, int y, char symbol)
{
	if (getBoardValue(x, y - 1) != symbol)
		return 1;

	return cUp(x, y - 1, symbol) + 1;
}

int Board::cBot(int x, int y, char symbol)
{
	if (getBoardValue(x, y + 1) != symbol)
		return 1;

	return cBot(x, y + 1, symbol) + 1;
}

int Board::cUpRight(int x, int y, char symbol)
{
	if (getBoardValue(x + 1, y - 1) != symbol)
		return 1;

	return cUpRight(x + 1, y - 1, symbol) + 1;
}

int Board::cUpLeft(int x, int y, char symbol)
{
	if (getBoardValue(x - 1, y - 1) != symbol)
		return 1;

	return cUpLeft(x - 1, y - 1, symbol) + 1;
}

int Board::cBotRight(int x, int y, char symbol)
{
	if (getBoardValue(x + 1, y + 1) != symbol)
		return 1;

	return cBotRight(x + 1, y + 1, symbol) + 1;
}

int Board::cBotLeft(int x, int y, char symbol)
{
	if (getBoardValue(x - 1, y + 1) != symbol)
		return 1;

	return cBotLeft(x - 1, y + 1, symbol) + 1;
}