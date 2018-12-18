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

namespace RUNBOXRUN
{
	/// \class Bonus
	/// \brief class defining a new bonus.
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
		std::vector<int>  _datas; /*!< map's datas */
		unsigned int	_nbline;
		unsigned int	_nbcol;
	};
}

#endif