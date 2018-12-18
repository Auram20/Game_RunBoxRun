#include <app/Map.hpp>

using namespace RUNBOXRUN;

int Map::readMap(const std::string &filename)
{
		std::ifstream file(filename);
		unsigned int data;
		if(! file.is_open())
		{
			THROW_EXCEPTION(filename + " is not found");
		}

		while(file)
		{
			file >> data;
			_datas.push_back(data);
		}
			
		file.close();

		//-----TEST-------//
		/*
		int size = datas.size();
		for(int i= 0; i< size; i++)
		{
		std::cout << "data : " << datas[i] << std::endl;
		}
		*/

		return 1;
}
