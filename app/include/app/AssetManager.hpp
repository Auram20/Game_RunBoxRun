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

namespace RUNBOXRUN
{
	/// \class AssetManager
	/// \brief class for  AssetManager.
	class AssetManager
	{
			
		public:
        // CONSTRUCTORS & DESTRUCTOR	
		AssetManager *getInstance();


		private:
        AssetManager() = delete;
        AssetManager(glimac::FilePath assetDir);/*!< constructor with parameters */
        ~AssetManager();
		static glimac::FilePath _assetDir;
        static std::map<std::string, std::shared_ptr<glimac::Asset>> _assets;

	};
}

#endif
