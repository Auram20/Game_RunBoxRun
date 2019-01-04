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
#include <glimac/Camera.hpp>
#include <utils/Error.hpp>
#include <algorithm>
#include "app/GameObject.hpp"
#include <glimac/Render.hpp>

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
				[&]( GameObject *gobj){
					render->program(gobj->programID());
					render->sendDatas(gobj->transformMatrix() * getCurrentViewMatrix());
					gobj->draw();
				}
			);
		}

		inline void setCurrentCamera(const std::string &name) {
			if(_Cameras.find(name) != _Cameras.end())
				_currentCam = _Cameras.at(name).get();
		}

		inline void addCamera(const std::string &name, const glimac::Camera &cam) {
			if(_Cameras.find(name) == _Cameras.end())
				_Cameras.emplace(name, cam);
		}

		inline void push(GameObject *gobj) {
			 //GameObject* gobj2 = new GameObject(gobj);
			_GameObjects.push_back(gobj);
		}

		inline const glm::mat4 getCurrentViewMatrix() const {
			if(_currentCam == nullptr) {
				return glm::mat4(1.f);
			} else {
				return _currentCam->getViewMatrix();
			}
		}

		private:
            std::vector<GameObject *> _GameObjects;
			std::map<std::string, std::unique_ptr<glimac::Camera>> _Cameras;
			glimac::Camera *_currentCam;
            
	};
}

#endif


  