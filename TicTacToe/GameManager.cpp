#include <iostream>
#include "GameManager.h"
#include <string>
#include "Board.h"

GameManager::GameManager() {

	//Amount of players
	status = false;
	while (status == false) {
		std::cout << "Enter number of players (2-4): ";
		std::cin >> numPlayers;
		if ((numPlayers != 2) && (numPlayers != 3) && (numPlayers != 4))
		{
			std::cout << "\n***That is an invalid entry***\n";
			system("PAUSE");
			continue;
		}
		status = true;
	}

	//Player info
	for (int i = 0; i < numPlayers; i++)
	{
		std::cout << "\nPlayer " << i + 1 << " please enter your name: \n";
		std::string name;
		std::cin >> name;
		playerList[i].setName(name);
		std::cout << "Hello there " << name << "!\n";
		std::cout << "Please enter the symbol you would like to use: \n";
		char symbol;
		std::cin >> symbol;
		playerList[i].setSymbol(symbol);
	}

	//Board info
	std::cout << "\nNow choose the size of your board.\n";

	status = false;
	while (status == false) {

		std::cout << "\nEnter how wide you would like the board to be? (3-15): ";
		std::cin >> x;
		if (x < 3 || x > 15)
		{
			std::cout << "\n***That number is not valid***\n";
			system("PAUSE");
			continue;
		}

		std::cout << "\nEnter how high you would like the board to be? (3-15): ";
		std::cin >> y;
		if (y < 3 || y > 15)
		{
			std::cout << "\nThat number is not valid.\n";
			system("PAUSE");
			continue;
		}
		status = true;
	}

	int winAmount;
	if (x == 3 || y == 3)
	{
		if (x == 3 && y == 3)
		{
			winAmount = 3;
		}
		else if (x == 4 || y == 4)
		{
			std::cout << "\nEnter the amount of markers in a row needed to win (3-4): ";
			winAmount;
			std::cin >> winAmount;
		}
		else {
			std::cout << "\nEnter the amount of markers in a row needed to win (3-5): ";
			winAmount;
			std::cin >> winAmount;
		}
	}
	else if (x == 4 || y == 4) {
		if (x == 4 && y == 4)
		{
			std::cout << "\nEnter the amount of markers in a row needed to win (3-4): ";
			winAmount;
			std::cin >> winAmount;
		}
		else {
			std::cout << "\nEnter the amount of markers in a row needed to win (3-5): ";
			winAmount;
			std::cin >> winAmount;
		}
	}
	else {
		std::cout << "\nEnter the amount of markers in a row needed to win (3-5): ";
		winAmount;
		std::cin >> winAmount;
	}

	//Print board
	Board newBoard(x, y, winAmount);

	//Game Loop
	status = false;
	int winnerIndex;
	while (status == false)
	{
		for (int i = 0; i < numPlayers; i++)
		{
			std::cout << playerList[i].getName() << "'s Turn!\n";
			std::cout << "Enter the X-Coordinate of where you wish to place your marker: \n";
			std::cin >> x;
			std::cout << "\nEnter the Y-Coordinate of where you wish to palce your marker: \n";
			std::cin >> y;
			status = newBoard.update(x, y, playerList[i].getSymbol());
			if (status == true)
			{
				winnerIndex = i;
				break;
			}
		}
	}
	//winner
	std::cout << "\nCongradulations!!! " << playerList[winnerIndex].getName() << " Wins!\n\n";
}