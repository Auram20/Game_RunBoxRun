// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ CAMERA.HPP ___________ 
//================================

#ifndef __CAMERA__HPP
#define __CAMERA__HPP

// Includes 
#include <utils/glm.hpp>

namespace glimac
{
	/// \class Camera
	/// \brief virtual class for camera.
	class Camera
	{
			
		public:
        // CONSTRUCTORS & DESTRUCTOR
		Camera() = default; /*!< default constructor */
		virtual ~Camera() = default; /*!< default destructor*/

        virtual const glm::mat4 getViewMatrix() const = 0;
		virtual void rotateLeft(float degrees) = 0;
        virtual void rotateUp(float degrees) = 0;
		virtual void translateZ(float t) = 0;
		virtual void translateX(float t) = 0;
		virtual void translateY(float t) = 0;

		// Camera FUNCTIONS
		//void displayInfos(); /*!< display of Camera's informations */

	};
}

#endif
