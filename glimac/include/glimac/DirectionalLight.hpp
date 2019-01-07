// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ POINTLIGHT.HPP_____ 
//================================

#ifndef __DIRECTIONALLIGHT__HPP
#define __DIRECTIONALLIGHT__HPP

#include <iostream>
#include <utils/glm.hpp>
#include <glimac/Light.hpp>

namespace glimac
{
	/// \class MainScene
	/// \brief class defining a new GameManager MainScene.
	class DirectionalLight : public Light
	{
		
		public:
		// CONSTRUCTORS & DESTRUCTOR
		DirectionalLight(
            const glm::vec3 &position = glm::vec3(0, 0, 0),
            const glm::vec3 &intensity = glm::vec3(1, 1, 1)
        )
        : Light(position, intensity)
        {};/*!< default constructor */
		~DirectionalLight() = default; /*!< default destructor*/
        
        private:


    };
}

#endif


  