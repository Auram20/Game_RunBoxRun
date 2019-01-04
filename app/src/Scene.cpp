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

void Scene::initmainMenu()
{

}


void Scene::mainMenu(SDL_Event e)
{	

    glDisable(GL_DEPTH_TEST);
	glimac::Model monBG(glimac::FilePath("../assets/obj/MenuBG.obj"));
	glimac::Model myCorner(glimac::FilePath("../assets/obj/CornerBox.obj"));
    bool left = true;
	glimac::Box Rectangle1(1,1,0);
	Scene scene;
	Object *Rec = new Object(1, glm::vec3(0,0,-5), glm::vec3(1), glm::vec3(100));

	GameObject *bg = new GameObject(monBG, *Rec,Transform(glm::vec3(-0.5, -0.8, -5),glm::vec3(0.125)));
	GameObject *cornerright = new GameObject(myCorner, *Rec,Transform(glm::vec3(2.5, -2.3, 0),glm::vec3(0.8,0.45,0)));
    GameObject *cornerleft = new GameObject(myCorner, *Rec,Transform(glm::vec3(-2.6, -2.3, 0),glm::vec3(0.8,0.45,0)));	
				            	

	  switch(e.type) {

            case SDL_KEYDOWN:
 
                if (e.key.keysym.sym==275)
                { //right
                 	cornerleft->_transform._translate[3][2]=0;
                }
                 if (e.key.keysym.sym==276)
                { //left
                 	cornerleft->_transform._translate[3][2]=0;
                 	cornerright->_transform._translate[3][2]=0;

	      		}

             case SDL_KEYUP:

                 if (e.key.keysym.sym == 275)
                 { //right 
                   	cornerright->_transform._translate[3][2]=-4.9; 
                   	cornerleft->_transform._translate[3][2]=0;
                 }
                 
                 if (e.key.keysym.sym == 276)
                 { //left                }
                	cornerright->_transform._translate[3][2]=0; 
                   	cornerleft->_transform._translate[3][2]=-4.9;
                 }	
                 break;

           	 default:
                break;

        }


        this->push(bg,"1");
		this->push(cornerleft,"2");
		this->push(cornerright,"3");

    glEnable(GL_DEPTH_TEST);
}
