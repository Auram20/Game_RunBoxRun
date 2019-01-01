// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ PLAYER.CPP ___________ 
//================================


#include <app/Player.hpp>
#include <iostream>

using namespace RUNBOXRUN;


// --------------- CONSTRUCTORS && DESTRUCTORS --------------

Player::Player(const double &speed, const glm::vec3 &position, const glm::vec3 &size, const glm::vec3 &color, const unsigned int &health, const  int &jumpState)
: GameObject(Object(speed, position, size, color)),  _health(health), _jumpState(jumpState)
{}

Player::Player(const double &speed, const glm::vec3 &position, const glm::vec3 &size, const glm::vec3 &color, const unsigned int &health, const  int &jumpState, const glimac::Model &model, const Transform &transform)
: GameObject(glimac::Model(model),Object(speed, position, size, color),Transform(transform)),  _health(health), _jumpState(jumpState)
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
 		 glimac::Model modelPlayer(glimac::FilePath("../assets/obj/boule.obj"));
 		 Transform transformPlayer(glm::vec3(0, 0, -5),glm::vec3(0.5));
		_instance = new Player(1,glm::vec3(0, 0, -5), glm::vec3(1),glm::vec3(100),3,0,modelPlayer,transformPlayer);
		}

	return _instance;
}

void const Player::jump(const double indice)
{
	 glm::vec3 jumpvec(0.f);
 	 jumpvec=_object->getPos();
	 jumpvec[1]=indice;
	_jumpState = indice;
 	 setTrans(jumpvec);
 	 _object->setPos(jumpvec);
}

 void Player::moveHorizontal(const double indice)
 {
 	 glm::vec3 horizvec(0.f);
 	 horizvec=_object->getPos();
	 horizvec[0]=indice;
 	 setTrans(horizvec);
 	 _object->setPos(horizvec);
 }

void Player::updatePlayer(SDL_Event e) 
{
    //gameEvents handling
        switch(e.type) {


            case SDL_KEYDOWN:
 
                if (e.key.keysym.sym==SDLK_z){ //up
                    jump(1);
                    displayInfos();
                }
                 if (e.key.keysym.sym==SDLK_s){ //down
                   jump(-1);
                   displayInfos();
                }
                 if (e.key.keysym.sym==SDLK_d){ //right
                  	moveHorizontal(1);
                    displayInfos();  
                }
                 if (e.key.keysym.sym==SDLK_q){ //left
                   	moveHorizontal(-1);
                    displayInfos();
                } 

                break;

            case SDL_KEYUP:

                if (e.key.keysym.sym == SDLK_z){ //up
					jump(0);
                    displayInfos();
                }
                
                if (e.key.keysym.sym == SDLK_s){ //down
                     jump(0);
                     displayInfos();
                 }
                
                if (e.key.keysym.sym==SDLK_d){ //right
                  	moveHorizontal(0);
                    displayInfos();  
                }
                
                if (e.key.keysym.sym==SDLK_q){ //left
                   	moveHorizontal(0);
                    displayInfos();
                }
                break;

            default:
                break;

        }
    
}
