// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ SCENEFACTORY.CPP ____ 
//================================

#include <app/SceneFactory.hpp>

using namespace RUNBOXRUN;

SceneFactory::SceneFactory(){} 

void SceneFactory::constructSceneFromMap(const Map &map) {

	std::vector<glm::vec4> datas = map.getAllInfosDatas();
	
	_nbLine = map.getNbline();
	_nbCol = map.getNbCol();
	_nbBloc = map.getNbBloc();

	int size = datas.size();

	for(int i=0 ; i<size ; i++){
		int indice = datas[i][0];
		switch(indice){
			case 0:
			{
				Enemy en(1, glm::vec3(datas[i][1], datas[i][2], datas[i][3]), glm::vec3(1), glm::vec3(100));
				_objects.push_back(en);
			}
			break;
			case 1: 
			{
				Obstacle obs(1, glm::vec3(datas[i][1], datas[i][2], datas[i][3]), glm::vec3(1), glm::vec3(100), "mur");
				_objects.push_back(obs);
			}
			break;
			case 2:
			{
				Coin co(1, glm::vec3(datas[i][1], datas[i][2], datas[i][3]), glm::vec3(1), glm::vec3(100), 10);
				_objects.push_back(co);
			}
			break;
			default: 
			break;
		}
	}
	

}
