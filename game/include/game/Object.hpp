// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ OBJECT.HPP ___________ 
//================================

#ifndef __OBJECT__HPP
#define __OBJECT__HPP

// Includes 
#include <game/glm.hpp>

namespace RUNBOXRUN
{
	/// \class Object
	/// \brief class defining a new object.
	class Object
	{
			
		public:
			
		// CONSTRUCTORS & DESTRUCTOR
		Object(); /*!< default constructor */
		Object(const double &speed, const glm::vec3 &position, const glm::vec3 &size, const glm::vec3 &color);/*!< object's constructor with arguments*/
		Object(const Object &object);/*!< constructor with arguments*/
		~Object(); /*!< default destructor */
		
		// GETTERS
		inline glm::vec3 getPos(){return _position;} /*!< getter object's position */ 
	
		// SETTERS
		inline void setPos(glm::vec3 &newPos){ _position = newPos;}	/*!< setter object's position */

		// OBJECT FUNCTIONS 
		virtual void displayInfos(); /*!< display object informations */
		void moveHorizontal(const double &t); /*!< horizontal movement of the object */

		protected:
		double _speed; /*!< object's speed */
		glm::vec3 _position ;  /*!< object's position */
		glm::vec3 _size; /*!< object's size */
		glm::vec3 _color; /*!< object's color */

	};
}



#endif
