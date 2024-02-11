#include "Rectangle.h"
#include <cassert>

Rectangle::Rectangle():x(0.0),y(0.0),w(0.0),h(0.0){}

Rectangle::Rectangle(float _x,float _y,float _w,float _h):x(_x),y(_y),w(_w),h(_h){}

Rectangle::Rectangle(const Rectangle& r):x(r.x),y(r.y),w(r.w),h(r.h){}

bool Rectangle::collision(const Rectangle& r){
    return( r.x>=x && r.x<=(x+w) && r.y>=y && r.y<=(y+h));
}

std::ostream& operator<< (std::ostream& flux,const Rectangle& r){
    flux<<"("<<r.x<<","<<r.y<<";"<<r.w<<","<<r.h<<")";
    return flux;
}

void Rectangle::testRegression() const {
    std::cout<<"\n--- Debut du test de la classe Rectangle ---\n";

    std::cout<<"Test du constructeur par défaut...";
    Rectangle r0;
    assert(r0.x==0 && r0.y==0 && r0.w==0 && r0.h==0);
    std::cout<<"ok\n";

    std::cout<<"Test du constructeur...";
    Rectangle r1 (2,2,8,10);
    std::cout<<"r1 = "<<r1<<"\n";
    assert(r1.x==2 && r1.y==2 && r1.w==8 && r1.h==10);
    std::cout<<"ok\n";


    Rectangle r2 (1,1,4,5);
    std::cout<<"r2 = "<<r2<<"\n";
    assert(r2.x==1 && r2.y==1 && r2.w==4 && r2.h==5);

    std::cout<<"Test de la fonction collision()\n";
    if(r2.collision(r1)) std::cout<<"r2 est dans r1...ok\n";
    else std::cout<<"r2 n'est pas dans r1...PAS OK\n";

    std::cout<<"\n--- Fin du test de la classe Rectangle ---\n";
}