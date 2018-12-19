// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ MAP.HPP_____ 
//================================

#ifndef __MAP__HPP
#define __MAP__HPP

#include <glimac/glm.hpp>
#include <GL/glew.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <utils/Error.hpp>
#include <app/glm.hpp>

namespace RUNBOXRUN
{
	/// \class Map
	/// \brief class defining a new map.
	class Map
	{
			
		public:
		// CONSTRUCTORS & DESTRUCTOR
		Map() = default; /*!< default constructor */
		~Map() = default; /*!< default destructor*/

		int readMap(const std::string &filename); /*!< read map in parameters */

		// GETTERS
		inline const std::vector<int> getDatas() const { return _datas; }/*!< get map datas*/

		private:
		std::vector<int>  _datas; /*!< map's id */
		unsigned int	_x; /*!< value x of datas */
		unsigned int	_z; /*!< value z of datas */
		unsigned int 	_y; /*!< value y of datas */
		std::std::vector<glm::vec4> _vecdata; /*!< id, x, y, z of datas */
	};
}

#endif


  