// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ TEXTURE.CPP ___________ 
//================================


#include <glimac/Texture.hpp>

using namespace glimac;

// CONSTRUCTORS
Texture::Texture(const std::string &path)
:_id(0)
{
	_path = _path + path;
	_texture = loadImage(_path);
	if (!_texture)
		std::cerr<<"ERROR loading texture"<<std::endl;
}

// FONCTIONS
void Texture::initTexture()
{
	glGenTextures(1, &_id);
    glBindTexture(GL_TEXTURE_2D, _id);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, _texture->getWidth(), _texture->getHeight(), 0, GL_RGBA, GL_FLOAT, _texture->getPixels());
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBindTexture(GL_TEXTURE_2D, 0);
}

