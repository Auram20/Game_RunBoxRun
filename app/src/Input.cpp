// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ INPUT.CPP_____ 
//================================

#include <app/Input.hpp>


using namespace RUNBOXRUN;
	

// --------------- CONSTRUCTORS && DESTRUCTORS --------------

	Input::Input(const SDLKey &key, std::function<void(Player* p)> &action)
	: _active(false), _key(key), _action(action)
	{

	}
