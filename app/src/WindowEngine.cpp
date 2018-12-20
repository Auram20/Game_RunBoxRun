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
  

   // std::for_each(scene._objects.begin(), scene._object.end(), )

    std::vector<Model> models;
    int size = _scene._objects.size();
    for(int i=0; i<size; i++)
    {
        models.push_back(_objects[i]._model);
    }


    Model model("../assets/obj/boule.obj");

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
        render.initRender();
        render.sendDatas();
        //model.draw();
        std::for_each(models.begin(), models.end(), [](const int i){models[i].draw();})
           //test.render();
        /* render of all objects*/
        // vecteur qui va contenir tous les models
     
        _windowManager.swapBuffers();

     }
    return EXIT_SUCCESS;

}

