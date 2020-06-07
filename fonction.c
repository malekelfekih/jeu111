#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_rotozoom.h>
#include "jeux.h"
#include <time.h>
void afficherfond(map map,SDL_Rect camera,SDL_Surface *ecran)
{
SDL_BlitSurface(map.fond,&camera, ecran,NULL);
}

SDL_Rect scrolling(int d,SDL_Rect camera,perso pers)
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
 
return camera ;
}

void initialiserfond(map *map)
{
map->position.x = 0 ;
map->position.y = 0 ;
map->position.w = 0 ;
map->position.h = 400 ;
map->fond = IMG_Load("back1.png");
}

void initialiserfond4(map *map)
{
map->position.x = 0 ;
map->position.y = 0 ;
map->position.w = 0 ;
map->position.h = 400 ;
map->fond = IMG_Load("back3.png");
}
void DrawScore1(SDL_Surface *screen, int* score,TTF_Font *police)
{   SDL_Surface *fond1;
        char actualScore[100];
        SDL_Color color;
        color.r = 255 ;
        color.g = 255 ;
        color.b = 255 ;
        sprintf (actualScore," score :%d",*score);
        SDL_Rect pospoints;
        pospoints.x=350;
        pospoints.y=400;
        fond1 = TTF_RenderText_Blended(police,actualScore,color);
        SDL_BlitSurface	(fond1,NULL,screen,&pospoints);
}
void DrawScore(SDL_Surface *screen, int* score,TTF_Font *police)
{   SDL_Surface *fond1;
        char actualScore[100];
        SDL_Color color;
        color.r = 255 ;
        color.g = 255 ;
        color.b = 255 ;
        sprintf (actualScore," score :%d",*score);
        SDL_Rect pospoints;
        pospoints.x=350;
        pospoints.y=10;
        fond1 = TTF_RenderText_Blended(police,actualScore,color);
        SDL_BlitSurface	(fond1,NULL,screen,&pospoints);
      
}
void initialiservie2(vie *vie)
{
vie->nb=3;
vie->position.x =0;
vie->position.y = 400;
vie->fond1 = IMG_Load("vie/vie11.png");
vie->fond2 = IMG_Load("vie/vie22.png");
vie->fond3 = IMG_Load("vie/vie33.png");
}


void affichervie(vie *vie , SDL_Surface *ecran)
{
if(vie->nb==3)
{
SDL_BlitSurface(vie->fond1,NULL, ecran,&vie->position);

}
if(vie->nb==2)
{
SDL_BlitSurface(vie->fond2,NULL, ecran,&vie->position);
 
}
if(vie->nb==1)
{
SDL_BlitSurface(vie->fond3,NULL, ecran,&vie->position);

}
if(vie->nb==0)
{
SDL_Flip(ecran);
SDL_Delay(2000);
menu(ecran);

}


}


 void initialiservie(vie *vie)
{
vie->nb=3;
vie->position.x =0;
vie->position.y = 0;
vie->fond1 = IMG_Load("vie/vie1.png");
vie->fond2 = IMG_Load("vie/vie2.png");
vie->fond3 = IMG_Load("vie/vie3.png");
}




SDL_Color  GetPixel ( SDL_Surface* pSurface, int x , int y)
{
    SDL_Color color;
    Uint32 col = 0 ;
    if (x >= 0 && y >= 0)
    {
        //determine position
        char* pPosition = ( char* ) pSurface->pixels ;

        //offset by y
        pPosition += ( pSurface->pitch * y ) ;

        //offset by x
        pPosition += ( pSurface->format->BytesPerPixel * x ) ;

        //copy pixel data
        memcpy ( &col , pPosition , pSurface->format->BytesPerPixel ) ;

        //convert color
    }
    SDL_GetRGB ( col , pSurface->format , &color.r , &color.g , &color.b ) ;
    return ( color ) ;
}

int collision_Parfaite(SDL_Surface *calque,perso perso,int decalage,int d)
{

  SDL_Color col;
  if(d==1)//imin
  {
    col=GetPixel(calque,perso.position.x+perso.image0->w +decalage,perso.position.y+(perso.image0->h/2));
  }
else  if(d==2)//issarr
  {
    col=GetPixel(calque,perso.position.x +decalage,perso.position.y+(perso.image0->h/2));
  }
else  if(d==3)//lfou9
  {
    col=GetPixel(calque,perso.position.x+(perso.image0->w/2)+decalage ,perso.position.y);
  }
else  if(d==4)//louta
  {
    col=GetPixel(calque,perso.position.x+(perso.image0->w/2) +decalage,perso.position.y+perso.image0->h);
  }
  printf("%d    %d   %d\n",col.r,col.b,col.g );
if ((col.r==0)&&(col.b==0)&&(col.g==0))
{
  return 1;
}
else return 0;
}
void collisionennemi(perso *perso,ennemis *ennemi,SDL_Rect *camera,vie *vie)
{

if((((perso->position.x+perso->image0->w > ennemi->position.x)&&(perso->position.x+perso->image0->w < ennemi->position.x+ennemi->fond1->w))||((perso->position.x < ennemi->position.x+ennemi->fond1->w)&&(perso->position.x > ennemi->position.x)))/*&&perso->position.y==255*/)
if(perso->position.y==ennemi->position.y)
{
SDL_Delay(100);
ennemi->position.x = 500 ;
perso->position.x = 2 ;
perso->position.y = 300 ;
camera->x=0;

vie->nb--;


}
}






