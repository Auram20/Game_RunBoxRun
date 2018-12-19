// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ INPUT.CPP_____ 
//================================

#include <app/Input.hpp>


using namespace RUNBOXRUN;
	
// --------------- CONSTRUCTORS && DESTRUCTORS --------------


	// CONSTRUCTORS & DESTRUCTOR
	Input::Input(std::function<void()> &action)
	: _active(false), _action(action)
	{

	}
