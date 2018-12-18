#include <app/WindowEngine.hpp>


using namespace glimac;

WindowEngine::WindowEngine(const uint32_t &width, const uint32_t &height, const char* title)
: _windowManager(width, height, title)
{}

int WindowEngine::initWindow()
{
	 GLenum glewInitError = glewInit();
    if(GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;

    return 0;
}

void WindowEngine::rendWindow()
{
	 // Application loop:
  
    bool done = false;
    RUNBOXRUN::InputManager *man = RUNBOXRUN::InputManager::getInstance();
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

     }
        // Update the display
        _windowManager.swapBuffers();
}
