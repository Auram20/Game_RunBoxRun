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
		Scene() = default; /*!< default constructor */
		~Scene() = default; /*!< default destructor*/

		inline void drawScene(const glimac::Render &render) const {
			std::for_each(
				_GameObjects.begin(),
				_GameObjects.end(),
				[&render]( GameObject *gobj){
					render.sendDatas(gobj->transformMatrix());
					gobj->draw();
				}
			);
		}

		inline void setCurrentCamera(const std::string &cam) {
			if(_Cameras.find(cam) != _Cameras.end())
				_currentCam = _Cameras.at(cam);
		}

		inline void push(const GameObject gobj) {
			 GameObject* gobj2 = new GameObject(gobj);
			_GameObjects.push_back(gobj2);
		}

		inline const glm::mat4 getCurrentViewMatrix() const {
			return _currentCam->getViewMatrix();
		}

		private:
            std::vector<GameObject *> _GameObjects;
			std::map<std::string, glimac::Camera*> _Cameras;
			glimac::Camera *_currentCam;
            //std::vector<Material> _Materials;
            
	};
}

#endif


  