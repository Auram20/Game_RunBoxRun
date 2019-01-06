// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ WINDOWENGINE.CPP_____ 
//================================

#include "app/WindowEngine.hpp"
#include <app/Menu.hpp>
#include <glimac/Sphere.hpp>
#include <glimac/Box.hpp>
#include <glimac/Program.hpp>
#include <glimac/Model.hpp>
#include <glimac/Render.hpp>
#include <glimac/SDLWindowManager.hpp>
#include "app/Map.hpp"
#include "app/SceneFactory.hpp"
#include "app/AssetManager.hpp"
#include "app/TrackballCamera.hpp"
#include "app/FreeflyCamera.hpp"
#include "app/MainScene.hpp"

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
    /*Program _program=loadProgram(
        app.dirPath()+"assets/shaders/3D.vs.glsl",
        app.dirPath()+"assets/shaders/normale.fs.glsl"
    );*/

    AssetManager *assetMan = AssetManager::getInstance();
    assetMan->find();

    Render::pushNewProgram(assetMan->get(AssetType::SHADER, "3D"), assetMan->get(AssetType::SHADER, "texture"));

    //  SHADERS & UMATRIX DEFINITIONS
    Render *render = Render::getInstance();
    render->program(0);
    render->displayInfos();
    render->initRender();
    render->sendDatas();

    bool done = false;
    RUNBOXRUN::InputManager *man = RUNBOXRUN::InputManager::getInstance();

// TESTS CREATION SCENE NORMALE
     //    Scene scene;
     //    Model model(FilePath("../assets/obj/boule.obj"));
     //    Enemy en(1, glm::vec3(0, 0, -5), glm::vec3(1), glm::vec3(100));
     //    scene.push(GameObject(model, en, RUNBOXRUN::Transform(glm::vec3(0, 0, -5),glm::vec3(0.5))));
     //    scene.push(GameObject(model, en, RUNBOXRUN::Transform(glm::vec3(1, 0, -5))));
     //    model.displayInfos();



// TESTS CREATION MENU 
    Menu Primary;
    Primary.initmainMenu();

// TESTS CREATION SCENE FROM MAP + PLAYER
    Map map("../assets/map/test2.txt");
    map.load();
    SceneFactory sceneMap;
    sceneMap.initSPrograms();
    Scene sceneplayer(sceneMap.constructSceneFromMap(map));

    sceneplayer.setGameManager<MainScene>(MainScene());

    //Scene testscene;
    //testscene = sceneplayer;

    Player* p = Player::getInstance();
    std::cout << " Avant changement " << std::endl;
    p->displayInfos(); 
    sceneplayer.push(p,"Player");


     sceneplayer.addCamera("TrackBall", new glimac::TrackballCamera());
     sceneplayer.addCamera("Freefly", new glimac::FreeflyCamera());
     sceneplayer.setCurrentCamera("Freefly");


     man->attachKey(*this, SDLK_c, [&](RUNBOXRUN::InputManager &im) {
         sceneplayer.changeCurrentCamera();
     });

     man->attachKey(*this, SDLK_l, [&](RUNBOXRUN::InputManager &im) {
         Camera::lock();
     });
// // -----------------
// BOUCLE DE RENDU 
// -----------------

    glEnable(GL_DEPTH_TEST);
    while(!done) {
        Uint32 startTime = SDL_GetTicks();
        // Event loop:
        SDL_Event e;
        while(_windowManager.pollEvent(e)) {
            man->execute(e);
        }

        render->clear();
        Primary.drawScene();
        Primary.rendermainMenu(e,render);
        //man->updateAll();

        if (Primary._etat==2)
            {
                     sceneplayer.runCameras(),
                     p->updatePlayer(e);
                     sceneplayer.drawScene(); 

           }

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

        Uint32 elapsedTime = SDL_GetTicks() - startTime;

        /* Si trop peu de temps s'est écoulé, on met en pause le programme */
        if (elapsedTime < FRAMERATE_MILLISECONDS) {
        SDL_Delay(FRAMERATE_MILLISECONDS - elapsedTime);
}

     }

    return EXIT_SUCCESS;

}

