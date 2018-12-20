// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ TEXTURE.HPP ___________ 
//================================

#ifndef __TEXTURE__HPP
#define __TEXTURE__HPP

#include <glimac/Image.hpp>
#include <glimac/FilePath.hpp>
#include <iostream>
#include <string>
#include <glimac/Asset.hpp>
#include <assimp/material.h>


namespace glimac {

        /// \class Texture
        /// \brief class defining a new texture.
    class Texture : public Asset
    {

        public:
            // CONSTRUCTORS & DESTRUCTOR
            Texture() = default;
            Texture(const std::string &path, const aiTextureType &type); /*!< Texture's constructor with parameters*/
            Texture(const Texture &tex);
            ~Texture() = default; /*!< Texture's destructor */
            
            // FONCTIONS
            const std::string getTypeName() const;
            inline const GLuint id() const {
                return _id;
            }

        private:
            GLuint _id; /*!< idTexture */
            aiTextureType _type; /*!< texture type */
            void TextureFromFile(const std::string &path);
    };
    
}

#endif 