// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ ASSET.HPP ___________ 
//================================

#pragma once

#include <GL/glew.h>
#include "FilePath.hpp"

namespace glimac {

	enum class AssetType {
		NONE,
		TEXTURE,
		MODEL,
		SHADER,
		MAP,
		MATERIAL
	};

	class Asset {
		public:
			Asset() = default; /*!< default constructor */
			Asset(const FilePath &path, const AssetType &type); /*!< Asset's constructor with parameters*/
			Asset(const std::string &path, const AssetType &type); /*!< Asset's constructor with parameters*/
			Asset(const Asset &asset);

			~Asset() = default; /*!< Asset's destructor*/
			virtual bool load() = 0; /*Doit lancer une erreur s'il y a*/
			inline const FilePath path() const {
				return _path;
			}
			inline const std::string pathStr() const {
				return _path.str();
			}

		protected:
			FilePath _path; /*!< path */
			AssetType _type;
	};
}
