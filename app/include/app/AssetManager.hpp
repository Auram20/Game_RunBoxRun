// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ ASSETMANAGER.HPP ___________ 
//================================

#ifndef __ASSETMANAGER__HPP
#define __ASSETMANAGER__HPP

// Includes 
#include <utils/Asset.hpp>
#include <iostream>
#include <map>
#include <memory>
#include <experimental/filesystem>
#include <glimac/Model.hpp>
#include <glimac/Shader.hpp>
#include <app/Map.hpp>
#include <glimac/Texture.hpp>

namespace RUNBOXRUN
{
	/// \class AssetManager
	/// \brief class for  AssetManager.
	class AssetManager
	{
			
		public:
        // CONSTRUCTORS & DESTRUCTOR	
		static inline void instanciate(const glimac::FilePath &bin) {
			if(_instance == nullptr) {
				_instance = new AssetManager(bin);	
			}
		}

		static inline void instanciate(const char* bin) {
			if(_instance == nullptr) {
				_instance = new AssetManager(glimac::FilePath(bin));	
			}
		}

		static inline void instanciate(const std::string &bin) {
			if(_instance == nullptr) {
				_instance = new AssetManager(glimac::FilePath(bin));	
			}
		}

		static inline AssetManager *getInstance() {
			return _instance;
		}

		static inline void destruct() {
			if(_instance == nullptr) return;
			delete _instance;
		}

		void find();
		void sortFile(const std::experimental::filesystem::directory_entry &dirEntry);

		const std::shared_ptr<glimac::Asset> get(const glimac::AssetType &type, const std::string &filename) {
			if(_assets.find(type) == _assets.end()) return nullptr;
			if(_assets[type].find(filename) == _assets[type].end()) return nullptr;
			return _assets[type][filename];
		}

		private:
        AssetManager() = delete;
        AssetManager(const glimac::FilePath &bin); /*!< constructor with parameters */
        ~AssetManager();
		void deleteFor(const glimac::AssetType &type);
		glimac::FilePath _assetDir;
        std::map<glimac::AssetType, std::map<std::string, std::shared_ptr<glimac::Asset>>> _assets;
		static AssetManager *_instance;

	};
}

#endif
