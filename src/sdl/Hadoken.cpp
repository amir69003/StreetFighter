#include"Hadoken.h"
using namespace std;

void Hadoken::updatehad(const Rectangle& monde){          
    assert(obj.masse>0.0);
    Vect2 pos(obj.rect.x,obj.rect.y);
    Vect2 dim(obj.rect.w,obj.rect.h);
    obj.vitesse=(obj.vitesse+obj.force*(0.1/obj.masse));
    pos=pos+obj.vitesse*0.1;

    Vect2 pos_res = pos;

    if(pos.x < monde.x-500){
        pos_res.x = monde.x-500;
    }
    else if(pos.x > (monde.x+monde.w+500)){
        pos_res.x = (monde.x+monde.w+500);
    }
    if(pos.y < monde.y){
        pos_res.y = monde.y;
    }
    /*
    if(pos.x==adversaire.x)
    {
        if(lanceinverse)
            pos_res.x=monde.x-300;
        else
            pos_res.x=monde.x+monde.w+300;
    }
    */   
    if(pos.y > (monde.y+monde.h)){
         pos_res.y = (monde.y+monde.h);
    }
    obj.set_rect(pos_res.x,pos_res.y,dim.x,dim.y);
}
