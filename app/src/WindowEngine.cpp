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

    AssetManager *assetMan = AssetManager::getInstance();
    assetMan->find();


    Render render;
    render.program(_program);
    _program.use();

    render.initRender();

    render.displayInfos();

    render.sendDatas();
    
    bool done = false;
    RUNBOXRUN::InputManager *man = RUNBOXRUN::InputManager::getInstance();
    Box test(1, 1, 1);
  



    std::vector<Model> models;
    //Sphere sphere(1, 38, 40);

    Model model(FilePath("../assets/obj/boule.obj"));

    //std::cout << assetMan->get(AssetType::MODEL, "boule.obj") << std::endl;

    Scene scene;

    Enemy en(1, glm::vec3(0, 0, -5), glm::vec3(1), glm::vec3(100));
	scene.push(GameObject(assetMan->get(AssetType::MODEL, "boule"), en, RUNBOXRUN::Transform(glm::vec3(0, 0, -5))));
    //scene.push(GameObject(*(assetMan->get(AssetType::MODEL, "boule.obj")), en, RUNBOXRUN::Transform(glm::vec3(1, 0, -5))));


// TESTS CREATION SCENE NORMALE
 //    Scene scene;
 //    Model model("../assets/obj/boule.obj");
 //    Enemy en(1, glm::vec3(0, 0, -5), glm::vec3(1), glm::vec3(100));
	// scene.push(GameObject(model, en, RUNBOXRUN::Transform(glm::vec3(0, 0, -5),glm::vec3(0.5))));
 //    scene.push(GameObject(model, en, RUNBOXRUN::Transform(glm::vec3(1, 0, -5))));
 //    model.displayInfos();


// TESTS CREATION SCENE FROM MAP 
    Map map("../assets/map/test2.txt");
    map.load();
    //std::cout << "taille de ma map si ça marchee" << map._datas.size() << std::endl;
    SceneFactory sceneMap;
    sceneMap.constructSceneFromMap(map);



    man->attach(*this, RUNBOXRUN::EventCode::QUITEVENT, new utils::Observer<WindowEngine>([&done](WindowEngine *w) {
        std::cout << "ferme" << std::endl;
        done = true;
    }));


    glEnable(GL_DEPTH_TEST);
    while(!done) {
        // Event loop:
        SDL_Event e;
        while(_windowManager.pollEvent(e)) {
            man->execute(e);
        }

        render.clear();
 // TESTS CREATION SCENE NORMALE
       // scene.drawScene(render);
      
 // TESTS CREATION SCENE FROM MAP
        scene.drawScene(render); //scène dans render brise la césure moteurs rendu/jeu
       

        /* render of all objects*/
        // vecteur qui va contenir tous les models
     
        _windowManager.swapBuffers();

     }
    return EXIT_SUCCESS;

}

