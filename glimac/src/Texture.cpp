// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ TEXTURE.CPP ___________ 
//================================


#include <glimac/Texture.hpp>

using namespace glimac;

// CONSTRUCTORS
Texture::Texture()
: Asset(std::string(""), AssetType::TEXTURE), _id(std::shared_ptr<GLuint>(nullptr, Texture::deleteTexID))
{
}

Texture::Texture(const std::string &path)
:Asset(path, AssetType::TEXTURE), _id(std::shared_ptr<GLuint>(new uint(0), Texture::deleteTexID))
{
	load();
}


Texture::Texture(const Texture &tex)
: Asset(tex), _id(tex._id)
{

}

bool Texture::load(){
        GLuint tex;
   		std::unique_ptr<Image> img = loadImage(_path);

		if (!img){
			std::cerr<<"ERROR loading texture at " + std::string(_path) <<std::endl;
			return false;
		}

        glGenTextures(1, &tex);
        glBindTexture(GL_TEXTURE_2D,tex);
        glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,img->getWidth(),img->getHeight(),0,GL_RGBA,GL_FLOAT,img->getPixels());
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBindTexture(GL_TEXTURE_2D,0);
        _id = std::make_shared<GLuint>(tex);

		return true;
}