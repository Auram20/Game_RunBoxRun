// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ GAMEOBJECT.CPP_____ 
//================================

#include "app/GameObject.hpp"

using namespace RUNBOXRUN;

GameObject::GameObject()
: _object(nullptr), _model(nullptr), /*_mat(nullptr),*/ _transform()
{

}

GameObject::GameObject(const glimac::Model &model, const Object &object)
: _object(new Object(object)), _model(std::make_shared<glimac::Model>(model)), _transform()
{

}

GameObject::GameObject(const GameObject &gobj)
: _object(new Object(*(gobj._object))), _model(gobj._model), _transform(gobj._transform)
{

}

GameObject::GameObject(const glimac::Model &model, const Object &object, const Transform &transform)
: _object(new Object(object)), _model(std::make_shared<glimac::Model>(model)), _transform(transform)
{

}




GameObject::~GameObject()
{
    //delete _object;
    //delete _model;
    //delete _mat;
}

void GameObject::draw() const {


    _model->draw();
}