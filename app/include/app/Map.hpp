// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ MAP.HPP_____ 
//================================

#ifndef __MAP__HPP
#define __MAP__HPP

#include <utils/glm.hpp>
#include <GL/glew.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <utils/Error.hpp>
#include <utils/Asset.hpp>

namespace RUNBOXRUN
{
	/// \class Map
	/// \brief class defining a new map.
	class Map : public glimac::Asset
	{
			
		public:
		// CONSTRUCTORS & DESTRUCTOR
		Map(const std::string &filename); /*!< default constructor */
		~Map() = default; /*!< default destructor*/

		bool load() override; /*!< read map in parameters */

		// GETTERS
		inline const std::vector<int> getDatas() const { return _datas; }/*!< get map datas*/
		inline const std::vector<glm::vec4> getAllInfosDatas() const { return _vecdata; }/*!< get all infos of datas*/

		public:
		std::vector<int>  _datas; /*!< map's id */
		int	_x; /*!< value x of datas */
		int	_z; /*!< value z of datas */
		int _y; /*!< value y of datas */
		std::string _filename; /*! < map's filename */
		std::vector<glm::vec4> _vecdata; /*!< id, x, y, z of datas */
	};
}

#endif


  