#include <iostream>
#include <cassert>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include "PartieSDL.h"
using namespace std;

PartieSDL::PartieSDL(SDL_Renderer * renderer,SDL_DisplayMode t):fin(false),
taille_window(t),ecran(MapSelect),tab(nullptr),nb_image(0),entrainement(false),
temps_debut(0),temps_restant(0),temps_pause(0),temps_entrainement(0),
joueur_t_atq_spe(0),ordi_t_atq_spe(0){

    music_menu = Mix_LoadMUS("./data/music/menu.mp3");
    if (music_menu == nullptr){
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Erreur chargement de la musique : %s", Mix_GetError());
        Mix_CloseAudio();
        SDL_Quit();
        return;
    }
    son_hadoken = Mix_LoadWAV("./data/music/Hadoken.wav");
    if (son_hadoken == nullptr){
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Erreur chargement de la musique : %s", Mix_GetError());
        Mix_CloseAudio();
        SDL_Quit();
        return;
    }
    music_combat1 = Mix_LoadMUS("./data/music/combat1.mp3");
    if (music_combat1 == nullptr){
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Erreur chargement de la musique : %s", Mix_GetError());
        Mix_CloseAudio();
        SDL_Quit();
        return;
    }
    music_combat2 = Mix_LoadMUS("./data/music/combat2.mp3");
    if (music_combat2 == nullptr){
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Erreur chargement de la musique : %s", Mix_GetError());
        Mix_CloseAudio();
        SDL_Quit();
        return;
    }
    music_combat3 = Mix_LoadMUS("./data/music/combat3.mp3");
    if (music_combat3 == nullptr){
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Erreur chargement de la musique : %s", Mix_GetError());
        Mix_CloseAudio();
        SDL_Quit();
        return;
    }
    music_combat4 = Mix_LoadMUS("./data/music/combat4.mp3");
    if (music_combat4 == nullptr){
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Erreur chargement de la musique : %s", Mix_GetError());
        Mix_CloseAudio();
        SDL_Quit();
        return;
    }
    music_fin = Mix_LoadMUS("./data/music/fin_partie.mp3");
    if (music_fin == nullptr){
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Erreur chargement de la musique : %s", Mix_GetError());
        Mix_CloseAudio();
        SDL_Quit();
        return;
    }

    temps_debut = 0;
    temps_restant = 0;
    temps_pause = 0;
    temps_entrainement = 0;

    sel.choix_map = 0;
    sel.choix_perso = 0;
    sel.choix_ordi = 0;
    sel.conf_perso = false;
    sel.conf_perso = false;
    sel.conf_ordi = false;

    tab = new Image [38];

    Image im;
    SDL_Rect rd;
    SDL_Rect rs;

    rd.x = 0; rd.y = 0;
    rd.w = taille_window.w; rd.h = taille_window.h;

    rs.x = 0; rs.y = 0;
    rs.w = 1920; rs.h = 1080;

    /// MENU

    im.chargerImage("./data/menu/PersoSelectMenu.png",rs,rd);           // 0
    ajouterImage(im);

    im.chargerImage("./data/menu/SelectionJoueur.png",rs,rd);           // 1
    ajouterImage(im);

    im.chargerImage("./data/menu/SelectionOrdi.png",rs,rd);             // 2
    ajouterImage(im);
    
    im.chargerImage("./data/menu/FightBouton.png",rs,rd);               // 3
    ajouterImage(im);

    // MAP
    im.chargerImage("./data/map/avion.png",rs,rd);                      // 4
    SDL_Rect mapSrc = {90,0,540,224};
    im.set_rect_src(mapSrc);
    ajouterImage(im);   // 720x224
    
    im.chargerImage("./data/map/quai.png",rs,rd);                       // 5
    im.set_rect_src(mapSrc);
    ajouterImage(im);   // 725x224

    //MENU MAP
    im.chargerImage("./data/menu/MapSelectMenu.png",rs,rd);             // 6
    ajouterImage(im);

    im.chargerImage("./data/menu/SelectionMap.png",rs,rd);              // 7
    ajouterImage(im);

    //BOUTON VALIDER
    im.chargerImage("./data/menu/Valider.png",rs,rd);                   // 8
    ajouterImage(im);

    //MEME CHOIX PERSO 
    im.chargerImage("./data/menu/SelectionRougeEtVert.png",rs,rd);      // 9
    ajouterImage(im);

    //MAP
    im.chargerImage("./data/map/quartier.png",rs,rd);                   // 10
    im.set_rect_src(mapSrc);
    ajouterImage(im);  

    im.chargerImage("./data/map/souk.png",rs,rd);                       // 11
    im.set_rect_src(mapSrc);
    ajouterImage(im);  

    //MENU PAUSE
    im.chargerImage("./data/menu/MenuPause.png",rs,rd);                 // 12
    ajouterImage(im);

    //TXT
    im.chargerImage("./data/menu/TXTMap.png",rs,rd);                    // 13
    ajouterImage(im);

    im.chargerImage("./data/menu/TXTJoueur.png",rs,rd);                 // 14
    ajouterImage(im);

    im.chargerImage("./data/menu/TXTOrdi.png",rs,rd);                   // 15
    ajouterImage(im);

    //PERSO CHOIX

    im.chargerImage("./data/perso/ryu1_Choix.png",rs,rd);               // 16
    ajouterImage(im);

    im.chargerImage("./data/perso/ryu2_Choix.png",rs,rd);               // 17
    ajouterImage(im);

    im.chargerImage("./data/perso/ryu3_Choix.png",rs,rd);               // 18
    ajouterImage(im);

    im.chargerImage("./data/perso/ken1_Choix.png",rs,rd);               // 19
    ajouterImage(im);

    im.chargerImage("./data/perso/ken2_Choix.png",rs,rd);               // 20
    ajouterImage(im);

    im.chargerImage("./data/perso/ken3_Choix.png",rs,rd);               // 21
    ajouterImage(im);

    //ORDI CHOIX

    im.chargerImage("./data/perso/ryu1_Choix.png",rs,rd);               // 22
    ajouterImage(im);

    im.chargerImage("./data/perso/ryu2_Choix.png",rs,rd);               // 23
    ajouterImage(im);

    im.chargerImage("./data/perso/ryu3_Choix.png",rs,rd);               // 24
    ajouterImage(im);

    im.chargerImage("./data/perso/ken1_Choix.png",rs,rd);               // 25
    ajouterImage(im);

    im.chargerImage("./data/perso/ken2_Choix.png",rs,rd);               // 26
    ajouterImage(im);

    im.chargerImage("./data/perso/ken3_Choix.png",rs,rd);               // 27
    ajouterImage(im);

    //TXT
    im.chargerImage("./data/menu/TXTJoueur1.png",rs,rd);                // 28
    ajouterImage(im);

    im.chargerImage("./data/menu/TXTJoueur2.png",rs,rd);                // 29
    ajouterImage(im);

    //COMBAT
    im.chargerImage("./data/combat/JoueurVSJoueur.png",rs,rd);          // 30
    ajouterImage(im);

    im.chargerImage("./data/combat/JoueurVSOrdi.png",rs,rd);            // 31
    ajouterImage(im);

    im.chargerImage("./data/combat/TriangleRouge.png",rs,rd);           // 32
    ajouterImage(im);
    SDL_Rect triangle_rouge_src = {384,532,433-384,578-532};
    tab[32].set_rect_src(triangle_rouge_src);

    im.chargerImage("./data/combat/TriangleVert.png",rs,rd);            // 33
    ajouterImage(im);
    SDL_Rect triangle_vert_src = {(996*taille_window.w)/1920,
                                   (532*taille_window.h)/1080,
                                   ((1044-996)*taille_window.w)/1920,
                                   ((578-532)*taille_window.h)/1080};
    tab[33].set_rect_src(triangle_vert_src);

    //FIN PARTIE

    im.chargerImage("./data/menu/VictoireJoueur1.png",rs,rd);            // 34
    ajouterImage(im);

    im.chargerImage("./data/menu/VictoireJoueur2.png",rs,rd);            // 35
    ajouterImage(im);

    im.chargerImage("./data/menu/FinEntrainement.png",rs,rd);            // 36
    ajouterImage(im);

    im.chargerImage("./data/menu/Egalité.png",rs,rd);                    // 37
    ajouterImage(im);

    police = TTF_OpenFont("./data/font.ttf",10);                        // FONT

    for(int i = 0;i<nb_image;i++){
        if(tab[i].get_texture()==nullptr){
            SDL_Texture* t = SDL_CreateTextureFromSurface(renderer,tab[i].get_surface());
            tab[i].set_texture(t);
        }
    }
}

