// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ MAINMENUSCENE.HPP_____ 
//================================

#ifndef __MAINMENUSCENE__HPP
#define __MAINMENUSCENE__HPP

#include <iostream>
#include <app/Scene.hpp>
#include <app/SceneManager.hpp>

namespace RUNBOXRUN
{
	/// \class MainMenuScene
	/// \brief class defining a new GameManager MainMenuScene.
	class MMScene : public GameManager
	{
		
		private:
		uint _etat;

		public:
		// CONSTRUCTORS & DESTRUCTOR
		MMScene() : GameManager(), _etat(0) {}; /*!< default constructor */
		~MMScene() = default; /*!< default destructor*/
        

		void initScene(Scene &scene) override 
		{
        	    glDisable(GL_DEPTH_TEST);
				glimac::Model monBG(glimac::FilePath("../assets/obj/MenuBG.obj"));
				glimac::Model myCorner(glimac::FilePath("../assets/obj/CornerBox.obj"));
				glimac::Box Rectangle1(1,1,0);

				GameObject *bg = new GameObject(monBG,Transform(glm::vec3(-0.5, -0.8, -5),glm::vec3(0.125)));
				GameObject *frame = new GameObject(myCorner,Transform(glm::vec3(-2.6, -2.3, -4.9),glm::vec3(0.8,0.45,0)));
				_etat=0;

		    	scene.push(bg,"1");
				scene.push(frame,"2");

			    glEnable(GL_DEPTH_TEST);	
		};

		void runScene(Scene &scene, SDL_Event &e) override 
		{
			    Render *render = Render::getInstance();
   		        scene.drawScene();
        		rendermainMenu(scene, e,*render);
		};

		void closeScene(Scene &scene) override {
			InputManager::clearInstance();
			_etat=0;
		};


		void rendermainMenu(Scene &scene, SDL_Event e,glimac::Render &render)
		{	
			  switch(e.type) {

	            case SDL_KEYDOWN:
	 
	                if (e.key.keysym.sym==275) //right arrow
	                { 
	             			std::string id="2";
							if ( scene._GameObjects.find(id) == scene._GameObjects.end() ) 
							{ // not found
								std::cout << id <<" n'est pas stockée dans la map." << std::endl;
							} 
							else 
							{ // found
								 scene._GameObjects.find(id)->second->_transform._translate[0]=1.9;
								 scene._GameObjects.find(id)->second->_transform._scale[0]=1;
								 _etat=1; // INSTRUCTIONS
							}
	                }

	                if (e.key.keysym.sym==276) //left arrow 
	                { 
		               		std::string id="2";
							if ( scene._GameObjects.find(id) == scene._GameObjects.end() ) 
							{ // not found
								std::cout << id <<" n'est pas stockée dans la map." << std::endl;
							} 
							else 
							{ // found
								 scene._GameObjects.find(id)->second->_transform._translate[0]=-2.6;
								 scene._GameObjects.find(id)->second->_transform._scale[0]=0.8;
								 _etat=0;
							}
					}

					if (e.key.keysym.sym==SDLK_RETURN) //left arrow 
	                { 
		               	if (_etat==1)
		               	{
		               		scene._GameObjects.clear();
		               		// ECRAN INSTRUCTIONS
		               	}

		               	if (_etat==0)
		               	{
		               		SceneManager *sm = SceneManager::getInstance();
		               		sm->setIndex(1);
				        	_etat=2;
		               		// ON LANCE LE JEU 
		               	}

					}
					}
				}




    };


}

#endif


  