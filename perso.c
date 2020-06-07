
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_rotozoom.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include"jeux.h"


void initialiserperso(perso *perso)
{
perso->position.x =2 ;
perso->position.y =300;
perso->image0 = IMG_Load("personnage/0.png");
perso->image1 = IMG_Load("personnage/1.png");
perso->image2 = IMG_Load("personnage/2.png");
perso->image3 = IMG_Load("personnage/3.png");
perso->imagea = IMG_Load("personnage/a.png");
perso->imageb = IMG_Load("personnage/b.png");
perso->imagec = IMG_Load("personnage/c.png");
}
void initialiserperso2(perso *perso)
{
perso->position.x =0 ;
perso->position.y =400;
perso->image0 = IMG_Load("personnage/P0.png");
perso->image1 = IMG_Load("personnage/P1.png");
perso->image2 = IMG_Load("personnage/P2.png");
perso->image3 = IMG_Load("personnage/P3.png");
perso->imagea = IMG_Load("personnage/Pa.png");
perso->imageb = IMG_Load("personnage/Pb.png");
perso->imagec = IMG_Load("personnage/Pc.png");
}
int direction(SDL_Event event,int *continuer)
{
int d;
SDL_PollEvent(&event);
switch(event.type)
    {
        case SDL_QUIT:
            *continuer = 0;
  		break;
	case SDL_KEYDOWN:

            switch (event.key.keysym.sym)
            {
 		case SDLK_ESCAPE:
		    continuer=0;
			break ;

		case SDLK_LEFT :
		d=2;	
                    	break ;

		case SDLK_RIGHT :
		d=1; 
			break ;

		case SDLK_UP :
		d=3;	
                    	break ;

		case SDLK_DOWN :
		d=4; 
			break ;
	    }
		break;
    }
return d;
}
int mouv(int d,int x)
{
switch (d)
{
case 0:
if(x>0&&x<5)
x=1;
if(x>4&&x<9)
x=5;
	break;
case 1:

switch(x)
{
case 0:
x=1;
	break;
case 1:
x=2;
	break;
case 2:
x=3;
	break;
case 3:
x=4;
	break;
case 4:
x=1;
	break;
default:
x=1;
}
	break ;

case 2 :
switch(x)
{
case 0:
x=5;
	break;
case 5:
x=6;
	break;
case 6:
x=7;
	break;
case 7:
x=8;
	break;
case 8:
x=5;
	break;
default:
x=5;
}
	break;
case 3 :
x=0;
	break ;
case 4 :
{if(x>0&&x<5)
x=1;
if(x>4&&x<9)
x=5;}
	break ;
}	
return x ;
}

void afficherperso(perso perso,SDL_Surface *ecran,int x)
{
switch(x)
{
case 0:
SDL_BlitSurface(perso.image0,NULL, ecran,&perso.position);
	break ;
case 1:
SDL_BlitSurface(perso.image1,NULL, ecran,&perso.position);
	break ;
case 2:
SDL_BlitSurface(perso.image2,NULL, ecran,&perso.position);
	break ;
case 3:
SDL_BlitSurface(perso.image1,NULL, ecran,&perso.position);
	break ;
case 4:
SDL_BlitSurface(perso.image3,NULL, ecran,&perso.position);
	break ;
case 5:
SDL_BlitSurface(perso.imagea,NULL, ecran,&perso.position);
	break ;
case 6:
SDL_BlitSurface(perso.imageb,NULL, ecran,&perso.position);
	break ;
case 7:
SDL_BlitSurface(perso.imagea,NULL, ecran,&perso.position);
	break ;
case 8:
SDL_BlitSurface(perso.imagec,NULL, ecran,&perso.position);
	break ;
}
}

 perso mouvement(perso pers,int d, SDL_Rect camera)
{ 
if(pers.position.x>=940)
pers.position.x-=20;
if(pers.position.x<=0)
pers.position.x+=20;
if((d==1 && pers.position.x<600)|| (d==1 && camera.x>=8000))
{
pers.position.x=pers.position.x+20;
}

if ((d==2 && pers.position.x>600)  || (d==2 && camera.x<=0))
{
pers.position.x=pers.position.x-20;
}
if(d==3 && pers.position.y<600)
{
pers.position.y-=20;
}
if(d==4 && pers.position.y<600){
pers.position.y+=20;
}

return pers;
}



