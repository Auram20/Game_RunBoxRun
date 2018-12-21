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

GameObject::GameObject(glimac::Model *model, Object *object)
: _object(object), _model(model), _transform()
{

}

GameObject::~GameObject()
{
    //delete _object; SEGFAULT
    delete _model;
    //delete _mat;
}

void GameObject::draw() const {


    _model->draw();
}