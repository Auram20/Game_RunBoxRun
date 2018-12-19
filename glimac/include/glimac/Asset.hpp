// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ ASSET.HPP ___________ 
//================================

#pragma once

#include <GL/glew.h>
#include "FilePath.hpp"

namespace glimac {

	class Asset {
		public:
			Asset() = default; /*!< default constructor */
			Asset(const FilePath &path); /*!< Asset's constructor with parameters*/
			~Asset() = default; /*!< Asset's destructor*/

		protected:
			FilePath _path; /*!< path */
	};
}
