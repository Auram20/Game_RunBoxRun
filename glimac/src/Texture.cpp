// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ TEXTURE.CPP ___________ 
//================================


#include <glimac/Texture.hpp>

using namespace glimac;

// CONSTRUCTORS
Texture::Texture()
: Asset(std::string(""), AssetType::TEXTURE), _id(0)
{
}

Texture::Texture(const std::string &path)
:Asset(path, AssetType::TEXTURE), _id(0)
{
	load();
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
        _id = tex;

		return true;
}

Texture::Texture(Texture &&tex) noexcept
: Asset(tex), _id(tex._id)
{
	tex._id = 0;
}

Texture::~Texture() {
	if(_id != 0)
		glDeleteTextures(1, &_id);
}