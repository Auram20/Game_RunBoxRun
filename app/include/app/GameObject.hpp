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
#include <vector>
#include <functional>
#include <glimac/Program.hpp>
#include <glimac/BBox.hpp>

namespace RUNBOXRUN
{

	/// \class GameObject
	/// \brief class defining a GameObject
	class GameObject
	{
			
		public:
		// CONSTRUCTORS & DESTRUCTOR
        GameObject(const unsigned int &sProgramID = 0); /*!< default constructor */
        GameObject(const glimac::Model &model, const unsigned int &sProgramID = 0);
        GameObject(const std::shared_ptr<glimac::Asset> &asset, const Transform &transform, const unsigned int &sProgramID = 0);
        GameObject(const std::shared_ptr<glimac::Asset> &asset, const unsigned int &sProgramID = 0);
        GameObject(const GameObject &gobj);
        GameObject(const GameObject &gobj, const Transform &transform);
        GameObject(const glimac::Model &model, const Transform &transform, const unsigned int &sProgramID = 0);
		~GameObject(); /*!< default destructor*/

        void draw() const;

        /*inline const glm::vec3 getLocalPos() const {
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
        }*/

        inline const glm::mat4 transformMatrix() const {
            return _transform.matrix();
        }

        inline const GLuint programID() const {
            return _sProgramID;
        }

        // SETTERS
        inline void setTrans(glm::vec3 &newTrans){ _transform = newTrans;} /*!< setter object's position */
        
        inline const glm::vec3 position() const {
            return _transform._translate;
        }


        virtual void displayInfos(); /*!< display object informations */

        inline void atCollision(const unsigned int &id) {
            if(id > _atCollision.size()) return;
            _atCollision[id]();
        }

        inline unsigned int addCollisionBehaviour(const std::function<void(void)> &newBehaviour) {
            _atCollision.push_back(newBehaviour);
            return _atCollision.size() - 1;
        }

        inline void addCollisionTarget(const std::string &id, const unsigned int &behaviour) {
            _targets.emplace(id, behaviour);
        }

        inline void checkCollisions(const std::map<std::string, GameObject *> &gobjs) {
            for(auto target = _targets.begin(); target != _targets.end(); target++) {
                auto it = gobjs.find(target->first);
                if(it != gobjs.end()) {
                    GameObject *gobj = it->second;
                    if(gobj != nullptr && glimac::conjoint(_boundingBox * _transform.matrix(), gobj->_boundingBox * gobj->_transform.matrix())) {
                        gobj->atCollision(target->second);
                    }
                }
            }
        }


            Transform _transform;
		protected:
            std::shared_ptr<glimac::Model> _model;
            //Material* _mat; material qu'utilisera le modèle. En ce moment la texture est incorporée au modèle
  
            GLuint _sProgramID;  //utilisera un shader particulier s'il est assigné, le défaut sinon
            glimac::BBox3f _boundingBox;
            std::vector<std::function<void(void)>> _atCollision;
            std::map<std::string, unsigned int> _targets;
	};
}

#endif


  