PartieSDL::~PartieSDL(){
    if(tab != nullptr) delete [] tab;
    Mix_FreeMusic(music_menu);
    Mix_FreeMusic(music_combat1);
    Mix_FreeMusic(music_combat2);
    Mix_FreeMusic(music_combat3);
    Mix_FreeMusic(music_combat4);
    Mix_FreeChunk(son_hadoken);
    Mix_FreeMusic(music_fin);
    TTF_CloseFont( police ); 
}

void PartieSDL::ajouterImage(const Image& i){
    tab[nb_image]=i;
    nb_image++;
}

void PartieSDL::initPartieSDL(bool _entrainement){
    Mix_HaltMusic();
    entrainement = _entrainement;
    joueur.perso.vie = 100;
    ordi.perso.vie = 100;
    fin = false;
    sel.choix_perso = 0;
    sel.choix_ordi = 0;
    sel.choix_map = 0;
    sel.conf_perso = false;
    sel.conf_ordi = false;
    sel.conf_map = false;
    ecran = MapSelect;
    Mix_PlayMusic(music_menu, -1);
}

void PartieSDL::afficherImage(SDL_Renderer * renderer,const Image& i){
    int ok;
    SDL_Rect rs = i.get_src_rect();
    SDL_Rect rd = i.get_dst_rect();
    ok = SDL_RenderCopy(renderer,i.get_texture(),&rs,&rd);
    assert(ok==0);
}

void PartieSDL::afficherImageInverse(SDL_Renderer * renderer,const Image& i){
    int ok;
    SDL_Rect rs = i.get_src_rect();
    SDL_Rect rd = i.get_dst_rect();
    ok = SDL_RenderCopyEx(renderer,i.get_texture(),&rs,&rd,180.0,nullptr,SDL_FLIP_VERTICAL);
    assert(ok==0);
}

bool clique(SDL_Event events,SDL_Rect r){
    return (events.type == SDL_MOUSEBUTTONDOWN && events.button.x>=r.x &&
     events.button.x<=(r.x+r.w) && events.button.y>=r.y && events.button.y<=(r.y+r.h));
}
bool cliqueBtnDown(SDL_Event events,SDL_Scancode t){
    return (events.type == SDL_KEYDOWN && events.key.keysym.scancode==t);
}
bool cliqueBtnUp(SDL_Event events,SDL_Scancode t){
    return (events.type == SDL_KEYUP && events.key.keysym.scancode==t);
}
bool cliqueBtnDown(SDL_Event events,SDL_Keycode t){
    return (events.type == SDL_KEYDOWN && events.key.keysym.sym==t);
}
bool cliqueBtnUp(SDL_Event events,SDL_Keycode t){
    return (events.type == SDL_KEYUP && events.key.keysym.sym==t);
}

void PartieSDL::evenementSelectionMap(SDL_Event events){

    SDL_Rect m1 ;
    m1.x = (438*taille_window.w)/1920;
    m1.y = (245*taille_window.h)/1080;
    m1.w = ((897-438)*taille_window.w)/1920;
    m1.h = ((501-245)*taille_window.h)/1080;

    SDL_Rect m2 ;
    m2.x = (1023*taille_window.w)/1920;
    m2.y = (245*taille_window.h)/1080;
    m2.w = ((1481-1023)*taille_window.w)/1920;
    m2.h = ((501-245)*taille_window.h)/1080;

    SDL_Rect m3 ;
    m3.x = (438*taille_window.w)/1920;
    m3.y = (579*taille_window.h)/1080;
    m3.w = ((897-438)*taille_window.w)/1920;
    m3.h = ((838-579)*taille_window.h)/1080;

    SDL_Rect m4 ;
    m4.x = (1023*taille_window.w)/1920;
    m4.y = (579*taille_window.h)/1080;
    m4.w = ((1481-1023)*taille_window.w)/1920;
    m4.h = ((838-579)*taille_window.h)/1080;

    SDL_Rect ok ;
    ok.x = (799*taille_window.w)/1920;
    ok.y = (909*taille_window.h)/1080;
    ok.w = ((1124-799)*taille_window.w)/1920;
    ok.h = ((1008-909)*taille_window.h)/1080;

    SDL_Rect retour = {0,0,
        (150*taille_window.w)/1920,
        (150*taille_window.h)/1080}; 
    
    if(events.type == SDL_MOUSEBUTTONDOWN){
        //SDL_Log("Clic de souris (%d %d)", events.button.x, events.button.y);
        if(clique(events,retour)){
            fin=true;
        }

        if (!sel.conf_map){
            if (clique(events,m1)){ 
                sel.choix_map = 1;
                SDL_Rect r = {0,0,taille_window.w,taille_window.h};
                tab[7].set_rect_dst(r);
            }
            if (clique(events,m2)){ 
                sel.choix_map = 2;
                SDL_Rect r = {(585*taille_window.w)/1920,
                               0,taille_window.w,taille_window.h};
                tab[7].set_rect_dst(r);
            }
            if (clique(events,m3)){ 
                sel.choix_map = 3;
                SDL_Rect r = {0,
                              (334*taille_window.h)/1080,
                              taille_window.w,taille_window.h};
                tab[7].set_rect_dst(r);
            }
            if (clique(events,m4)){ 
                sel.choix_map = 4;
                SDL_Rect r = {(585*taille_window.w)/1920,
                              (334*taille_window.h)/1080,
                              taille_window.w,taille_window.h};
                tab[7].set_rect_dst(r);
            }
        }
        if (sel.choix_map != 0 && clique(events,ok)){
            ecran=PersoSelect;
            sel.conf_map=true;
        }
    }
    // SDL_Log("Clic de souris (%d %d)", events.button.x, events.button.y); // Coordonnées des clics
}

