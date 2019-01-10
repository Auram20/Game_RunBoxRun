// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ WINDOWENGINE.HPP ___________ 
//================================

#ifndef __WINDOWENGINE__HPP
#define __WINDOWENGINE__HPP

// Includes 
#include <utils/glm.hpp>
#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <iostream>
#include <vector>
#include <glimac/Image.hpp>
#include <app/InputManager.hpp>
#include <glimac/Program.hpp>
#include <app/Map.hpp>
#include <app/SceneFactory.hpp>
#include <utils/FilePath.hpp>
#include <utils/Observable.hpp>
#include <SDL/SDL_mixer.h>

#define FPS 60
#define FRAMERATE_MILLISECONDS 1000 / FPS

using namespace RUNBOXRUN;
namespace glimac
{
	/// \class WindowEngine
	/// \brief class for  WindowEngine.
	/*!< Class WindowEngine */
	class WindowEngine : public utils::Observable<InputManager>
	{
			
		public:
        // CONSTRUCTORS & DESTRUCTOR
		//WindowEngine();	
		WindowEngine(const uint32_t &width, const uint32_t &height, const char* title, const SceneFactory &sceneFactory); /*!< constructor with parameters */
		~WindowEngine()=default; /*!< default destructor*/

		// WINDOWENGINE FUNCTIONS

		int initWindow(FilePath app); /*!< render loop */

		/*!< load et joue la musique du jeu */
		inline int playMusic()
		{

	        if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1){
	        	std::cout <<"ERROR initializing mix" << std::endl;
	            return EXIT_FAILURE;
	        }


	        Mix_Music *game_music = Mix_LoadMUS( "../assets/sounds/runboyrun.mp3");// load music for the game 
	        Mix_PlayMusic(game_music, -1); // play music

			return EXIT_SUCCESS;
		};


		private:
		SDLWindowManager _windowManager; /*!< window */
		SceneFactory _scene;

	};
}

#endif
