#pragma once
#include "Player.h"

class GameManager {
public:
	GameManager();

private:
	int x, y;
	bool status;
	int numPlayers;
	Player playerList[4];
};