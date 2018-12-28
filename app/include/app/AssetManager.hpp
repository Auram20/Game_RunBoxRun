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

		void find();


		private:
        AssetManager() = delete;
        AssetManager(const glimac::FilePath &bin); /*!< constructor with parameters */
        ~AssetManager();
		glimac::FilePath _assetDir;
        std::map<glimac::AssetType, std::map<std::string, std::shared_ptr<glimac::Asset>>> _assets;
		static AssetManager *_instance;

	};
}

#endif
