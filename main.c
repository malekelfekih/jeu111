#include <stdlib.h>
#include <stdio.h>
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
#include"perso.c"
#include"perso2.c"
#include"ennemi.c"
#include"fonction.c"
#include"enigf.c"
#include"menupause.c"
#include"game.c"

int main(int argc, char * argv[]) 
{ SDL_Surface *ecran=NULL;

int continuer = 1;
SDL_Event event;
while (continuer)
{
SDL_WaitEvent(&event);
switch(event.type)
{
case SDL_QUIT:
continuer = 0;
}
menu(ecran);

}




}

