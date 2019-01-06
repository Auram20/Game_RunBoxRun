// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ SCENE.CPP_____ 
//================================

#include "app/Scene.hpp"

using namespace RUNBOXRUN;

Scene::Scene(const Scene &sc)
: _GameObjects(sc._GameObjects), _Cameras(sc._Cameras), _currentCam(_Cameras.begin()), _gameManager(sc._gameManager)
{
    _gameManager.initScene(*this);
}

Scene::Scene()
: _GameObjects(), _Cameras(), _currentCam(_Cameras.end()), _gameManager()
{

}

Scene::~Scene() {
    clearScene();
}