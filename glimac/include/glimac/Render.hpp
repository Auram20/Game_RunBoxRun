// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ RENDER.HPP ___________ 
//================================

#ifndef __RENDER__HPP
#define __RENDER__HPP

// Includes 
#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <iostream>
#include <vector>
#include <glimac/Image.hpp>
#include <app/InputManager.hpp>
#include <glimac/Program.hpp>


namespace glimac
{
	/// \class Render
	/// \brief class for the rendering.
	class Render
	{
			
		public:
        // CONSTRUCTORS & DESTRUCTOR
		Render() = default ; /*!< constructor with parameters */
		~Render() = default ; /*!< default destructor*/

		// WINDOWENGINE FUNCTIONS
		void program(const Program &program);
		void initRender(); 
		void clear(); 
		void sendDatas();
	
		void displayInfos() const {
			std::cout << _ProjMatrix << std::endl;
			std::cout << _MVMatrix << std::endl;
			std::cout << _NormalMatrix << std::endl;
			std::cout << uMVPMatrix << std::endl;
			std::cout << uMVMatrix << std::endl;
			std::cout << uNormalMatrix << std::endl;
			std::cout << uTexture << std::endl;
		}


		private:
		glm::mat4 _ProjMatrix;
		glm::mat4 _MVMatrix;
		glm::mat4 _NormalMatrix;
		GLint uMVPMatrix;
		GLint uMVMatrix;
		GLint uNormalMatrix;
		GLint uTexture;

	};
}

#endif
