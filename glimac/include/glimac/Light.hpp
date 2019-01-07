// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ LIGHT.HPP_____ 
//================================

#ifndef __LIGHT__HPP
#define __LIGHT__HPP

#include <iostream>
#include <utils/glm.hpp>

namespace glimac
{
	/// \class MainScene
	/// \brief class defining a new GameManager MainScene.
	class Light
	{
		
		public:
		// CONSTRUCTORS & DESTRUCTOR
		Light(
            const glm::vec3 &position = glm::vec3(0, 0, 0),
            const glm::vec3 &intensity = glm::vec3(1, 1, 1),
            const float &shininess = 1.f
        )
        : _shininess(shininess), _position(position), _intensity(intensity)
        {};/*!< default constructor */
		~Light() = default; /*!< default destructor*/
        
        private:
        float _shininess;
        glm::vec3 _position;
        glm::vec3 _intensity;

    };
}

#endif


  