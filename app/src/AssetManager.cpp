// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ ASSETMANAGER.CPP_____ 
//================================

#include <app/AssetManager.hpp>

using namespace RUNBOXRUN;

AssetManager::AssetManager(const glimac::FilePath &bin)
: _assetDir(bin.dirPath() + "assets"), _assets()
{
    _assets.emplace(glimac::AssetType::NONE, std::map<std::string, std::shared_ptr<glimac::Asset>>());
    _assets.emplace(glimac::AssetType::TEXTURE, std::map<std::string, std::shared_ptr<glimac::Asset>>());
    _assets.emplace(glimac::AssetType::MODEL, std::map<std::string, std::shared_ptr<glimac::Asset>>());
    _assets.emplace(glimac::AssetType::MAP, std::map<std::string, std::shared_ptr<glimac::Asset>>());
    _assets.emplace(glimac::AssetType::MATERIAL, std::map<std::string, std::shared_ptr<glimac::Asset>>());
}

AssetManager::~AssetManager() {
    AssetManager::_instance = nullptr;
}

void AssetManager::find() {
    std::experimental::filesystem::recursive_directory_iterator itPath(_assetDir.str());
    std::cout << "In " << _assetDir << std::endl;

    for (auto& dirEntry : itPath)
     std::cout << dirEntry << std::endl;
}

AssetManager* AssetManager::_instance = nullptr;