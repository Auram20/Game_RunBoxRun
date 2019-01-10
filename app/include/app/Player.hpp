// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ PLAYER.HPP ___________ 
//================================

#ifndef __PLAYER__HPP
#define __PLAYER__HPP

// Includes 
#include <app/GameObject.hpp>
#include <app/Scene.hpp>
#include <utils/Observable.hpp>
#include <app/InputManager.hpp>
#include <glimac/Model.hpp>
#include <app/SceneFactory.hpp>
#include <SDL/SDL_mixer.h>

#define VULNERABILITY_DELAY 1500 


namespace RUNBOXRUN
{
	/// \class Player
	/// \brief class defining a new player.
	/*!< Classe Joueur avec de ses positions, size, mouvements...*/
	class Player : public GameObject, public utils::Observable<InputManager>
	{
			
		private:
			Player(const double &speed, const glm::vec3 &position, const glm::vec3 &size, const glm::vec3 &color, const unsigned int &health, const  int &jumpState); /*!< private constructor with parameters*/
			Player(const double &speed, const glm::vec3 &position, const glm::vec3 &size, const glm::vec3 &color, const unsigned int &health, const unsigned int &score, const  int &jumpState, const glimac::Model &model, const Transform &transform); /*!< private constructor with parameters and model*/
		
			static Player* _instance; /*! < here will be the instance stored */
			double _speed;
			unsigned int _health; /*!< health points of the player */
			int _jumpState;  /*!< check if player is jumping = 2 /crouching = 1/standing = 0 */	
			bool _victory;
			bool _touched;  /*! Player Touched or not */
			Uint32  _vulnerabilityTime;  /*! Vulnerability Time*/
			unsigned int _score; /*! Game scored by player */
		public:

			~Player();/*!< default destructor*/

			// SETTERS
			inline void setHealth(unsigned int &health)
			{
			_health = health;
			} /*!< set player's health points */

			inline void setJumpState(unsigned int &jumpState)
			{
			_jumpState = jumpState;
			}/*!< display player's state : jumping, crouching or running*/


			inline void setTouched(const bool touched)
			{
			_touched = touched;
			}

			inline const unsigned int health() const {
				return _health;
			}

			inline const bool victory() const {
				return _victory;
			}

			//  PLAYER FUNCTIONS

			virtual void displayInfos(); /*!< display of player's informations */		
			void const jump(const double indice);/*!< vertical movement of the player */			
			static Player* getInstance();  /* Static access method. */
			void updatePlayer(SDL_Event e);
			void moveHorizontal(const double indice);
			void turnRight();
			void run();
			inline bool const isInvulnerable() const
			{ 
			return SDL_GetTicks() < VULNERABILITY_DELAY + _vulnerabilityTime;
			}
			void vulnerability();
			void initCollisionBehaviours();
		

	};
}


#endif
