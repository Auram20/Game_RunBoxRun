// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ SCENE.CPP_____ 
//================================

#include "app/Scene.hpp"

using namespace RUNBOXRUN;

Scene::Scene(const Scene &sc)
: _GameObjects(sc._GameObjects), _Cameras(sc._Cameras), _currentCam(sc._currentCam)
{

}


void Scene::mainMenu()
{	

    glDisable(GL_DEPTH_TEST);
	glimac::Model monBG(glimac::FilePath("../assets/obj/MenuBG.obj"));
	glimac::Model myCorner(glimac::FilePath("../assets/obj/CornerBox.obj"));

	glimac::Box Rectangle1(1,1,0);
	Scene scene;
	Object *Rec = new Object(1, glm::vec3(0,0,-5), glm::vec3(1), glm::vec3(100));

	GameObject *bg = new GameObject(monBG, *Rec,Transform(glm::vec3(-0.5, -0.8, -5),glm::vec3(0.125)));

	GameObject *corner = new GameObject(myCorner, *Rec,Transform(glm::vec3(-2.6, -2.3, -4.9),glm::vec3(0.80,0.45,0)));

	this->push(bg);
	this->push(corner);
	
    glEnable(GL_DEPTH_TEST);
}
