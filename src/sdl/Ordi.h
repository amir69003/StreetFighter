#ifndef ORDI_H
#define ORDI_H
#include "Image.h"
#include "Joueur.h"
#include "../core/Personnage.h"
#include"Hadoken.h"

class Ordi {
public:
    Personnage perso;
    Image im;
    bool jump,accroupi,attaque,inverser;
    Hadoken hado;

    /**
   * @brief Constructeur sans paramètres
  */
    Ordi();

    /**
   * @brief Initialise toutes les données relatives à l'ordi (force,vitesse,rectangle...)
   * @param id l'identifiant de l'ordi
   * @param taille_window taille de l'écran w et h
  */    
    void initOrdi(int id,SDL_DisplayMode taille_window);

    /**
   * @brief Attaque le personnage en paramètre
   * @param atq le type de l'attaque (poing, pied, speciale)
   * @param p le personnage à attaquer
   * @param accroupi le personnage à attaquer est accroupi ou pas
  */    
    void attaquer(type_attaque atq,Personnage& p,bool accroupi);

    /**
   * @brief Déplace le personnage dans une direction
   * @param dir la direction (haut,droite,bas,gauche,rien)
  */    
    void deplacer(direction dir);

    /**
   * @brief Met à jour la position du perso
  */    
    void update();

    /**
   * @brief Met à jour la position du perso
   * @param monde le rectangle du monde
  */    
    void update(const Rectangle& monde,SDL_DisplayMode taille_window);

    /**
   * @brief Synchronise le rectangle du perso et l'image du perso
  */  
    void synchro();

    /**
   * @brief Synchronise le rectangle du hado et l'image du hado
  */  
    void synchrohado();

};
#endif