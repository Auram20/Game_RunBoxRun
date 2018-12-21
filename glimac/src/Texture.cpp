// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ TEXTURE.CPP ___________ 
//================================


#include <glimac/Texture.hpp>

using namespace glimac;

// CONSTRUCTORS
Texture::Texture(const std::string &path, const aiTextureType &type)
:_id(0), _type(type)
{
	TextureFromFile(path);
}

void Texture::TextureFromFile(const std::string &path){
        GLuint tex;
   		std::unique_ptr<Image> img = loadImage(path);

		if (!img)
			std::cerr<<"ERROR loading texture at " + path <<std::endl;

        glGenTextures(1, &tex);
        glBindTexture(GL_TEXTURE_2D,tex);
        glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,img->getWidth(),img->getHeight(),0,GL_RGBA,GL_FLOAT,img->getPixels());
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBindTexture(GL_TEXTURE_2D,0);
        _id = tex;
		_path = FilePath(path.c_str());
}

const std::string Texture::getTypeName() const {

	std::string typeName;

	switch(_type) {

		case(aiTextureType_NONE):
			typeName = "texture_none";
			break;

		case(aiTextureType_DIFFUSE):
			typeName = "texture_diffuse";
			break;


		case(aiTextureType_SPECULAR):
			typeName = "texture_specular";
			break;


		case(aiTextureType_AMBIENT):
			typeName = "texture_ambient";
			break;


		case(aiTextureType_EMISSIVE):
			typeName = "texture_emissive";
			break;

		case(aiTextureType_HEIGHT):
			typeName = "texture_height";
			break;


		case(aiTextureType_NORMALS):
			typeName = "texture_normals";
			break;


		case(aiTextureType_SHININESS):
			typeName = "texture_shininess";
			break;

		case(aiTextureType_OPACITY):
			typeName = "texture_opacity";
			break;
		
		case(aiTextureType_DISPLACEMENT):
			typeName = "texture_displacement";
			break;

		case(aiTextureType_LIGHTMAP):
			typeName = "texture_lightmap";
			break;

		case(aiTextureType_REFLECTION):
			typeName = "texture_reflection";
			break;

		case(aiTextureType_UNKNOWN):
			typeName = "texture_unknown";
			break;

		default:
			break;
	}

	return typeName;
}

Texture::Texture(const Texture &tex)
: _id(tex._id), _type(tex._type)
{

}

Texture::~Texture() {
	glDeleteTextures(1, &_id);
}