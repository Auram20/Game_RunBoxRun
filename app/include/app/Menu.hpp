// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ MENU.HPP_____ 
//================================

#ifndef __MENU__HPP
#define __MENU__HPP

#include <app/Scene.hpp>

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
		void rendermainMenu(SDL_Event e);  /*!< render main menu */

		
            
	};
}

#endif


  