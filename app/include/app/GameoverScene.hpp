// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ __GAMEOVERSCENE__HPP__ 
//================================

#ifndef __GAMEOVERSCENE__HPP
#define __GAMEOVERSCENE__HPP

#include <iostream>
#include <app/Scene.hpp>
#include <app/SceneManager.hpp>
#include <time.h>  

namespace RUNBOXRUN
{
	/// \class MainMenuScene
	/// \brief class defining a new GameManager MainMenuScene.
	/*!< GameOverScene permet de créer une nouvelle scène de fin de jeu, elle est intialisée, affichée et supprimée */
	class GOScene : public GameManager
	{
		
		private:

		public:
		// CONSTRUCTORS & DESTRUCTOR
		GOScene() : GameManager(){}; /*!< default constructor */
		~GOScene() = default; /*!< default destructor*/
        
		/*!<create new scene*/
		void initScene(Scene &scene) override 
		{
				glDisable(GL_DEPTH_TEST);
				glimac::Model monBG2(glimac::FilePath("../assets/obj/GameOver2.obj"));
				glimac::Box Rectangle1(1,1,0);

				GameObject *bg = new GameObject(monBG2,Transform(glm::vec3(-0.5, -0.8, -5),glm::vec3(0.125)));

		    	scene.push(bg,"1");

			    glEnable(GL_DEPTH_TEST);	

		};

		/*!< render of the new scene*/
		void runScene(Scene &scene, SDL_Event &e) override 
		{

				SceneManager *sm = SceneManager::getInstance();
   				scene.drawScene();
   		       
   		        switch(e.type) {
	            case SDL_KEYDOWN:
	 
	                if (e.key.keysym.sym==SDLK_m)  { 
	             		sm->setIndex(0);	
	                }

	                if (e.key.keysym.sym==SDLK_r) //left arrow 
	                { 
		             	sm->setIndex(1);  		
					}
 				};
 		}
		
		/*!< end of the scene */
		void closeScene(Scene &scene) override {
					
		
		};

};





}



#endif


  