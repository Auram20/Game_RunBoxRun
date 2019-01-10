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
    /*!< Classe qui gère les lumières */
	class Light
	{
		
		public:
		// CONSTRUCTORS & DESTRUCTOR
		Light(
            const glm::vec3 &position = glm::vec3(0, 0, 0),
            const glm::vec3 &intensity = glm::vec3(1, 1, 1)
        )
        : _position(position), _intensity(intensity)
        {};/*!< constructor with parameters */
        
		virtual ~Light() = default; /*!< default destructor*/
        
        inline const glm::vec3 position() const {
            return _position;
        }

        inline const glm::vec3 intensity() const {
            return _intensity;
        }

        private:
        glm::vec3 _position;
        glm::vec3 _intensity;

    };
}

#endif


  