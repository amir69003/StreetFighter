#ifndef JOUEUR_H
#define JOUEUR_H
#include "Image.h"
#include "../core/Personnage.h"
#include"Hadoken.h"

enum direction {haut,droite,bas,gauche,rien};


class Joueur {
public:
    Personnage perso;   // personnage
    Hadoken hado;    //hadoken
    Image im;           // image
    bool jump,accroupi,attaque,inverser;

    /**
   * @brief Constructeur sans paramètres
  */
    Joueur();

    /**
   * @brief Initialise toutes les données relatives à un joueur (force,vitesse,rectangle...)
   * @param id l'identifiant du joueur
   * @param taille_window taille de l'écran w et h
  */    
    void initJoueur(int id,SDL_DisplayMode taille_window);

    /**
   * @brief Déplace le personnage dans une direction
   * @param dir la direction (haut,droite,bas,gauche,rien)
  */    
    void deplacer(direction dir);

    /**
   * @brief Attaque le personnage en paramètre
   * @param atq le type de l'attaque (poing, pied, speciale)
   * @param p le personnage à attaquer
   * @param accroupi le personnage à attaquer est accroupi ou pas
  */    
    void attaquer(type_attaque atq, Personnage& p,bool accroupi);

    /**
   * @brief Met à jour la position du perso
  */    
    void update();

    /**
   * @brief Met à jour la position du perso
   * @param monde le rectangle du monde
   * @param taille_window taille de l'écran w et h
  */    
    void update(const Rectangle& monde,SDL_DisplayMode taille_window);

    /**
   * @brief Synchronise le rectangle du perso et l'image du perso
  */   
    void synchro();

    /**
   * @brief Synchronise le rectangle du hadoken et l'image du hadoken
  */   
    void synchrohadoken(); 
};
#endif