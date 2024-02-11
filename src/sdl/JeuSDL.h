#ifndef JEU_SDL_H
#define JEU_SDL_H
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include "Image.h"
#include "PartieSDL.h"
#include "Joueur.h"

enum typeEcran {intro, mainMenu};


class JeuSDL {
private:
    SDL_Renderer * renderer;        // Le rendu de la fenetre
    SDL_Window * window;            // La fenetre
    SDL_DisplayMode taille_window;  // La taille de la fenetre
    typeEcran ecran;                // L'ecran affiché
    Mix_Music * music;               // La musique de fond
    Image * tab;                    // Le tableau de toutes les images du jeu
    unsigned int nb_image;          // Le nombre d'image dans le tableau

public:
    /**
   * @brief Constructeur avec paramètres
   * @param fullscreen booléen plein écran
   * @param dimx Dimension x de la fenêtre (si fenetré)
   * @param dimy Dimension y de la fenêtre (si fenetré)
  */
    JeuSDL(bool fullscreen = true,unsigned int dimx = 720,unsigned int dimy = 576);

    /**
   * @brief Destructeur de la classe
  */
    ~JeuSDL();

    /**
   * @brief Ajoute une image au tableau d'image de la classe
   * @param i l'image à ajouter
  */
    void ajouterImage(const Image& i);

    /**
   * @brief Charge toutes les images dans le tableau de la classe
  */
    void chargerTabImage();

    /**
   * @brief Affiche l'image passé en paramètre
   * @param i l'image à afficher
  */
    void afficherImage(const Image& i);

    /**
   * @brief Met à jour toutes les images du tableau (pour animation)
  */
    void updateTabImage();

    /**
   * @brief Affiche le menu principal du jeu
   * @param e l'ecran à afficher (mainMenu par défaut)
  */
    void afficherJeuSDL(typeEcran e);

    /**
   * @brief Lance le jeu et gère les évènements sur le menu principal
  */
    void run();
};

#endif