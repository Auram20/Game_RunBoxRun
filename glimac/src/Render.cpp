// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ RENDER.CPP ___________ 
//================================


// Includes 
#include <glimac/Render.hpp>
#include <glimac/Program.hpp>

using namespace glimac;

void Render::program(const unsigned int &id){
    if(getProgramSize() <= id) return;
	uMVPMatrix = glGetUniformLocation(_sPrograms[id].getGLId(), "uMVPMatrix");
	uMVMatrix = glGetUniformLocation(_sPrograms[id].getGLId(), "uMVMatrix");
	uNormalMatrix = glGetUniformLocation(_sPrograms[id].getGLId(), "uNormalMatrix");
	uTexture = glGetUniformLocation(_sPrograms[id].getGLId(), "uTexture");
    uTextureSize = glGetUniformLocation(_sPrograms[id].getGLId(), "uTextureSize");
    uKdColor = glGetUniformLocation(_sPrograms[id].getGLId(), "uKd");
    uKsColor = glGetUniformLocation(_sPrograms[id].getGLId(), "uKs");
    uShininess = glGetUniformLocation(_sPrograms[id].getGLId(), "uShininess");
    uLightPos = glGetUniformLocation(_sPrograms[id].getGLId(), "uLightPos_vs");
    uLightIntensity = glGetUniformLocation(_sPrograms[id].getGLId(), "uLightIntensity");
    use(id);
}


void Render::initRender()
{

   	_ProjMatrix = glm::perspective(glm::radians(70.f),
                                  (float)800/600,
                                   0.1f,
                                   100.f);

    _MVMatrix = glm::translate(glm::mat4(1.f),glm::vec3(0.f, 0.f, -5.f));
    //_MVMatrix = glm::rotate(_MVMatrix, -45.f, glm::vec3(0.f, 1.f, 0.f));
    _NormalMatrix = glm::transpose(glm::inverse(_MVMatrix));
}

void Render::clear()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
}

void Render::sendDatasTex(const std::vector<Texture> &tex) const {
  GLuint textures[MAX_TEXTURE];
    for(int i = 0; i < tex.size(); ++i) {
        textures[i] = tex[i].id();
    }
    unsigned int size = (tex.size() > MAX_TEXTURE) ? MAX_TEXTURE : tex.size();
    glUniform1uiv(uTexture, MAX_TEXTURE, textures);
    glUniform1ui(uTextureSize, size);
}

void Render::sendDatasLight(const std::vector<Light> &lights) const {

}

void Render::sendDatas(const glm::mat4 &MVPMatrix, const glm::mat4 &MVMatrix, const glm::mat4 &NormalMatrix) const
{
	glUniformMatrix4fv(uMVPMatrix, 1, GL_FALSE, glm::value_ptr(MVPMatrix)); 
    glUniformMatrix4fv(uMVMatrix, 1, GL_FALSE, glm::value_ptr(MVMatrix)); 
    glUniformMatrix4fv(uNormalMatrix, 1, GL_FALSE, glm::value_ptr(NormalMatrix));
}

void Render::sendDatas(const glm::mat4 &MVMatrix) const
{
	glUniformMatrix4fv(uMVPMatrix, 1, GL_FALSE, glm::value_ptr(_ProjMatrix * MVMatrix)); 
    glUniformMatrix4fv(uMVMatrix, 1, GL_FALSE, glm::value_ptr(MVMatrix)); 
    glUniformMatrix4fv(uNormalMatrix, 1, GL_FALSE, glm::value_ptr(_NormalMatrix));
}

void Render::sendDatas() const
{
	glUniformMatrix4fv(uMVPMatrix, 1, GL_FALSE, glm::value_ptr(_ProjMatrix * _MVMatrix)); 
    glUniformMatrix4fv(uMVMatrix, 1, GL_FALSE, glm::value_ptr(_MVMatrix)); 
    glUniformMatrix4fv(uNormalMatrix, 1, GL_FALSE, glm::value_ptr(_NormalMatrix));
}

std::vector<Program> Render::_sPrograms;
Render* Render::_instance = nullptr;