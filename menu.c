
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_rotozoom.h>
#include"jeux.h"
#include <time.h>

void menu (SDL_Surface * ecran)
    {SDL_Surface  * imageDeFond = NULL, *imageDeFond1= NULL, * affiche[2]={NULL}, * affiche1[2]={NULL} , * affiche2[2]={NULL} ;
    SDL_Rect positionFond, positionAffiche, positionAffiche1, positionAffiche2,positionFond1;
   SDL_Rect positionoption;
  SDL_Rect posText;
SDL_Surface *optionz= NULL,*back= NULL,*sound_on=NULL,*sound_off=NULL,*FULLSCREEN[2]={NULL};
int sound=0;
SDL_Rect positionback,positionsound,positionsound2,positionf,p;
SDL_Surface *text = NULL,*text2 = NULL;
    SDL_Event event;
    int continuer = 1;
TTF_Font *font;
 SDL_Surface *animation[20];
   char tab_animation[20];
int q;

SDL_Color couleur={0,0,102};
p.x=5;
p.y=5;
   positionback.x =0;
    positionback.y=0;

    positionsound.x = 450;
    positionsound.y=350;

 positionsound2.x = 800;
positionsound2.y=350;

    positionFond.x = 0;
    positionFond.y = 0;
    positionAffiche.x = 550;
    positionAffiche.y = 240;
    positionoption.x=0;
     positionoption.y=0;

    positionAffiche1.x = 550;
    positionAffiche1.y = 360;

    positionAffiche2.x = 550;
    positionAffiche2.y = 480;
     posText.x =500;
      posText.y =50;
positionf.x=620;
positionf.y=550;

    //SDL_Init(SDL_INIT_VIDEO);
 TTF_Init();
    ecran = SDL_SetVideoMode(1280, 730, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Lost in Egypt", NULL);
    imageDeFond =IMG_Load("menu/bg.png");
   
    affiche[0] = SDL_LoadBMP("menu/paly1.bmp");
    affiche1[0] = SDL_LoadBMP("menu/option1.bmp");
    font = TTF_OpenFont("de.ttf",90);
    affiche2[0]= SDL_LoadBMP("menu/quit1.bmp");
      for (q=0;q<4;q++) 
{
sprintf(tab_animation,"animation%d.png",q+1);
animation[q]=IMG_Load(tab_animation);    
}
q=0;
   int a=0,b=0,c=0,j=0;
optionz=IMG_Load("menu/op.png");
sound_on=IMG_Load("menu/son.png");
sound_off=IMG_Load("menu/sonn.png");
back=IMG_Load("menu/backb.png");
affiche[1] = SDL_LoadBMP("menu/paly2.bmp");
    affiche1[1] = SDL_LoadBMP("menu/option2.bmp");
    affiche2[1] = SDL_LoadBMP("menu/quit2.bmp");
text = TTF_RenderText_Blended(font, "LOST IN EGYPT ", couleur);
text2=TTF_RenderText_Blended(font, "OPTION", couleur);
int test=0;
int page=1;
  FULLSCREEN[0]=IMG_Load("menu/on.png");
 FULLSCREEN[1]=IMG_Load("menu/off.png");
    //musique
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) {
      printf("%s", Mix_GetError());
    }
    Mix_Music * musique;
    musique = Mix_LoadMUS("song.mp3");
    Mix_Chunk *click;
    click =Mix_LoadWAV("ButtonClick.wav");
    Mix_PlayMusic(musique,-1);
    //endmusique
SDL_BlitSurface(imageDeFond, NULL, ecran, & positionFond);
SDL_BlitSurface(affiche[0], NULL, ecran, & positionAffiche);
SDL_BlitSurface(affiche1[0], NULL, ecran, & positionAffiche1);
 SDL_BlitSurface(affiche2[0], NULL, ecran, & positionAffiche2);
SDL_BlitSurface(text, NULL, ecran, &posText);
int fullscreen=0;
int i=0;
q=0;
 while (continuer!=0)
    {
       SDL_PollEvent( & event) ;
        switch(event.type)
        {
        case SDL_QUIT:
            continuer = 0;
            break;


        case SDL_KEYDOWN:

           { switch(event.key.keysym.sym)

            {

            case SDLK_KP1:
 Mix_PlayChannel(-1,click,0);  
                
                    i=1;
       a=1;
       b=0;
       c=0;
break;

                   case SDLK_KP2:
 Mix_PlayChannel(-1,click,0);  
       i=2;           
       a=0;
       b=1;
       c=0;             
break;
   case SDLK_KP3:
 Mix_PlayChannel(-1,click,0);  
                
  i=3;
   a=0;
       b=0;
       c=1; 
break;

   
case SDLK_a:
page=3;
break;

}
            
            }
case SDL_MOUSEBUTTONUP:
  if  (event.button.x>0 && event.button.x<104 && event.button.y> 0 && event.button.y<100 &&event.button.button==SDL_BUTTON_LEFT)
 {if(page==2)
 { page=1;
}
 
}
 if (event.button.x>800 && event.button.x<880 && event.button.y> 350&& event.button.y<400 && page==2&&event.button.button==SDL_BUTTON_LEFT)
 {if(sound==1)
Mix_VolumeMusic(0);
sound=0;
 }
 if (event.button.x>450 && event.button.x<500 && event.button.y> 350&& event.button.y<450 && page==2&&event.button.button==SDL_BUTTON_LEFT)
{if(sound==0)
Mix_VolumeMusic(128);
sound=1;
}
 else if  (event.button.x > 550 && event.button.x < 810 && event.button.y > 360 && event.button.y <450 && page==1&& event.button.button==SDL_BUTTON_LEFT) 
 page=2;

 else if (event.button.x >550 && event.button.x <=810 && event.button.y >=480 && event.button.y <630&&page==1&&event.button.button==SDL_BUTTON_LEFT)
 {exit(0);}
 else if (event.button.x > 550 && event.button.x < 810 && event.button.y >=240 && event.button.y < 450 && page==1 &&event.button.button==SDL_BUTTON_LEFT)
{
   
newgame(&ecran);
}
 
 break;


      case SDL_MOUSEMOTION:
          if (event.button.x > 550 && event.button.x < 810 && event.button.y >240 && event.button.y < 400 )
            { if(page==1)
               { i=1;
              Mix_PlayChannel(-1,click,0);}               
            }
         
            else if (event.button.x > 550 && event.button.x <810&& event.button.y > 360 && event.button.y <480 ) 
            {    if(page==1)
                {i=2;
                Mix_PlayChannel(-1,click,0); }
                 
            }
          
            else if (event.button.x >550 && event.button.x <=810 && event.button.y >=480 && event.button.y <570) 
            {   if(page==1)
                  {i=4;
                   Mix_PlayChannel(-1,click,0);}
                     
            
            }
            
  
break;

}

if(page==1)  
    {

if(i==1)
     { a=1;
       b=0;
       c=0;

        }

        if(i==2)
        { 
             b=1;
           a=0;
         c=0;

        }
        if(i==4)
        {        c=1; 
         a=0;
       b=0;
  
        }

 SDL_BlitSurface(imageDeFond, NULL, ecran, & positionFond);
 SDL_BlitSurface(animation[q],NULL,ecran,&p);
 q=q+1;
if(q==4)
q=0;
SDL_BlitSurface(text, NULL, ecran, &posText);
SDL_BlitSurface(affiche[a], NULL, ecran, & positionAffiche);
SDL_BlitSurface(affiche1[b], NULL, ecran, & positionAffiche1);
 SDL_BlitSurface(affiche2[c], NULL, ecran, & positionAffiche2);
SDL_Flip(ecran);
}

if(page==2)
{ 
SDL_BlitSurface(optionz, NULL, ecran, & positionFond);
  SDL_BlitSurface(back, NULL, ecran, & positionback);
SDL_BlitSurface(text2, NULL, ecran, &posText);
SDL_BlitSurface(sound_on,NULL,ecran,&positionsound);
SDL_BlitSurface(sound_off,NULL,ecran,&positionsound2);
				
if (fullscreen==0)
					{
					 SDL_BlitSurface(FULLSCREEN[0],NULL,ecran,&positionf);
					}
					else 
					{
					SDL_BlitSurface(FULLSCREEN[1],NULL,ecran,&positionf);
					}

 SDL_Flip(ecran);
}

 } 


   TTF_CloseFont(font);
      TTF_Quit();
      Mix_FreeChunk(click);
      SDL_FreeSurface(imageDeFond);
for (q=0;i<4;q++) 
            {
          SDL_FreeSurface(animation[q+1]);  
            }
      SDL_FreeSurface(affiche[0]);
      SDL_FreeSurface(affiche1[0]);
      SDL_FreeSurface(affiche2[0]);
      Mix_FreeMusic(musique);
SDL_FreeSurface(sound_on);
SDL_FreeSurface(sound_off);
      Mix_CloseAudio();
      //SDL_Quit();

}




 void oneortwo(SDL_Surface **ecran)
{
SDL_Surface* aff2=IMG_Load("menu/oneplayer.png");
	SDL_Surface* aff3=IMG_Load("menu/twoplayers.png");
	SDL_Surface* aff1=IMG_Load("menu/players.png");
	SDL_Surface* bg=IMG_Load("menu/masr.png");
     
	
            SDL_Rect pq;
	*ecran = SDL_SetVideoMode(1000,700, 32, SDL_HWSURFACE | SDL_DOUBLEBUF );  
          
	 pq.x=220;
         pq.y=420;
        SDL_BlitSurface(bg,NULL, *ecran,NULL);
       SDL_BlitSurface(aff1,NULL, *ecran,&pq);
	
	 int continuer=1;
	SDL_Flip(*ecran);
	SDL_Event event;
	while(continuer)
	{SDL_WaitEvent(&event);
		switch(event.type)
		{
			case SDL_MOUSEMOTION : 
			{
				if(event.motion.x>230 && event.motion.x<452 && event.motion.y>420 && event.motion.y<504)
				{
					SDL_BlitSurface(bg,NULL, *ecran,NULL);
					  SDL_BlitSurface(aff2,NULL, *ecran,&pq);
	                             
	
					
					SDL_Flip(*ecran);
				}
				else if(event.motion.x>521 && event.motion.x<743 && event.motion.y>420 && event.motion.y<504)
				{
					SDL_BlitSurface(bg,NULL, *ecran,NULL);
					  SDL_BlitSurface(aff3,NULL, *ecran,&pq);
	                         SDL_Flip(*ecran);
	
				}
				else 
				{
					SDL_BlitSurface(bg,NULL,* ecran,NULL);
				        SDL_BlitSurface(aff1,NULL,* ecran,&pq);
	                             
	
					SDL_Flip(*ecran);
				}
			}
			break;
			case SDL_KEYDOWN :
			{
				if(event.key.keysym.sym==SDLK_q)
				{
					continuer=0;
				}
			}
			break;
			case SDL_MOUSEBUTTONDOWN :
			{
				if(event.button.x>230 && event.button.x<452 && event.button.y>420 && event.button.y<504)
				{
					 game2(*ecran,0); 	
                                      
				}
				else if(event.button.x>521 && event.button.x<743 && event.button.y>420 && event.button.y<504)
				{
				   player(ecran);
                                            
				}
			}
			break;
		}
	}
}


