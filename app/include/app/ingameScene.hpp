// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ IGSCENE.HPP_____ 
//================================

#ifndef __IGSCENE__HPP
#define __IGSCENE__HPP

#include <GL/glew.h>
#include <vector>
#include <map>
#include <app/Scene.hpp>


/// \class In Game 
	/// \brief class defining a new GameManager.
	class IGScene : public GameManager
	{
	
	private:

	public: 
		IGScene() = default ;
		~IGScene() = default ;
		virtual void initScene(Scene &scene) override{};
		virtual void runScene(Scene &scene) override{};
		virtual void closeScene(Scene &scene) override{};		
	};

#endif