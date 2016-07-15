#include "public.h"
#include "init.h"
#include "keyEvent.h"

SDL_Event event;
/*-----------------------function border------------------------------*/
int dealWithEvent(void){
	if(SDL_PollEvent(&event)){
		if(event.type == SDL_QUIT){
			exit(0);
		}
		if(event.type == SDL_KEYDOWN){
			switch(event.key.keysym.sym){
				case SDLK_SPACE: 
					count = 0;
					if(game_state == GAME_READY){
						game_state = GAME_RUNNING;
						break;
					}else if(game_state == GAME_OVER){
						game_state = GAME_RESET;
						break;
					}
					bird.speed = BIRD_SPEED;
					bird.y += bird.y_offset;
					bird.y_offset = 0;	//鸟的偏移重置为0
					break;

				case SDLK_q:
					exit(0);
					break;
			}
		}
		if(event.type == SDL_MOUSEBUTTONDOWN){
			if(event.button.button == SDL_BUTTON_LEFT){
				count = 0;
				if(game_state == GAME_READY){
					game_state = GAME_RUNNING;
					return 0;
				}else if(game_state == GAME_OVER){
					game_state = GAME_RESET;
					return 0;
				}
				bird.speed = BIRD_SPEED;
				bird.y += bird.y_offset;
				bird.y_offset = 0;	
			}
		}
	}
}
