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
    uLightSize = glGetUniformLocation(_sPrograms[id].getGLId(), "uLightSize");
    uLightType = glGetUniformLocation(_sPrograms[id].getGLId(), "uLightType");
    uColors = glGetUniformLocation(_sPrograms[id].getGLId(), "uK");
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
                                   150.f);

    _MVMatrix = glm::translate(glm::mat4(1.f),glm::vec3(0.f, 0.f, -5.f));
    //_MVMatrix = glm::rotate(_MVMatrix, -45.f, glm::vec3(0.f, 1.f, 0.f));
    _NormalMatrix = glm::transpose(glm::inverse(_MVMatrix));
}

void Render::clear()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
}

void Render::sendDatasMat(const Material &mat) const {
    glm::vec3 colors[MAX_TEXTURE];
    for(int i = 0; i < MAX_TEXTURE; ++i) {
        colors[i] = mat.color(aiTextureType(i));
    }
    glUniform3fv(uColors, MAX_TEXTURE, &colors[0].x);
    glUniform1ui(uShininess, mat.shininess());

}

void Render::sendDatasTex(const std::map<aiTextureType, Texture>::const_iterator &begin, const std::map<aiTextureType, Texture>::const_iterator &end) const {
    GLuint textures[MAX_TEXTURE];
    for(auto i = begin; i != end; ++i) {
        textures[i->first] = (i->second).id();
    }
    glUniform1uiv(uTexture, MAX_TEXTURE, textures);
}

void Render::sendDatasLight(const std::map<LightType, std::vector<Light>> &lights) const {
    uint size = 0;
    glm::vec3 lightPos[MAX_LIGHT];
    glm::vec3 lightIntensity[MAX_LIGHT];
    int lightType[MAX_LIGHT];

    for(auto it = lights.begin(); it != lights.end(); ++it) {
        for(uint i = 0; i < (it->second).size(); ++i) {
            lightPos[i] = (it->second)[i].position();
            lightIntensity[i] = (it->second)[i].intensity();
            lightType[i] = int(it->first);
            size++;
        }
    }

    if(size > 0) {
        glUniform3fv(uLightPos, size, &lightPos[0].x);
        glUniform3fv(uLightIntensity, size, &lightIntensity[0].x);
        glUniform1iv(uLightType, size, lightType);
    }
    glUniform1ui(uLightSize, size);
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