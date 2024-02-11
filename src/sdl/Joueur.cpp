#include "Joueur.h"

Joueur::Joueur(){}

void Joueur::initJoueur(int id,SDL_DisplayMode taille_window){

    perso.objet.set_vitesse(0,0);
    perso.objet.set_force(0,2000);
    perso.objet.set_rect(200*taille_window.w/1920,400*taille_window.h/1080,6*70*taille_window.w/1920,6*80*taille_window.h/1080);

    hado.obj.set_vitesse(0,0);
    hado.obj.set_force(0,0);
    hado.obj.set_rect(2180*taille_window.w/1920,400*taille_window.h/1080,6*70*taille_window.w/1920,6*80*taille_window.h/1080);
    
    SDL_Rect s = {0,0,70,80};
    SDL_Rect d = {200*taille_window.w/1920,400*taille_window.h/1080,6*70*taille_window.w/1920,6*80*taille_window.h/1080};
    SDL_Rect de= {2180*taille_window.w/1920,400*taille_window.h/1080,6*70*taille_window.w/1920,6*80*taille_window.h/1080};
    if(id == 1){
        perso.setPerso(1,"ryu1");        
        im.chargerImage("./data/perso/ryu1.png",s,d,true);
        hado.im.chargerImage("./data/perso/ryu1.png",s,de,true);
    }
    else if(id == 2){
        perso.setPerso(2,"ryu2");        
        im.chargerImage("./data/perso/ryu2.png",s,d,true);
        hado.im.chargerImage("./data/perso/ryu2.png",s,de,true);
    }
    else if(id == 3){
        perso.setPerso(3,"ryu3");        
        im.chargerImage("./data/perso/ryu3.png",s,d,true);
        hado.im.chargerImage("./data/perso/ryu3.png",s,de,true);
    }
    else if(id == 4){
        perso.setPerso(4,"ken1");        
        im.chargerImage("./data/perso/ken1.png",s,d,true);
        hado.im.chargerImage("./data/perso/ken1.png",s,de,true);
    }
    else if(id == 5){
        perso.setPerso(5,"ken2");        
        im.chargerImage("./data/perso/ken2.png",s,d,true);
        hado.im.chargerImage("./data/perso/ken2.png",s,de,true);
    }
    else if(id == 6){
        perso.setPerso(6,"ken3");        
        im.chargerImage("./data/perso/ken3.png",s,d,true);
        hado.im.chargerImage("./data/perso/ken3.png",s,de,true);
    }
    unsigned int tab [10] = {4,4,3,5,2,4,5,5,1,1};
    im.initAnim(80,70,10,2,tab);
    im.switchAnim(1);
    hado.im.initAnim(80,70,10,2,tab);
    hado.im.switchAnim(4);
    inverser=false;
    accroupi = false;
    jump = false;
    attaque = false;
}

void Joueur::deplacer(direction dir){
    Vect2 v = perso.objet.vitesse;
    switch (dir)
    {
    case droite:
        perso.deplacer(500,v.y);
        synchro();
        break;
    case gauche:
        perso.deplacer(-500,v.y);
        synchro();
        break;
    case bas:
        perso.deplacer(0,v.y);
        im.switchAnim(9);
        synchro();
        break;
    case haut:
        if(perso.objet.rect.y>(perso.objet.rect.h-10)){
            perso.deplacer(v.x,-1300);
            jump = true;
        }
        synchro();
        break;         
    case rien:
        perso.deplacer(0,v.y);
        synchro();
        break;   
    }
}

