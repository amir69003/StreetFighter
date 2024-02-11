#ifndef PARTIE_SDL_H
#define PARTIE_SDL_H
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"
#include "SDL2/SDL_ttf.h"
#include "Image.h"
#include "Joueur.h"
#include "Ordi.h"

enum typeEcranPartie {PersoSelect, MapSelect, Partie, Pause, FinPartie};

struct Selection {
    int choix_perso,choix_ordi,choix_map;
    bool conf_perso,conf_ordi,conf_map;
};

class PartieSDL {
private:
    bool fin;                       // fin de la partie
    Selection sel;                  // structure de selection des éléments de la partie
    SDL_DisplayMode taille_window;  // la taille de la fenetre
    typeEcranPartie ecran;          // l'ecran affiché
    Image * tab;                    // tableau des images
    unsigned int nb_image;          // nombre d'image dans le tableau
    Joueur joueur;                  // le joueur
    Ordi ordi;                      // l'ordi d'entrainement ou le joueur 2
    bool entrainement;              // le mode entrainement
    Mix_Music * music_menu;         // La musique du menu
    Mix_Chunk * son_hadoken;
    Mix_Music * music_combat1;      // Une des musique du combat
    Mix_Music * music_combat2;      // Une des musique du combat
    Mix_Music * music_combat3;      // Une des musique du combat
    Mix_Music * music_combat4;      // Une des musique du combat
    Mix_Music * music_fin;          // La musique de la fin de partie
    TTF_Font * police;              // la police d'ecriture du chrono
    float temps_debut;              // le temps du début de la partie
    float temps_restant;            // le temps restant de la partie
    float temps_pause;              // le temps passé en etat de pause de la partie
    float temps_entrainement;       // le temps passé en mode entrainement
    float joueur_t_atq_spe;
    float ordi_t_atq_spe;

public:
    /// @brief Constructeur d'une PartieSDL
    /// @param renderer le rendu de la fenetre utilisée pour afficher la PartieSDL
    /// @param t la taille de la fenetre utilisée pour afficher la PartieSDL
    PartieSDL(SDL_Renderer * renderer,SDL_DisplayMode t);

    /// @brief Destructeur d'une PartieSDL
    ~PartieSDL();

    /// @brief Initalisation de tout les éléments d'une PartieSDL
    /// @param _entrainement mode entrainement
    void initPartieSDL(bool _entrainement);

    /// @brief Affiche une image en miroir
    /// @param renderer le rendu de la fenetre utilisée pour afficher la PartieSDL
    /// @param i l'image à afficher
    void afficherImageInverse(SDL_Renderer * renderer,const Image& i);

    /// @brief Affiche une image
    /// @param renderer le rendu de la fenetre utilisée pour afficher la PartieSDL
    /// @param i l'image à afficher
    void afficherImage(SDL_Renderer * renderer,const Image& im);

    /// @brief Ajoute une image dans le tableau d'image
    /// @param i l'image à ajoutet
    void ajouterImage(const Image& i);
    
    /// @brief Les evenements à prendre en compte lors de l'ecran SelectionMap
    /// @param events le SDL_Event de la boucle de jeu
    void evenementSelectionMap(SDL_Event events);

    /// @brief L'affichage à effectuer pour l'ecran SelectionMap
    /// @param renderer le rendu de la fenetre utilisée pour afficher la PartieSDL
    void selectionMap(SDL_Renderer * renderer);

    /// @brief Les evenements à prendre en compte lors de l'ecran SelectionPers
    /// @param events le SDL_Event de la boucle de jeu
    /// @param renderer le rendu de la fenetre utilisée pour afficher la PartieSDL
    void evenementSelectionPerso(SDL_Event events,SDL_Renderer * renderer);

    /// @brief L'affichage à effectuer pour l'ecran SelectionPerso
    /// @param renderer le rendu de la fenetre utilisée pour afficher la PartieSDL
    void selectionPerso(SDL_Renderer * renderer);  

    /// @brief Initialisation des éléments du combat après la selection
    /// @param renderer 
    void initCombat(SDL_Renderer * renderer);

    /// @brief Les evenements à prendre en compte lors de l'ecran Partie
    /// @param events le SDL_Event de la boucle de jeu
    void evenementPartie(SDL_Event events);

    /// @brief L'affichage à effectuer pour l'ecran Partie
    /// @param renderer le rendu de la fenetre utilisée pour afficher la PartieSDL
    void partie(SDL_Renderer * renderer);

    /// @brief Les evenements à prendre en compte lors de l'ecran Fin Partie
    /// @param events le SDL_Event de la boucle de jeu
    void evenementFinPartie(SDL_Event events);

    /// @brief L'affichage à effectuer pour l'ecran FinPartie
    /// @param renderer le rendu de la fenetre utilisée pour afficher la PartieSDL
    void finPartie(SDL_Renderer * renderer);

    /// @brief Les evenements à prendre en compte lors de l'ecran Pause
    /// @param events le SDL_Event de la boucle de jeu
    void evenementPause(SDL_Event events);

    /// @brief L'affichage à effectuer pour l'ecran Pause
    /// @param renderer le rendu de la fenetre utilisée pour afficher la PartieSDL
    void pause(SDL_Renderer * renderer);

    /// @brief Les evenements à prendre en compte lors de la PartieSDL
    /// @param events le SDL_Event de la boucle de jeu
    /// @param renderer le rendu de la fenetre utilisée pour afficher la PartieSDL
    void evenementPartieSDL(SDL_Event events,SDL_Renderer * renderer);

    /// @brief L'affichage à effectuer pour la PartieSDL
    /// @param renderer le rendu de la fenetre utilisée pour afficher la PartieSDL
    void afficherPartieSDL(SDL_Renderer * renderer);
    
    /// @brief Mise à jour des éléments de la PartieSDL
    void update();

    /// @brief Verification de la fin de la PartieSDL
    /// @return la fin de la PartieSDL
    bool verifierFin();

    /// @brief La boucle de la PartieSDL
    /// @param renderer le rendu de la fenetre utilisée pour afficher la PartieSDL
    /// @param entrainement le mode entrainement
    void run(SDL_Renderer * renderer,bool entrainement);    
};

/// @brief Verifie si un clique de souris à été effectué dans un Rect
/// @param events Le SDL_Event qui verifie l'appui des touches
/// @param r Le Rect dans le quel le clique
/// @return le clique dans le Rect
bool clique(SDL_Event events,SDL_Rect r);

/// @brief Verifie si une touche est appuyée
/// @param events Le SDL_Event qui verifie le clique
/// @param t Le SDL_Scancode de la touche
/// @return l'appui de la touche
bool cliqueBtnDown(SDL_Event events,SDL_Scancode t);

/// @brief Verifie si une touche est relachée
/// @param events Le SDL_Event qui verifie le relachement
/// @param t Le SDL_Scancode de la touche
/// @return le relachement de la touche
bool cliqueBtnUp(SDL_Event events,SDL_Scancode t);

/// @brief Verifie si une touche est appuyée
/// @param events Le SDL_Event qui verifie le clique
/// @param t Le SDL_Keycode de la touche
/// @return l'appui de la touche
bool cliqueBtnDown(SDL_Event events,SDL_Keycode t);

/// @brief Verifie si une touche est relachée
/// @param events Le SDL_Event qui verifie le relachement
/// @param t Le SDL_Keycode de la touche
/// @return le relachement de la touche
bool cliqueBtnUp(SDL_Event events,SDL_Keycode t);

#endif