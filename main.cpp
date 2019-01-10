#include <iostream>
#include <cstdio>
#include <SDL/SDL.h>
#include <GL/glew.h>
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

    WindowEngine wind(800,600, "RunBoxRun", scene);
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