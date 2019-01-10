// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ __INSTRUCTIONS__HPP__ 
//================================

#ifndef __INSTRUCTIONS__HPP
#define __INSTRUCTIONS__HPP

#include <iostream>
#include <app/Scene.hpp>
#include <app/SceneManager.hpp>
#include <time.h>  

namespace RUNBOXRUN
{
	/// \class MainMenuScene
	/// \brief class defining a new GameManager Instruction Scene.
	class INScene : public GameManager
	{
		
		private:

		public:
		// CONSTRUCTORS & DESTRUCTOR
		INScene() : GameManager(){}; /*!< default constructor */
		~INScene() = default; /*!< default destructor*/
        

		void initScene(Scene &scene) override 
		{
				glDisable(GL_DEPTH_TEST);
				glimac::Model monBG2(glimac::FilePath("../assets/obj/instructions.obj"));
				glimac::Box Rectangle1(1,1,0);

				GameObject *bg = new GameObject(monBG2,Transform(glm::vec3(-0.5, -0.8, -5),glm::vec3(0.125)));

		    	scene.push(bg,"1");

				Player* p = Player::getInstance();
				p->transform()._translate[0]=-0.2;
				p->transform()._translate[1]=-0.8;
				p->transform()._rotateLocal[0]=-1;
				p->transform()._rotateLocal[1]=-1;
		    	scene.push(p,"Player");

			    glEnable(GL_DEPTH_TEST);	

		};



		void runScene(Scene &scene, SDL_Event &e) override 
		{

				Player* p = Player::getInstance();
				p->transform()._rotateLocal[1]-=0.001;

				SceneManager *sm = SceneManager::getInstance();
   				scene.drawScene();
   		       
   		        switch(e.type) {
	            case SDL_KEYDOWN:
	 
	                if (e.key.keysym.sym==SDLK_m)  { 
	             		sm->setIndex(0);	
	                }

	                if (e.key.keysym.sym==SDLK_p) //left arrow 
	                { 
		             	sm->setIndex(1);  		
					}
 				};
 		}

		void closeScene(Scene &scene) override {
					
		
		};

};





}



#endif


  