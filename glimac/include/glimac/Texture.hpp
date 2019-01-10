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
            Texture(const Texture&);
            Texture(const std::string &path); /*!< Texture's constructor with parameters*/
            ~Texture() = default; /*!< Texture's destructor */
            
            // FONCTIONS
            bool load() override;
            inline const GLuint id() const {
                if(_id.get() != nullptr)
                    return *_id;
                else
                    return 0;
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


        private:
            std::shared_ptr<GLuint> _id; /*!< idTexture */
            void TextureFromFile(const std::string &path);
            static void deleteTexID(GLuint *id) {
                if(id != nullptr) {
                    std::cout << "delete !" << std::endl;
                    if(*id != 0)
                        glDeleteTextures(1, id);
                    delete id;
                }
            }
    };
    
}

#endif 