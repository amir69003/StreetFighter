#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <iostream>

class Rectangle {
public:
    float x; // position x
    float y; // position y
    float w; // largeur
    float h; // hauteur

      /**
   * @brief Constructeur par défaut : initialise les données membres à 0
  */
    Rectangle();

  /**
   * @brief Constructeur avec paramètres 
   * @param _x coordonnée x du rectangle
   * @param _y coordonné y du rectangle
   * @param _w largeur du rectangle
   * @param _h hauteur du rectangle
  */
    Rectangle(float _x,float _y,float _w,float _h);

  /**
   * @brief Constructeur par copie
   * @param r le Rectangle à copier
  */
    Rectangle(const Rectangle& r);

  /**
   * @brief Verifie si le rectangle de l'instance et celui en paramètre sont en collisions
   * @param r le 2ème rectangle
   * @return retourne True si les 2 rectangles sont en collisions
  */
    bool collision(const Rectangle& r);

  /**
   * @brief Surchage de l'opérateur <<
   * @param flux le flux dans lequel il faut ajouté les informations du rectangle
   * @param r le rectangle dont il faut ajouter les infos dans le flux
   * @return le flux passé en paramètre
  */
    friend std::ostream& operator<<(std::ostream& flux,const Rectangle& r);

  /**
   * @brief Test les fonctions membres de la classe Rectangle
  */
    void testRegression()const;
};

#endif
