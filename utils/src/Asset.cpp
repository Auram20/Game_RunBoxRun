// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ ASSET.HPP ___________ 
//================================

#include <utils/Asset.hpp>
#include <iostream>

const std::vector<std::string> MODEL_EXT = {".obj"};
const std::vector<std::string> MATERIAL_EXT = {".mtl"};
const std::vector<std::string> TEXTURE_EXT = {".jpg", ".png", ".jpeg"};
const std::vector<std::string> SHADER_EXT = {".vs.glsl", ".fs.glsl"};
const std::vector<std::string> MAP_EXT = {".map"};


namespace glimac {

    Asset::Asset(const FilePath &path, const AssetType &type)
    : _path(path), _type(type)
    {}

    Asset::Asset(const std::string &path, const AssetType &type)
    : _path(path), _type(type)
    {}

    Asset::Asset(const Asset &asset)
    : _path(asset._path), _type(asset._type)
    {

    }

    bool compareEnd(const std::string &fullString, const std::string &ending) {
        if (fullString.length() >= ending.length()) {
            return (fullString.compare(fullString.length() - ending.length(), ending.length(), ending) == 0);
        } else {
            return false;
        }
    }

    int endWithVector(const std::string &fullstring, const std::vector<std::string> &vec) {
        bool check = false;
        int r = -1;
        auto it = vec.begin();
        while(it != vec.end() && !check) {
            check = compareEnd(fullstring, *it);
            if(!check) ++it;
        }

        if(it - vec.begin() < vec.size()) {
            r = it - vec.begin();
        }

        return r;
    }
}