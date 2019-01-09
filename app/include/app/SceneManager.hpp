// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ SCENEMANAGER.HPP_____ 
//================================

#ifndef __SCENEMANAGER__HPP
#define __SCENEMANAGER__HPP

#include <GL/glew.h>
#include <vector>
#include <map>
#include <app/Scene.hpp>
#include <app/Player.hpp>

namespace RUNBOXRUN
{

/// \class In Scene Manager 
	/// \brief class defining a new Scene manager.
	class SceneManager 
	{
	
	private:
		std::vector<std::shared_ptr<GameManager>> _GameManagers;
		unsigned int _currentindex;
		Scene _scene;
		static SceneManager* _instance; /*! < here will be the instance stored */


	public: 
		SceneManager()
		:_GameManagers(), _currentindex(0), _scene()
		{
		};

		~SceneManager() = default ;

		static SceneManager* getInstance()
		{
			if(_instance == nullptr)
		    {
		        _instance = new SceneManager();
		    }
			    return _instance;
		}

		void run(SDL_Event &e) 
		{
			_scene.run(e);
		}

		void setIndex(const int &index)
		{
			_currentindex=index;
			if (index < _GameManagers.size())
			{
			_scene.setGameManager(_GameManagers[index]);
			}
		}

		template<typename T>
		void push(const T &gm)
		{
			std::shared_ptr<GameManager> ptr = std::make_shared<T>(gm);
			_GameManagers.push_back(ptr);
		}

		void push(const std::shared_ptr<GameManager> &gm)
		{
			_GameManagers.push_back(gm);
		}



	 	void swapScenes(Scene &Menu, Scene &Jeu,SDL_Event &e) 
	 	{

	// 	    Player *player = Player::getInstance();
	// 		(Menu._gameManager)->runScene(Menu,e);
	// 		if (Menu._etat==2)
    //            {
    //                    (Jeu._gameManager)->runScene(Jeu,e);
            		
    //            }

	//            if (player->_health==0)
	//            {
	// 			Jeu.setGameManager(GameManager());
	// 			//Jeu._GameObjects.clear();
	// 			Menu._etat=0;

	// 			(Menu._gameManager)->runScene(Menu,e);
                
 	//             std::cout << " PERDU" << std::endl;
                
 	//                player->_health=4;
 	//        }
		};

	 };

	 SceneManager * SceneManager::_instance = nullptr;
}

#endif