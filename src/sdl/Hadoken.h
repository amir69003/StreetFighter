#ifndef HADOKEN_H
#define HADOKEN_H
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <cassert>
#include"Image.h"
#include"../core/Personnage.h"

class Hadoken
{
    public:
        Image im;           // l'image du Hadoken
        Objet obj;          // l'objet du Hadoken
        bool lanceinverse;  // le sens du lancé du Hadoken
        
        /// @brief Mise à jour du Hadoken
        /// @param monde Rectangle dans lequel le Hadoken se met à jour
        void updatehad(const Rectangle& monde);
};

#endif