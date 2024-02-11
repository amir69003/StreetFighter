#ifndef JEU_TXT_H
#define JEU_TXT_H
#include "PartieTxt.h"

class JeuTxt{
private:
    PartieTxt partie; // La partieTxt
    bool fin;         // La fin du JeuTxt

public:
    /// @brief Le Constructeur du JeuSDL
    JeuTxt();  

    /// @brief La boucle du JeuSDL   
    void run();
};

#endif