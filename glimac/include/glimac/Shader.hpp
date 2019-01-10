#pragma once

#include <GL/glew.h>
#include <string>
#include <utils/FilePath.hpp>
#include <utils/Asset.hpp>

#define GLIMAC_SHADER_SRC(str) #str

namespace glimac {

	/*!< class shader */

class Shader : public Asset {
public:
	Shader(GLenum type, const FilePath &path): Asset(path, AssetType::SHADER), m_nGLId(glCreateShader(type)), _shaderType(type) {
	} /*!< constructor with parameters */

	Shader(GLenum type): Asset(FilePath(""), AssetType::SHADER), m_nGLId(glCreateShader(type)) {
	}  /*!< constructor with parameters */

	~Shader() {
		glDeleteShader(m_nGLId);
	}  /*!< destructor */

	Shader(Shader&& rvalue): Asset(rvalue._path, AssetType::SHADER), m_nGLId(rvalue.m_nGLId), _shaderType(rvalue._shaderType) {
		rvalue.m_nGLId = 0;
	} /*!< constructor by copy */

	//Getter
	inline const GLenum shaderType() const {
	
		return _shaderType; 
	}


	/*!< surcharge de l'opérateur = */ 
	Shader& operator =(Shader&& rvalue) {
		m_nGLId = rvalue.m_nGLId;
		rvalue.m_nGLId = 0;
		return *this;
	}

	// GETTER
	GLuint getGLId() const {
		return m_nGLId;
	}
	// Setter
	void setSource(const char* src) {
		glShaderSource(m_nGLId, 1, &src, 0);
	}

	bool compile();
	bool load() override;

	const std::string getInfoLog() const;

private:
	Shader(const Shader&);
	Shader& operator =(const Shader&);

	GLuint m_nGLId;
	GLenum _shaderType;
};

}
