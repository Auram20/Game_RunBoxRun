// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ SCENEFACTORY.CPP ____ 
//================================

#include <app/SceneFactory.hpp>
#include <glimac/Box.hpp>
#include <app/GameObject.hpp>

using namespace RUNBOXRUN;

SceneFactory::SceneFactory(){} 

Scene SceneFactory::constructSceneFromMap(const Map &map) {

	Scene newScene;
	Model model("../assets/obj/boule.obj");
	std::vector<glm::vec4> datas = map.getAllInfosDatas();
	int size = datas.size();
	
	for(int i=0 ; i<size ; i++){
		int indice = datas[i][0];
		switch(indice){
			case 0:
			{
				Enemy *en = new Enemy(1, glm::vec3(datas[i][1], datas[i][2], datas[i][3]), glm::vec3(1), glm::vec3(100));
				newScene.push(GameObject(model, *en));
			}
			break;
			case 1: 
			{
				Obstacle *obs = new Obstacle(1, glm::vec3(datas[i][1], datas[i][2], datas[i][3]), glm::vec3(1), glm::vec3(100), "mur");
				newScene.push(GameObject(model, *obs));
			}
			break;
			case 3:
			{
				Coin *co = new Coin(1, glm::vec3(datas[i][1], datas[i][2], datas[i][3]), glm::vec3(1), glm::vec3(100), 10);
				newScene.push(GameObject(model, *co));
			}
			break;
			default: 
			break;
		}
	}

	return newScene;
	
}
