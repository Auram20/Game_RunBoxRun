// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ ERROR.HPP ___________ 
//================================

#ifndef __ERROR__HPP
#define __ERROR__HPP


// Includes 
#include <exception>
#include <string>
#include <sstream>

namespace RUNBOXRUN
{

	/// \class Error
	/// \brief class returning error kind, line and file.
	class Error : public std::exception
	{
	public:
		
		// CONSTRUCTORS & DESTRUCTOR
		Error(const std::string &description, const std::string &file, const unsigned int line) noexcept
			: m_description(description), m_file(file), m_line(line)
		{
			m_what	= "-> Exception thrown from file " + m_file + " at line " + std::to_string(m_line)
					+ "\n---> " + m_description;
		}/*!< default constructor */
		
		virtual ~Error() noexcept {}/*!< default destructor */

		const char *what() const noexcept override 
		{
			return m_what.c_str();
		}/*!< message of error */
		


	private:
		std::string m_description;
		std::string m_file;
		unsigned int m_line;
		std::string m_what;
	};

	#define THROW_EXCEPTION(str) throw Error(str, __FILE__, __LINE__)
}


// --------------- ERROR'S FUNCTIONS --------------

	void testException(const int x);/*!< test function for errors display*/


#endif
