// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ SCENE.HPP_____ 
//================================

#ifndef __SCENE__HPP
#define __SCENE__HPP

#include <GL/glew.h>
#include <vector>
#include <map>
#include <app/Camera.hpp>
#include <utils/Error.hpp>
#include <algorithm>
#include "app/GameObject.hpp"
#include <glimac/Render.hpp>
#include <glimac/Box.hpp>
#include <utils/FilePath.hpp>
#include <glimac/Light.hpp>

namespace RUNBOXRUN
{

	class Scene;

	/// \class GameManager
	/// \brief class defining a new GameManager.
	class GameManager
	{
		
		private:

		public:
		// CONSTRUCTORS & DESTRUCTOR
		GameManager() = default; /*!< default constructor */
		virtual ~GameManager() = default; /*!< default destructor*/
        

		virtual void initScene(Scene &scene) {};

		virtual void runScene(Scene &scene, SDL_Event &e) {};

		virtual void closeScene(Scene &scene) {};

    };

	



	/// \class Scene
	/// \brief class defining a new Scene
	class Scene
	{
			
		public:
		// CONSTRUCTORS & DESTRUCTOR
		Scene(); /*!< default constructor */
		Scene(const Scene &sc);

		~Scene(); /*!< default destructor*/

		virtual inline void drawScene() const {
			glimac::Render *render = glimac::Render::getInstance(); 
			std::for_each(
				_GameObjects.begin(),
				_GameObjects.end(),

				[&](const std::pair<std::string,GameObject *> &pair)
				{
					(pair.second)->checkCollisions(_GameObjects);
					render->program(pair.second->programID());
					render->sendDatas(getCurrentViewMatrix() * pair.second->transformMatrix());
					pair.second->draw();
				}
			);
		} /*!< draw all game objects from map*/


		inline void run(SDL_Event &e) {
			if(_gameManager.get() != nullptr)
				_gameManager->runScene(*this, e);
			drawScene();
		}

		inline void setCurrentCamera(const std::string &name) {
			if(_currentCam != _Cameras.end()) (_currentCam->second)->activate();
			_currentCam = _Cameras.find(name);
			(_currentCam->second)->activate();
		}

		inline void runCameras(){
			std::for_each(
				_Cameras.begin(),
				_Cameras.end(),
				[&](const std::pair<std::string, glimac:: Camera*> &pair)
					{
						pair.second->translateZ(0.1);
					}
				);
		}

		inline void changeCurrentCamera() {
			(_currentCam->second)->activate();
			++_currentCam;
			if(_currentCam == _Cameras.end()) {
				_currentCam = _Cameras.begin();
			}
			(_currentCam->second)->activate();
		}

		inline void addCamera(const std::string &name, glimac::Camera *cam) {
			if(_Cameras.find(name) == _Cameras.end())
				_Cameras.emplace(name, cam);
		}

		inline void push(GameObject *gobj, std::string id) {
			_GameObjects.insert(std::pair<std::string,GameObject *>(id,gobj));
		} /*!< push game object in scene */

		inline GameObject *find(const std::string &id) const {
			auto it = _GameObjects.find(id);
			if(it == _GameObjects.end()) {
				return nullptr;
			} else {
				return it->second;
			}
		}

		inline const glm::mat4 getCurrentViewMatrix() const {
			if(_currentCam == _Cameras.end()) {
				return glm::mat4(1.f);
			} else {
				return (_currentCam->second)->getViewMatrix();
			}
		}

		template<typename T>
		inline void setGameManager(const T &gm) {
			clearScene();
			_gameManager = std::make_shared<T>(gm);
			init();
		}

		inline void setGameManager(const std::shared_ptr<GameManager> &gm) {
			clearScene();
			_gameManager = gm;
			init();
		}

		Scene &operator=(const Scene &scene) {
			 if(this != &scene) {
			 	clearScene();
			 	_GameObjects = scene._GameObjects;
			 	_Cameras = scene._Cameras;
				_gameManager = scene._gameManager;
				//init();
			 }
			return *this;
		}

		Scene &operator+(Scene &scene) {
			if(this != &scene) {
				_GameObjects.insert(scene._GameObjects.begin(), scene._GameObjects.end());
				scene._GameObjects.clear();
			}

			return *this;
		}

		inline void clearScene() {
			close();
			resetMap<GameObject>(_GameObjects);
			resetMap<glimac::Camera>(_Cameras);
			_currentCam = _Cameras.end();
		}

		inline void init() {
			if(_gameManager.get() != nullptr)
				_gameManager->initScene(*this);
		}

		inline void close() {
			if(_gameManager.get() != nullptr)
				_gameManager->closeScene(*this);
		}

		template<typename T>
		inline void resetMap(std::map<std::string, T*> &map) {
			for(auto it = map.begin(); it != map.end(); ++it) {
				delete it->second;
			}
			map.clear();
		}

		
			std::shared_ptr<GameManager> _gameManager;
            std::map<std::string, GameObject *> _GameObjects;
            int _etat;
		protected:
			std::map<std::string, glimac::Camera*> _Cameras;
			std::map<std::string, glimac::Camera*>::iterator _currentCam;
			//std::shared_ptr<GameManager> _gameManager;
			std::map<glimac::LightType, std::vector<glimac::Light>> _lights;
			glm::vec3 _color;
            
	};
}

#endif


  