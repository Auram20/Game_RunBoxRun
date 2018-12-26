// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ TEXT.HPP ___________ 
//================================

#ifndef __TEXT__HPP
#define __TEXT__HPP

#include <iostream>
#include <SDL/SDL_ttf.h>
#include <string>
#include <vector>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>

namespace glimac {

        /// \class Text
        /// \brief class defining a new text.
    class Text
    {

        public:
            // CONSTRUCTORS & DESTRUCTOR
            Text(const std::string &font, const int &taille, const std::vector<int> color, const std::string &message);
            //Text(const std::string &path, const aiTextureType &type); /*!< Texture's constructor with parameters*/
            ~Text() = default; /*!< Texture's destructor */
            

        void initText();
        void stopTTF();
        void write();

        private:
            TTF_Font *_police;
            int _taille;
            SDL_Color _fontColor;
            std::string _message;
            SDL_Surface *_fond;
            SDL_Surface *_texte;
    };
    
}

#endif 


//fond sera le meme que le button, il faut que les deux communiquent
