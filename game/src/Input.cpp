// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ INPUT.HPP_____ 
//================================

#include "../include/Input.hpp"

using namespace RUNBOXRUN;
	
	// CONSTRUCTORS & DESTRUCTOR
	Input::Input(const SDLKey &key, std::function<void()> &action)
	: _active(false), _key(key), _action(action)
	{

	}
