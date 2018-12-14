// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ PLAYER.CPP ___________ 
//================================


#include "../include/Player.hpp"
#include <iostream>

using namespace RUNBOXRUN;

Player::Player()
: Object(), _health(1), _jumpState(0)
{}


Player::Player(const double &speed, const glm::vec3 &position, const glm::vec3 &size, const glm::vec3 &color, const unsigned int &health, const unsigned int &jumpState)
: Object(speed, position, size, color),  _health(health), _jumpState(jumpState)
{}


Player::Player(const Player &player)	
: Object(player._speed, player._position, player._size, player._color), _health(player._health), _jumpState(player._jumpState)
{}

/*
void const Player::displayInfos() const
{
	Object::displayInfos();
	std::cout << "health :" << _health << std::endl
	<< "jumpState : " << _jumpState << std::endl;
}
*/

void Player::moveLeft(const double &t)
{
	_position.y += t;
}

void const Player::jump()
{
	_position.y++;
	_jumpState = 2;
}

Player::~Player()
{}