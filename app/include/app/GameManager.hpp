// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ GAMEMANAGER.HPP_____ 
//================================

#ifndef __GAMEMANAGER__HPP
#define __GAMEMANAGER__HPP

#include <iostream>
#include <app/Scene.hpp>

namespace RUNBOXRUN
{
	/// \class GameManager
	/// \brief class defining a new GameManager.
	class GameManager
	{
		
		private:

		public:
		// CONSTRUCTORS & DESTRUCTOR
		GameManager(); /*!< default constructor */
		~GameManager() = default; /*!< default destructor*/
        

		virtual void initScene(Scene &scene) {};

		virtual void runScene(Scene &scene) {};

		virtual void closeScene(Scene &scene) {};

    };
}

#endif


  