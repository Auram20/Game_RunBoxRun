// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ POINTLIGHT.HPP_____ 
//================================

#ifndef __POINTLIGHT__HPP
#define __POINTLIGHT__HPP

#include <iostream>
#include <utils/glm.hpp>
#include <glimac/Light.hpp>

namespace glimac
{
	/// \class MainScene
	/// \brief class defining a new GameManager MainScene.
	class PointLight : public Light
	{
		
		public:
		// CONSTRUCTORS & DESTRUCTOR
		PointLight(
            const glm::vec3 &position = glm::vec3(0, 0, 0),
            const glm::vec3 &intensity = glm::vec3(1, 1, 1)
        )
        : Light(position, intensity)
        {};/*!< default constructor */
		~PointLight() = default; /*!< default destructor*/
        
        private:


    };
}

#endif


  