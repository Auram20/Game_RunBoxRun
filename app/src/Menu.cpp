// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ MENU.CPP_____ 
//================================


#include "app/Menu.hpp"

using namespace RUNBOXRUN;

Menu::Menu()
{

}


void Menu::initmainMenu()
{
    glDisable(GL_DEPTH_TEST);
	glimac::Model monBG(glimac::FilePath("../assets/obj/MenuBG.obj"));
	glimac::Model myCorner(glimac::FilePath("../assets/obj/CornerBox.obj"));
	glimac::Box Rectangle1(1,1,0);
	Object *Rec = new Object(1, glm::vec3(0,0,-5), glm::vec3(1), glm::vec3(100));

	GameObject *bg = new GameObject(monBG, *Rec,Transform(glm::vec3(-0.5, -0.8, -5),glm::vec3(0.125)));
	GameObject *frame = new GameObject(myCorner, *Rec,Transform(glm::vec3(-2.6, -2.3, -4.9),glm::vec3(0.8,0.45,0)));
	_etat=0;

    this->push(bg,"1");
	this->push(frame,"2");

    glEnable(GL_DEPTH_TEST);	
}


void Menu::rendermainMenu(SDL_Event e,glimac::Render *render)
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
							 _etat=0; // INSTRUCTIONS
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
							 _etat=1;
						}
				}


				if (e.key.keysym.sym==SDLK_RETURN) //left arrow 
                { 
	               	if (_etat==0)
	               	{
	               		_GameObjects.clear();
	               		// ECRAN INSTRUCTIONS
	               	}

	               	if (_etat==1)
	               	{
	               		_GameObjects.clear();
	               		_etat=2;
	               		// ON LANCE LE JEU 
	               	}

				}


        }

}
