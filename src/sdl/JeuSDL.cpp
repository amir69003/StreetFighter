#include "JeuSDL.h"
#include <iostream>
#include <cassert>
using namespace std;

JeuSDL::JeuSDL(bool fullscreen,unsigned int dimx,unsigned int dimy):
renderer(nullptr),window(nullptr),ecran(mainMenu),music(nullptr),
tab(nullptr),nb_image(0){

    assert(dimx>0 && dimy>0);
    // INITIALISATION DE LA SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << endl;SDL_Quit();exit(1);
    }
    int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
    if( !(IMG_Init(imgFlags) & imgFlags)) {
        cout << "Erreur lors de l'initialisation de la SDL_image : " << IMG_GetError() << endl;SDL_Quit();exit(1);
    }
    if (TTF_Init() < 0){
        cout << "Erreur lors de l'initialisation de la SDL_ttf : " << IMG_GetError() << endl;SDL_Quit();exit(1);
    }

    // CREATION DE LA FENETRE
    if(fullscreen){
        window = SDL_CreateWindow("Street Fighter", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, dimx, dimy, SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN_DESKTOP);
    }
    else {
        window = SDL_CreateWindow("Street Fighter", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, dimx, dimy, SDL_WINDOW_SHOWN);
    }
    if (window == NULL) {
        cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << endl; SDL_Quit(); exit(1);
    }
    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

    // TAILLE DE LA FENETRE
    if (SDL_GetCurrentDisplayMode(0, &taille_window) != 0)
    {
        std::cerr << "Erreur lors de la récup de taille_window : " << SDL_GetError() << std::endl;SDL_Quit();exit(1);
    }

    // CHARGEMENT DES IMAGES
    chargerTabImage();

    // INITIALISATION DE SDL_MIXER
    if (Mix_OpenAudio(96000, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) < 0) // création de la configuration de la carte son
    {
        SDL_Log("Erreur initialisation SDL_mixer : %s", Mix_GetError());
        Mix_CloseAudio();
        SDL_Quit();
    }

    // CHARGEMENT DES MUSIQUES
    music = Mix_LoadMUS("./data/music/menu.mp3");
    if (music == nullptr)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Erreur chargement de la musique : %s", Mix_GetError());
        Mix_CloseAudio();
        SDL_Quit();
        return;
    }
}

void JeuSDL::ajouterImage(const Image& i){
    tab[nb_image]=i;
    nb_image++;
}

void JeuSDL::chargerTabImage(){

    tab = new Image [10];

    Image im;
    SDL_Rect rd;
    SDL_Rect rs;

    rd.x = 0; rd.y = 0;
    rd.w = taille_window.w; rd.h = taille_window.h;
    
    rs.x = 0; rs.y = 0;
    rs.w = 1920; rs.h = 1080;
    im.chargerImage("./data/menu/MainMenu.png",rs,rd); // 0
    ajouterImage(im);

    for(int i = 0;i<nb_image;i++){
        if(tab[i].get_texture()==nullptr){
            SDL_Texture* t = SDL_CreateTextureFromSurface(renderer,tab[i].get_surface());
            tab[i].set_texture(t);
        }
    }
}

void JeuSDL::afficherImage(const Image& i){
    int ok;
    SDL_Rect rs = i.get_src_rect();
    SDL_Rect rd = i.get_dst_rect();
    ok = SDL_RenderCopy(renderer,i.get_texture(),&rs,&rd);
    assert(ok==0);
}

void JeuSDL::updateTabImage(){
    for(unsigned int i=0;i<nb_image;i++){
        tab[i].update();
    }
}

void JeuSDL::afficherJeuSDL(typeEcran e){
    
    switch (ecran){
        case intro:
            SDL_Rect r;
            r.x = 0; r.y = 0; r.w = taille_window.w; r.h = taille_window.h;
            SDL_SetRenderDrawColor(renderer,255,0,0,255);
            SDL_RenderFillRect(renderer,&r);
            break;

        case mainMenu:
            afficherImage(tab[0]);
            break;
    }
}
// amir le bg
void JeuSDL::run(){

    PartieSDL p (renderer,taille_window);

    SDL_Event events;
	bool fin = false;

    SDL_Rect jouer ;
    jouer.x = (975*taille_window.w)/1920;
    jouer.y = (450*taille_window.h)/1080;
    jouer.w = ((1715-975)*taille_window.w)/1920;
    jouer.h = ((580-450)*taille_window.h)/1080;

    SDL_Rect entrainement ;
    entrainement.x = (975*taille_window.w)/1920;
    entrainement.y = (638*taille_window.h)/1080;
    entrainement.w = ((1715-975)*taille_window.w)/1920;
    entrainement.h = ((580-450)*taille_window.h)/1080;

    SDL_Rect quitter ;
    quitter.x = (975*taille_window.w)/1920;
    quitter.y = (820*taille_window.h)/1080;
    quitter.w = ((1715-975)*taille_window.w)/1920;
    quitter.h = ((950-820)*taille_window.h)/1080;

    bool mus = true;
    
	while (!fin) {
        if(mus){
            Mix_PlayMusic(music, -1);
            mus = false;
        }
        
		while (SDL_PollEvent(&events)) {

            if (events.window.event == SDL_WINDOWEVENT_CLOSE) fin = true; // la croix de fermeture en mode fenetre 
            //if (events.type == SDL_KEYDOWN && events.key.keysym.scancode==SDL_SCANCODE_ESCAPE) fin = true;

            if(ecran == mainMenu){
                switch (events.type)
                {
                case SDL_MOUSEBUTTONDOWN:
                    //SDL_Log("Clic de souris (%d %d)", events.button.x, events.button.y); // Coordonnées des clics

                    if (clique(events,jouer)){ 
                        p.run(renderer,false);
                        mus = true;
                    }
                    if (clique(events,entrainement)){ 
                        p.run(renderer,true);
                        mus = true;
                    }
                    if (clique(events,quitter)){
                        fin=true;
                    }
                    break;
                }
            }
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);
       
        afficherJeuSDL(ecran);

        SDL_RenderPresent(renderer);
        SDL_Delay(150);
	}
}
JeuSDL::~JeuSDL(){
    delete [] tab;
    tab = nullptr;
    if(renderer != nullptr) SDL_DestroyRenderer(renderer);
    if(window != nullptr) SDL_DestroyWindow(window);
    if(music != nullptr) Mix_FreeMusic(music);
    renderer = nullptr;
    window = nullptr;
    music = nullptr;
    Mix_CloseAudio();
    TTF_Quit(); 
    SDL_Quit();
}
