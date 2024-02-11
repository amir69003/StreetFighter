#include <iostream>
#include <unistd.h>
#include <cassert>
#include "JeuTxt.h"
using namespace std;

JeuTxt::JeuTxt():partie(),fin(false){}

void JeuTxt::run(){
    cout<<"\n========= LANCEMENT DU JEU =========\n";
    while(!fin){
        cout<<"Lancer une partie (P) ou quitter le jeu (Q)\n";
        char choix;
        cin>>choix;
        switch (choix)
        {
            case 'P': partie.run();
                break;
            case 'Q':fin=true;
                break;
            default:
                break;
        }
    }
}