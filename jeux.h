
#ifndef JEUX_H_INCLUDED
#define JEUX_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_rotozoom.h>


typedef struct perso
{
	SDL_Rect position;
	SDL_Surface *image0;
	SDL_Surface *image1;
	SDL_Surface *image2;
	SDL_Surface *image3;
	SDL_Surface *imagea;
        SDL_Surface *imageb;
        SDL_Surface *imagec;
      
}perso;

typedef struct vie 
{
	int nb;
	SDL_Rect position;
	SDL_Surface *fond1;
	SDL_Surface *fond2;
	SDL_Surface *fond3;
	SDL_Surface *fond4;
}vie;



typedef struct 
{
	SDL_Rect position;
	SDL_Surface *fond;
}map;

typedef struct ennemis
{
	SDL_Rect position;
	SDL_Surface *fond1;
	SDL_Surface *fond2;
	SDL_Surface *fonda;
	SDL_Surface *fondb;
}ennemis;
typedef struct 
{
	SDL_Rect position;
	SDL_Surface *fond1;
	SDL_Surface *fond2;	
}anubis;
typedef struct 
{
 SDL_Surface * img;
 SDL_Rect 	p;
}enigme;
void initialiserperso2(perso *perso);
void init_enigme(enigme * e) ;
 void generate_afficher (SDL_Surface * screen  , char image [],enigme *e,int *alea);
 int solution_e (char image []) ;
int resolution (int * running,int *run);
void afficher_resultat (SDL_Surface * screen,int s,int r,enigme *en) ;
int enigme1(SDL_Surface **ecran,int *victory, int * score);
void initialiservie(vie *vie);
void DrawScore(SDL_Surface *screen, int *score,TTF_Font *police);
void initialiseranubis(anubis* anubis);
void afficheranubis(anubis anubis,SDL_Surface *ecran,SDL_Rect camera);
void initialiserennemi(ennemis *ennemi);
ennemis mouvennemi(ennemis ennemi,int d,SDL_Rect camera,int *q,int *w,int *y);
int splitennemi(int y);
void affichervie(vie *vie,SDL_Surface *ecran);
void afficherennemi(ennemis ennemi,SDL_Surface *ecran,int y);
void initialiserperso(perso *perso);
int direction(SDL_Event event,int *continuer);
perso mouvement(perso pers,int d, SDL_Rect camera);
void afficherfond(map map,SDL_Rect camera,SDL_Surface *ecran);
SDL_Rect scrolling(int d,SDL_Rect camera, perso pers);
void collision(perso *p,SDL_Surface* pSurface, int d);
void initialiservie2(vie *vie);
void direction2(SDL_Event event,int *continuer, int *d, int *d1);
SDL_Color GetPixel (SDL_Surface* pSurface , int x , int y);
int collisione(perso *p,ennemis *e );
int CCollision(SDL_Rect a, SDL_Rect b,SDL_Rect camera,int direction);
void initialiserfond(map *map);
int collision_Parfaite(SDL_Surface *calque,perso perso,int decalage,int d);
int mouv(int d,int x);
void initialiserfond2(map *map);
void player(SDL_Surface **ecran);
void afficherperso(perso perso,SDL_Surface *ecran,int x);
SDL_Rect scrolling2(int d,SDL_Rect camera,perso pers);
void initialiserfond4(map *map);
void afficherfond2(map map,SDL_Rect camera,SDL_Surface *ecran);
  void newgame(SDL_Surface **ecran);
void game2(SDL_Surface *ecran,int save);
int quitscreen(SDL_Surface **ecran,perso P,SDL_Rect camera,int  score );
void menu (SDL_Surface * ecran);
void  game1(SDL_Surface *ecran,int test);
void collisionennemi(perso *perso,ennemis *ennemi,SDL_Rect *camera,vie *vie);
 void oneortwo(SDL_Surface **ecran);
void initialiserfond3(map *map);
void initialiserperso1(perso *perso);
void  game1p2(SDL_Surface *ecran,int test);
void DrawScore1(SDL_Surface *screen, int* score,TTF_Font *police);
void affichervie2(vie *vie , SDL_Surface *ecran);
void afficherfond3(map map,SDL_Rect camera,SDL_Surface *ecran);
void roto(SDL_Surface *screen,SDL_Surface *image, SDL_Surface *rotation ,SDL_Rect rect);
#endif
