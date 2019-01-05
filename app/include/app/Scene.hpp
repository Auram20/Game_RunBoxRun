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

					[&render](const std::pair<std::string,GameObject *> &pair)
				{
					render->program(pair.second->programID());
					render->sendDatas(pair.second->transformMatrix());
					pair.second->draw();
				}
			);
		} /*!< draw all game objects from map*/

		inline void setCurrentCamera(const std::string &name) {
			if(_Cameras.find(name) != _Cameras.end())
				_currentCam = _Cameras.at(name);
		}

		inline void addCamera(const std::string &name, glimac::Camera *cam) {
			if(_Cameras.find(name) == _Cameras.end())
				_Cameras.emplace(name, cam);
		}

		inline void push(GameObject *gobj, std::string id) {
			_GameObjects.insert(std::pair<std::string,GameObject *>(id,gobj));
		} /*!< push game object in scene */

		inline const glm::mat4 getCurrentViewMatrix() const {
			if(_currentCam == nullptr) {
				return glm::mat4(1.f);
			} else {
				return _currentCam->getViewMatrix();
			}
		}


		protected:
            std::map<std::string, GameObject *> _GameObjects;
			std::map<std::string, glimac::Camera*> _Cameras;
			glimac::Camera *_currentCam;
            
	};
}

#endif


  