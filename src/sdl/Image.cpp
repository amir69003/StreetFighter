#include "Image.h"
#include <cassert> 
#include <fstream>
#include <iostream>

Image::Image():surface(nullptr),texture(nullptr),animated(false),
h_anim(0),w_anim(0),nb_anim(0),num_anim(0),tab_anim(nullptr){}

Image::Image(const std::string filename,SDL_Rect src_r,SDL_Rect dst_r,bool animation):
src_rect(src_r),dst_rect(dst_r),surface(nullptr),texture(nullptr),animated(animation),
h_anim(0),w_anim(0),nb_anim(0),num_anim(0),tab_anim(nullptr){
    surface = IMG_Load(filename.c_str());
    if(animation){
         Uint32 colorkey = SDL_MapRGB(surface->format, 255, 0, 255);
        SDL_SetColorKey(surface, SDL_TRUE, colorkey);
    }
    if (surface == nullptr) {
        std::cout<<"Erreur lors du chargement de "<< filename << std::endl;
        exit(1);
    }
}

void Image::chargerImage(const std::string filename,SDL_Rect src_r,SDL_Rect dst_r,bool animation){
    animated = animation; 
    src_rect = src_r;
    dst_rect = dst_r;

    if(tab_anim!=nullptr) delete [] tab_anim;
    tab_anim = nullptr;
    
    surface = IMG_Load(filename.c_str());
    if(animation){
         Uint32 colorkey = SDL_MapRGB(surface->format, 255, 0, 255);
        SDL_SetColorKey(surface, SDL_TRUE, colorkey);
    }
    if (surface == nullptr) {
        std::cout<<"Erreur lors du chargement de "<< filename << std::endl;
        exit(1);
    }
}

SDL_Surface* Image::get_surface()const{ return surface; }

SDL_Texture* Image::get_texture()const{ return texture; }

SDL_Rect Image::get_src_rect()const{ return src_rect; }

SDL_Rect Image::get_dst_rect()const{ return dst_rect; }

int Image::get_num_anim()const{ return num_anim; }

int Image::get_h_anim()const{ return h_anim; }

int Image::get_w_anim()const{ return w_anim; }

int Image::get_tab_anim(int indice)const{ return tab_anim[indice]; }


void Image::set_texture(SDL_Texture* t){ texture = t; }

void Image::set_rect_src(SDL_Rect rs){ src_rect = rs; }

void Image::set_rect_dst(SDL_Rect rd){ dst_rect = rd; }

void Image::set_num_anim(unsigned int n){ num_anim = n; }


void Image::initAnim(int h1,int w1,int nb_anim1,int num_anim1,unsigned int* tab1){
    animated = true;
    h_anim=h1; w_anim=w1;
    nb_anim = nb_anim1;
    num_anim = num_anim1;
    if (tab_anim != nullptr) delete [] tab_anim;
    tab_anim = new int [nb_anim];
    for(unsigned int i=0;i<nb_anim;i++){
      tab_anim[i] = tab1[i];
    }
}

void Image::resetAnim(){
    src_rect.x=0;
}

void Image::switchAnim(int number){ 
    num_anim = number;
    src_rect.y = num_anim*h_anim;
}

void Image::update(){
    if(animated){
        src_rect.x = (src_rect.x+w_anim)%(tab_anim[num_anim]*w_anim);  
    }
}

Image::~Image(){
    //if(surface!=nullptr) SDL_FreeSurface(surface);
    if(texture!=nullptr) SDL_DestroyTexture(texture);
    if(tab_anim!=nullptr) delete [] tab_anim;
    surface=nullptr;
    texture=nullptr;
    tab_anim=nullptr;
}