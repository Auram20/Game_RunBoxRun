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
		Map(const std::string &filename); /*!< default constructor */
		~Map() = default; /*!< default destructor*/

		int readMap(); /*!< read map in parameters */

		// GETTERS
		inline const std::vector<int> getDatas() const { return _datas; }/*!< get map datas*/
		inline const std::vector<glm::vec4> getAllInfosDatas() const { return _vecdata; }/*!< get all infos of datas*/
		inline const unsigned int getNbline() const { return _nbline; } /*!< get nb lines */
		inline const unsigned int getNbCol() const { return _nbcol; } /*!< get nb lines */
		inline const unsigned int getNbBloc() const { return _nbBloc; } /*!< get nb lines */

		private:
		std::vector<int>  _datas; /*!< map's id */
		unsigned int	_nbline; /*!< number of line in data map */
		unsigned int	_nbcol; /*!< number of col in data map */
		unsigned int 	_nbBloc; /*!< number of blocs in data map*/
		unsigned int	_x; /*!< value x of datas */
		unsigned int	_z; /*!< value z of datas */
		unsigned int 	_y; /*!< value y of datas */
		std::string _filename; /*! < map's filename */
		std::vector<glm::vec4> _vecdata; /*!< id, x, y, z of datas */
	};
}

#endif


  