void PartieSDL::selectionMap(SDL_Renderer * renderer){
    SDL_Rect r = {0,(100*taille_window.h)/1080,taille_window.w,taille_window.h};
    afficherImage(renderer,tab[6]);
    if(sel.choix_map !=0){
        afficherImage(renderer,tab[7]);
        tab[8].set_rect_dst(r);
        afficherImage(renderer,tab[8]);
    }
    if(sel.choix_map==0){
        afficherImage(renderer,tab[13]);
    }
}

void PartieSDL::evenementSelectionPerso(SDL_Event events,SDL_Renderer * renderer){

    SDL_Rect p1 ;
    p1.x = (559*taille_window.w)/1920;
    p1.y = (244*taille_window.h)/1080;
    p1.w = (213*taille_window.w)/1920;
    p1.h = (213*taille_window.h)/1080;

    SDL_Rect p2 ;
    p2.x = (854*taille_window.w)/1920;
    p2.y = (244*taille_window.h)/1080;
    p2.w = (213*taille_window.w)/1920;
    p2.h = (213*taille_window.h)/1080;

    SDL_Rect p3 ;
    p3.x = (1149*taille_window.w)/1920;
    p3.y = (244*taille_window.h)/1080;
    p3.w = (213*taille_window.w)/1920;
    p3.h = (213*taille_window.h)/1080;

    SDL_Rect p4 ;
    p4.x = (559*taille_window.w)/1920;
    p4.y = (504*taille_window.h)/1080;
    p4.w = (213*taille_window.w)/1920;
    p4.h = (213*taille_window.h)/1080;

    SDL_Rect p5 ;
    p5.x = (854*taille_window.w)/1920;
    p5.y = (504*taille_window.h)/1080;
    p5.w = (213*taille_window.w)/1920;
    p5.h = (213*taille_window.h)/1080;

    SDL_Rect p6 ;
    p6.x = (1149*taille_window.w)/1920;
    p6.y = (504*taille_window.h)/1080;
    p6.w = (213*taille_window.w)/1920;
    p6.h = (213*taille_window.h)/1080;

    SDL_Rect fight ;
    fight.x = (753*taille_window.w)/1920;
    fight.y = (797*taille_window.h)/1080;
    fight.w = ((1171-753)*taille_window.w)/1920;
    fight.h = ((945-797)*taille_window.h)/1080;

    SDL_Rect retour = {0,0,
                        (180*taille_window.w)/1920,
                        (150*taille_window.h)/1080};  


    if(events.type == SDL_MOUSEBUTTONDOWN){
        if(clique(events,retour)){
            if(!sel.conf_perso){
                fin = true;
            }
            else if (!sel.conf_ordi){
                sel.conf_perso = false;
                sel.choix_perso = 0;
                sel.choix_ordi = 0;
            }
            else {
                sel.conf_ordi = false;
                sel.choix_ordi = 0;
            }
        }

        if(!sel.conf_perso){
            if (clique(events,p1)){ 
                sel.choix_perso = 1;
                SDL_Rect r = {0,0,taille_window.w,taille_window.h};
                tab[1].set_rect_dst(r);
                SDL_Rect r2 = {0,0,taille_window.w,taille_window.h};
                tab[16].set_rect_dst(r2);
            }
            if (clique(events,p2)){ 
                sel.choix_perso = 2;
                SDL_Rect r = {(296*taille_window.w)/1920,0,taille_window.w,taille_window.h};
                tab[1].set_rect_dst(r);
                SDL_Rect r2 = {0,0,taille_window.w,taille_window.h};
                tab[17].set_rect_dst(r2);
            }
            if (clique(events,p3)){ 
                sel.choix_perso = 3;
                SDL_Rect r = {(591*taille_window.w)/1920,0,taille_window.w,taille_window.h};
                tab[1].set_rect_dst(r);
                SDL_Rect r2 = {0,0,taille_window.w,taille_window.h};
                tab[18].set_rect_dst(r2);
            }
            if (clique(events,p4)){ 
                sel.choix_perso = 4;
                SDL_Rect r = {0,(261*taille_window.h)/1080,taille_window.w,taille_window.h};
                tab[1].set_rect_dst(r);
                SDL_Rect r2 = {0,0,taille_window.w,taille_window.h};
                tab[19].set_rect_dst(r2);
            }
            if (clique(events,p5)){ 
                sel.choix_perso = 5;
                SDL_Rect r = {(296*taille_window.w)/1920,(261*taille_window.h)/1080,taille_window.w,taille_window.h};
                tab[1].set_rect_dst(r);
                SDL_Rect r2 = {0,0,taille_window.w,taille_window.h};
                tab[20].set_rect_dst(r2);
            }
            if (clique(events,p6)){ 
                sel.choix_perso = 6;
                SDL_Rect r = {(591*taille_window.w)/1920,(261*taille_window.h)/1080,taille_window.w,taille_window.h};
                tab[1].set_rect_dst(r);
                SDL_Rect r2 = {0,0,taille_window.w,taille_window.h};
                tab[21].set_rect_dst(r2);
            }

            SDL_Rect r ;
             r.x = (802*taille_window.w)/1920;
             r.y = (910*taille_window.h)/1080;
             r.w = ((1124-802)*taille_window.w)/1920;
             r.h = ((1007-910)*taille_window.h)/1080;
             
            if (sel.choix_perso != 0 && clique(events,r)){
                sel.conf_perso = true;
            }
        }
        else if (!sel.conf_ordi){
            if (clique(events,p1)){
                sel.choix_ordi = 1;
                if (sel.choix_ordi == sel.choix_perso){
                    SDL_Rect r = {0,0,taille_window.w,taille_window.h};
                    tab[9].set_rect_dst(r);
                }
                else {
                    SDL_Rect r2 = {0,0,taille_window.w,taille_window.h};
                    tab[2].set_rect_dst(r2);
                }
                SDL_Rect r2 = {500,0,taille_window.w,taille_window.h};
                tab[22].set_rect_dst(r2);
            }
            if (clique(events,p2)){ 
                sel.choix_ordi = 2;
                if (sel.choix_ordi == sel.choix_perso){
                    SDL_Rect r = {(296*taille_window.w)/1920,0,taille_window.w,taille_window.h};
                    tab[9].set_rect_dst(r);
                }
                else{
                    SDL_Rect r2 = {(296*taille_window.w)/1920,0,taille_window.w,taille_window.h};
                    tab[2].set_rect_dst(r2);
                }
                SDL_Rect r2 = {500,0,taille_window.w,taille_window.h};
                tab[23].set_rect_dst(r2);
            }
            if (clique(events,p3)){ 
                sel.choix_ordi = 3;
                if (sel.choix_ordi == sel.choix_perso){
                    SDL_Rect r = {(591*taille_window.w)/1920,0,taille_window.w,taille_window.h};
                    tab[9].set_rect_dst(r);
                }
                else{
                    SDL_Rect r2 = {(591*taille_window.w)/1920,0,taille_window.w,taille_window.h};
                    tab[2].set_rect_dst(r2);
                }
                SDL_Rect r2 = {500,0,taille_window.w,taille_window.h};
                tab[24].set_rect_dst(r2);
            }
            if (clique(events,p4)){ 
                sel.choix_ordi = 4;
                if (sel.choix_ordi == sel.choix_perso){
                    SDL_Rect r = {0,(261*taille_window.h)/1080,taille_window.w,taille_window.h};
                    tab[9].set_rect_dst(r);
                }
                else{
                    SDL_Rect r2 = {0,(261*taille_window.h)/1080,taille_window.w,taille_window.h};
                    tab[2].set_rect_dst(r2);
                }
                SDL_Rect r2 = {500,0,taille_window.w,taille_window.h};
                tab[25].set_rect_dst(r2);
            }
            if (clique(events,p5)){ 
                sel.choix_ordi = 5;
                if (sel.choix_ordi == sel.choix_perso){
                    SDL_Rect r = {(296*taille_window.w)/1920,(261*taille_window.h)/1080,taille_window.w,taille_window.h};
                    tab[9].set_rect_dst(r);
                }
                else{
                    SDL_Rect r2 = {(296*taille_window.w)/1920,(261*taille_window.h)/1080,taille_window.w,taille_window.h};
                    tab[2].set_rect_dst(r2);
                }
                SDL_Rect r2 = {500,0,taille_window.w,taille_window.h};
                tab[26].set_rect_dst(r2);
            }
            if (clique(events,p6)){ 
                sel.choix_ordi = 6;
                if (sel.choix_ordi == sel.choix_perso){
                    SDL_Rect r = {(591*taille_window.w)/1920,(261*taille_window.h)/1080,taille_window.w,taille_window.h};
                    tab[9].set_rect_dst(r);
                }
                else{
                    SDL_Rect r2 = {(591*taille_window.w)/1920,(261*taille_window.h)/1080,taille_window.w,taille_window.h};
                    tab[2].set_rect_dst(r2);
                }
                SDL_Rect r2 = {500,0,taille_window.w,taille_window.h};
                tab[27].set_rect_dst(r2);
            }

            SDL_Rect r ;
             r.x = (802*taille_window.w)/1920;
             r.y = (910*taille_window.h)/1080;
             r.w = ((1124-802)*taille_window.w)/1920;
             r.h = ((1007-910)*taille_window.h)/1080;

            if (sel.choix_ordi != 0 && clique(events,r)){
                sel.conf_ordi = true;
            }
        }
        else if(clique(events,fight)){
            initCombat(renderer);
            ecran = Partie;
            temps_debut = SDL_GetTicks();
            Mix_HaltMusic();
            srand(time(nullptr));
            int i = rand()%4;
            if(i==0)Mix_PlayMusic(music_combat1,-1);
            else if(i==1)Mix_PlayMusic(music_combat2,-1);
            else if(i==2)Mix_PlayMusic(music_combat3,-1);
            else Mix_PlayMusic(music_combat4,-1);
        }
    }
    if(!entrainement){
        SDL_Rect r= {0,0,taille_window.w,taille_window.h};
        tab[28].set_rect_dst(r);
    }
}

