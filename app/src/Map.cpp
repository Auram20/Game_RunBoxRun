#include <app/Map.hpp>

using namespace RUNBOXRUN;

int Map::readMap(const std::string &filename)
{
		std::ifstream file(filename);
		unsigned int data;
		_nbline=0;
		_nbcol =0;
		if(! file.is_open())
		{
			THROW_EXCEPTION(filename + " is not found");
		}

		while(file)
		{
			file >> data;
			_datas.push_back(data);
			if(file.eof())
				_nbline++; // y or x or z
		}
		_nbline--;

		file.close();
		unsigned int size = _datas.size();
		_nbcol = size / _nbline++; // y or x or z

		//-----TEST-------//
		/*
		int size = datas.size();
		std::cout<< "col : " << _nbcol << "| nbline : " << _nbline << std::endl;
		for(int i= 0; i< size; i++)
		{
		std::cout << "data : " << datas[i] << std::endl;
		}
		*/

		return 1;
}
