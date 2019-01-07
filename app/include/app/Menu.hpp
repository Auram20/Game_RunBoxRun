// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ MENU.HPP_____ 
//================================

#ifndef __MENU__HPP
#define __MENU__HPP


// Includes 
#include <GL/glew.h>
#include <iostream>
#include <vector>

#include <utils/glm.hpp>
#include <utils/FilePath.hpp>
#include <utils/Observable.hpp>
#include <utils/Asset.hpp>

#include <glimac/SDLWindowManager.hpp>
#include <glimac/Image.hpp>
#include <glimac/Program.hpp>
#include <glimac/Sphere.hpp>
#include <glimac/Box.hpp>
#include <glimac/Model.hpp>
#include <glimac/Render.hpp>
#include <glimac/Texture.hpp>

#include "app/SceneFactory.hpp"
#include "app/AssetManager.hpp"
#include <app/Scene.hpp>
#include <app/GameObject.hpp>
#include <app/InputManager.hpp>

namespace RUNBOXRUN
{
	/// \class Menu
	/// \brief class defining a new Menu
	class Menu : public Scene 
	{
			
		public:
		// CONSTRUCTORS & DESTRUCTOR
		Menu(); /*!< default constructor */
		~Menu() = default; /*!< default destructor*/

		void initmainMenu();  /*!< initialize main menu */
		void rendermainMenu(SDL_Event e,glimac::Render *render);  /*!< render main menu */

		public : 
		//int _etat;

		// MENUS FUNCTIONS
		Scene mainMenuRender();

		private:
		
};
}

#endif


  