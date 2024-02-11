#ifndef IMAGE_H
#define IMAGE_H
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Image {
private: 
  SDL_Rect src_rect;      // le rectangle de la sous-image 
  SDL_Rect dst_rect;      // le rectangle de l'image dans la fenetre
  SDL_Surface * surface;  // surface de l'image
  SDL_Texture * texture;  // texture de l'image

  bool animated;          // image animé ou non
  int h_anim;             // hauteur d'une animation
  int w_anim;             // largeur d'une animation
  unsigned int nb_anim;   // nombre d'animation dans l'image
  int num_anim;           // numero de l'animation jouée
  int* tab_anim;          // nombre d'image par animation

public :
  /**
   * @brief Constructeur par défaut : initialise les données à nullptr et à 0
  */
  Image();
  
   /**
   * @brief Constructeur : initialise la surface, les rectanlges et determine si l'image est animée
   */
  Image(const std::string filename,SDL_Rect src_r,SDL_Rect dst_r,bool animation = false);


   /**
   * @brief Destructeur : détruit la surface, la texture, 
   */
  ~Image();

    /**
   * @brief Supprime l'ancienne image dans l'instance, et initialise la surface, les rectanlges et determine si l'image est animée
   */
  void chargerImage(const std::string filename,SDL_Rect src_r,SDL_Rect dst_r,bool animation = false);

   /**
   * @brief Accesseur : récupère la surface SDL
   */
  SDL_Surface* get_surface() const;

  /**
   * @brief Accesseur : récupère la texture SDL
   */
  SDL_Texture* get_texture() const;

  /**
   * @brief Accesseur : récupère le rectangle source de l'image
   */
  SDL_Rect get_src_rect() const;

  /**
   * @brief Accesseur : récupère le rectangle destination de l'image
   */
  SDL_Rect get_dst_rect() const;

  /**
   * @brief Accesseur : récupère le numéro de l'animation
   */
  int get_num_anim() const;

  /**
   * @brief Accesseur : 
   */
  int get_h_anim() const;

  /**
   * @brief Accesseur : 
   */
  int get_w_anim() const;

  /**
   * @brief Accesseur : 
   */
  int get_tab_anim(int indice) const;

  /**
   * @brief Mutateur : modifie la texture
   */
  void set_texture(SDL_Texture* t);

   /**
   * @brief Mutateur : modifie le rectangle source
   */
  void set_rect_src (SDL_Rect rs);

   /**
   * @brief Mutateur : modifie le rectangle destination
   */
  void set_rect_dst (SDL_Rect rd);

  /**
   * @brief Mutateur : modifie le numéro de l'animatio,
   */
  void set_num_anim(unsigned int n);

  /**
   * @brief Si l'image est animée, initialise les données requises
   */
  void initAnim(int h1,int w1,int nb_anim1,int num_anim1,unsigned int* tab1);

  /**
   * @brief Remet l'animation à la premiere image
   */
  void resetAnim();

  /**
   * @brief Si l'image est animée, change l'animation jouée
   */
  void switchAnim(int number);

   /**
   * @brief Si l'image est animée, modifie le rectangle source
   */
  void update();
};
#endif