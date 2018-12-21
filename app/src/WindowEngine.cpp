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
#include <glimac/TrackballCamera.hpp>
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

    //CAM
    TrackballCamera camera1;

    GLenum glewInitError = glewInit();
    if(GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;

    Program _program=loadProgram(app.dirPath()+"assets/shaders/3D.vs.glsl",app.dirPath()+"assets/shaders/normale.fs.glsl");
    Render render(camera1);
    render.program(_program);
    
    bool done = false;
    RUNBOXRUN::InputManager *man = RUNBOXRUN::InputManager::getInstance();
    Box test(1, 1, 1);

    unsigned int nbIndiceX = _scene.getNbline();
    unsigned int nbIndiceY = _scene.getNbCol();
    unsigned int nbBloc = _scene.getNbBloc();

    glEnable(GL_DEPTH_TEST);

    int prevX = 0;
    //int prevY = 0;

    bool click = false;

    while(!done) {

        render.getViewMatrix();

    
        // Event loop:
        SDL_Event e;
        while(_windowManager.pollEvent(e)) {
            if(e.type == SDL_MOUSEMOTION)
            {
                if(click)
                {
                    glm::vec2 pos = _windowManager.getMousePosition();
               
                    if(prevX-pos.x > 0)
                    {
                        render._camera.rotateLeft(-1);
                    }
                    if(prevX-pos.x < 0)
                    {
                        render._camera.rotateLeft(1);
                    }
                    /*
                        if(prevY-pos.y > 0)
                        {
                           // render._camera.rotateUp(1);
                        }
                        if(prevY-pos.y < 0)
                        {
                            //render._camera.rotateUp(-1);
                        }
                    */
                }
            }

            if(e.type == SDL_MOUSEBUTTONDOWN)
            {
                if(e.button.button == SDL_BUTTON_RIGHT)
                {
                    glm::vec2 pos = _windowManager.getMousePosition();
                    prevX = pos.x;
                    // prevY = pos.y;
                    click = true;
                }
                if(e.button.button == SDL_BUTTON_WHEELUP)
                {
                    render._camera.moveFront(-1);
                }
                if(e.button.button == SDL_BUTTON_WHEELDOWN)
                {
                    render._camera.moveFront(1);
                }
            }

            if(e.type == SDL_MOUSEBUTTONUP)
            {
                if(e.button.button == SDL_BUTTON_RIGHT)
                    click = false;
            } 

            if(e.type == SDL_QUIT)
            {
                done = true; // Leave the loop after this iteration
            }

            if(e.type == SDL_KEYDOWN)
            {
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
            render.sendDatas();
            Model model(_scene._objects[i]._pathObj);
            model.draw();
            //render.transformation(_windowManager);
          //  render._MVMatrix = glm::rotate(render._newVM*render._MVMatrix, _windowManager.getTime(), glm::vec3(1, 0, 0));
            
        }
     
        _windowManager.swapBuffers();

     }
    return EXIT_SUCCESS;

}

