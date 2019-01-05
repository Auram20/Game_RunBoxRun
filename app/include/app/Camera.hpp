// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ CAMERA.HPP ___________ 
//================================

#ifndef __CAMERA__HPP
#define __CAMERA__HPP

// Includes 
#include <utils/glm.hpp>
#include <glimac/SDLWindowManager.hpp>
#include <utils/Observable.hpp>
#include <app/InputManager.hpp>

namespace glimac
{
	/// \class Camera
	/// \brief virtual class for camera.
	class Camera : public utils::Observable<RUNBOXRUN::InputManager>
	{
			
		public:
        // CONSTRUCTORS & DESTRUCTOR
		Camera()
		: Observable()
		{
			RUNBOXRUN::InputManager *im = RUNBOXRUN::InputManager::getInstance();
			im->attachMouse(*this, [&](RUNBOXRUN::InputManager &im) {
				glm::vec2 pos = im.getMousePosition();
				glm::vec2 cursor = im.mousePosition();
				
				if(cursor.x-pos.x > 0)
				{
					rotateLeft(-1);
				}
				if(cursor.x-pos.x < 0)
				{
					rotateLeft(1);
				}
				if(cursor.y-pos.y > 0)
				{
					rotateUp(1);
				}
				if(cursor.y-pos.y < 0)
				{
					rotateUp(-1);
				}

				im.setMousePosition();
			});
		} /*!< default constructor */
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
