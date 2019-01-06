// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ IGSCENE.CPP_____ 
//================================

#include "app/ingameScene.hpp.hpp"


void IGScene::initScene(Scene &scene)
{	
    Player* p = Player::getInstance();
    std::cout << " Avant changement " << std::endl;
    p->displayInfos(); 
    scene.push(p,"Player");

    scene.addCamera("TrackBall", new glimac::TrackballCamera());
    scene.addCamera("Freefly", new glimac::FreeflyCamera());
    scene.setCurrentCamera("Freefly");
}


void IGScene::runScene(Scene &scene)
{	
   
	scene.drawScene(); 
	scene.runCameras(),
	//p->updatePlayer(e);
}