void player(SDL_Surface **ecran)
{
SDL_Surface* aff2=IMG_Load("player1.png");
	SDL_Surface* aff3=IMG_Load("player2.png");
	SDL_Surface* bg=IMG_Load("menu/masr.png");
     
	
            SDL_Rect p1,p2;
	*ecran = SDL_SetVideoMode(1000,700, 32, SDL_HWSURFACE | SDL_DOUBLEBUF );  
          
	
         p1.x=220;
         p1.y=420;
          p2.x=521;
         p2.y=420;
        SDL_BlitSurface(bg,NULL, *ecran,NULL);
        SDL_BlitSurface(aff2,NULL, *ecran,&p1);
        SDL_BlitSurface(aff3,NULL, *ecran,&p2);
	 int continuer=1;
	SDL_Flip(*ecran);
	SDL_Event event;
	while(continuer)
	{SDL_WaitEvent(&event);
		switch(event.type)
		{
		case SDL_KEYDOWN :
			{
				if(event.key.keysym.sym==SDLK_q)
				{
					exit(0);
				}
			}
			break;
			case SDL_MOUSEBUTTONDOWN :
			{
				if(event.button.x>230 && event.button.x<452 && event.button.y>420 && event.button.y<504)
				{
                                       game1p2(*ecran,0);
                                      
				}
				else if(event.button.x>521 && event.button.x<743 && event.button.y>420 && event.button.y<504)
				{
				    game1(*ecran,0); 	
                                      
				}
			}
			break;
		


}
	}






}

  void newgame(SDL_Surface **ecran)
{
SDL_Surface* aff3=IMG_Load("menu/newgame.png");
	SDL_Surface* aff2=IMG_Load("menu/loadgame.png");
	SDL_Surface* aff1=IMG_Load("menu/game.png");
	SDL_Surface* bg=IMG_Load("menu/masr.png");
     
	
            SDL_Rect pq;
	*ecran = SDL_SetVideoMode(1000,700, 32, SDL_HWSURFACE | SDL_DOUBLEBUF );  
          
	 pq.x=220;
         pq.y=420;
        SDL_BlitSurface(bg,NULL, *ecran,NULL);
       SDL_BlitSurface(aff1,NULL, *ecran,&pq);
	
	 int continuer=1;
	SDL_Flip(*ecran);
	SDL_Event event;
	while(continuer)
	{SDL_WaitEvent(&event);
		switch(event.type)
		{
			case SDL_MOUSEMOTION : 
			{
				if(event.motion.x>230 && event.motion.x<452 && event.motion.y>420 && event.motion.y<504)
				{
					SDL_BlitSurface(bg,NULL, *ecran,NULL);
					  SDL_BlitSurface(aff2,NULL, *ecran,&pq);
	                             
	
					
					SDL_Flip(*ecran);
				}
				else if(event.motion.x>521 && event.motion.x<743 && event.motion.y>420 && event.motion.y<504)
				{
					SDL_BlitSurface(bg,NULL, *ecran,NULL);
					  SDL_BlitSurface(aff3,NULL, *ecran,&pq);
	                         
	                                      SDL_Flip(*ecran);
				}
				else 
				{
					SDL_BlitSurface(bg,NULL,* ecran,NULL);
				        SDL_BlitSurface(aff1,NULL,* ecran,&pq);
	                             
	
					SDL_Flip(*ecran);
				}
			}
			break;
			case SDL_KEYDOWN :
			{
				if(event.key.keysym.sym==SDLK_q)
				{
					continuer=0;
				}
			}
			break;
			case SDL_MOUSEBUTTONDOWN :
			{
				if(event.button.x>230 && event.button.x<452 && event.button.y>420 && event.button.y<504)
				{
					oneortwo(ecran);
                                      
				}
				else if(event.button.x>521 && event.button.x<743 && event.button.y>420 && event.button.y<504)
				{
					game1(*ecran,1); 
				}
			}
			break;
		}
	}
}


			

    
int  quitscreen(SDL_Surface **ecran,perso P,SDL_Rect camera,int  score )
{
	SDL_Surface* aff2=IMG_Load("menu/quit2.png");
	SDL_Surface* aff3=IMG_Load("menu/quit3.png");
	SDL_Surface* aff1=IMG_Load("menu/quit1.png");
	SDL_Surface* question=IMG_Load("menu/question.png");
        SDL_Surface* bg=IMG_Load("q.png");
	FILE* f=NULL;
            SDL_Rect pquestion,pq;
	
          pquestion.x=250;
          pquestion.y=250;
          
	 pq.x=220;
         pq.y=420;
        SDL_BlitSurface(bg,NULL, *ecran,NULL);
       SDL_BlitSurface(aff1,NULL, *ecran,&pq);
	SDL_BlitSurface(question,NULL, *ecran,&pquestion);
	 int continuer=1;
	SDL_Flip(*ecran);
	SDL_Event event;
	while(continuer)
	{SDL_WaitEvent(&event);
		switch(event.type)
		{
			case SDL_MOUSEMOTION : 
			{
				if(event.motion.x>230 && event.motion.x<452 && event.motion.y>420 && event.motion.y<504)
				{
					SDL_BlitSurface(bg,NULL, *ecran,NULL);
					  SDL_BlitSurface(aff2,NULL, *ecran,&pq);
	                              SDL_BlitSurface(question,NULL, *ecran,&pquestion);
	
					
					SDL_Flip(*ecran);
				}
				else if(event.motion.x>521 && event.motion.x<743 && event.motion.y>420 && event.motion.y<504)
				{
					SDL_BlitSurface(bg,NULL, *ecran,NULL);
					  SDL_BlitSurface(aff3,NULL, *ecran,&pq);
	                         SDL_BlitSurface(question,NULL, *ecran,&pquestion);
	
				}
				else 
				{
					SDL_BlitSurface(bg,NULL,* ecran,NULL);
				        SDL_BlitSurface(aff1,NULL,* ecran,&pq);
	                              SDL_BlitSurface(question,NULL,* ecran,&pquestion);
	
					SDL_Flip(*ecran);
				}
			}
			break;
			case SDL_KEYDOWN :
			{
				if(event.key.keysym.sym==SDLK_q)
				{
					continuer=0;
				}
			}
			break;
			case SDL_MOUSEBUTTONDOWN :
			{
				if(event.button.x>230 && event.button.x<452 && event.button.y>420 && event.button.y<504)
				{
					continuer=0;
                                       menu(*ecran);
				}
				else if(event.button.x>521 && event.button.x<743 && event.button.y>420 && event.button.y<504)
				{
					f=fopen("savedgame.txt","w");
	                             fprintf(f," %hd %hd %hd %hd     \n",P.position.x,P.position.y,camera.x,score);
				
					fclose(f);
					
				   continuer=0;
                                 menu(*ecran);
					
				}
			}
			break;
		}
	}
}


