#include "Vect2.h"
#include "Rectangle.h"
#include "Objet.h"
#include "Personnage.h"

int main (){
    Vect2 vecteur;
    vecteur.testRegression();

    Rectangle rect;
     rect.testRegression();

    Objet obj;
    obj.testRegression();

    Personnage perso;
    perso.testRegression();
    
    return 0;
}