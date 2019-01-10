// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ ASSETMANAGER.HPP ___________ 
// Design Pattern : Singleton
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

	/*!< Cette classe permet de charger tous les assets qui seront utiles pour les jeux.
	// Ils sont tous chargés préalablement et non au cours du rendu.*/

	class AssetManager
	{
			
		public:
        // CONSTRUCTORS & DESTRUCTOR	
		
		/*!< instanciate _instance with a FilePath */
		static inline void instanciate(const glimac::FilePath &bin) {
			if(_instance == nullptr) {
				_instance = new AssetManager(bin);	
			}
		}
		/*!< instanciate _instance with a char* */
		static inline void instanciate(const char* bin) {
			if(_instance == nullptr) {
				_instance = new AssetManager(glimac::FilePath(bin));	
			}
		}

		/*!< instanciate _instanciate with a string */
		static inline void instanciate(const std::string &bin) {
			if(_instance == nullptr) {
				_instance = new AssetManager(glimac::FilePath(bin));	
			}
		}

		/*!<  getter of _instance */
		static inline AssetManager *getInstance() {
			return _instance;
		}


		/*!< destructor of all assets used  and reset _instance = null */
		static inline void destruct() {
			if(_instance == nullptr) return;
			delete _instance;
		}

		/*!< std::experimental to have a recursive reading */
		void find();

		/*!< load all asset : insert ( emplace() ) all assets present with the FilePath */
		void sortFile(const std::experimental::filesystem::directory_entry &dirEntry);

		/*!< getter of asset's type and filename */
		const std::shared_ptr<glimac::Asset> get(const glimac::AssetType &type, const std::string &filename) {
			if(_assets.find(type) == _assets.end()) return nullptr;
			if(_assets[type].find(filename) == _assets[type].end()) return nullptr;
			return _assets[type][filename];
		}

		private:
        AssetManager() = delete; /*!< default constructor */
        AssetManager(const glimac::FilePath &bin); /*!< constructor with parameters */
        ~AssetManager();
		void deleteFor(const glimac::AssetType &type);
		glimac::FilePath _assetDir; // Filepath for assets
        std::map<glimac::AssetType, std::map<std::string, std::shared_ptr<glimac::Asset>>> _assets; //  AssetType = MODEL | SHADER | MAP | NONE | TEXTURE , configuration of all assets 
		static AssetManager *_instance; // Singleton 

	};
}

#endif
