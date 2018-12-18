#include <app/WindowEngine.hpp>
#include <glimac/Sphere.hpp>
#include <glimac/Box.hpp>
#include <glimac/FilePath.hpp>
#include <glimac/Program.hpp>

using namespace glimac;

WindowEngine::WindowEngine(const uint32_t &width, const uint32_t &height, const char* title)
: _windowManager(width, height, title)
{}

int WindowEngine::initWindow(char** argv) const
{
	 GLenum glewInitError = glewInit();
    if(GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;

    FilePath applicationPath(argv[0]);
    Program program=loadProgram(applicationPath.dirPath()+"assets/shaders/3D.vs.glsl",applicationPath.dirPath()+"assets/shaders/normale.fs.glsl");
    program.use();

    // On recupere uMVPMatrix
    GLint uMVPMatrix=glGetUniformLocation(program.getGLId(),"uMVPMatrix");
    // On recupere uMVMatrix
    GLint uMVMatrix=glGetUniformLocation(program.getGLId(),"uMVMatrix");
    // On recupere uNormalMatrix
    GLint uNormalMatrix=glGetUniformLocation(program.getGLId(),"uNormalMatrix");


     glm::mat4 ProjMatrix;
    glm::mat4 MVMatrix;
    glm::mat4 NormalMatrix;



    ProjMatrix = glm::perspective(glm::radians(70.f),
                                 (float)800/600,
                                  0.1f,
                               100.f);

    MVMatrix= glm::translate(MVMatrix,glm::vec3(0.f, 0.f, -10.f));

    NormalMatrix = glm::transpose(glm::inverse(MVMatrix));


    glUniformMatrix4fv(uMVPMatrix, 1, GL_FALSE, glm::value_ptr(ProjMatrix * MVMatrix)); 
         glUniformMatrix4fv(uMVMatrix, 1, GL_FALSE, glm::value_ptr(MVMatrix)); 
         glUniformMatrix4fv(uNormalMatrix, 1, GL_FALSE, glm::value_ptr(NormalMatrix)); 

    return 0;
}

void WindowEngine::rendWindow()
{
	 // Application loop:
  
    bool done = false;
    RUNBOXRUN::InputManager *man = RUNBOXRUN::InputManager::getInstance();
    Box test(1.f, 1.f, 1.f);

    glEnable(GL_DEPTH_TEST);

    while(!done) {
        // Event loop:
        SDL_Event e;
        while(_windowManager.pollEvent(e)) {
            if(e.type == SDL_QUIT) {
                done = true; // Leave the loop after this iteration
            }
        }

        /*********************************
         * HERE SHOULD COME THE RENDERING CODE
         *********************************/

         test.render();

     }
        // Update the display
        _windowManager.swapBuffers();

}
