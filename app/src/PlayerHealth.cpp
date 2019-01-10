// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ PLAYERHEALTH.CPP ___________ 
//================================


#include <app/PlayerHealth.hpp>
#include <iostream>
#include "SDL/SDL.h" 
 #include <string> 
 #include <sstream>

using namespace RUNBOXRUN;


// --------------- CONSTRUCTORS && DESTRUCTORS --------------

PlayerHealth::PlayerHealth(const double &speed, const glm::vec3 &position, const glm::vec3 &size)
: GameObject(), _speed(speed)
{
}

PlayerHealth::PlayerHealth(const double &speed, const glm::vec3 &position, const glm::vec3 &size, const unsigned int &score, const glimac::Model &model, const Transform &transform)
: GameObject(glimac::Model(model),Transform(transform)), _speed(speed)
{
}



PlayerHealth::~PlayerHealth()
{
    _instance = nullptr;
}

PlayerHealth* PlayerHealth::_instance = nullptr;

PlayerHealth* PlayerHealth::getInstance()
{
    if(_instance == nullptr)
    {
         glimac::Model modelPlayer(glimac::FilePath("../assets/obj/Heart.obj"));
         Transform transformPlayer(glm::vec3(0 , -2.3, -4.9),glm::vec3(0.4));
        _instance = new PlayerHealth(0.1,glm::vec3(0, -3 , -4.9), glm::vec3(0.4),0,modelPlayer,transformPlayer);
        
    }

    return _instance;
}


 void PlayerHealth::run()
 {  
     glm::vec3 runvec(0.f);
     runvec=_transform._translate;
     runvec[2]-= _speed;
     setTrans(runvec);
     _transform._translate = runvec;

     Player* p = Player::getInstance();

     _transform._scale[0]=(float)((float)(p->_health)/8);
     _transform._scale[1]=(float)((float)(p->_health)/8);
     _transform._scale[2]=(float)((float)(p->_health)/8);
     
}