void Joueur::attaquer(type_attaque atq,Personnage& p,bool accroupi){

    Rectangle rect_attaque;
    if(perso.objet.rect.x + perso.objet.rect.w/2  < p.objet.rect.x + p.objet.rect.w/2){
        rect_attaque.x = perso.objet.rect.x + perso.objet.rect.w/2; rect_attaque.y = perso.objet.rect.y; 
        rect_attaque.w = perso.objet.rect.w/2; rect_attaque.h = perso.objet.rect.h/4;
    }
    else{
        rect_attaque.x = perso.objet.rect.x; rect_attaque.y = perso.objet.rect.y; 
        rect_attaque.w = perso.objet.rect.w/2; rect_attaque.h = perso.objet.rect.h/4;
    }

    Rectangle ordi_corps;
    if(accroupi){
        ordi_corps.x = perso.objet.rect.x + perso.objet.rect.w/3; 
        ordi_corps.y = perso.objet.rect.y + perso.objet.rect.h/3; 
        ordi_corps.w = perso.objet.rect.w/3; ordi_corps.h = 2*(perso.objet.rect.h/3);
    }
    else{
        ordi_corps.x = p.objet.rect.x + p.objet.rect.w/3; ordi_corps.y = p.objet.rect.y; 
        ordi_corps.w = p.objet.rect.w/3; ordi_corps.h = p.objet.rect.h;
    }

    switch (atq)
    {
    case pied:
        if(!attaque){
            if(rect_attaque.collision(ordi_corps)||ordi_corps.collision(rect_attaque)){
                p.vie -= DEGAT_PIED;
            }
            attaque = true;
            im.switchAnim(6);  
        }
        break;
    case poing:
        
        if(!attaque){
            if(rect_attaque.collision(ordi_corps)||ordi_corps.collision(rect_attaque)){
                p.vie -= DEGAT_POING;
            }
            attaque = true;
            im.switchAnim(2);
        }
        break;
    case speciale:
        if(!attaque){
            attaque = true;
            im.switchAnim(0);
            hado.obj.rect.x=perso.objet.rect.x;
            hado.obj.rect.y=perso.objet.rect.y;
            if(inverser)
            {
                hado.lanceinverse=true;
                hado.obj.set_vitesse(-500,hado.obj.vitesse.y);
            }else
            {
                hado.lanceinverse=false;
                hado.obj.set_vitesse(500,hado.obj.vitesse.y);
            }
            synchrohadoken();
        }
        break;
    }
}

void Joueur::update(){
    im.update();
    hado.obj.update();
    perso.update();

    if(perso.objet.vitesse.x != 0) im.switchAnim(3);
    else if(perso.objet.vitesse.x == 0 && !accroupi && !attaque) im.switchAnim(1);  
    if(perso.objet.vitesse.y < 0){
        im.switchAnim(8);
        SDL_Rect r = {2*im.get_w_anim(),im.get_src_rect().y,im.get_src_rect().w,im.get_src_rect().h};
        im.set_rect_src(r);
    }  
    else if(perso.objet.vitesse.y == 0) jump = false;

    if(im.get_num_anim()==2 && im.get_src_rect().x>=im.get_w_anim()*(im.get_tab_anim(2)-1)){
        im.resetAnim();
        im.switchAnim(1);
        attaque = false;
    }
    if(im.get_num_anim()==6 && im.get_src_rect().x>=im.get_w_anim()*(im.get_tab_anim(6)-1)){
        im.resetAnim();
        im.switchAnim(1);
        attaque = false;
    }
    synchro();
    synchrohadoken();
}

void Joueur::update(const Rectangle& monde,SDL_DisplayMode taille_window){
    im.update();
    perso.update(monde);
    hado.updatehad(monde);
    if(perso.objet.vitesse.x != 0 && !attaque) im.switchAnim(3);
    else if(perso.objet.vitesse.x == 0 && !accroupi && !attaque) im.switchAnim(1);

    if(perso.objet.rect.y < (monde.h)){
        im.switchAnim(8);
        SDL_Rect r = {2*im.get_w_anim(),im.get_src_rect().y,im.get_src_rect().w,im.get_src_rect().h}; 
        im.set_rect_src(r); //trafic de l'anim de saut
    }  
    if(perso.objet.rect.y+perso.objet.rect.h==taille_window.h){
        if(jump){
            im.resetAnim();
            im.switchAnim(1);
            jump = false; 
        }
    }
    if(im.get_num_anim()==2 && im.get_src_rect().x>=im.get_w_anim()*(im.get_tab_anim(2)-1)){
        attaque = false;
        im.resetAnim();
        im.switchAnim(1);
    }
    if(im.get_num_anim()==6 && im.get_src_rect().x>=im.get_w_anim()*(im.get_tab_anim(6)-1)){
        attaque = false;
        im.resetAnim();
        im.switchAnim(1);
    }
    if(im.get_num_anim()==0 && im.get_src_rect().x>=im.get_w_anim()*(im.get_tab_anim(0)-1)){
        attaque = false;
        im.resetAnim();
        im.switchAnim(1);
    }
    synchro();
    synchrohadoken();
}

void Joueur::synchro(){
    SDL_Rect r = {perso.objet.rect.x,perso.objet.rect.y,perso.objet.rect.w,perso.objet.rect.h};
    im.set_rect_dst(r);
}
void Joueur::synchrohadoken(){
    SDL_Rect r = {hado.obj.rect.x,hado.obj.rect.y,hado.obj.rect.w,hado.obj.rect.h};
    hado.im.set_rect_dst(r);
}