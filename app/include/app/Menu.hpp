// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ MENU.HPP ___________ 
//================================

#ifndef __MENU__HPP
#define __MENU__HPP

// Includes 
#include <utils/glm.hpp>
#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <iostream>
#include <vector>
#include <glimac/Image.hpp>
#include <app/InputManager.hpp>
#include <glimac/Program.hpp>
#include <app/Map.hpp>
#include <app/SceneFactory.hpp>
#include <utils/FilePath.hpp>
#include <utils/Observable.hpp>


namespace RUNBOXRUN
{
	/// \class Menu
	/// \brief class for Menu
	class Menu 
	{
			
		public:
        // CONSTRUCTORS & DESTRUCTOR
		Menu(); /*!< default constructor*/
		~Menu()=default; /*!< default destructor*/

		// MENUS FUNCTIONS
		void mainMenuRender();

		private:
		
}


#endif