void PartieSDL::selectionPerso(SDL_Renderer * renderer){
    afficherImage(renderer,tab[0]);
    if(sel.choix_perso != 0){
        afficherImage(renderer,tab[1]);
        switch(sel.choix_perso)
        {
            case 1:
                afficherImage(renderer,tab[16]);
                break;
            case 2:
                afficherImage(renderer,tab[17]);
                break;
            case 3:
                afficherImage(renderer,tab[18]);
                break;
            case 4:
                afficherImage(renderer,tab[19]);
                break;
            case 5:
                afficherImage(renderer,tab[20]);
                break;
            case 6:
                afficherImage(renderer,tab[21]);
                break;
        }
        if(!sel.conf_perso){    // afficher bouton confirmer perso
            afficherImage(renderer,tab[8]);
        }
    }
    if(sel.choix_ordi != 0){    
        if(sel.choix_perso != sel.choix_ordi) afficherImage(renderer,tab[2]);
        else afficherImage(renderer,tab[9]); // afficher le carré de selection mouette mouette
        switch(sel.choix_ordi)
        {
            case 1:
                afficherImageInverse(renderer,tab[16]);
                break;
            case 2:
                afficherImageInverse(renderer,tab[17]);
                break;
            case 3:
                afficherImageInverse(renderer,tab[18]);
                break;
            case 4:
                afficherImageInverse(renderer,tab[19]);
                break;
            case 5:
                afficherImageInverse(renderer,tab[20]);
                break;
            case 6:
                afficherImageInverse(renderer,tab[21]);
                break;
        }
        if(!sel.conf_ordi){ // afficher bouton confirmer ordi
            afficherImage(renderer,tab[8]);
        }
    }

    if(entrainement){
        if(sel.conf_perso && sel.conf_ordi){
            afficherImage(renderer,tab[3]);
        }
        if(sel.choix_perso==0){
            afficherImage(renderer, tab[14]);
        }

        if(sel.conf_perso==true && sel.choix_ordi==0){
            afficherImage(renderer, tab[15]);
        }
    }
    else{
        if(sel.conf_perso && sel.conf_ordi){
            afficherImage(renderer,tab[3]);
        }
        if(sel.choix_perso==0){
            afficherImage(renderer, tab[28]);
        }

        if(sel.conf_perso==true && sel.choix_ordi==0){
            afficherImage(renderer, tab[29]);
        }
    }
}

