// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ EVENTOBJECT.HPP ___________ 
//================================

#ifndef __EVENTOBJECT__HPP
#define __EVENTOBJECT__HPP

// Includes 
#include "Object.hpp"
#include <string>

namespace RUNBOXRUN
{
	/// \class EventObject
	/// \brief class defining a new EventObject.
	class EventObject : public Object
	{
			
		public:

		// CONSTRUCTORS & DESTRUCTOR
		EventObject(); /*!< default constructor */
		EventObject(const double &speed, const glm::vec3 &position, const glm::vec3 &size, const glm::vec3 &color, const std::string &pathObj);/*!< event object's constructor with arguments*/
		EventObject(const EventObject &eventObject); /*!< constructor with arguments*/
		~EventObject(); /*!< default destructor*/

    };
}

#endif
