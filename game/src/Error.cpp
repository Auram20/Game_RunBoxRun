// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ ERROR.CPP ___________ 
//================================


#include <game/Error.hpp>
#include <iostream>


using namespace RUNBOXRUN;

// --------------- ERROR'S FUNCTIONS --------------

void testException(const int x)
    {
        if (x == 0)
            THROW_EXCEPTION(std::to_string(x) + " : ne passe pas");
        else
            std::cout << x << " : ca passe" << std::endl;
    }