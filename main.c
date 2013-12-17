/*
** main.c for my_watch in /Users/BQN_T/Documents/cours/projet/perso/Montre binaire
**
** Made by Thibaut Bourquin
** Login   <bourqu_t@etna-alternance.net>
**
** Started on  Wed Sep  25 22:09:17 2013 Thibaut Bourquin
** Last update Wed Sep  25 22:09:17 2013 Thibaut Bourquin
*/

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <time.h>
#include "my.h"

void def_pos_sec(SDL_Rect *position_sec, SDL_Surface *support, SDL_Surface **seconde)
{
	position_sec[0].x = support->w / 2 - seconde[0]->w / 2;
    position_sec[0].y = support->h / 2 - seconde[0]->h / 2 - 240;
    position_sec[1].x = support->w / 2 - seconde[1]->w / 2 + 240;
    position_sec[1].y = support->h / 2 - seconde[1]->h / 2;
    position_sec[2].x = support->w / 2 - seconde[2]->w / 2;
    position_sec[2].y = support->h / 2 - seconde[2]->h / 2 + 240;
    position_sec[3].x = support->w / 2 - seconde[3]->w / 2 - 240;
    position_sec[3].y = support->h / 2 - seconde[3]->h / 2;
    position_sec[4].x = support->w / 2 - seconde[4]->w / 2;
    position_sec[4].y = support->h / 2 - seconde[4]->h / 2 - 180;
    position_sec[5].x = support->w / 2 - seconde[5]->w / 2 + 180;
    position_sec[5].y = support->h / 2 - seconde[5]->h / 2;
}

void def_pos_min(SDL_Rect *position_min, SDL_Surface *support, SDL_Surface **minute)
{
	position_min[0].x = support->w / 2 - minute[0]->w / 2;
    position_min[0].y = support->h / 2 - minute[0]->h / 2 + 180;
    position_min[1].x = support->w / 2 - minute[1]->w / 2 - 180;
    position_min[1].y = support->h / 2 - minute[1]->h / 2;
    position_min[2].x = support->w / 2 - minute[2]->w / 2;
    position_min[2].y = support->h / 2 - minute[2]->h / 2 - 120;
    position_min[3].x = support->w / 2 - minute[3]->w / 2 + 120;
    position_min[3].y = support->h / 2 - minute[3]->h / 2;
    position_min[4].x = support->w / 2 - minute[4]->w / 2;
    position_min[4].y = support->h / 2 - minute[4]->h / 2 + 120;
    position_min[5].x = support->w / 2 - minute[5]->w / 2 - 120;
    position_min[5].y = support->h / 2 - minute[5]->h / 2;
}

void def_pos_heu(SDL_Rect *position_heu, SDL_Surface *support, SDL_Surface **heure)
{
	position_heu[0].x = support->w / 2 - heure[0]->w / 2;
    position_heu[0].y = support->h / 2 - heure[0]->h / 2 - 60;
    position_heu[1].x = support->w / 2 - heure[1]->w / 2 + 60;
    position_heu[1].y = support->h / 2 - heure[1]->h / 2;
    position_heu[2].x = support->w / 2 - heure[2]->w / 2;
    position_heu[2].y = support->h / 2 - heure[2]->h / 2 + 60;
    position_heu[3].x = support->w / 2 - heure[3]->w / 2 - 60;
    position_heu[3].y = support->h / 2 - heure[3]->h / 2;
}

void def_pos_dec(SDL_Rect *position_dec, SDL_Surface *support, SDL_Surface **decor)
{
	int i;

	position_dec[0].x = 0;
    position_dec[0].y = 0;
    position_dec[1].x = 310;
    position_dec[1].y = 0;
    position_dec[2].x = 310;
    position_dec[2].y = 310;
    position_dec[3].x = 0;
    position_dec[3].y = 310;
    for (i = 0; i < 4; ++i)
    {
    	SDL_FillRect(decor[i], NULL, SDL_MapRGB(decor[i]->format, 0, 0, 255));
    	SDL_BlitSurface(decor[i], NULL, support, &position_dec[i]);
    }
}

