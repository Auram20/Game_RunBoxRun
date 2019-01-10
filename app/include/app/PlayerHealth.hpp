// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ PLAYERHEALTH.HPP ___________ 
//================================

#ifndef __PLAYERHEALTH__HPP
#define __PLAYERHEALTH__HPP

// Includes 
#include <app/GameObject.hpp>
#include <app/Scene.hpp>
#include <utils/Observable.hpp>
#include <app/InputManager.hpp>
#include <glimac/Model.hpp>
#include <app/SceneFactory.hpp>
#include <app/Player.hpp>

namespace RUNBOXRUN
{
	/// \class PlayerHealth
	class PlayerHealth : public GameObject, public utils::Observable<InputManager>
	{
			
		private:
			PlayerHealth(const double &speed, const glm::vec3 &position, const glm::vec3 &size); /*!< private constructor with parameters*/
			PlayerHealth(const double &speed, const glm::vec3 &position, const glm::vec3 &size, const unsigned int &score, const glimac::Model &model, const Transform &transform); /*!< private constructor with parameters and model*/
			static PlayerHealth* _instance; /*! < here will be the instance stored */
			double _speed;
		
		public:


			~PlayerHealth();/*!< default destructor*/

			// SETTERS
			static PlayerHealth* getInstance();  /* Static access method. */
			void run();
	};
}


#endif
