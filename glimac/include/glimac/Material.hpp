// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ MATERIAL.HPP_____ 
//================================

#ifndef __MATERIAL__HPP
#define __MATERIAL__HPP

#include <glimac/Texture.hpp>
#include <iostream>

namespace glimac
{

	/// \class Material
	/// \brief class defining a Material
	class Material
	{
		public:
        Material()
        : _textures(), _colors(), _shininess(1) 
        {

        }

        Material(const Material& material)
        : _textures(material._textures), _colors(material._colors), _shininess(material._shininess) 
        {

        }

        ~Material() = default;

        inline const int textureId(const aiTextureType &type) {
            auto it = _textures.find(type);
            if(_textures.find(type) == _textures.end()) return -1;
            return (it->second).id();
        }

        inline void addTexture(const aiTextureType &type, const std::string &path) {
            _textures.emplace(type, path);
        }

        inline const glm::vec3 color(const aiTextureType &type) {
            auto it = _colors.find(type);
            if(_colors.find(type) == _colors.end()) return glm::vec3(1, 1, 1);
            return (it->second);
        }

        inline const uint colorNb() const {
            return _colors.size();
        }

        inline const uint textureNb() const {
            return _textures.size();
        }

        inline const float shininess() {
            return _shininess;
        }

        inline void setColor(const aiTextureType &type, const glm::vec3 &color) {
            _colors.emplace(type, color);
        }

        inline const std::map<aiTextureType, Texture>::const_iterator textureBegin() const {
            return _textures.begin();
        }

        inline const std::map<aiTextureType, Texture>::const_iterator textureEnd() const {
            return _textures.end();
        }

        inline const std::map<aiTextureType, glm::vec3>::const_iterator colorBegin() const {
            return _colors.begin();
        }

        inline const std::map<aiTextureType, glm::vec3>::const_iterator colorEnd() const {
            return _colors.end();
        }

        static const std::string getTypeName(const aiTextureType &type) {

            std::string typeName;

            switch(type) {

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


        private:
        std::map<aiTextureType, Texture> _textures;
        std::map<aiTextureType, glm::vec3> _colors;
        float _shininess;
        
		
	};
}

#endif


  