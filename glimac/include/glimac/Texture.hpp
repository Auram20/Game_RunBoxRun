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
            Texture();
            Texture(const std::string &path); /*!< Texture's constructor with parameters*/
            Texture(Texture &&tex) noexcept;
            ~Texture(); /*!< Texture's destructor */
            
            // FONCTIONS
            bool load() override;
            inline const GLuint id() const {
                return _id;
            }

            Texture& operator =(Texture&& rvalue) noexcept {
                _id = rvalue._id;
                rvalue._id = 0;
                return *this;
            }

            Texture& operator =(const std::string &path) {
                if(path != "") {
                    _path = path;
                    load();
                }
                return *this;
            }

            Texture& operator =(const FilePath &path) {
                if(path != "") {
                    _path = path;
                    load();
                }
                return *this;
            }

            Texture(const Texture& tex) {};

        private:
            GLuint _id; /*!< idTexture */
            void TextureFromFile(const std::string &path);
	        Texture& operator =(const Texture&);
    };
    
}

#endif 