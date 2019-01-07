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
#include <glimac/Texture.hpp>
#include <glimac/Light.hpp>
#include <memory>
#define MAX_TEXTURE 10

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
		void sendDatas() const;
		void sendDatas(const glm::mat4 &MVPMatrix, const glm::mat4 &MVMatrix, const glm::mat4 &NormalMatrix) const;
		void sendDatas(const glm::mat4 &MVMatrix) const;
		void sendDatasTex(const std::vector<Texture> &tex) const;
		void sendDatasLight(const std::vector<Light> &lights) const;

		static inline void destroy() {
			if(_instance != nullptr)
				delete _instance;
		}

		static inline Render *getInstance() {
			if(_instance == nullptr) {
				_instance = new Render();
				_instance->initRender();
			}
			return _instance;
		}
	
		void displayInfos() const {
			std::cout << _ProjMatrix << std::endl;
			std::cout << _MVMatrix << std::endl;
			std::cout << _NormalMatrix << std::endl;
			std::cout << uMVPMatrix << std::endl;
			std::cout << uMVMatrix << std::endl;
			std::cout << uNormalMatrix << std::endl;
			std::cout << uTexture << std::endl;
		}

		inline void use(const unsigned int &id) const {
			if(getProgramSize() <= id) return;
			_sPrograms[id].use();
		}

		static inline const unsigned int getProgramSize() {
			return _sPrograms.size();
		}

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

		static inline const unsigned int pushNewProgram() {
			_sPrograms.push_back(Program());
			return getProgramSize() - 1;
		} 

		private:
		glm::mat4 _ProjMatrix;
		glm::mat4 _MVMatrix;
		glm::mat4 _NormalMatrix;
		GLint uMVPMatrix;
		GLint uMVMatrix;
		GLint uNormalMatrix;
		GLint uTexture;
		GLint uTextureSize;
		GLint uKdColor;
		GLint uKsColor;
		GLint uShininess;
		GLint uLightPos;
		GLint uLightIntensity;
		Render() = default ; /*!< constructor with parameters */
		static std::vector<Program> _sPrograms;
		static Render* _instance;

	};
}

#endif
