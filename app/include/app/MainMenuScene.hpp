// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ MAINMENUSCENE.HPP_____ 
//================================

#ifndef __MAINMENUSCENE__HPP
#define __MAINMENUSCENE__HPP

#include <iostream>
#include <app/Scene.hpp>

namespace RUNBOXRUN
{
	/// \class MainMenuScene
	/// \brief class defining a new GameManager MainMenuScene.
	class MMScene : public GameManager
	{
		
		private:

		public:
		// CONSTRUCTORS & DESTRUCTOR
		MMScene() : GameManager() {}; /*!< default constructor */
		~MMScene() = default; /*!< default destructor*/
        

		void initScene(Scene &scene) override 
		{
        	    glDisable(GL_DEPTH_TEST);
				glimac::Model monBG(glimac::FilePath("../assets/obj/MenuBG.obj"));
				glimac::Model myCorner(glimac::FilePath("../assets/obj/CornerBox.obj"));
				glimac::Box Rectangle1(1,1,0);

				GameObject *bg = new GameObject(monBG,Transform(glm::vec3(-0.5, -0.8, -5),glm::vec3(0.125)));
				GameObject *frame = new GameObject(myCorner,Transform(glm::vec3(-2.6, -2.3, -4.9),glm::vec3(0.8,0.45,0)));
				scene._etat=0;

		    	scene.push(bg,"1");
				scene.push(frame,"2");

			    glEnable(GL_DEPTH_TEST);	
		};

		void runScene(Scene &scene, SDL_Event &e) override 
		{
     				
		};

		void closeScene(Scene &scene) override {};


    };
}

#endif


  