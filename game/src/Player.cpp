// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ PLAYER.CPP ___________ 
//================================


#include "../include/Player.hpp"
#include <iostream>

using namespace RUNBOXRUN;

Player::Player()
{}


Player::Player(const unsigned int &health, const unsigned int &jumpState)
: Object(1, glm::vec3(0)), _health(health), _jumpState(jumpState)
{}


Player::Player(const Player &player)	
	:Player(player._health, player._jumpState)
{}


void Player::displayInfos()
{
	std::cout << "health :" << _health << std::endl
	<< "jumpState : " << _jumpState << std::endl
	<< "speed : " << _speed << std::endl
	<< "positon : " << _position << std::endl;
}

void Player::moveLeft(const double &t)
{
	_position += t;
}

void const Player::jump()
{
	_position.y++;
	_jumpState = 2;
}

Player::~Player()
{}