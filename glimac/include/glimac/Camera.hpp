// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ CAMERA.HPP ___________ 
//================================

#ifndef __CAMERA__HPP
#define __CAMERA__HPP

// Includes 
#include <glimac/glm.hpp>

namespace RUNBOXRUN
{
	/// \class Camera
	/// \brief virtual class for camera.
	class Camera
	{
			
		public:
        // CONSTRUCTORS & DESTRUCTOR
		Camera() = default; /*!< default constructor */
		~Camera() = default; /*!< default destructor*/

        virtual glm::mat4 getViewMatrix() const = 0;

		// Camera FUNCTIONS
		//void displayInfos(); /*!< display of Camera's informations */

	};
}

#endif