void PartieSDL::initCombat(SDL_Renderer * renderer){
    if(sel.choix_perso == 1)        joueur.initJoueur(1,taille_window);
    else if(sel.choix_perso == 2)   joueur.initJoueur(2,taille_window);
    else if(sel.choix_perso == 3)   joueur.initJoueur(3,taille_window);
    else if(sel.choix_perso == 4)   joueur.initJoueur(4,taille_window);
    else if(sel.choix_perso == 5)   joueur.initJoueur(5,taille_window);
    else if(sel.choix_perso == 6)   joueur.initJoueur(6,taille_window);
    
    if(sel.choix_ordi == 1)         ordi.initOrdi(1,taille_window);
    else if(sel.choix_ordi == 2)    ordi.initOrdi(2,taille_window);
    else if(sel.choix_ordi == 3)    ordi.initOrdi(3,taille_window);
    else if(sel.choix_ordi == 4)    ordi.initOrdi(4,taille_window);
    else if(sel.choix_ordi == 5)    ordi.initOrdi(5,taille_window);
    else if(sel.choix_ordi == 6)    ordi.initOrdi(6,taille_window);

    SDL_Texture * t = SDL_CreateTextureFromSurface(renderer,joueur.im.get_surface());
    SDL_Texture * a = SDL_CreateTextureFromSurface(renderer,joueur.hado.im.get_surface());
    joueur.im.set_texture(t);
    joueur.hado.im.set_texture(a);
    t = SDL_CreateTextureFromSurface(renderer,ordi.im.get_surface());
    a = SDL_CreateTextureFromSurface(renderer,ordi.hado.im.get_surface());
    ordi.im.set_texture(t);
    ordi.hado.im.set_texture(a);
}

void PartieSDL::evenementPartie(SDL_Event events){

    if(cliqueBtnDown(events,SDL_SCANCODE_ESCAPE)){
        ecran = Pause;
        temps_pause = SDL_GetTicks();
    }

    /// PERSO
    if(cliqueBtnDown(events,SDLK_z)){
        joueur.deplacer(haut);
        joueur.jump = true;
    }
    else if(cliqueBtnDown(events,SDLK_q)){
        joueur.deplacer(gauche);

    }
    else if(cliqueBtnDown(events,SDLK_s)){
        joueur.im.resetAnim();
        joueur.deplacer(bas);
        joueur.accroupi = true;
    }
    else if(cliqueBtnDown(events,SDLK_d)){
        joueur.deplacer(droite);
    }
    if(cliqueBtnUp(events,SDLK_q)||cliqueBtnUp(events,SDLK_d)){
        joueur.im.resetAnim();
        joueur.deplacer(rien);
    }
    else if(cliqueBtnUp(events,SDLK_s)){
        joueur.im.resetAnim();
        joueur.accroupi = false;
        joueur.deplacer(rien);
    }
    if(cliqueBtnDown(events,SDLK_e) && joueur.jump == false){
        if(!joueur.attaque){
            joueur.im.resetAnim();
            joueur.attaquer(poing,ordi.perso,ordi.accroupi);
        }
    }
    else if(cliqueBtnDown(events,SDLK_f) && joueur.jump == false){
        if(!joueur.attaque){
            joueur.im.resetAnim();
            joueur.attaquer(pied,ordi.perso,ordi.accroupi);
        }
    }
    else if(cliqueBtnDown(events,SDLK_r) && joueur.jump == false){
        if(!joueur.attaque){
            if(((SDL_GetTicks() - joueur_t_atq_spe)/1000) > 5){
                joueur_t_atq_spe = SDL_GetTicks();
                joueur.im.resetAnim();
                joueur.attaquer(speciale,ordi.perso,ordi.accroupi);
                Mix_PlayChannel(1,son_hadoken,0);
            }
        }
    }

    /// ORDI
    if(!entrainement){
        if(cliqueBtnDown(events,SDLK_l)){
        ordi.deplacer(droite);
        }
        if(cliqueBtnDown(events,SDLK_j)){
            ordi.deplacer(gauche);
        }
        if(cliqueBtnDown(events,SDLK_i)){
            ordi.deplacer(haut);
            ordi.jump = true;
        }
        if(cliqueBtnDown(events,SDLK_k)){
            ordi.im.resetAnim();
            ordi.deplacer(bas);
            ordi.accroupi = true;
        }
        if(cliqueBtnUp(events,SDLK_j)||cliqueBtnUp(events,SDLK_l)){
            ordi.im.resetAnim();
            ordi.deplacer(rien);
        }
        if(cliqueBtnUp(events,SDLK_k)){
            ordi.im.resetAnim();
            ordi.deplacer(rien);
            ordi.accroupi = false;
        }
        if(cliqueBtnDown(events,SDLK_o) && ordi.jump == false){
            if(!ordi.attaque){
                ordi.im.resetAnim();
                ordi.attaquer(poing,joueur.perso,joueur.accroupi);
            }
        }
        else if(cliqueBtnDown(events,SDLK_m) && ordi.jump == false){
            if(!ordi.attaque){
                ordi.im.resetAnim();
                ordi.attaquer(pied,joueur.perso,joueur.accroupi);
            }
        }
        else if(cliqueBtnDown(events,SDLK_p) && ordi.jump == false){
            if(!ordi.attaque){
                if(((SDL_GetTicks() - ordi_t_atq_spe)/1000) > 5){
                    ordi_t_atq_spe = SDL_GetTicks();
                    ordi.im.resetAnim();
                    ordi.attaquer(speciale,ordi.perso,ordi.accroupi);
                }
            }
        }
    }
    if (entrainement){
        if (ordi.perso.vie<=30){
            ordi.perso.vie=100;
        }
    }
}

