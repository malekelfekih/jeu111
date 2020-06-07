#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_rotozoom.h>
#include "jeux.h"
#include <time.h>
void initialiserperso1(perso *perso)
{
perso->position.x =2 ;
perso->position.y =500;
perso->image0 = IMG_Load("personnage/01.png");
perso->image1 = IMG_Load("personnage/11.png");
perso->image2 = IMG_Load("personnage/22.png");
perso->image3 = IMG_Load("personnage/33.png");
perso->imagea = IMG_Load("personnage/a1.png");
perso->imageb = IMG_Load("personnage/b1.png");
perso->imagec = IMG_Load("personnage/c1.png");
}


void afficherfond2(map map,SDL_Rect camera,SDL_Surface *ecran)
{
SDL_BlitSurface(map.fond,&camera, ecran,&map.position);
}

void afficherfond3(map map,SDL_Rect camera,SDL_Surface *ecran)
{
SDL_BlitSurface(map.fond,&camera, ecran,&map.position);
}
void initialiserfond3(map *map)
{
map->position.x = 0 ;
map->position.y = 0 ;
map->position.w = 0 ;
map->position.h = 400 ;
map->fond = IMG_Load("back2.png");
}
void initialiserfond2(map *map)
{
map->position.x =0 ;
map->position.y = 400 ;
map->position.w =1300 ;
map->position.h = 400 ;
map->fond = IMG_Load("back2.png");
}
SDL_Rect scrolling2(int d,SDL_Rect camera,perso pers)
{
if(camera.x<=0) camera.x=0;
if(camera.x>=8000) camera.x=8000;
if(d==1&&pers.position.x>=600)
{
camera.x=camera.x+20;
}
if(d==2&&pers.position.x<=600)
{
camera.x=camera.x-20;
}
}
void direction2(SDL_Event event,int *continuer, int *d, int *d1)
{ int keys[322]={0};
switch(event.type)
    {
        case SDL_KEYDOWN:
            keys[event.key.keysym.sym]=1;
            break;
     case SDL_KEYUP:
            keys[event.key.keysym.sym]=0;
            break;
} 
		if(keys[SDLK_q])
		{*d1=2;	}
                   

		if(keys[SDLK_d])
		*d1=1; 
			

		if(keys[SDLK_z])
		*d1=3;	
                    	
              if(keys[SDLK_s])
		*d1=4; 
	      if(keys[SDLK_LEFT])
		*d=2;	
                if(keys[SDLK_RIGHT])    	
		*d=1; 
		if(keys[SDLK_UP])
		*d=3;	
                  if(keys[SDLK_DOWN])
		*d=4; 
			
    

} 
