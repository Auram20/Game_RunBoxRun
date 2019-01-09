// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ GAMEOBJECT.CPP_____ 
//================================

#include "app/GameObject.hpp"

using namespace RUNBOXRUN;

GameObject::GameObject(const unsigned int &sProgramID)
: _model(), _transform(), _sProgramID(sProgramID), _boundingBox(), _atCollision(), _targets()
{
    _enable=1;
}

GameObject::GameObject(const glimac::Model &model, const unsigned int &sProgramID)
: _model(new glimac::Model(model)), _transform(), _sProgramID(sProgramID), _boundingBox(), _atCollision(), _targets()
{
    _enable=1;
}

GameObject::GameObject(const GameObject &gobj)
: _model(gobj._model), _transform(gobj._transform), _sProgramID(gobj._sProgramID), _boundingBox(gobj._boundingBox), _atCollision(gobj._atCollision), _targets(gobj._targets)
{
    _enable=1;
}

GameObject::GameObject(const GameObject &gobj, const Transform &transform)
: _model(gobj._model), _transform(transform), _sProgramID(gobj._sProgramID), _boundingBox(gobj._boundingBox), _atCollision(gobj._atCollision), _targets(gobj._targets)
{
    _enable=1;
}

GameObject::GameObject(const glimac::Model &model, const Transform &transform, const unsigned int &sProgramID)
: _model(new glimac::Model(model)), _transform(transform), _sProgramID(sProgramID), _boundingBox(glm::vec3(-0.5, -0.5, -0.5), glm::vec3(0.5, 0.5, 0.5)), _atCollision(), _targets()
{
    _enable=1;    
}

GameObject::GameObject(const std::shared_ptr<glimac::Asset> &asset, const unsigned int &sProgramID)
: _model(nullptr), _transform(), _sProgramID(sProgramID), _boundingBox(), _atCollision(), _targets()
{
    _enable=1;
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
    std::cout /*<< "speed: " << getLocalSpeed() << std::endl
    << "position : " << getLocalPos() << std::endl
    << "position : " << getGlobalPos() << std::endl
    << "size : " << getLocalSize() << std::endl
    << "color : " << getLocalColor() << std::endl*/
    << "MVMATRIX" << _transform.matrix() << std::endl;
}