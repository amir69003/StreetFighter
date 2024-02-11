#ifndef PERSONNAGE_H
#define PERSONNAGE_H
#include <iostream>
#include <string>
#include "Objet.h"

 const int DEGAT_POING = 10;
 const int DEGAT_PIED = 20;
 const int DEGUAT_SPE = 30;
 
enum type_attaque {poing, pied, speciale};

class Personnage {
public:
    unsigned int identifiant;
    std::string nom;
    int vie;
    Objet objet;
    
      /**
   * @brief Constructeur par défaut
  */
    Personnage ();

      /**
   * @brief Mutateur d'un personnage (vie = 100)
   * @param id identifiant du personnage
   * @param nom nom du personnage
  */
    void setPerso(unsigned int id,std::string n,int v = 100);

      /**
   * @brief Le personnage de l'instance attaque le personnage en paramètre
   * @param t le type de l'attaque utilisé (poing, pied, speciale)
   * @param p le personnage qui va subir l'attaque
  */
    void attaquer(type_attaque t,Personnage& p);

  /**
   * @brief Vérifie si le personnage de l'instance est mort ou pas
   * @return retourne vrai si le personnage est mort
  */
    bool estMort () const ;

      /**
   * @brief Retire de la vie  au personnage de l'instance
   * @param nbDegat le nombre de vie à retirer
  */
    void retirerVie (int nbDegat);

      /**
   * @brief Teleporte le personnage 
   * @param v le vecteur 2D nécessaire pour teleporter le personnage
  */
    void teleporter(float _x,float _y);

   /**
   * @brief Deplace le personnage 
   * @param v le vecteur 2D nécessaire pour déplacer le personnage
  */
    void deplacer(float _x,float _y);

  /**
   * @brief Met à jour la position du personnage
  */
    void update();

    /**
   * @brief Met à jour la position du personnage
  */
    void update(const Rectangle& monde);

  /**
   * @brief Test les fonctions membres de la classe Personnage
  */
    void testRegression() const;

};

#endif
