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
#define VULNERABILITY_DELAY 1500 


namespace RUNBOXRUN
{
	/// \class Player
	/// \brief class defining a new player.
	class Player : public GameObject, public utils::Observable<InputManager>
	{
			
		private:
			Player(const double &speed, const glm::vec3 &position, const glm::vec3 &size, const glm::vec3 &color, const unsigned int &health, const  int &jumpState); /*!< private constructor with parameters*/
			Player(const double &speed, const glm::vec3 &position, const glm::vec3 &size, const glm::vec3 &color, const unsigned int &health, const unsigned int &score, const  int &jumpState, const glimac::Model &model, const Transform &transform); /*!< private constructor with parameters and model*/
		
			int _jumpState;  /*!< check if player is jumping = 2 /crouching = 1/standing = 0 */	
			static Player* _instance; /*! < here will be the instance stored */
			bool _touched;  /*! Player Touched or not */
			Uint32  _vulnerabilityTime;  /*! Vulnerability Time*/
		
		public:
			double _speed;
			unsigned int _health; /*!< health points of the player */
			unsigned int _score; /*! Game scored by player */


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
