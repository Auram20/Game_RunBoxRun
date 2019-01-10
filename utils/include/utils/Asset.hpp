// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ ASSET.HPP ___________ 
//================================

#pragma once

#ifndef __ASSET__HPP
#define __ASSET__HPP

#include <GL/glew.h>
#include "FilePath.hpp"
#include <vector>

extern const std::vector<std::string> MODEL_EXT;
extern const std::vector<std::string> MATERIAL_EXT;
extern const std::vector<std::string> TEXTURE_EXT;
extern const std::vector<std::string> SHADER_EXT;
extern const std::vector<std::string> MAP_EXT;

namespace glimac {

	enum class AssetType {
		NONE,
		TEXTURE,
		MODEL,
		SHADER,
		MAP,
		MATERIAL,
		SOUND
	};

	class Asset {
		public:
			Asset() = default; /*!< default constructor */
			Asset(const FilePath &path, const AssetType &type); /*!< Asset's constructor with parameters*/
			Asset(const std::string &path, const AssetType &type); /*!< Asset's constructor with parameters*/
			Asset(const Asset &asset);

			virtual ~Asset() = default; /*!< Asset's destructor*/
			virtual bool load() = 0; /*Doit lancer une erreur s'il y a*/
			inline const FilePath path() const {
				return _path;
			}
			inline const std::string pathStr() const {
				return _path.str();
			}

			inline const AssetType type() const {
				return _type;
			}

		protected:
			FilePath _path; /*!< path */
			AssetType _type;
	};

	bool compareEnd(const std::string &fullString, const std::string &ending);

	int endWithVector(const std::string &fullstring, const std::vector<std::string> &vec);
}

#endif