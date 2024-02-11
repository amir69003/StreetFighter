#include <iostream>
#include <cassert>
#include "Personnage.h"


Personnage::Personnage():identifiant(0),nom("perso_test"),vie(100),
objet(Objet(Rectangle(0,0,1,1),Vect2(0,0),Vect2(0,0),1)){}

void Personnage::setPerso(unsigned int id,std::string n,int v){
    identifiant=id;   nom=n;  vie=v;
}

bool Personnage::estMort() const {
        return vie<=0;
}

void Personnage::retirerVie(int nbDegat) {
    vie = vie - nbDegat;
}

void Personnage::attaquer(type_attaque t,Personnage& p){
    if(t==poing){
        if(objet.rect.collision(p.objet.rect)){ // à modifier
            p.retirerVie(DEGAT_POING);
        }
    }
    else if(t==pied){
        //Rectangle atq (0,0,0,0);
        if(objet.rect.collision(p.objet.rect)){ // à modifier
            p.retirerVie(DEGAT_PIED);
        }
    }
    else if(t==speciale){
        //Rectangle atq (0,0,0,0);
        if(objet.rect.collision(p.objet.rect)){ // à modifier
            p.retirerVie(DEGUAT_SPE);
        }
    }
}

void Personnage::teleporter(float _x,float _y){
    objet.rect.x = objet.rect.x + _x;
    objet.rect.y = objet.rect.y + _y;
}

void Personnage::deplacer(float _x,float _y){
    objet.set_vitesse(_x,_y);
}

void Personnage::update(){
    objet.update();
}

void Personnage::update(const Rectangle& monde){
    objet.update(monde);
}

void Personnage::testRegression() const{
    std::cout<<"--- Debut du test de la classe Personnage ---\n";

    Personnage p0;
    p0.setPerso(0,"bot_0");
    assert(p0.identifiant==0 && p0.vie==100 && p0.estMort()==false);
    if(p0.estMort()) std::cout<<"p0 est mort...\n";
    else std::cout<<"p0 est vivant !\n";
    std::cout<<"p0 a "<<p0.vie<<" points de vie\n";

    Personnage p1;
    p1.setPerso(1,"bot_1");
    assert(p1.identifiant==1 && p1.vie==100 && p1.estMort()==false);
    if(p1.estMort()) std::cout<<"p1 est mort...\n";
    else std::cout<<"p1 est vivant !\n";
    std::cout<<"p1 a "<<p1.vie<<" points de vie\n";

    std::cout<<"p0 donne un coup de poing à p1\n";
    p0.attaquer(poing,p1);
    assert(p1.vie==100-DEGAT_POING);

    std::cout<<"p1 donne un coup de pied à p0\n";
    p1.attaquer(pied,p0);
    assert(p0.vie==100-DEGAT_PIED);

    std::cout<<"p0 se lance une attaque speciale sur lui meme wtf ?!\n";
    p0.attaquer(speciale,p0);
    assert(p0.vie==100-(DEGAT_PIED+DEGUAT_SPE));

    std::cout<<"p0 se sent pas bien, il perd 100 points de vie\n";
    p0.retirerVie(100);
    if(p0.estMort()) std::cout<<"p0 est mort...\n";
    else std::cout<<"p0 est encore vivant !\n";

    std::cout<<"--- Fin du test de la classe Personnage ---\n";
}