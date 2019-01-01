// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ GAMEOBJECT.HPP_____ 
//================================

#ifndef __GAMEOBJECT__HPP
#define __GAMEOBJECT__HPP

#include <GL/glew.h>
#include <utils/Error.hpp>
#include "app/Transform.hpp"
#include <glimac/Model.hpp>
#include <game/Object.hpp>
#include <memory>

namespace RUNBOXRUN
{

	/// \class GameObject
	/// \brief class defining a GameObject
	class GameObject
	{
			
		public:
		// CONSTRUCTORS & DESTRUCTOR
		GameObject(); /*!< default constructor */
        GameObject(const Object &object);
        GameObject(const glimac::Model &model);
        GameObject(const glimac::Model &model, const Object &object);
        GameObject(const std::shared_ptr<glimac::Asset> &asset, const Object &object);
        GameObject(const std::shared_ptr<glimac::Asset> &asset, const Object &object, const Transform &transform);
        GameObject(const GameObject &gobj);
        GameObject(const glimac::Model &model, const Object &object, const Transform &transform);
		~GameObject(); /*!< default destructor*/

        void draw() const;

        inline const glm::vec3 getLocalPos() const {
            return _object->getPos();
        }

        inline const double getLocalSpeed() const {
            return _object->getSpeed();
        }

        inline const glm::vec3 getLocalSize() const {
            return _object->getSize();
        }
        
        inline const glm::vec3 getLocalColor() const {
            return _object->getColor();
        }

        inline const glm::vec3 getGlobalPos() const {
            return glm::vec3(_transform.matrix() * glm::vec4(getLocalPos(), 1.f));
        }

        inline const glm::mat4 transformMatrix() const {
            return _transform.matrix();
        }



        virtual void displayInfos(); /*!< display object informations */


		protected:
            std::unique_ptr<Object> _object;
            std::shared_ptr<glimac::Model> _model;
            //Material* _mat; material qu'utilisera le modèle. En ce moment la texture est incorporée au modèle
            Transform _transform;
            //ShaderProgram sProgram;  utilisera un shader particulier s'il est assigné, le défaut sinon
            
	};
}

#endif


  