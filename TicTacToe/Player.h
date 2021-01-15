#pragma once
#include <string>

class Player {

public:
	Player();
	void setName(std::string name);
	std::string getName();
	void setSymbol(char symbol);
	char getSymbol();
private:
	std::string _name;
	char _symbol;
};