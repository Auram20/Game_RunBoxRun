#include <iostream>
#include <cstdio>
#include <SDL/SDL.h>
#include <GL/glew.h>
#include <app/Button.hpp>
#include <utils/Error.hpp>
#include <app/Map.hpp>
#include <glimac/Sphere.hpp>
#include <glimac/Box.hpp>
#include <glimac/Texture.hpp>
#include <app/WindowEngine.hpp>
#include <assimp/Importer.hpp>
#include <glimac/Model.hpp>
#include <app/AssetManager.hpp>
#include <SDL/SDL_ttf.h>

using namespace RUNBOXRUN;
using namespace glimac;


int main(int argc, char** argv) 
{

    
    // ------------- INSTANTIATION ---------------------------
    // Player* p = Player::getInstance();
    // std::cout << " Avant changement " << std::endl;
    // p->displayInfos();
    //InputManager man;
    Decor decor(1,glm::vec3(10), glm::vec3(10), glm::vec3(100));
    Obstacle obs(1, glm::vec3(100), glm::vec3(10), glm::vec3(100), "cailloux");
    Malus mal(1, glm::vec3(10), glm::vec3(10), glm::vec3(100), "maladie");
    Object ob(1, glm::vec3(10), glm::vec3(10), glm::vec3(100));
    Bonus bo(1, glm::vec3(10), glm::vec3(10), glm::vec3(100), 10);
    Coin co(1, glm::vec3(10), glm::vec3(10), glm::vec3(100), 10);
    Enemy en(1, glm::vec3(10), glm::vec3(10), glm::vec3(100));
    Ui ui;
    UiElement ue;
    Button butt(100,100, "menu");
    Score sc;
    Time ti;
    FilePath applicationPath(argv[0]);
    //std::cout << argv[0] << std::endl;
    //Asset asset(applicationPath);

    Map map("../assets/map/test2.txt");

    SceneFactory scene;
    //scene.constructSceneFromMap(map);

    AssetManager::instanciate(argv[0]);

    //Assimp::Importer importer;
    //Sphere sp(3,1,1);
    //Box box1(1,1,1);
    //box1.displayInfos();

    // ------------- TESTS FONCTIONS ---------------------------
    decor.displayInfos();
    bo.displayInfos();
    co.displayInfos();
    en.displayInfos();
    mal.displayInfos();
    obs.displayInfos();

    AssetManager::instanciate(argv[0]);

    WindowEngine wind(800,600, "BON ANNIVERSAIRE LE MOCHE", scene);
    wind.initWindow(applicationPath);

   // Texture Texture1("../assets/textue/texture.jpg");

    
    // ------------- TESTS ERRORS ---------------------------

    try // portion de code à tester (peut potentiellement lever une exception)
    {
      

       testException(79);
      // testException(0);
    }
    catch (const std::exception &e) // gestion des erreurs : ici, on affiche simplement l'erreur
    {
        std::cerr << e.what() << std::endl;
    }

    AssetManager::destruct();

    return 0;
}