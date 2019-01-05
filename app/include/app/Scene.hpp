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

namespace RUNBOXRUN
{
	/// \class Scene
	/// \brief class defining a new Scene
	class Scene
	{
			
		public:
		// CONSTRUCTORS & DESTRUCTOR
		Scene(); /*!< default constructor */
		Scene(const Scene &sc);

		~Scene() = default; /*!< default destructor*/

		inline void drawScene() const {
			glimac::Render *render = glimac::Render::getInstance(); 
			std::for_each(
				_GameObjects.begin(),
				_GameObjects.end(),

				[&](const std::pair<std::string,GameObject *> &pair)
				{
					render->program(pair.second->programID());
					render->sendDatas(getCurrentViewMatrix() * pair.second->transformMatrix());
					pair.second->draw();
				}
			);
		} /*!< draw all game objects from map*/

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

		inline const glm::mat4 getCurrentViewMatrix() const {
			if(_currentCam == _Cameras.end()) {
				return glm::mat4(1.f);
			} else {
				return (_currentCam->second)->getViewMatrix();
			}
		}


		protected:
            std::map<std::string, GameObject *> _GameObjects;
			std::map<std::string, glimac::Camera*> _Cameras;
			std::map<std::string, glimac::Camera*>::iterator _currentCam;
            
	};
}

#endif


  