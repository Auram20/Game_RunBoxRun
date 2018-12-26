// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ TEXT.CPP ___________ 
//================================


// Includes 
#include <glimac/Text.hpp>

using namespace glimac;


Text::Text(const std::string &font, const int &taille, const std::vector<int> color, const std::string &message)
: _taille(taille), _fontColor(color), _message(message)
{
  _police = TTF_OpenFont(font, taille);
  initText();
  _fond = IMG_Load("./assets/blanc.jpg")
}

void Text::initText(){
  TTF_Init();
  if(TTF_Init() == -1)
  {
    fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
    exit(EXIT_FAILURE);
  }
}


void Text::write(){
  SDL_Surface *ecran = NULL, *texte = NULL, *background = NULL;
  _texte = TTF_RenderText_Blended(_police, _message, _fontColor);
}

void Text::stopTTF(){
  TTF_CloseFont(_police);
  TTF_Quit();
  SDL_FreeSurface(_texte);
  
}