// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ MAINSCENE.HPP_____ 
//================================

#ifndef __MAINSCENE__HPP
#define __MAINSCENE__HPP

#include <iostream>
#include <app/Scene.hpp>

namespace RUNBOXRUN
{
	/// \class MainScene
	/// \brief class defining a new GameManager MainScene.
	class MainScene : public GameManager
	{
		
		private:

		public:
		// CONSTRUCTORS & DESTRUCTOR
		MainScene(); /*!< default constructor */
		~MainScene() = default; /*!< default destructor*/
        

		void initScene(Scene &scene) override;

		void runScene(Scene &scene) override;

		void closeScene(Scene &scene) override;

    };
}

#endif


  