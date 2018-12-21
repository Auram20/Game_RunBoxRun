// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ WINDOWENGINE.HPP ___________ 
//================================

#ifndef __WINDOWENGINE__HPP
#define __WINDOWENGINE__HPP

// Includes 
#include <glimac/glm.hpp>
#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <iostream>
#include <vector>
#include <glimac/Image.hpp>
#include <app/InputManager.hpp>
#include <glimac/Program.hpp>
#include <app/Map.hpp>
#include <app/SceneFactory.hpp>

using namespace RUNBOXRUN;
namespace glimac
{
	/// \class WindowEngine
	/// \brief class for  WindowEngine.
	class WindowEngine
	{
			
		public:
        // CONSTRUCTORS & DESTRUCTOR
		//WindowEngine();	
		WindowEngine(const uint32_t &width, const uint32_t &height, const char* title, const SceneFactory &sceneFactory); /*!< constructor with parameters */
		~WindowEngine()=default; /*!< default destructor*/

		// WINDOWENGINE FUNCTIONS
		int initWindow(FilePath app); /*!< render loop */

		private:
		SDLWindowManager _windowManager; /*!< window */
		SceneFactory _scene;
		//Program _program;

	};
}

#endif
