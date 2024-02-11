#include"Vect2.h"
#include<iostream>
#include<cassert>

Vect2::Vect2():x(0.0),y(0.0){}

Vect2::Vect2(float _x,float _y):x(_x),y(_y){}

Vect2::Vect2(const Vect2& v):x(v.x),y(v.y){}

std::ostream& operator<< (std::ostream& flux,const Vect2& v){
    flux<<"("<<v.x<<","<<v.y<<")";
    return flux;
}

Vect2& Vect2::operator=(const Vect2 &v){
    x=v.x;  y=v.y;
    return *this;
}

Vect2 Vect2::operator+(const Vect2 &v)const{
    return Vect2(x+v.x,y+v.y);
}

Vect2 Vect2::operator-(const Vect2 &v)const{
    return Vect2((x-v.x),(y-v.y));
}

Vect2 Vect2::operator*(const float &a)const{
    return Vect2(x*a,y*a);
}

bool Vect2::operator==(const Vect2 &v) const{
    return (x==v.x && y==v.y);
}

void Vect2::testRegression() const{
    std::cout<<"\n--- Debut du test de la classe Vect2 ---\n";

    std::cout<<"Test du constructeur par défaut ... ";
    Vect2 v0;
    assert(v0.x==0 && v0.y==0);
    std::cout<<"ok\n";
    std::cout<<"v0 = "<<v0<<"\n";

    std::cout<<"Test du constructeur ... ";      
    Vect2 v1(1,2);                          
    assert(v1.x==1 && v1.y==2);
    std::cout<<"ok\n";
    std::cout<<"v1 = "<<v1<<"\n";

    std::cout<<"Test du constructeur par copie ... ";
    Vect2 v2(v1);
    assert(v2.x==1 && v2.y==2);
    std::cout<<"ok\n";
    std::cout<<"v2 = "<<v2<<"\n";
    
    std::cout<<"Test de l'operateur ==\n";
    std::cout<<v1<<" == "<<v2<<" ? ";
    assert(v2==v1);
    std::cout<<"ok\n";

    std::cout<<"Test de l'operateur = et test de l'operateur + ...";
    Vect2 v3 = v1+v2;
    assert( v3.x==(v1.x+v2.x) && v3.y==(v1.y+v2.y));
    std::cout<<"ok\n";
    std::cout<<"v3 = "<<v3<<"\n";

    std::cout<<"Test de l'operateur - ... ";
    Vect2 v4 = v3-v2;                           
    assert(v4==v1);
    assert(v4==v2);
    std::cout<<"ok\n";
    std::cout<<"v4 = "<<v4<<"\n";


    std::cout<<"Test de l'operateur * ... ";
    Vect2 v5 = v2*3;                            
    assert(v5.x==3 && v5.y==6);       
    std::cout<<"ok\n";
    std::cout<<"v5 = "<<v5<<"\n";
    std::cout<<"--- Fin du test de la classe Vect2 ---\n";
}