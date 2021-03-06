// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ MAP.CPP_____ 
//================================

#include <app/Map.hpp>

using namespace RUNBOXRUN;



// --------------- CONSTRUCTORS && DESTRUCTORS --------------

Map::Map(const std::string &filename)
: Asset(filename, glimac::AssetType::MAP) 
{}

bool Map::load() /*pas de retour de bool si exception*/
{
        std::ifstream file(_path);

         int data;
         unsigned int size = 0;
         int i =0; // nb col
         int j =0; // nb line
         int k = 0; // nb bloc

        _x = 0;
        _y = 0;
        _z = 0;

        if(! file.is_open())
            THROW_EXCEPTION(_path + " is not found");

        file >> j >> i >> k;
        int nbByBloc = (j*i)/k;

        while(!file.eof())
        {
            file >> data;
          
            _datas.push_back(data);
            size = _datas.size();
            
            glm::vec4 dataVec = glm::vec4(data,_x,_y,_z);
            _vecdata.push_back(dataVec);

            _z++;

            if(size%nbByBloc == 0)
            {
                _x=_z=0;
                _y++;
            }
            else if(size%i == 0)
            {
                _x++;
                _z=0;
            }

        }

        file.close();

        return true;
}