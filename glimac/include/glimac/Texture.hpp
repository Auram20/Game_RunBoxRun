// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ TEXTURE.HPP ___________ 
//================================

#ifndef __TEXTURE__HPP
#define __TEXTURE__HPP

#include <glimac/Image.hpp>
#include <utils/FilePath.hpp>
#include <iostream>
#include <string>
#include <utils/Asset.hpp>
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
            Texture(Texture &&tex) noexcept;
            Texture(const Texture &tex);
            ~Texture(); /*!< Texture's destructor */
            
            // FONCTIONS
            const std::string getTypeName() const;
            bool load() override;
            inline const GLuint id() const {
                return _id;
            }

            Texture& operator =(Texture&& rvalue) {
                _id = rvalue._id;
                rvalue._id = 0;
                return *this;
            }

        private:
            GLuint _id; /*!< idTexture */
            aiTextureType _type; /*!< texture type */
            void TextureFromFile(const std::string &path);
	        Texture& operator =(const Texture&);
    };
    
}

#endif 