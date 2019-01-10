// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ RENDER.HPP ___________ 
//================================

#ifndef __RENDER__HPP
#define __RENDER__HPP

// Includes 
#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <iostream>
#include <vector>
#include <glimac/Image.hpp>
#include <app/InputManager.hpp>
#include <glimac/Program.hpp>
#include <glimac/Material.hpp>
#include <glimac/Light.hpp>
#include <memory>

//define 
#define MAX_TEXTURE aiTextureType::aiTextureType_UNKNOWN
#define MAX_LIGHT 10

namespace glimac
{

	enum class LightType {
		DIRECTIONAL,
		POINT
	};

	enum class ProgramShader {
		ENEMY,
		COIN
	};


	/// \class Render
	/// \brief class for the rendering.
	/*! class de rendering qui se charge d'envoyer toutes les informations nécessaire aux shaders afind e permettre un rendu du jeu.
		Qu'une seule instance est en jeu à chaque fois */
	class Render
	{
			
		public:
        // CONSTRUCTORS & DESTRUCTOR
		~Render() {
			_instance = nullptr;
		} /*!< default destructor*/

		// WINDOWENGINE FUNCTIONS
		void program(const unsigned int &id);
		void initRender(); 
		void clear(); 
		void sendDatas() const; /*!< send Datas to shader */
		void sendDatas(const glm::mat4 &MVPMatrix, const glm::mat4 &MVMatrix, const glm::mat4 &NormalMatrix) const; /*!<send datas to shader */
		void sendDatas(const glm::mat4 &MVMatrix) const; /*!< send datas to shader */
		void sendDatasTex(const std::map<aiTextureType, Texture>::const_iterator &begin, const std::map<aiTextureType, Texture>::const_iterator &end) const; /*!< send datas texture to shader*/
		void sendDatasLight(const std::map<LightType, std::vector<Light>> &lights) const; /*!< send datas of light to shader */
		void sendDatasMat(const Material &mat) const; /*!<send datas of material to shader */

		/*!< delete the only instance of rendering */
		static inline void destroy() {
			if(_instance != nullptr)
				delete _instance;
		}

		/*!< Pour avoir un comportement Singleton : avoir qu'une seule instance à chaque fois*/
		static inline Render *getInstance() {
			if(_instance == nullptr) {
				_instance = new Render();
				_instance->initRender();
			}
			return _instance;
		}
	
		/*!< Affiche les informations relative aux variables uniformes et aux matrices pour debug */
		void displayInfos() const {
			std::cout << _ProjMatrix << std::endl;
			std::cout << _MVMatrix << std::endl;
			std::cout << _NormalMatrix << std::endl;
			std::cout << uMVPMatrix << std::endl;
			std::cout << uMVMatrix << std::endl;
			std::cout << uNormalMatrix << std::endl;
			std::cout << uTexture << std::endl;
		}

		/*!< call shaders in Program */
		inline void use(const unsigned int &id) const {
			if(getProgramSize() <= id) return;
			_sPrograms[id].use();
		}

		 /* GETTER*/
		static inline const unsigned int getProgramSize() {
			return _sPrograms.size();
		}

		/*!< insert a new program with new shaders */
		static inline const unsigned int pushNewProgram(Shader& vsShader, Shader& fsShader) {
			unsigned int id = getProgramSize();
			_sPrograms.push_back(buildProgramFromShaders(vsShader, fsShader));
			return id;
		}

		static inline const unsigned int pushNewProgram(const std::shared_ptr<Asset> &vsShaderPtr, const std::shared_ptr<Asset> &fsShaderPtr) {
			unsigned int id = getProgramSize();
			_sPrograms.push_back(buildProgramFromShaders(*(std::dynamic_pointer_cast<Shader>(vsShaderPtr)), *(std::dynamic_pointer_cast<Shader>(fsShaderPtr))));
			std::cout << "Program::" << id << std::endl;
			return id;
		} 

		/* insert new prgram */
		static inline const unsigned int pushNewProgram() {
			_sPrograms.push_back(Program());
			return getProgramSize() - 1;
		} 

		private:
		glm::mat4 _ProjMatrix; // Matrice de projection 
		glm::mat4 _MVMatrix; // View Matrice
		glm::mat4 _NormalMatrix; 
		GLint uMVPMatrix; 
		GLint uMVMatrix;
		GLint uNormalMatrix;
		GLint uTexture;
		GLint uLightSize;
		GLint uLightType;
		GLint uColors;
		GLint uShininess;
		GLint uLightPos;
		GLint uLightIntensity;
		Render() = default ; /*!< constructor with parameters */
		static std::vector<Program> _sPrograms;
		static Render* _instance; 

	};
}

#endif
