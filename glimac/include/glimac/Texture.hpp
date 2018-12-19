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
#include <glimac/common.hpp>
#include <string>
#include <glimac/Asset.hpp>

namespace glimac {

        /// \class Texture
        /// \brief class defining a new texture.
    class Texture : public Asset
    {

        public:
            // CONSTRUCTORS & DESTRUCTOR
            Texture(const std::string &path); /*!< Texture's constructor with parameters*/
            ~Texture() = default; /*!< Texture's destructor */
            
            // FONCTIONS
            void initTexture(); /*!< Generate, Bind texture*/

        private:
            GLint _uTexture; /*!< uniform texture */
            FilePath _path; /*!< texture's path */
            GLuint _id; /*!< idTexture */
            std::unique_ptr<Image> _texture; /*!< loading texture */
    };
    
}

#endif 