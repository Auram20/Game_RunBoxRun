// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ ASSET.HPP ___________ 
//================================

#include <utils/Asset.hpp>

using namespace glimac;

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