void PartieSDL::partie(SDL_Renderer * renderer){
    if(sel.choix_map==1) afficherImage(renderer,tab[4]);
    else if(sel.choix_map==2) afficherImage(renderer,tab[5]);
    else if(sel.choix_map==3) afficherImage(renderer,tab[10]);
    else if(sel.choix_map==4) afficherImage(renderer,tab[11]);
    if(joueur.perso.objet.rect.x + joueur.perso.objet.rect.w/2 < 
        ordi.perso.objet.rect.x + ordi.perso.objet.rect.w/2){
        joueur.inverser=false;
        ordi.inverser=false;

        afficherImage(renderer,joueur.im);
        afficherImageInverse(renderer,ordi.im);

        if(joueur.hado.lanceinverse==true){
            afficherImageInverse(renderer,joueur.hado.im);
        }
        else{
            afficherImage(renderer,joueur.hado.im);
            // SDL_Rect h;
            // h.x = joueur.hado.obj.rect.x + joueur.hado.obj.rect.w/4; 
            // h.y = joueur.hado.obj.rect.y + joueur.hado.obj.rect.h/4;
            // h.w = joueur.hado.obj.rect.w/3; 
            // h.h = joueur.hado.obj.rect.h/3;
            // SDL_SetRenderDrawColor(renderer,255,0,0,255);
            // SDL_RenderDrawRect(renderer,&h);
        }
        
        if(ordi.hado.lanceinverse==true){
            afficherImage(renderer,ordi.hado.im);
            // SDL_Rect h;
            // h.x = ordi.hado.obj.rect.x + ordi.hado.obj.rect.w/4; 
            // h.y = ordi.hado.obj.rect.y + ordi.hado.obj.rect.h/4;
            // h.w = ordi.hado.obj.rect.w/3; 
            // h.h = ordi.hado.obj.rect.h/3;
            // SDL_SetRenderDrawColor(renderer,255,0,0,255);
            // SDL_RenderDrawRect(renderer,&h);

        }
        else{
            afficherImageInverse(renderer,ordi.hado.im);
        }
    }
    else{
        joueur.inverser=true;
        ordi.inverser=true;

        afficherImageInverse(renderer,joueur.im);
        if(joueur.hado.lanceinverse==true)
            afficherImageInverse(renderer,joueur.hado.im);
        else
            afficherImage(renderer,joueur.hado.im);
        
        if(ordi.hado.lanceinverse==true)
            afficherImage(renderer,ordi.hado.im);
        else
            afficherImageInverse(renderer,ordi.hado.im);

        afficherImage(renderer,ordi.im);
    }


    SDL_Rect j_bar;
    j_bar.x = (100*taille_window.w)/1920;
    j_bar.y = (50*taille_window.h)/1080;
    j_bar.w = ((800-100)*taille_window.w)/1920;
    j_bar.h = ((100-50)*taille_window.h)/1080;
    SDL_SetRenderDrawColor(renderer,0,0,0,255);
    SDL_RenderFillRect(renderer,&j_bar);

    SDL_Rect o_bar;
    o_bar.x = (1120*taille_window.w)/1920;
    o_bar.y = (50*taille_window.h)/1080;
    o_bar.w = (((800-100)*taille_window.w)/1920);
    o_bar.h = ((100-50)*taille_window.h)/1080;
    SDL_SetRenderDrawColor(renderer,0,0,0,255); 
    SDL_RenderFillRect(renderer,&o_bar);

    SDL_Rect j_vie; 
    j_vie.x = j_bar.x; j_vie.y = j_bar.y; j_vie.w = (j_bar.w*joueur.perso.vie)/100 ; j_vie.h = j_bar.h;
    SDL_SetRenderDrawColor(renderer,255,0,0,255);
    SDL_RenderFillRect(renderer,&j_vie);

    SDL_Rect o_vie;
    o_vie.x = o_bar.x; o_vie.y = o_bar.y; o_vie.w = (o_bar.w*ordi.perso.vie)/100 ; o_vie.h = o_bar.h;
    SDL_SetRenderDrawColor(renderer,0,255,0,255);
    SDL_RenderFillRect(renderer,&o_vie);

    SDL_Rect r = {0,0,taille_window.w,taille_window.h};
    SDL_Rect triangle_rouge_dst = {joueur.perso.objet.rect.x+120,joueur.perso.objet.rect.y-50,433-384,578-532};    
    SDL_Rect triangle_vert_dst = {ordi.perso.objet.rect.x+120,ordi.perso.objet.rect.y-50,433-384,578-532};
    
    if(entrainement){
        tab[31].set_rect_dst(r);
        afficherImage(renderer,tab[31]);
    }
    else{
        tab[30].set_rect_dst(r);
        afficherImage(renderer,tab[30]);
        if(sel.choix_ordi==sel.choix_perso){
            tab[32].set_rect_dst(triangle_rouge_dst);
            tab[33].set_rect_dst(triangle_vert_dst);
            afficherImage(renderer,tab[32]);
            afficherImage(renderer,tab[33]);
        }
    }

    // ----- ----- CHRONO ----- ----- 
    SDL_Color couleur;
    couleur.r = 0; couleur.g = 0; couleur.b = 0; couleur.a = 255;
    SDL_Rect chrono_rect = {(1010*taille_window.w)/1920,
                            (130*taille_window.h)/1080,
                            (300*taille_window.w)/1920,
                            (200*taille_window.h)/1080};
    SDL_Surface * chrono_surface;
    if(!entrainement){
        temps_restant = 60 - ((SDL_GetTicks() - temps_debut)/1000); // 60sec pour une partie
        string chrono_string = to_string((int)temps_restant);
        chrono_surface = TTF_RenderText_Solid( police,chrono_string.c_str(),couleur); 
    }
    else{
        temps_entrainement = ((SDL_GetTicks() - temps_debut)/1000);
        string chrono_string = to_string((int)temps_entrainement);
         chrono_surface = TTF_RenderText_Solid( police,chrono_string.c_str(),couleur); 
    }
    SDL_Texture * chrono_texture = SDL_CreateTextureFromSurface(renderer,chrono_surface);
    SDL_RenderCopy(renderer,chrono_texture,nullptr,&chrono_rect);
    SDL_FreeSurface(chrono_surface);
    SDL_DestroyTexture(chrono_texture);
    // ----- ----- ----- ----- -----

    // ----- ----- DEBUG HITBOX ----- -----
    // SDL_Rect corps_joueur;
    // corps_joueur.x = joueur.perso.objet.rect.x + joueur.perso.objet.rect.w/3; 
    // corps_joueur.y = joueur.perso.objet.rect.y; 
    // corps_joueur.w = joueur.perso.objet.rect.w/3; 
    // corps_joueur.h = joueur.perso.objet.rect.h;

    // SDL_Rect image_joueur;
    // image_joueur.x = joueur.perso.objet.rect.x; 
    // image_joueur.y = joueur.perso.objet.rect.y; 
    // image_joueur.w = joueur.perso.objet.rect.w; 
    // image_joueur.h = joueur.perso.objet.rect.h;

    // SDL_Rect accroupi_joueur;
    // accroupi_joueur.x = joueur.perso.objet.rect.x + joueur.perso.objet.rect.w/3; 
    // accroupi_joueur.y = joueur.perso.objet.rect.y +joueur. perso.objet.rect.h/3; 
    // accroupi_joueur.w = joueur.perso.objet.rect.w/3; 
    // accroupi_joueur.h = 2*(joueur.perso.objet.rect.h/3);

    // SDL_Rect attaque1_joueur;
    // attaque1_joueur.x = joueur.perso.objet.rect.x + joueur.perso.objet.rect.w/2; 
    // attaque1_joueur.y = joueur.perso.objet.rect.y; 
    // attaque1_joueur.w = joueur.perso.objet.rect.w/2; 
    // attaque1_joueur.h = joueur.perso.objet.rect.h/4;

    // SDL_Rect attaque2_joueur;
    // attaque2_joueur.x = joueur.perso.objet.rect.x; 
    // attaque2_joueur.y = joueur.perso.objet.rect.y; 
    // attaque2_joueur.w = joueur.perso.objet.rect.w/2; 
    // attaque2_joueur.h = joueur.perso.objet.rect.h/4;

    // SDL_Rect corps_ordi;
    // corps_ordi.x = ordi.perso.objet.rect.x + ordi.perso.objet.rect.w/3; 
    // corps_ordi.y = ordi.perso.objet.rect.y; 
    // corps_ordi.w = ordi.perso.objet.rect.w/3; 
    // corps_ordi.h = ordi.perso.objet.rect.h;

    // SDL_Rect accroupi_ordi;
    // accroupi_ordi.x = ordi.perso.objet.rect.x + ordi.perso.objet.rect.w/3; 
    // accroupi_ordi.y = ordi.perso.objet.rect.y +ordi. perso.objet.rect.h/3; 
    // accroupi_ordi.w = ordi.perso.objet.rect.w/3; 
    // accroupi_ordi.h = 2*(ordi.perso.objet.rect.h/3);

    // SDL_Rect attaque1_ordi;
    // attaque1_ordi.x = ordi.perso.objet.rect.x + ordi.perso.objet.rect.w/2; 
    // attaque1_ordi.y = ordi.perso.objet.rect.y; 
    // attaque1_ordi.w = ordi.perso.objet.rect.w/2; 
    // attaque1_ordi.h = ordi.perso.objet.rect.h/4;

    // SDL_Rect attaque2_ordi;
    // attaque2_ordi.x = ordi.perso.objet.rect.x; 
    // attaque2_ordi.y = ordi.perso.objet.rect.y; 
    // attaque2_ordi.w = ordi.perso.objet.rect.w/2; 
    // attaque2_ordi.h = ordi.perso.objet.rect.h/4;

    // SDL_SetRenderDrawColor(renderer,0,0,255,255);
    // SDL_RenderDrawRect(renderer,&corps_joueur);
    // SDL_RenderDrawRect(renderer,&image_joueur);
    // SDL_RenderDrawRect(renderer,&accroupi_joueur);
    // SDL_RenderDrawRect(renderer,&attaque1_joueur);
    // SDL_RenderDrawRect(renderer,&attaque2_joueur);

    // SDL_SetRenderDrawColor(renderer,255,0,0,255);
    // SDL_RenderDrawRect(renderer,&corps_ordi);
    // SDL_RenderDrawRect(renderer,&accroupi_ordi);
    // SDL_RenderDrawRect(renderer,&attaque1_ordi);
    // SDL_RenderDrawRect(renderer,&attaque2_ordi);

    // ----- ----- ----- ----- ----- -----
}

