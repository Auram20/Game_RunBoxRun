#include <iostream>
#include <cstdio>
#include <SDL/SDL.h>
#include <GL/glew.h>
#include "game/include/Player.hpp"
#include "game/include/Bonus.hpp"
#include "game/include/Button.hpp"
#include "game/include/Coin.hpp"
#include "game/include/Decor.hpp"
#include "game/include/Enemy.hpp"
#include "game/include/Obstacle.hpp"
#include "game/include/Malus.hpp"
#include "game/include/Score.hpp"
#include "game/include/Time.hpp"

using namespace RUNBOXRUN;

int main(void) 
{

    
    // ------------- INSTANTIATION ---------------------------
    Player p(1,glm::vec3(200),glm::vec3(200),glm::vec3(300),300,200);
    Decor decor(1,glm::vec3(10), glm::vec3(10), glm::vec3(100));
    Obstacle obs(1, glm::vec3(100), glm::vec3(10), glm::vec3(100), "cailloux");
    Malus mal(1, glm::vec3(10), glm::vec3(10), glm::vec3(100), "maladie");
    Object ob(1, glm::vec3(10), glm::vec3(10), glm::vec3(100));
    Bonus bo(1, glm::vec3(10), glm::vec3(10), glm::vec3(100), 10);
    Coin co(1, glm::vec3(10), glm::vec3(10), glm::vec3(100), 10);
    Enemy en(1, glm::vec3(10), glm::vec3(10), glm::vec3(100));
    Ui ui();
    UiElement ue();
    Button butt(100,100, "menu");
    Score sc();
    Time ti();




    // ------------- TESTS FONCTIONS ---------------------------

    p.displayInfos();
    decor.displayInfos();

    return 0;
}