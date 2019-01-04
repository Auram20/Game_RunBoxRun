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
    glDisable(GL_DEPTH_TEST);
	glimac::Model monBG(glimac::FilePath("../assets/obj/MenuBG.obj"));
	glimac::Model myCorner(glimac::FilePath("../assets/obj/CornerBox.obj"));
	glimac::Box Rectangle1(1,1,0);
	Object *Rec = new Object(1, glm::vec3(0,0,-5), glm::vec3(1), glm::vec3(100));

	GameObject *bg = new GameObject(monBG, *Rec,Transform(glm::vec3(-0.5, -0.8, -5),glm::vec3(0.125)));
	GameObject *frame = new GameObject(myCorner, *Rec,Transform(glm::vec3(1.9, -2.3, -4.9),glm::vec3(1,0.45,0)));

    this->push(bg,"1");
	this->push(frame,"2");

    glEnable(GL_DEPTH_TEST);	
}


void Scene::mainMenu(SDL_Event e)
{	
            	
	  switch(e.type) {

            case SDL_KEYDOWN:
 
                if (e.key.keysym.sym==275) //right arrow
                { 
             		std::string id="2";
						if ( _GameObjects.find(id) == _GameObjects.end() ) 
						{ // not found
							std::cout << id <<" n'est pas stockée dans la map." << std::endl;
						} 
						else 
						{ // found

							 _GameObjects.find(id)->second->_transform._translate[3][0]=1.9;
							 _GameObjects.find(id)->second->_transform._scale[0][0]=1;
						}
                }



                


                if (e.key.keysym.sym==276) //left arrow 
                { 
	               	std::string id="2";
						if ( _GameObjects.find(id) == _GameObjects.end() ) 
						{ // not found
							std::cout << id <<" n'est pas stockée dans la map." << std::endl;
						} 
						else 
						{ // found
							 _GameObjects.find(id)->second->_transform._translate[3][0]=-2.6;
							 _GameObjects.find(id)->second->_transform._scale[0][0]=0.8;
						}
				}





             case SDL_KEYUP:

               
                 break;

           	 default:
                break;

        }

}
