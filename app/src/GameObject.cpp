// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ GAMEOBJECT.CPP_____ 
//================================

#include "app/GameObject.hpp"

using namespace RUNBOXRUN;

GameObject::GameObject()
: _object(nullptr), _model(), /*_mat(nullptr),*/ _transform()
{

}

GameObject::GameObject(const Object &object)
: _object(new Object(object)), _model(), _transform()
{

}

GameObject::GameObject(const glimac::Model &model, const Object &object)
: _object(new Object(object)), _model(new glimac::Model(model)), _transform()
{

}



GameObject::GameObject(const GameObject &gobj)
: _object(new Object(*(gobj._object))), _model(gobj._model), _transform(gobj._transform)
{

}

GameObject::GameObject(const glimac::Model &model, const Object &object, const Transform &transform)
: _object(new Object(object)), _model(new glimac::Model(model)), _transform(transform)
{
    
}

GameObject::GameObject(const std::shared_ptr<glimac::Asset> &asset, const Object &object)
: _object(new Object(object)), _model(nullptr), _transform()
{
    if(asset.get() != nullptr && asset->type() == glimac::AssetType::MODEL)
    _model = std::dynamic_pointer_cast<glimac::Model>(asset);
}

GameObject::GameObject(const std::shared_ptr<glimac::Asset> &asset, const Object &object, const Transform &transform)
: _object(new Object(object)), _model(nullptr), _transform(transform)
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
    << "size : " << getLocalSize() << std::endl
    << "color : " << getLocalColor() << std::endl;
}