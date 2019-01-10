// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ __VICTORY__HPP__ 
//================================

#ifndef __VICTORY__HPP
#define __VICTORY__HPP

#include <iostream>
#include <app/Scene.hpp>
#include <app/SceneManager.hpp>
#include <time.h>  

namespace RUNBOXRUN
{
	/// \class MainMenuScene
	/// \brief class defining a new GameManager Victory screen.
	/*!< Il s'agit de la classe qui gère l'écran de fin  lorsque le joueur gagne */
	class VIScene : public GameManager
	{
		
		private:

		public:
		// CONSTRUCTORS & DESTRUCTOR
		VIScene() : GameManager(){}; /*!< default constructor */
		~VIScene() = default; /*!< default destructor*/
        

		void initScene(Scene &scene) override 
		{
				glDisable(GL_DEPTH_TEST);
				glimac::Model monBG2(glimac::FilePath("../assets/obj/WellDone.obj"));
				glimac::Box Rectangle1(1,1,0);

				GameObject *bg = new GameObject(monBG2,Transform(glm::vec3(-0.5, -0.8, -5),glm::vec3(0.125)));

		    	scene.push(bg,"1"); // index == 1

			    glEnable(GL_DEPTH_TEST);	

		};


		/*!< lance l'appel à l'affichage de la scene */
		void runScene(Scene &scene, SDL_Event &e) override 
		{

				SceneManager *sm = SceneManager::getInstance();
   				scene.drawScene();
   		       
   		        switch(e.type) {
	            case SDL_KEYDOWN:
	 
	                if (e.key.keysym.sym==SDLK_m)  {  // Pour repartir dans le menu
	             		sm->setIndex(0);	
	                }

	                if (e.key.keysym.sym==SDLK_r) // Pour recommencer
	                { 
		             	sm->setIndex(1);  		
					}
 				};
 		}

 		/*!< quitte la scene */
		void closeScene(Scene &scene) override {
					
		
		};

};





}



#endif


  