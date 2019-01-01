// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ WINDOWENGINE.CPP_____ 
//================================

#include "app/WindowEngine.hpp"
#include <glimac/Sphere.hpp>
#include <glimac/Box.hpp>
#include <glimac/Program.hpp>
#include <glimac/Model.hpp>
#include <glimac/Render.hpp>
#include <glimac/SDLWindowManager.hpp>
#include "app/Map.hpp"
#include "app/SceneFactory.hpp"
#include "app/AssetManager.hpp"


using namespace glimac;

// --------------- CONSTRUCTORS && DESTRUCTORS --------------

WindowEngine::WindowEngine(const uint32_t &width, const uint32_t &height, const char* title, const SceneFactory &sceneFactory)
: Observable(), _windowManager(width, height, title), _scene(sceneFactory)
{}


// --------------- WINDOW ENGINE FUNCTIONS --------------
int WindowEngine::initWindow(FilePath app)
{

    // INITIALIZING GLEW
    GLenum glewInitError = glewInit();
    if(GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;
    
    // INITIALIZING SHADERS
    Program _program=loadProgram(
        app.dirPath()+"assets/shaders/3D.vs.glsl",
        app.dirPath()+"assets/shaders/normale.fs.glsl"
    );

    AssetManager *assetMan = AssetManager::getInstance();
    assetMan->find();

    //  SHADERS & UMATRIX DEFINITIONS
    Render render;
    render.program(_program);
    _program.use();
    render.displayInfos();
    render.initRender();
    render.sendDatas();

    bool done = false;
    RUNBOXRUN::InputManager *man = RUNBOXRUN::InputManager::getInstance();


// TESTS CREATION SCENE JOUEUR
    Player* p = Player::getInstance();
    std::cout << " Avant changement " << std::endl;
    p->displayInfos(); 
    Scene sceneplayer; 
    sceneplayer.push(p);
//  sceneplayer.push(GameObject(*p,RUNBOXRUN::Transform(p->_object->_position,glm::vec3(0.5))));


// BOUCLE DE RENDU 
    glEnable(GL_DEPTH_TEST);
    while(!done) {
        // Event loop:
        SDL_Event e;
        while(_windowManager.pollEvent(e)) {
            man->execute(e);
        }

        render.clear();
        p->updatePlayer(e);
        sceneplayer.drawScene(render); 


// POUR QUITTER LE JEU 
        switch(e.type) {
            case SDL_QUIT:
                done = true;
            break;
            case SDL_KEYDOWN:
            if (e.key.keysym.sym==27){ ///escape
                    done=true;
            }
            break;            
        }

       _windowManager.swapBuffers();

     }

    return EXIT_SUCCESS;

}

