#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_rotozoom.h>
#include"jeux.h"
#include <time.h>
void roto(SDL_Surface *screen,SDL_Surface *image, SDL_Surface *rotation ,SDL_Rect rect)
{
	int tempsActuel = 0; int tempsPrecedent = 0; int done;
	Uint32 oldTime = SDL_GetTicks();
	done = 1; int angle = 0;
	while(done){
		angle += 2;
		
		rotation =rotozoomSurface(image, angle, 1.5, 1);
		SDL_BlitSurface(rotation , NULL, screen, &rect); 
		SDL_Flip(screen);        
		SDL_FreeSurface(rotation);
		if(SDL_GetTicks() - oldTime > 600){
			done = 0;
		}

    }
}
void init_enigme(enigme * e)
{
	e->p.x=0;
	e->p.y=0;	
	e->img=NULL;
}

 void generate_afficher (SDL_Surface * screen  , char image [],enigme *e,int *alea)
{ 
	

   *alea = 1+rand()%3;

 sprintf(image ,"enigmefichier/%d.png",*alea);
  e->img = IMG_Load(image);
  SDL_BlitSurface(e->img,NULL,screen,&(e->p)) ;
   SDL_Flip(screen) ;
}





 int solution_e (char image [])
 {
 	int solution =0 ;
 	
 	if(strcmp(image,"enigmefichier/1.png")==0)
 	{
             solution =1 ;
 	}
 	else  	if(strcmp(image,"enigmefichier/2.png")==0)
 	{
 		solution =2;

 	}
 	else 	if(strcmp(image,"enigmefichier/3.png")==0)
 	{
 		solution =1;	
 	}
 	return solution;
 }

int resolution (int * running,int *run )
{
	SDL_Event event ;
  int r=0 ;
	SDL_PollEvent(&event);
	switch(event.type)
	{
		  case SDL_QUIT:
			        *running= 0 ;
                *run = 0;
				break ;

       case SDL_KEYDOWN : 
            switch( event.key.keysym.sym )
                {
			  case  SDLK_a: 
			   r= 1;
			   break ;
			   case  SDLK_b :
			   r= 2;
			   break;
			   case SDLK_c: 
			   r=3 ;
			   break;
		}
       break ;

                 
	}
  return r ;
}
 
 void afficher_resultat (SDL_Surface * screen,int s,int r,enigme *en)
 {
 
 	if (r==s)
 	{
 		en->img=IMG_Load("enigmefichier/00.png");
 		SDL_BlitSurface(en->img, NULL, screen, &(en->p)) ;
        	SDL_Flip(screen);
        	SDL_Delay(3000);
               roto(screen,en->img,en->img ,en->p);
 	}
 	else
 	{
 		en->img=IMG_Load("enigmefichier/11.png");
 		SDL_BlitSurface(en->img, NULL, screen, &(en->p)) ;
        	SDL_Flip(screen);
        	SDL_Delay(3000);
               roto(screen,en->img,en->img ,en->p);
 	}
 }


int enigme1(SDL_Surface **ecran,int *victory, int *score)
{ 
	enigme  e;
	int s,r,run =1,running=1,alea;
	char image[30]="";
	SDL_Event event;
            char chrono[16];
  TTF_Font *police;
  int  t1=0, t2=0;
           SDL_Surface  *texte =  NULL; 
   SDL_Color noir = {255,255,180,0}, rouge = {100,0,0};
    	srand(time(NULL));
 SDL_Rect post;
 post.x=750;
 post.y=10;
 TTF_Init(); 
 police = TTF_OpenFont("Takota.ttf", 50);
   
	init_enigme(&e);
	
	 while (run)
	 {t1 = SDL_GetTicks();  
          t2 = SDL_GetTicks()-t1;     
        sprintf(chrono, "%d:%d", t2/1000/60%60, t2/1000%60);
         texte = TTF_RenderText_Shaded(police, chrono, rouge,noir);
	     running=1,r=0 ;
	     SDL_PollEvent(&event);
           switch(event.type)
            {
              case SDL_QUIT:
                run = 0;
			  break ;
            }	
      generate_afficher ( *ecran  , image ,&e,&alea) ;
			s=solution_e (image );
			do{

                        
			r=resolution (&running,&run);
			}while((r>3 || r<1) && running!=0) ;
      	while(running){    
                     
                    
				 afficher_resultat (*ecran,s,r,&e) ;
					if (r!=s)
 {(*victory)--;
(*score)-=20;}
   if(r==s)
 {(*score)+=20;}
 if (*score==40){
                
SDL_Flip(*ecran);
SDL_Delay(2000);
menu(*ecran);

        }

if (*victory==1)
{SDL_Flip(*ecran);
SDL_Delay(2000);
menu(*ecran);

}

			      	 SDL_WaitEvent(&event);
					running=0;
					run=0;
                    
                     
 } 
SDL_BlitSurface(texte, NULL, *ecran,&post);	
   }




TTF_Quit();
	return 0;
}


