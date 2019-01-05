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
	Model coin(FilePath("../assets/obj/coin.obj"));
	Box bo(1,1,1);
	std::vector<glm::vec4> datas = map.getAllInfosDatas();
	int size = datas.size();


	for(int i=0 ; i<size ; i+=4){
		int indice = datas[i][0];
		//std::cout << "INDICE" << datas[i][0] << datas[i+1][0] << datas[i+2][0] << datas[i+3][0] << std::endl;

		switch(indice){
			case 0:
			{
				Enemy *en = new Enemy(1, glm::vec3(0), glm::vec3(100), glm::vec3(100));
				GameObject *go= new GameObject(model, *en,Transform(glm::vec3(datas[i+1][0], datas[i+2][0], datas[i+3][0]),glm::vec3(0.5)), _sPrograms[1]);
				newScene.push(go,"Enemy"+i);
			}
			break;
			case 1: 
			{
				Obstacle *obs = new Obstacle(1, glm::vec3(0), glm::vec3(100), glm::vec3(100), "mur");
				GameObject *go = new GameObject(bo, *obs,Transform(glm::vec3(datas[i+1][0], datas[i+2][0], datas[i+3][0]),glm::vec3(0.5)), _sPrograms[1]);
				newScene.push(go,"Obstacle"+i);
			}
			break;
			case 3:
			{	
				Coin *co = new Coin(1, glm::vec3(10), glm::vec3(10), glm::vec3(100), 10);
				GameObject *go = new GameObject(coin, *co,Transform(glm::vec3(datas[i+1][0], datas[i+2][0]-0.5, datas[i+3][0]),glm::vec3(0.25)), _sPrograms[1]);
				newScene.push(go,"Coin"+i);
			}
			break;
			default: 
			break;
		}
	}

	return newScene;
	
}

void SceneFactory::initSPrograms() {
	AssetManager *assetMan = AssetManager::getInstance();
	_sPrograms[1] = Render::pushNewProgram(assetMan->get(AssetType::SHADER, "3D"), assetMan->get(AssetType::SHADER, "normale"));
}