int main ()
{
	time_t timestamp;
    struct tm * t;
	SDL_Surface *support;
	SDL_Surface *seconde[6];
	SDL_Surface *minute[6];
	SDL_Surface *heure[4];
	SDL_Surface *matinSoir;
	SDL_Surface *decor[4];
	SDL_Event event;
	SDL_Rect position;
	SDL_Rect position_sec[6];
	SDL_Rect position_min[6];
	SDL_Rect position_heu[4];
	SDL_Rect position_dec[4];
	int continuer = 1;
	int i;

	SDL_Init(SDL_INIT_VIDEO);

    support = SDL_SetVideoMode(550, 550, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Horloge Binaire", NULL);
    matinSoir = SDL_CreateRGBSurface(SDL_HWSURFACE, 50, 50, 32, 0, 0, 0, 0);
    SDL_FillRect(support, NULL, SDL_MapRGB(support->format, 0, 0, 0));
    position.x = support->w / 2 - matinSoir->w / 2;
    position.y = support->h / 2 - matinSoir->h / 2;
    for (i = 0; i < 6; ++i)
    {
    	seconde[i] = SDL_CreateRGBSurface(SDL_HWSURFACE, 50, 50, 32, 0, 0, 0, 0);
    	minute[i] = SDL_CreateRGBSurface(SDL_HWSURFACE, 50, 50, 32, 0, 0, 0, 0);
    	if (i < 4)
    	{
    		heure[i] = SDL_CreateRGBSurface(SDL_HWSURFACE, 50, 50, 32, 0, 0, 0, 0);
    		decor[i] = SDL_CreateRGBSurface(SDL_HWSURFACE, 240, 240, 32, 255, 255, 255, 255);
    	}
    }
    def_pos_sec(position_sec, support, seconde);
    def_pos_min(position_min, support, minute);
    def_pos_heu(position_heu, support, heure);
    def_pos_dec(position_dec, support, decor);

    SDL_Flip(support);

    while (continuer)
    {
    	SDL_PollEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_KEYDOWN:
	            if (event.key.keysym.sym == SDLK_ESCAPE)
	            	continuer = 0;
	            break;
        }
        timestamp = time(NULL);
    	t = localtime(&timestamp);
        for (i = 0; i < 6; ++i)
        {
        	if ((t->tm_sec / (my_power_rec(2, i))) % 2 != 0)
	        	SDL_FillRect(seconde[i], NULL, SDL_MapRGB(seconde[i]->format, 0, 0, 255));
	        else
	        	SDL_FillRect(seconde[i], NULL, SDL_MapRGB(seconde[i]->format, 0, 0, 0));
	        if ((t->tm_min / (my_power_rec(2, i))) % 2 != 0)
	        	SDL_FillRect(minute[i], NULL, SDL_MapRGB(minute[i]->format, 255, 0, 0));
	        else
	        	SDL_FillRect(minute[i], NULL, SDL_MapRGB(minute[i]->format, 0, 0, 0));
	        if (t->tm_hour >= 12 && (((t->tm_hour - 12) / (my_power_rec(2, i))) % 2 != 0) && i < 4)
	        	SDL_FillRect(heure[i], NULL, SDL_MapRGB(heure[i]->format, 0, 255, 0));
	        else if (t->tm_hour < 12 && (((t->tm_hour) / (my_power_rec(2, i))) % 2 != 0) && i < 4)
	        	SDL_FillRect(heure[i], NULL, SDL_MapRGB(heure[i]->format, 0, 255, 0));
	        else if (i < 4)
	        	SDL_FillRect(heure[i], NULL, SDL_MapRGB(heure[i]->format, 0, 0, 0));
	        if (t->tm_hour / 12 == 1)
    			SDL_FillRect(matinSoir, NULL, SDL_MapRGB(matinSoir->format, 255, 255, 255));
    		else
    			SDL_FillRect(matinSoir, NULL, SDL_MapRGB(matinSoir->format, 0, 0, 0));
	        SDL_BlitSurface(seconde[i], NULL, support, &position_sec[i]);
	        SDL_BlitSurface(minute[i], NULL, support, &position_min[i]);
	        SDL_BlitSurface(heure[i], NULL, support, &position_heu[i]);
	        SDL_BlitSurface(matinSoir, NULL, support, &position);
        }
    	SDL_Flip(support);
    }
    for (i = 0; i < 6; ++i)
    {
    	SDL_FreeSurface(seconde[i]);
    	SDL_FreeSurface(minute[i]);
    	if (i < 4)
    	{
    		SDL_FreeSurface(heure[i]);
    		SDL_FreeSurface(decor[i]);
    	}
    }
	SDL_FreeSurface(matinSoir);
    SDL_Quit();

	return EXIT_SUCCESS;
}