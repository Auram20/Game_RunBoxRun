// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ EVENTOBJECT.CPP ___________ 
//================================


#include "game/EventObject.hpp"
#include <iostream>

using namespace RUNBOXRUN;

// --------------- CONSTRUCTORS && DESTRUCTORS --------------

EventObject::EventObject()
: Object()
{}


EventObject::EventObject(const double &speed, const glm::vec3 &position, const glm::vec3 &size, const glm::vec3 &color, const std::string &pathObj)
: Object(speed, position, size, color, pathObj)
{}

EventObject::EventObject(const EventObject &eventObject)
: Object(eventObject._speed, eventObject._position, eventObject._size, eventObject._color, eventObject._pathObj)
{}

EventObject::~EventObject()
{}




// --------------- EVENT OBJECT'S FUNCTIONS --------------

