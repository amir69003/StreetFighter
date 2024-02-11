#include <iostream>
#include <fstream>
#include <cassert>
#include <unistd.h>
#include "PartieTxt.h"
using namespace std;

PartieTxt::PartieTxt(){}

void PartieTxt::chargement_perso(Personnage * &p,unsigned int& nb_perso){
    ifstream fichier ("./data/personnages.txt");
    assert(fichier.is_open());

    fichier>>nb_perso;

    if(p!=nullptr) delete [] p;
    else p = new Personnage [nb_perso];

    int identifiant;
    string nom;
    for(unsigned int i=0;i<nb_perso;i++){   
        fichier>>identifiant>>nom;
        p[i].setPerso(identifiant,nom);
    }
    fichier.close();
}

void PartieTxt::selection_perso(){
    Personnage * p = nullptr;
    unsigned int nb = 0;
    unsigned int id = 0;

    chargement_perso(p,nb);
    cout<<"\n-- MENU DE SELECTION DES PERSONNAGES --\n";

    cout<<"Choisissez votre personnages parmis les suivants:\n";
    for(unsigned int i=0;i<nb;i++){
        cout<<p[i].identifiant<<" - "<<p[i].nom<<"\n";
    }

    cout<<"Entrer l'identifiant du personnage que vous voulez :\n";
    cin>>id;
    joueur.setPerso(p[id-1].identifiant,p[id-1].nom);
    
    ordi.setPerso(0,"Ordi");

    if(p!=nullptr) delete [] p;
}

void PartieTxt::init(){
    fin = false;
    selection_perso();
    joueur.objet.set_rect(0,0,20,20);
    ordi.objet.set_rect(100,0,20,20);
}

bool PartieTxt::verifierFin(){
    return(joueur.estMort() || ordi.estMort());
}

void PartieTxt::afficher(){
    cout<<"position joueur = "<<joueur.objet.rect<<" vie joueur = "<<joueur.vie<<"\n"; 
    cout<<"position ordi = "<<ordi.objet.rect<<" vie ordi = "<<ordi.vie<<"\n"; 
}

void PartieTxt::run(){
    init();
    cout<<"--- La Partie va commencer dans ..."<<flush;
    sleep(1);   cout<<" TROIS !"<<flush;
    sleep(1);   cout<<" DEUX !"<<flush;
    sleep(1);   cout<<" UN !"<<flush;
    sleep(1);   cout<<"  FIGHT !\n"<<flush; sleep(1);
    char action;
    while(!fin){
        cout<<"\n";
        afficher();
        cout<<"Action à choisir :\n";
        cout<<"- p : coup de poing\n- k : coup de pied\n- s : attaque spe\n";
        cout<<"- g : teleporter à gauche\n- d : teleporter à droite\n- j : sauter\n";
        cout<<"- q : quitter la partie\n";
        cout<<"\n";
        cin>>action;
        switch (action)
        {
            case 'p': cout<<"le joueur donne un coup de poing !\n"; if(joueur.objet.rect.collision(ordi.objet.rect)){
                joueur.attaquer(poing,ordi);
                cout<<"l'ordi est touché \n";
            }
            else{ cout<<"l'ordi est trop loin..."; }
            
                      fin=verifierFin();
                break;
            case 'k': cout<<"le joueur donne un coup de pied !\n"; if(joueur.objet.rect.collision(ordi.objet.rect)){
                joueur.attaquer(pied,ordi);
                cout<<"l'ordi est touché !\n";
            }
            else{ cout<<"l'ordi est trop loin...\n"; }
                      fin=verifierFin();
                break;
            case 's': cout<<"le joueur donne une attaque speciale !\n"; if(joueur.objet.rect.collision(ordi.objet.rect)){
                joueur.attaquer(speciale,ordi);
                cout<<"l'ordi est touché !";
            }
            else{ cout<<"l'ordi est trop loin..."; }
                      fin=verifierFin();
                break;
            case 'd': cout<<"le joueur bouge à droite\n"; joueur.teleporter(10,0);
                      fin=verifierFin();
                break;
            case 'g': cout<<"le joueur bouge à gauche\n"; joueur.teleporter(-10,0);
                      fin=verifierFin();
                break;
            case 'j': cout<<"le joueur saute\n"; // on ne peut pas le faire sans le update qui depend du temps
                      fin=verifierFin();
                break;
            case 'q': fin = true;
                break;
            default: 
                break;
        }
    }
    cout<<"\n";
    if(ordi.estMort()) cout<<joueur.nom<<" a gagner le combat !\n";
    else if(joueur.estMort()) cout<<"L'ordi a gagner le combat !\n";
    else cout<<"--- La partie est finie ---\n";
    cout<<"Retour au menu ... \n";
}