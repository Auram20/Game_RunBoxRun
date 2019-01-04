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
		Scene() = default; /*!< default constructor */
		Scene(const Scene &sc);

		~Scene() = default; /*!< default destructor*/



		void initmainMenu();
		void mainMenu(SDL_Event e);

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
		}

		inline void setCurrentCamera(const std::string &cam) {
			if(_Cameras.find(cam) != _Cameras.end())
				_currentCam = _Cameras.at(cam);
		}

		inline void push(GameObject *gobj, std::string id) {
			 //GameObject* gobj2 = new GameObject(gobj);
			_GameObjects.insert(std::pair<std::string,GameObject *>(id,gobj));
		}

		inline const glm::mat4 getCurrentViewMatrix() const {
			return _currentCam->getViewMatrix();
		}

		private:
            std::map<std::string, GameObject *> _GameObjects;
			std::map<std::string, glimac::Camera*> _Cameras;
			glimac::Camera *_currentCam;
            //std::vector<Material> _Materials;
            
	};
}

#endif


  