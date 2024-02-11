#ifndef OBJET2D_H
#define OBJET2D_H
#include "Rectangle.h"
#include "Vect2.h"

class Objet {
public:

    Rectangle rect; // le rectangle de l'objet
    Vect2 vitesse;  // la vitesse de l'objet
    Vect2 force;    // la force appliquée à l'objet
    float masse;    // la masse de l'objet

    /**
    * @brief Constructeur par défault : initialise les données à 0
    */
    Objet();

    /**
    * @brief Constructeur avec paramètres
    */
    Objet(const Rectangle& r,const Vect2& v,const Vect2& f,float m);

    /**
    * @brief Constructeur par copie
    */
    Objet(const Objet& o);
    
    /**
    * @brief Mutateur : modifie le rectangle de l'objet
    */
    void set_rect(float _x,float _y,float _w,float _h);
    
    /**
    * @brief Mutateur : modifie la vitesse de l'objet
    */
    void set_vitesse(float _x,float _y);
    
    /**
    * @brief Mutateur : modifie la force de l'objet
    */
    void set_force(float _x,float _y);
    
    /**
    * @brief Met à jour la position du rectangle de l'objet en fonction de la vitesse,la force et du temps
    */
    void update();

    /**
    * @brief Met à jour la position du rectangle de l'objet dans le rectangle monde
    */
    void update(const Rectangle& monde);

    /**
    * @brief Test de regression qui teste toutes les autres fonctions
    */
    void testRegression() const;
};

#endif