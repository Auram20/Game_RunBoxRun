// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ PLAYER.CPP ___________ 
//================================


#include <game/Player.hpp>
#include <iostream>

using namespace RUNBOXRUN;


// --------------- CONSTRUCTORS && DESTRUCTORS --------------

Player::Player(const double &speed, const glm::vec3 &position, const glm::vec3 &size, const glm::vec3 &color, const unsigned int &health, const unsigned int &jumpState)
: GameObject(Object(speed, position, size, color)),  _health(health), _jumpState(jumpState)
{}


Player::~Player()
{}


// --------------- PLAYER'S FUNCTIONS --------------
void  Player::displayInfos() 
{
	std::cout << "\n------------ PLAYER INFORMATIONS ------------" << std::endl;
	GameObject::displayInfos();
	std::cout << "health : " << _health << std::endl;
	std::cout << "jumpState : " << _jumpState << std::endl;
}

Player* Player::_instance = nullptr;

Player* Player::getInstance()
{
	if(_instance == nullptr)
	{
		_instance = new Player(1,glm::vec3(200),glm::vec3(200),glm::vec3(300),3,2);
	}

	return _instance;
}

void const Player::jump(const double indice)
{
	_jumpState = 2;
//	GameObject::getLocalPos().y+= indice;
}