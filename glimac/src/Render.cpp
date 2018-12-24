// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ RENDER.CPP ___________ 
//================================


// Includes 
#include <glimac/Render.hpp>
#include <glimac/Program.hpp>

using namespace glimac;

void Render::program(const Program &program){
	uMVPMatrix = glGetUniformLocation(program.getGLId(), "uMVPMatrix");
	uMVMatrix = glGetUniformLocation(program.getGLId(), "uMVMatrix");
	uNormalMatrix = glGetUniformLocation(program.getGLId(), "uNormalMatrix");
	uTexture = glGetUniformLocation(program.getGLId(), "uTexture");
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

void Render::sendDatas(const glm::mat4 &MVPMatrix, const glm::mat4 &MVMatrix, const glm::mat4 &NormalMatrix)
{
	glUniformMatrix4fv(uMVPMatrix, 1, GL_FALSE, glm::value_ptr(MVPMatrix)); 
    glUniformMatrix4fv(uMVMatrix, 1, GL_FALSE, glm::value_ptr(MVMatrix)); 
    glUniformMatrix4fv(uNormalMatrix, 1, GL_FALSE, glm::value_ptr(NormalMatrix));
}

void Render::sendDatas(const glm::mat4 &MVMatrix)
{
	glUniformMatrix4fv(uMVPMatrix, 1, GL_FALSE, glm::value_ptr(_ProjMatrix * MVMatrix)); 
    glUniformMatrix4fv(uMVMatrix, 1, GL_FALSE, glm::value_ptr(_MVMatrix)); 
    glUniformMatrix4fv(uNormalMatrix, 1, GL_FALSE, glm::value_ptr(_NormalMatrix));
}

void Render::sendDatas()
{
	glUniformMatrix4fv(uMVPMatrix, 1, GL_FALSE, glm::value_ptr(_ProjMatrix * _MVMatrix)); 
    glUniformMatrix4fv(uMVMatrix, 1, GL_FALSE, glm::value_ptr(_MVMatrix)); 
    glUniformMatrix4fv(uNormalMatrix, 1, GL_FALSE, glm::value_ptr(_NormalMatrix));
}