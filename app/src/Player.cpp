// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ PLAYER.CPP ___________ 
//================================


#include <app/Player.hpp>
#include <iostream>
#include "SDL/SDL.h" 
 #include <string> 
 #include <sstream>

using namespace RUNBOXRUN;


// --------------- CONSTRUCTORS && DESTRUCTORS --------------

Player::Player(const double &speed, const glm::vec3 &position, const glm::vec3 &size, const glm::vec3 &color, const unsigned int &health, const  int &jumpState)
: GameObject(), _speed(speed),  _health(health), _jumpState(jumpState), _touched(false), _vulnerabilityTime(0)
{
    initCollisionBehaviours();
}

Player::Player(const double &speed, const glm::vec3 &position, const glm::vec3 &size, const glm::vec3 &color, const unsigned int &health, const unsigned int &score, const  int &jumpState, const glimac::Model &model, const Transform &transform)
: GameObject(glimac::Model(model),Transform(transform)), _speed(speed), _health(health), _jumpState(jumpState), _touched(false), _vulnerabilityTime(0), _score(health)
{
    initCollisionBehaviours();
}


Player::~Player()
{
    _instance = nullptr;
}


// --------------- PLAYER'S FUNCTIONS --------------
void  Player::displayInfos() 
{
	std::cout << "\n------------ PLAYER INFORMATIONS ------------" << std::endl;
	GameObject::displayInfos();
	std::cout << "health : " << _health << std::endl;
	std::cout << "jumpState : " << _jumpState << std::endl;
}

Player* Player::_instance = nullptr;

void Player::initCollisionBehaviours() {
    addCollisionBehaviour([&](){
         
            if(!isInvulnerable() && _health > 0) {
              setTouched(true); 
              _health--;
              vulnerability();
              std::cout << _touched << std::endl;        
              std::cout << "PLAYER'S HEALTH CHANGED" << _health << std::endl;
            }

    });

    addCollisionBehaviour([&](){
         
              std::cout << "COIN TOUCHED" << _score <<std::endl;
              _score++;
            
    });
}

Player* Player::getInstance()
{
    if(_instance == nullptr)
    {
         glimac::Model modelPlayer(glimac::FilePath("../assets/obj/boule.obj"));
         Transform transformPlayer(glm::vec3(1, 0, -5),glm::vec3(1));
        _instance = new Player(0.1,glm::vec3(1, -0 , -5), glm::vec3(1),glm::vec3(100),2,0,0,modelPlayer,transformPlayer);
        
    }

    return _instance;
}

void Player::vulnerability()
{   
    if(_touched) 
  {
    _vulnerabilityTime =  SDL_GetTicks();
  }
  _touched = false;
}


// --------------- PLAYER MOVEMENTS ---------------

void const Player::jump(const double indice)
{
	 glm::vec3 jumpvec(0.f);
 	 jumpvec=_transform._translate;
	 jumpvec[1]=indice;
	_jumpState = indice;
 	 setTrans(jumpvec);
 	 _transform._translate = jumpvec;
}

 void Player::moveHorizontal(const double indice)
 {
 	 glm::vec3 horizvec(0.f);
 	 horizvec=_transform._translate;
	 horizvec[0]=indice;
 	 setTrans(horizvec);
 	 _transform._translate = horizvec;
 }

 void Player::run()
 {
     glm::vec3 runvec(0.f);
     runvec=_transform._translate;
     runvec[2]-= _speed;
     setTrans(runvec);
     _transform._translate = runvec;
 }

 void Player::turnRight()
 {  
    glm::vec3 myVec=glm::vec3(0,45,0);
    _transform.setRotation(myVec);
 }

void Player::updatePlayer(SDL_Event e) 
{
    //gameEvents handling
        run();
        switch(e.type) {


            case SDL_KEYDOWN:
 
                if (e.key.keysym.sym==SDLK_z){ //up
                    jump(1);
                }
                 if (e.key.keysym.sym==SDLK_s){ //down
                   jump(-1);
                }
                 if (e.key.keysym.sym==SDLK_d){ //right
                    if (_transform._translate[0] >= -1 && _transform._translate[0] < 1)
                        {
                             moveHorizontal((position()[0]+1));
                        }
                    // if (_object->getPos()[0] == 1) 
                    //     {
                    //         std::cout << _object->getPos()[0] << std::endl;
                    //        // turnRight();
                    //        // moveHorizontal((_object->getPos()[0]+1));
                    //     }    
                }

                 if (e.key.keysym.sym==SDLK_q){ //left

                    if (position()[0] > -1 && position()[0] <= 1)
                        {
                             moveHorizontal((position()[0]-1));
                        }
                 } 

                break;

            case SDL_KEYUP:

                if (e.key.keysym.sym == SDLK_z){ //up
					jump(0);
                }
                
                if (e.key.keysym.sym == SDLK_s){ //down
                     jump(0);
                 }
                
                if (e.key.keysym.sym==SDLK_d){ //right
                }
                
                if (e.key.keysym.sym==SDLK_q){ //left
                   
                }
                break;

            default:
                break;

        }
    
}
    