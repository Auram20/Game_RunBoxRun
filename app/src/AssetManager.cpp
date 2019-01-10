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
    _assets.emplace(glimac::AssetType::SHADER, std::map<std::string, std::shared_ptr<glimac::Asset>>());
}

AssetManager::~AssetManager() {
    AssetManager::_instance = nullptr;
    deleteFor(glimac::AssetType::NONE);
    deleteFor(glimac::AssetType::TEXTURE);
    deleteFor(glimac::AssetType::MODEL);
    deleteFor(glimac::AssetType::MAP);
    deleteFor(glimac::AssetType::MATERIAL);
    deleteFor(glimac::AssetType::SHADER);
}

void AssetManager::find() {
    std::experimental::filesystem::recursive_directory_iterator itPath(_assetDir.str());

    for (auto& dirEntry : itPath) {
        sortFile(dirEntry);
    }
}


void AssetManager::sortFile(const std::experimental::filesystem::directory_entry &dirEntry) {
    glimac::FilePath filepath(dirEntry.path());
    int i;

    std::cout << filepath.filename() << std::endl;

    if(filepath.ext() != "") {
        if(glimac::endWithVector(filepath.str(), MODEL_EXT) > -1) {
            _assets[glimac::AssetType::MODEL].emplace(filepath.filename(), std::make_shared<glimac::Model>(glimac::Model(filepath)));
        }
        else if (glimac::endWithVector(filepath.str(), MAP_EXT) > -1) {
            _assets[glimac::AssetType::MAP].emplace(filepath.filename(), std::make_shared<Map>(Map(filepath)));
        }
        else if ((i = glimac::endWithVector(filepath.str(), SHADER_EXT)) > -1) {
            if(i == 0) {
                _assets[glimac::AssetType::SHADER].emplace(filepath.filename(), std::make_shared<glimac::Shader>(glimac::Shader(GL_VERTEX_SHADER, filepath)));
            } else {
                _assets[glimac::AssetType::SHADER].emplace(filepath.filename(), std::make_shared<glimac::Shader>(glimac::Shader(GL_FRAGMENT_SHADER, filepath)));
            }
        }
    }
}

void AssetManager::deleteFor(const glimac::AssetType &type) {
    if(_assets.find(type) == _assets.end()) return;
    std::map<std::string, std::shared_ptr<glimac::Asset>> map = _assets[type];
    for(auto it = map.begin(); it != map.end(); ++it) {
        (it->second).reset();
    }
}

AssetManager* AssetManager::_instance = nullptr;