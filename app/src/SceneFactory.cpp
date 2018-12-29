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
	Model model(FilePath("../assets/obj/boule.obj"));
	Box bo(1,1,1);
	std::vector<glm::vec4> datas = map.getAllInfosDatas();
	int size = datas.size();





	for(int i=0 ; i<size ; i+=4){
		int indice = datas[i][0];
		//std::cout << indice << std::endl;
		switch(indice){
			case 0:
			{
				Enemy *en = new Enemy(1, glm::vec3(0), glm::vec3(100), glm::vec3(100));
				newScene.push(GameObject(bo, *en,Transform(glm::vec3(datas[i+1][0], datas[i+2][0], datas[i+3][0]),glm::vec3(0.5))));
			}
			break;
			case 1: 
			{
				Obstacle *obs = new Obstacle(1, glm::vec3(0), glm::vec3(100), glm::vec3(100), "mur");
				newScene.push(GameObject(model, *obs,Transform(glm::vec3(datas[i+1][0], datas[i+2][0], datas[i+3][0]),glm::vec3(0.5))));
			}
			break;
			case 3:
			{
				Coin *co = new Coin(1, glm::vec3(datas[i][1], datas[i][2], datas[i][3]), glm::vec3(1), glm::vec3(100), 10);
				//newScene.push(GameObject(model, *co));
			}
			break;
			default: 
			break;
		}
	}

	return newScene;
	
}
