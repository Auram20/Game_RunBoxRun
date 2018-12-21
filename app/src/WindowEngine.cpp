// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ WINDOWENGINE.CPP_____ 
//================================

#include "app/WindowEngine.hpp"
#include <glimac/Sphere.hpp>
#include <glimac/Box.hpp>
#include <glimac/FilePath.hpp>
#include <glimac/Program.hpp>
#include <glimac/Model.hpp>
#include <glimac/Render.hpp>
#include <glimac/SDLWindowManager.hpp>
#include "app/Map.hpp"
#include "app/SceneFactory.hpp"


using namespace glimac;

// --------------- CONSTRUCTORS && DESTRUCTORS --------------

WindowEngine::WindowEngine(const uint32_t &width, const uint32_t &height, const char* title, const SceneFactory &sceneFactory)
: _windowManager(width, height, title), _scene(sceneFactory)
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

    Program _program=loadProgram(
        app.dirPath()+"assets/shaders/3D.vs.glsl",
        app.dirPath()+"assets/shaders/normale.fs.glsl"
    );
    Render render;
    render.program(_program);
    _program.use();

    render.initRender();

    render.displayInfos();

    render.sendDatas();
    
    bool done = false;
    RUNBOXRUN::InputManager *man = RUNBOXRUN::InputManager::getInstance();
    Box test(1, 1, 1);
  

    Scene scene;

    std::vector<Model> models;
    //Sphere sphere(1, 38, 40);

    Model model("../assets/obj/boule.obj");

    Enemy en(1, glm::vec3(0, 0, -5), glm::vec3(1), glm::vec3(100));
	scene.push(GameObject(model, en));

     model.displayInfos();

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
        //model.draw();
        //scene.drawScene();
           scene.drawScene();
        /* render of all objects*/
        // vecteur qui va contenir tous les models
     
        _windowManager.swapBuffers();

     }
    return EXIT_SUCCESS;

}

