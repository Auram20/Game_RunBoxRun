// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ GAMEOBJECT.CPP_____ 
//================================

#include "app/GameObject.hpp"

using namespace RUNBOXRUN;

GameObject::GameObject()
: _object(nullptr), _model(), /*_mat(nullptr),*/ _transform(), _sProgramID(0)
{

}

GameObject::GameObject(const Object &object, const unsigned int &sProgramID)
: _object(new Object(object)), _model(), _transform(), _sProgramID(sProgramID)
{

}

GameObject::GameObject(const glimac::Model &model, const Object &object, const unsigned int &sProgramID)
: _object(new Object(object)), _model(new glimac::Model(model)), _transform(), _sProgramID(sProgramID)
{

}


GameObject::GameObject(const glimac::Model &model, const unsigned int &sProgramID)
: _object(), _model(new glimac::Model(model)), _transform(), _sProgramID(sProgramID)
{

}


GameObject::GameObject(const GameObject &gobj)
: _object(new Object(*(gobj._object))), _model(gobj._model), _transform(gobj._transform), _sProgramID(gobj._sProgramID)
{

}

GameObject::GameObject(const GameObject &gobj, const Transform &transform)
: _object(new Object(*(gobj._object))), _model(gobj._model), _transform(transform), _sProgramID(gobj._sProgramID)
{

}

GameObject::GameObject(const glimac::Model &model, const Object &object, const Transform &transform, const unsigned int &sProgramID)
: _object(new Object(object)), _model(new glimac::Model(model)), _transform(transform), _sProgramID(sProgramID)
{
    
}

GameObject::GameObject(const std::shared_ptr<glimac::Asset> &asset, const Object &object, const unsigned int &sProgramID)
: _object(new Object(object)), _model(nullptr), _transform(), _sProgramID(sProgramID)
{
    if(asset.get() != nullptr && asset->type() == glimac::AssetType::MODEL)
    _model = std::dynamic_pointer_cast<glimac::Model>(asset);
}

GameObject::GameObject(const std::shared_ptr<glimac::Asset> &asset, const Object &object, const Transform &transform, const unsigned int &sProgramID)
: _object(new Object(object)), _model(nullptr), _transform(transform), _sProgramID(sProgramID)
{
    std::cout << asset.get() << std::endl;
    if(asset.get() != nullptr && asset->type() == glimac::AssetType::MODEL)
    _model = std::dynamic_pointer_cast<glimac::Model>(asset);
}

GameObject::~GameObject()
{
    //delete _object;
    _model.reset();
    //delete _mat;
}

void GameObject::draw() const {

    if(_model.get() != nullptr)
        _model->draw();
}


void  GameObject::displayInfos() 
{
    std::cout << "speed: " << getLocalSpeed() << std::endl
    << "position : " << getLocalPos() << std::endl
    << "position : " << getGlobalPos() << std::endl
    << "size : " << getLocalSize() << std::endl
    << "color : " << getLocalColor() << std::endl
    << "MVMATRIX" << _transform.matrix() << std::endl;
}