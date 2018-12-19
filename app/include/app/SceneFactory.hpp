// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ SCENEFACTORY.HPP_____ 
//================================

#ifndef __SCENEFACTORY__HPP
#define __SCENEFACTORY__HPP

#include <glimac/glm.hpp>
#include <GL/glew.h>
#include <iostream>
#include <app/Scene.hpp>
#include <utils/Error.hpp>
#include <app/Map.hpp>

namespace RUNBOXRUN
{
	/// \class SceneFactory
	/// \brief class defining a new Scene from a Map.
	class SceneFactory
	{
			
		public:
		// CONSTRUCTORS & DESTRUCTOR
		SceneFactory(); /*!< default constructor */
		~SceneFactory() = default; /*!< default destructor*/
        Scene constructSceneFromMap(const Map &map);


		private:
		
	};
}

#endif


  