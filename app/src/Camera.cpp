// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ CAMERA.CPP_____ 
//================================

#include <app/Camera.hpp>

namespace glimac {

    Camera::Camera()
		: Observable(), _isActive(false)
		{
			RUNBOXRUN::InputManager *im = RUNBOXRUN::InputManager::getInstance();
			im->attachMouse(*this, [&](RUNBOXRUN::InputManager &im) {
				if(_locked || !_isActive) return;
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
		}


    bool Camera::_locked = true;

}