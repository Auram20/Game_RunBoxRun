// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ WINDOWENGINE.CPP_____ 
//================================


#include <app/WindowEngine.hpp>
#include <glimac/Sphere.hpp>
#include <glimac/Box.hpp>
#include <glimac/FilePath.hpp>
#include <glimac/Program.hpp>
#include <glimac/tiny_obj_loader.h>

using namespace glimac;


// --------------- CONSTRUCTORS && DESTRUCTORS --------------

WindowEngine::WindowEngine(const uint32_t &width, const uint32_t &height, const char* title)
: _windowManager(width, height, title)
{}

// --------------- WINDOW ENGINE FUNCTIONS --------------
int WindowEngine::initWindow(char* path)
{
	 GLenum glewInitError = glewInit();
    if(GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;

    FilePath applicationPath(path);
    Program program=loadProgram(applicationPath.dirPath()+"assets/shaders/3D.vs.glsl",applicationPath.dirPath()+"assets/shaders/normale.fs.glsl");
    program.use();

    // On recupere uMVPMatrix
    GLint uMVPMatrix=glGetUniformLocation(program.getGLId(),"uMVPMatrix");
    // On recupere uMVMatrix
    GLint uMVMatrix=glGetUniformLocation(program.getGLId(),"uMVMatrix");
    // On recupere uNormalMatrix
    GLint uNormalMatrix=glGetUniformLocation(program.getGLId(),"uNormalMatrix");


    _ProjMatrix = glm::perspective(glm::radians(70.f),
                                 (float)800/600,
                                  0.1f,
                               100.f);


    _MVMatrix = glm::translate(glm::mat4(1.f),glm::vec3(0.f, 0.f, -5.f));
    _MVMatrix = glm::rotate(_MVMatrix, -45.f, glm::vec3(0.f, 1.f, 0.f));

    _NormalMatrix = glm::transpose(glm::inverse(_MVMatrix));


    glUniformMatrix4fv(uMVPMatrix, 1, GL_FALSE, glm::value_ptr(_ProjMatrix * _MVMatrix)); 
    glUniformMatrix4fv(uMVMatrix, 1, GL_FALSE, glm::value_ptr(_MVMatrix)); 
    glUniformMatrix4fv(uNormalMatrix, 1, GL_FALSE, glm::value_ptr(_NormalMatrix)); 

    return EXIT_SUCCESS;
}

void WindowEngine::rendWindow()
{
	 // Application loop:
  
    bool done = false;
    RUNBOXRUN::InputManager *man = RUNBOXRUN::InputManager::getInstance();
    Box test(1, 1, 1);

    glEnable(GL_DEPTH_TEST);

    while(!done) {
        // Event loop:
        SDL_Event e;
        while(_windowManager.pollEvent(e)) {
            if(e.type == SDL_QUIT) {
                done = true; // Leave the loop after this iteration
            }

            if(e.type == SDL_KEYDOWN) {
                man->call(e.key.keysym.sym);
            }
        }

        /*********************************
         * HERE SHOULD COME THE RENDERING CODE
         *********************************/

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

         test.render();

        // Update the display
        _windowManager.swapBuffers();

     }

}
