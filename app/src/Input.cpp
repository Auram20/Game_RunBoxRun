// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ INPUT.HPP_____ 
//================================

#include <app/Input.hpp>


using namespace RUNBOXRUN;
	
	// CONSTRUCTORS & DESTRUCTOR
	Input::Input(std::function<void()> &action)
	: _active(false), _action(action)
	{

	}
