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
	glimac::Texture BG(glimac::FilePath("../assets/img/BG.jpg"),aiTextureType_DIFFUSE);
	glimac::Model monBG(glimac::FilePath("../assets/obj/BG.obj"));
	glimac::Box Rectangle1(1,1,0);
	Scene scene;
	Object *Rec = new Object(1, glm::vec3(0,0,-5), glm::vec3(100), glm::vec3(100));

	GameObject *go = new GameObject(monBG, *Rec,Transform(glm::vec3(0, 4, -5),glm::vec3(0.8),glm::vec3(0,0,0)));
	this->push(go);
}
