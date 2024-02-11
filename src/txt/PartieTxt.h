#ifndef PARTIE_TXT_H
#define PARTIE_TXT_H
#include"../core/Personnage.h"

class PartieTxt {
private:
    Personnage joueur;  // le personnage
    Personnage ordi;    // du joueur
    bool fin;           // la fin de la partie
public:
    /// @brief Constructeur de la PartieTxt
    PartieTxt();

    /// @brief Initialisation de tous les éléments de la PartieTxt
    void init();

    /// @brief Chargement des personnages à partir d'un fichier
    /// @param p le tableau de tous les personnages chargés
    /// @param nb_perso le nombre de personnage dans le tableau
    void chargement_perso(Personnage * &p,unsigned int& nb_perso);

    /// @brief La selection des personnages pour jouer
    void selection_perso();

    /// @brief La boucle de la PartieTxt
    void run();

    /// @brief L'affichage en mode texte
    void afficher();

    /// @brief La vérification de la fin de la PartieTxt
    /// @return la fin de la partie
    bool verifierFin();
};

#endif