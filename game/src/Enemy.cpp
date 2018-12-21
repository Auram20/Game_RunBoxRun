// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ ENEMY.CPP ___________ 
//================================


#include "game/Enemy.hpp"
#include <iostream>

using namespace RUNBOXRUN;


// --------------- CONSTRUCTORS && DESTRUCTORS --------------
Enemy::Enemy()
: EventObject()
{}

Enemy::Enemy(const double &speed, const glm::vec3 &position, const glm::vec3 &size, const glm::vec3 &color, const std::string &pathObj)
: EventObject(speed, position, size, color, pathObj)
{}

Enemy::Enemy(const Enemy &enemy)
: EventObject(enemy._speed, enemy._position, enemy._size, enemy._color, enemy._pathObj)
{}

Enemy::~Enemy()
{}


// --------------- ENNEMY'S FUNCTIONS --------------

void Enemy::displayInfos() 
{
	std::cout << "\n------------ ENNEMY INFORMATIONS ------------" << std::endl;
	Object::displayInfos();
}


