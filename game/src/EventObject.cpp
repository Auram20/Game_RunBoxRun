// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ EVENTOBJECT.CPP ___________ 
//================================


#include <game/EventObject.hpp>
#include <iostream>

using namespace RUNBOXRUN;
using namespace glimac;




// --------------- CONSTRUCTORS && DESTRUCTORS --------------
/*
EventObject::EventObject()
: Object()
{}
*/

EventObject::EventObject(const double &speed, const glm::vec3 &position, const glm::vec3 &size, const glm::vec3 &color, const Model &model)
: Object(speed, position, size, color, model)
{}

EventObject::EventObject(const EventObject &eventObject)
: Object(eventObject._speed, eventObject._position, eventObject._size, eventObject._color, eventObject._model)
{}

EventObject::~EventObject()
{}




// --------------- EVENT OBJECT'S FUNCTIONS --------------

void EventObject::displayInfos()
{
	Object::displayInfos();
}

