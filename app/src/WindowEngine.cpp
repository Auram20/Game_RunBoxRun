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
#include <glimac/Model.hpp>
#include <glimac/Render.hpp>
#include <glimac/SDLWindowManager.hpp>
#include <app/Map.hpp>
#include <app/SceneFactory.hpp>


using namespace glimac;

// --------------- CONSTRUCTORS && DESTRUCTORS --------------

WindowEngine::WindowEngine(const uint32_t &width, const uint32_t &height, const char* title, const SceneFactory &scene)
: _windowManager(width, height, title), _scene(scene)
{}


// --------------- WINDOW ENGINE FUNCTIONS --------------
int WindowEngine::initWindow(FilePath app)
{

    GLenum glewInitError = glewInit();
    if(GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;

    Program _program=loadProgram(app.dirPath()+"assets/shaders/3D.vs.glsl",app.dirPath()+"assets/shaders/normale.fs.glsl");
    Render render;
    render.program(_program);
    
    bool done = false;
    RUNBOXRUN::InputManager *man = RUNBOXRUN::InputManager::getInstance();
    Box test(1, 1, 1);

    unsigned int nbIndiceX = _scene.getNbline();
    unsigned int nbIndiceY = _scene.getNbCol();
    unsigned int nbBloc = _scene.getNbBloc();

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

        render.clear();
        _program.use();

        int size = _scene._objects.size();
        for(int i=0; i<size; i++)
        {
            render.initRender();
            render._MVMatrix = glm::translate(glm::mat4(1.f), glm::vec3(_scene._objects[i]._position.x-(nbIndiceX/(nbBloc*2)),(_scene._objects[i]._position.y)-(nbBloc/2) , (_scene._objects[i]._position.z)-20));
            
            render._MVMatrix = glm::scale(render._MVMatrix, glm::vec3(0.2, 0.2, 0.2));
            Model model(_scene._objects[i]._pathObj);
            render.sendDatas();
            model.draw();
        }
     
        _windowManager.swapBuffers();

     }
    return EXIT_SUCCESS;

}

