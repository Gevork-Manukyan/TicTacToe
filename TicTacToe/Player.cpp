#include <iostream>
#include "Player.h"
#include <string>

Player::Player() {
	_name = "null";
	_symbol = ' ';
}

void Player::setName(std::string name) {
	_name = name;
}

std::string Player::getName() {
	return _name;
}

void Player::setSymbol(char symbol) {
	_symbol = symbol;
}

char Player::getSymbol() {
	return _symbol;
}