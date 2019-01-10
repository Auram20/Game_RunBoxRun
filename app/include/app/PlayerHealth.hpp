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


namespace RUNBOXRUN
{
	/// \class PlayerHealth
	/// \brief class defining a new PlayerHealth.
	/*!< Classe PlayerHealth qui gère la ligne de vie du joueur : sa position, sa vitesse, son affichage (modele obg, matrice de transformation) */

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
			static PlayerHealth* getInstance(); /* Static access method. for just one instance cf.Singleton */
			void run();
	};
}


#endif
