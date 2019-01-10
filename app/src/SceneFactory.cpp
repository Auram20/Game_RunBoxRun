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
	Model obstacle(FilePath("../assets/obj/Obstacle.obj"));
	Model obstacle2(FilePath("../assets/obj/Obstacle3.obj"));
	Model coin(FilePath("../assets/obj/coin1.obj"));
	Box bo(1,1,1);
	std::vector<glm::vec4> datas = map.getAllInfosDatas();
	int size = datas.size();


	for(int i=0 ; i<size ; i+=4){
		int indice = datas[i][0];
		//std::cout << "INDICE" << datas[i][0] << datas[i+1][0] << datas[i+2][0] << datas[i+3][0] << std::endl;

		switch(indice){
			case 0:
			{
				GameObject *go2= new GameObject(coin, Transform(glm::vec3(datas[i+1][0], datas[i+2][0], datas[i+3][0]),glm::vec3(0.5)), _sPrograms[0]);
				go2->addCollisionTarget("Player", 2); // Met le Victory à 1
				newScene.push(go2,"End"+std::to_string(i));
			}
			break;
			case 1: 
			{
				GameObject *go = new GameObject(obstacle, Transform(glm::vec3(datas[i+1][0], datas[i+2][0], datas[i+3][0]),glm::vec3(0.5)), _sPrograms[0]);
				//go->addCollisionTarget("Player", 0);
				newScene.push(go,"Mur"+std::to_string(i));
			}
			break;
			case 2: 
			{
				GameObject *go = new GameObject(obstacle2, Transform(glm::vec3(datas[i+1][0], datas[i+2][0], datas[i+3][0]),glm::vec3(0.5)), _sPrograms[0]);
				go->addCollisionTarget("Player", 0);
				newScene.push(go,"Obstacle"+std::to_string(i));
			}
			break;
			case 3:
			{	
				GameObject *go = new GameObject(coin,Transform(glm::vec3(datas[i+1][0], datas[i+2][0], datas[i+3][0]),glm::vec3(0.5)), _sPrograms[0]);
				go->addCollisionTarget("Player", 1);
				newScene.push(go,"Coin"+std::to_string(i));
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
