#ifndef VECT2D_H
#define VECT2D_H
#include <iostream>

class Vect2{

public:

    float x;    //position x
    float y;    //position y 

  /**
   * @brief Constructeur par défaut : initialise à 0
  */
    Vect2();   

  /**
   * @brief Constructeur avec paramètre 
   * @param _x la position x du vecteur
   * @param _y la position y du vecteur
  */
    Vect2(float _x,float _y);   // Constructeur
    
  /**
   * @brief Constructeur par copie
   * @param v le vecteur à copier
  */
    Vect2(const Vect2& v);  // Constructeur par copie

  /**
   * @brief Surchage de l'opérateur <<
   * @param flux le flux dans lequel il faut ajouté les informations du vecteur
   * @param v le vecteur dont il faut ajouter les infos dans le flux
   * @return le flux passé en paramètre
  */
    friend std::ostream& operator<< (std::ostream& flux,const Vect2& v);

  /**
   * @brief Modifie le vecteur de l'instance par celui en paramètre
   * @param v le vecteur à copier
   * @return retourne un vect 2D
  */
    Vect2& operator=(const Vect2 &v);

  /**
   * @brief Ajoute les coordonnées du vecteur de l'instance et du vecteur passé en paramètre 
   * @param v le vecteur à ajouter
   * @return retourne un vect 2D
  */
    Vect2 operator+(const Vect2 &v) const;

  /**
   * @brief Soustrait les coordonnées du vecteur de l'instance et du vecteur passé en paramètre 
   * @param v le vecteur à soustraire
   * @return retourne un vect 2D
  */
    Vect2 operator-(const Vect2 &v) const;

  /**
   * @brief Multiplie le vecteur de l'instance par a / operator*
   * @param a le réel qui va multiplier le vecteur
   * @return retourne un vect 2D
  */
    Vect2 operator*(const float &a) const;

  /**
   * @brief Verifie si le vecteur de l'instance est égale à celui passé en paramètre 
   * @param v le vecteur à tester
   * @return retourne vrai si les 2 vecteurs sont égaux
  */
    bool operator==(const Vect2 &v) const;

  /**
   * @brief Test les fonctions membres de la classe Vect2
  */
    void testRegression() const;

};
#endif