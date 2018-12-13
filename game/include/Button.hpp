// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ BUTTON.HPP ___________ 
//================================

#ifndef __BUTTON__HPP
#define __BUTTON__HPP

// Includes 
#include "UiElement.hpp"
#include <string>

namespace RUNBOXRUN
{
	/// \class Button
	/// \brief class defining a new button.
	class Button: public UiElement
	{
			
		public:
		Button(); /*!< default constructor */
		Button(const unsigned int &width, const unsigned int &height, const std::string &description); /*!< button constructor width description */
		Button(const unsigned int &width, const unsigned int &height, const glm::vec3 &backgroundColor, const glm::vec3 &frontColor, const std::string &description);  /*!< button's constructor with arguments */
		Button(const Button &button); /*!< button's constructor by copy*/
		~Button(); /*!< default destructor*/

		//setters 
		inline void setBackgroundColor( const unsigned int r, const unsigned int v , const unsigned int b )
		{
			_backgroundColor.x = r;
			_backgroundColor.y = v;
			_backgroundColor.z = b;
		}

		inline void setFrontColor(const unsigned int r, const unsigned int v , const unsigned int b )
		{
			_frontColor.x = r;
			_frontColor.y = v;
			_frontColor.z = b;
		}
		

		void displayInfos(); /*!< display of button's informations */

		private:
		unsigned int _width; /*!< button's width */
		unsigned int _height; /*!< button's height */
		glm::vec3 _backgroundColor; /*!< button's background color */
		glm::vec3 _frontColor;  /*!< button's front color */
		std::string _description; /*!< button's description */

	};
}

#endif
