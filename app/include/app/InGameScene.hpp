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
#include <unistd.h>
#include <app/Scene.hpp>
#include <app/SceneManager.hpp>

namespace RUNBOXRUN
{

/// \class In Game 
	/// \brief class defining a new GameManager.
	class IGScene : public GameManager, public utils::Observable<InputManager>
	{
	
	private:

	public: 
		IGScene() : GameManager() {}; 
		~IGScene() = default ;

		void initScene(Scene &scene) override
		{
			/*InputManager *man= InputManager::getInstance();
			man->attachKey(*this, SDLK_c, [&](RUNBOXRUN::InputManager &im) {
        		 scene.changeCurrentCamera();
     		});
		     man->attachKey(*this, SDLK_l, [&](RUNBOXRUN::InputManager &im) {
		         Camera::lock();
		     });*/


			Map map("../assets/map/test2.txt");
		    map.load();
    		SceneFactory sceneMap;
    		sceneMap.initSPrograms();
    		Scene Masc(sceneMap.constructSceneFromMap(map)); // Car const 
    		scene=scene+Masc;

			std::cout << "non" << std::endl;
		    Player* p = Player::getInstance();
		    std::cout << " Avant changement " << std::endl;
		    p->displayInfos(); 
		    scene.push(p,"Player");

		    scene.addCamera("TrackBall", new glimac::TrackballCamera());
		    scene.addCamera("Freefly", new glimac::FreeflyCamera());
		    scene.setCurrentCamera("Freefly");
		};


		void runScene(Scene &scene, SDL_Event &e) override
		{
			scene.drawScene(); 
			scene.runCameras();
			
			std::map<std::string,GameObject *>::iterator it;
			it = scene._GameObjects.find("Player");
  			if (it != scene._GameObjects.end())
  			{
	    		dynamic_cast<Player*>(it->second)->updatePlayer(e);
			}

			Player *player = Player::getInstance();

			if(player->_health == 0) {
				SceneManager *sm = SceneManager::getInstance();
				sm->setIndex(2);
			}


		};

		void closeScene(Scene &scene) override{};		
	};
}

#endif