void PartieSDL::evenementPause(SDL_Event events){
    SDL_Rect r1 ;
    r1.x = (723*taille_window.w)/1920;
    r1.y = (412*taille_window.h)/1080;
    r1.w = ((1188-723)*taille_window.w)/1920;
    r1.h = ((554-412)*taille_window.h)/1080;

    SDL_Rect r2 ;
    r2.x = (723*taille_window.w)/1920;
    r2.y = (622*taille_window.h)/1080;
    r2.w = ((1188-723)*taille_window.w)/1920;
    r2.h = ((554-412)*taille_window.h)/1080;

    if(cliqueBtnDown(events,SDL_SCANCODE_ESCAPE)||clique(events,r1)){
        ecran = Partie;
        temps_debut += SDL_GetTicks() - temps_pause;
    }
    else if(clique(events,r2)){
        ecran = FinPartie;
        Mix_HaltMusic();
        Mix_PlayMusic(music_fin,-1);
    }
}

void PartieSDL::pause(SDL_Renderer * renderer){
    afficherImage(renderer,tab[12]);
}

void PartieSDL::evenementFinPartie(SDL_Event events){
    SDL_Rect r = {(1273*taille_window.w)/1920,(950*taille_window.h)/1080,
                   (454*taille_window.w)/1920,(71*taille_window.h)/1080};
    if(cliqueBtnDown(events,SDL_SCANCODE_ESCAPE)) fin = true;
    if(clique(events,r)){
        fin = true;
        Mix_HaltMusic();
    }
}

void PartieSDL::finPartie(SDL_Renderer * renderer){
     
    SDL_Color couleur;
    couleur.r = 0; couleur.g = 0; couleur.b = 0; couleur.a = 255;
    SDL_Rect chrono_rect;
    string chrono_string;
    if(entrainement){
        afficherImage(renderer,tab[36]);
        chrono_rect.x = (980*taille_window.w)/1920;
        chrono_rect.y = (430*taille_window.h)/1080;
        chrono_rect.w = (300*taille_window.w)/1920;
        chrono_rect.h = (200*taille_window.h)/1080;
        chrono_string = to_string((int)temps_entrainement);
    }
    else{
        SDL_Rect r = {(200*taille_window.w)/1920,(120*taille_window.h)/1080,taille_window.w,taille_window.h};
        if(joueur.perso.estMort()){
            afficherImage(renderer,tab[35]);
            tab[21+sel.choix_ordi].set_rect_dst(r);
            afficherImage(renderer,tab[21+sel.choix_ordi]);
        }
        else if (ordi.perso.estMort()){
            afficherImage(renderer,tab[34]);
            tab[21+sel.choix_perso].set_rect_dst(r);
            afficherImage(renderer,tab[21+sel.choix_perso]);
        }
        else if (!ordi.perso.estMort() && !joueur.perso.estMort()){
            afficherImage(renderer,tab[37]);
        }
        chrono_rect.x = (1300*taille_window.w)/1920;
        chrono_rect.y = (380*taille_window.h)/1080;
        chrono_rect.w = (300*taille_window.w)/1920;
        chrono_rect.h = (200*taille_window.h)/1080;
        chrono_string = to_string((int)temps_restant);
    }
    SDL_Surface * chrono_surface = TTF_RenderText_Solid( police,chrono_string.c_str(),couleur); 
    SDL_Texture * chrono_texture = SDL_CreateTextureFromSurface(renderer,chrono_surface);
    SDL_RenderCopy(renderer,chrono_texture,nullptr,&chrono_rect);
    SDL_FreeSurface(chrono_surface);
    SDL_DestroyTexture(chrono_texture);
}

