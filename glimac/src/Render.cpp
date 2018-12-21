// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ RENDER.CPP ___________ 
//================================


// Includes 
#include <glimac/Render.hpp>
#include <glimac/Program.hpp>
#include <glimac/TrackballCamera.hpp>

using namespace glimac;

Render::Render(const TrackballCamera &cam)
: _camera(cam)
{}

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
    _MVMatrix = glm::rotate(_MVMatrix, -45.f, glm::vec3(0.f, 1.f, 0.f));
    _NormalMatrix = glm::transpose(glm::inverse(_MVMatrix));
}

void Render::getViewMatrix()
{
  _newVM = _camera.getViewMatrix();
}

void Render::clear()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
}

void Render::transformation(const SDLWindowManager &window)
{
  _MVMatrix = glm::translate(glm::mat4(), glm::vec3(0.0f, 0.0f, 0.0f));
 // _MVMatrix = glm::rotate(_newVM*_MVMatrix, glm::r glm::vec3(0, 1, 0));
}

void Render::sendDatas()
{
	glUniformMatrix4fv(uMVPMatrix, 1, GL_FALSE, glm::value_ptr(_ProjMatrix * _newVM * _MVMatrix)); 
  glUniformMatrix4fv(uMVMatrix, 1, GL_FALSE, glm::value_ptr(_MVMatrix)); 
  glUniformMatrix4fv(uNormalMatrix, 1, GL_FALSE, glm::value_ptr(_NormalMatrix));
}

    
   