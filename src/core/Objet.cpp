#include <cassert>
#include "Objet.h"

const float dt = 0.1;

Objet::Objet():rect(Rectangle(0,0,0,0)),vitesse(Vect2(0,0)),force(Vect2(0,0)),masse(1){}

Objet::Objet(const Rectangle& r,const Vect2& v,const Vect2& f,float m=1):
rect(r),vitesse(v),force(v),masse(1){}

Objet::Objet(const Objet& o):rect(o.rect),vitesse(o.vitesse),force(o.force),masse(o.masse){}

void Objet::set_rect(float _x,float _y,float _w,float _h){
    rect.x=_x;  rect.y=_y;  rect.w=_w;  rect.h=_h;
}

void Objet::set_vitesse(float _x,float _y){
    vitesse.x=_x;   vitesse.y=_y;
}

void Objet::set_force(float _x,float _y){
    force.x=_x; force.y=_y;
}

void Objet::update(){          
    assert(masse>0.0);
    Vect2 pos(rect.x,rect.y);
    vitesse=(vitesse+force*(dt/masse));
    pos=pos+vitesse*dt;
    set_rect(pos.x,pos.y,rect.w,rect.h);
}

void Objet::update(const Rectangle& monde){          
    assert(masse>0.0);
    Vect2 pos(rect.x,rect.y);
    Vect2 dim(rect.w,rect.h);
    vitesse=(vitesse+force*(dt/masse));
    pos=pos+vitesse*dt;

    Vect2 pos_res = pos;

    if(pos.x < monde.x){
        pos_res.x = monde.x;
    }
    else if(pos.x > (monde.x+monde.w)){
        pos_res.x = (monde.x+monde.w);
    }
    if(pos.y < monde.y){
        pos_res.y = monde.y;
    }
    if(pos.y > (monde.y+monde.h)){
         pos_res.y = (monde.y+monde.h);
    }
    set_rect(pos_res.x,pos_res.y,dim.x,dim.y);
}

void Objet::testRegression() const{
    std::cout<<"\n--- Debut du test de la classe Objet ---\n";

    std::cout<<"Test du constructeur par defaut...";
    Objet obj0;
    assert(obj0.rect.x==0 && obj0.rect.y==0 && obj0.rect.w==0 && obj0.rect.h==0);
    assert(obj0.masse==1 && obj0.vitesse==Vect2(0,0) && obj0.force==Vect2(0,0));
    std::cout<<"ok\n";

    std::cout<<"Test du constructeur";
    Objet obj1(Rectangle(1,1,1,1),Vect2(0,0),Vect2(0,0));
    assert(obj1.rect.x==1 && obj1.rect.y==1 && obj1.rect.w==1 && obj1.rect.h==1);
    assert(obj1.masse==1 && obj1.vitesse==Vect2(0,0) && obj1.force==Vect2(0,0));
    std::cout<<"ok\n";

    std::cout<<"Test du constructeur par copie\n";
    Objet obj2(obj1);
    assert(obj2.rect.x==1 && obj2.rect.y==1 && obj2.rect.w==1 && obj2.rect.h==1);
    assert(obj2.masse==1 && obj2.vitesse==Vect2(0,0) && obj2.force==Vect2(0,0));
    std::cout<<"ok\n";

    std::cout<<"Test des mutateurs ";
    obj1.set_rect(3,2,5,6);
    obj1.set_vitesse(15,22);
    obj1.set_force(2,1);
    assert(obj1.rect.x==3 && obj1.rect.y==2 && obj1.rect.w==5 && obj1.rect.h==6);
    assert(obj1.masse==1 && obj1.vitesse==Vect2(15,22) && obj1.force==Vect2(2,1));
    std::cout<<"ok\n";

    std::cout<<"Test de la fonction update() ";
    for(int i=0;i<20;i++){
        std::cout<<i<<"eme update\n";
        obj1.update();
        obj0.update();
        std::cout<<"obj1 = "<<obj1.rect<<obj1.vitesse<<obj1.force<<"\n";
        std::cout<<"obj0 = "<<obj0.rect<<obj0.vitesse<<obj0.force<<"\n";   /// PROBLEME UPDATE UN ZERO != ZERO
    }
    assert(obj1.rect.x!=3 && obj1.rect.y!=2 && obj1.rect.w==5 && obj1.rect.h==6);
    assert(obj1.vitesse.x!=15 && obj1.vitesse.y!=22 && obj1.force==Vect2(2,1));
    assert(obj0.rect.x==0 && obj0.rect.y==0 && obj0.rect.w==0 && obj0.rect.h==0);
    assert(obj0.vitesse.x!=0 && obj0.vitesse.y!=0 && obj0.force==Vect2(0,0));
    std::cout<<"ok\n";

    std::cout<<"\n--- Fin du test de la classe Objet ---\n";
}