bool PartieSDL::verifierFin(){
    return ((joueur.perso.estMort() || ordi.perso.estMort()||
    (60 - (((SDL_GetTicks() - temps_debut)/1000))<=0)) &&(ecran == Partie));
}

void PartieSDL::update(){
    Rectangle r;
    r.x = 0; r.y = 0; r.w = taille_window.w-((6*joueur.im.get_w_anim()*taille_window.w)/1920); 
    r.h = taille_window.h-((6*joueur.im.get_h_anim()*taille_window.h)/1080);
    joueur.update(r,taille_window);
    ordi.update(r,taille_window);

    if(verifierFin()){
        ecran = FinPartie;
        Mix_HaltMusic();
        Mix_PlayMusic(music_fin,-1);
    }

    Rectangle hj;
    hj.x = joueur.hado.obj.rect.x + joueur.hado.obj.rect.w/4; 
    hj.y = joueur.hado.obj.rect.y + joueur.hado.obj.rect.h/4;
    hj.w = joueur.hado.obj.rect.w/3; 
    hj.h = joueur.hado.obj.rect.h/3;

    Rectangle corps_ordi;
    corps_ordi.x = ordi.perso.objet.rect.x + ordi.perso.objet.rect.w/3; 
    corps_ordi.y = ordi.perso.objet.rect.y; 
    corps_ordi.w = ordi.perso.objet.rect.w/3; 
    corps_ordi.h = ordi.perso.objet.rect.h;
    
    Rectangle accroupi_ordi;
    accroupi_ordi.x = ordi.perso.objet.rect.x + ordi.perso.objet.rect.w/3; 
    accroupi_ordi.y = ordi.perso.objet.rect.y +ordi. perso.objet.rect.h/3; 
    accroupi_ordi.w = ordi.perso.objet.rect.w/3; 
    accroupi_ordi.h = 2*(ordi.perso.objet.rect.h/3);

    if(!ordi.accroupi){
        if(hj.collision(corps_ordi)||corps_ordi.collision(hj)){
            joueur.hado.obj.rect.x = 3000;
            joueur.hado.obj.set_vitesse(0,0);
            ordi.perso.retirerVie(DEGUAT_SPE);
        }
    }
    else{
        if(hj.collision(accroupi_ordi)||accroupi_ordi.collision(hj)){
            joueur.hado.obj.rect.x = 3000;
            joueur.hado.obj.set_vitesse(0,0);
            ordi.perso.retirerVie(DEGUAT_SPE);
        }
    }
    
    Rectangle ho;
    ho.x = ordi.hado.obj.rect.x + ordi.hado.obj.rect.w/4; 
    ho.y = ordi.hado.obj.rect.y + ordi.hado.obj.rect.h/4;
    ho.w = ordi.hado.obj.rect.w/3; 
    ho.h = ordi.hado.obj.rect.h/3;

    Rectangle corps_joueur;
    corps_ordi.x = joueur.perso.objet.rect.x + joueur.perso.objet.rect.w/3; 
    corps_ordi.y = joueur.perso.objet.rect.y; 
    corps_ordi.w = joueur.perso.objet.rect.w/3; 
    corps_ordi.h = joueur.perso.objet.rect.h;
    
    Rectangle accroupi_joueur;
    accroupi_joueur.x = joueur.perso.objet.rect.x + joueur.perso.objet.rect.w/3; 
    accroupi_joueur.y = joueur.perso.objet.rect.y +joueur. perso.objet.rect.h/3; 
    accroupi_joueur.w = joueur.perso.objet.rect.w/3; 
    accroupi_joueur.h = 2*(joueur.perso.objet.rect.h/3);
    if(ho.collision(hj)||hj.collision(ho)){
            ordi.hado.obj.rect.x = 3000;
            ordi.hado.obj.set_vitesse(0,0);
            joueur.hado.obj.rect.x = 3000;
            joueur.hado.obj.set_vitesse(0,0);
        }
    if(!joueur.accroupi){
        if(ho.collision(corps_ordi)||corps_ordi.collision(ho)){
            ordi.hado.obj.rect.x = 3000;
            ordi.hado.obj.set_vitesse(0,0);
            joueur.perso.retirerVie(DEGUAT_SPE);
        }
    }
    else{
        if(ho.collision(accroupi_joueur)||accroupi_joueur.collision(ho)){
            ordi.hado.obj.rect.x = 3000;
            ordi.hado.obj.set_vitesse(0,0);
            joueur.perso.retirerVie(DEGUAT_SPE);
        }
    }

    joueur.synchrohadoken();
    ordi.synchrohado();
}

void PartieSDL::afficherPartieSDL(SDL_Renderer * renderer){
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
    switch (ecran)
    {
    case PersoSelect: selectionPerso(renderer);
        break;

    case MapSelect: selectionMap(renderer);
        break;
    
    case Partie: partie(renderer);
        break;
    
    case Pause: pause(renderer);
        break;

    case FinPartie: finPartie(renderer);
        break;
    }
    SDL_RenderPresent(renderer);
    SDL_Delay(100);	    
}

void PartieSDL::evenementPartieSDL(SDL_Event events,SDL_Renderer * renderer){
    switch (ecran)
    {
    case PersoSelect: evenementSelectionPerso(events,renderer);
        break;

    case MapSelect: evenementSelectionMap(events);
        break;

    case Partie: evenementPartie(events);
        break;

    case Pause: evenementPause(events);
        break;

    case FinPartie: evenementFinPartie(events);
        break;
    }
}

void PartieSDL::run(SDL_Renderer * renderer,bool entrainement){
    initPartieSDL(entrainement);

    // ----- ----- DEBUG COMBAT ----- -----
    // sel.choix_map = 1;
    // sel.conf_map = true;
    // sel.choix_perso = 4;
    // sel.conf_perso = true;
    // sel.choix_ordi = 5;
    // sel.conf_ordi = true;
    // initCombat(renderer);
    // ecran = Partie;
    // ----- ----- ----- ----- ----- -----

    SDL_Event events;

	while (!fin) {
    
        while (SDL_PollEvent(&events)) {
            evenementPartieSDL(events,renderer);
        }

        afficherPartieSDL(renderer);
        update();
    }
    Mix_HaltMusic();
}