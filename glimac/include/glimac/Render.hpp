// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ RENDER.HPP ___________ 
//================================

#ifndef __RENDER__HPP
#define __RENDER__HPP

// Includes 
#include <glimac/glm.hpp>
#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <iostream>
#include <vector>
#include <glimac/Image.hpp>
#include <app/InputManager.hpp>
#include <glimac/Program.hpp>
#include <glimac/SDLWindowManager.hpp>
#include <glimac/TrackballCamera.hpp>

namespace glimac
{
	/// \class Render
	/// \brief class for  Render.
	class Render
	{
			
		public:
        // CONSTRUCTORS & DESTRUCTOR
		Render(const TrackballCamera &cam); /*!< constructor with parameters */
		~Render() = default ; /*!< default destructor*/

		// WINDOWENGINE FUNCTIONS
		void program(const Program &program);
		void initRender(); 
		void getViewMatrix();
		void clear(); 
		void transformation(const SDLWindowManager &window);
		void sendDatas();
	

		public:
		glm::mat4 _newVM;
		glm::mat4 _ProjMatrix;
		glm::mat4 _MVMatrix;
		glm::mat4 _NormalMatrix;
		GLint uMVPMatrix;
		GLint uMVMatrix;
		GLint uNormalMatrix;
		GLint uTexture;
		TrackballCamera _camera;

	};
}

#endif
