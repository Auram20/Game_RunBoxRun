#pragma once

#include <GL/glew.h>
#include <string>
#include "FilePath.hpp"
#include <glimac/Asset.hpp>

#define GLIMAC_SHADER_SRC(str) #str

namespace glimac {

	class Shader : public Asset {
		public:
			Shader(GLenum type): Asset(), m_nGLId(glCreateShader(type)) {
			}

			~Shader() {
				glDeleteShader(m_nGLId);
			}

			Shader(Shader&& rvalue): m_nGLId(rvalue.m_nGLId) {
				rvalue.m_nGLId = 0;
			}

			Shader& operator =(Shader&& rvalue) {
				m_nGLId = rvalue.m_nGLId;
				rvalue.m_nGLId = 0;
				return *this;
			}

			GLuint getGLId() const {
				return m_nGLId;
			}

			void setSource(const char* src) {
				glShaderSource(m_nGLId, 1, &src, 0);
				_path = FilePath(src);
			}

			bool compile();

			const std::string getInfoLog() const;

			static Shader load(GLenum type, const FilePath& filepath);

		private:
			Shader(const Shader&);
			Shader& operator =(const Shader&);

			GLuint m_nGLId;
	};

}
