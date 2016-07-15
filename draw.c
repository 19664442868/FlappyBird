#include "draw.h"
/*-----------------------function border------------------------------*/
void draw_land(GameEngine* game_engine, Sprite* land){
	SDL_Rect land_rect;

	land->x -= land->speed;
	land_rect.x = land->x;
	land_rect.y = land->y;

	/**
	 * 288-366+23 最后的23是为了防止右侧出现图片的边界，同时23代表草地间隔的长度
	 */
	if(land_rect.x <= (288-336+23)){
		land->x = 0;
	}

	SDL_BlitSurface (game_engine->land, NULL, game_engine->screen, &land_rect);

}
/*-----------------------function border------------------------------*/
void draw_pipes(GameEngine* game_engine, Sprite* pipe_down){
	int i = 0;
	SDL_Rect pipe_rect;
	for(; i < 2; i++){
		/**
		 * 当管子在左边超出边界时，我们就要让管子重新回到最右边
		 * 当然是上下管都要回到最右边
		 */
		if(pipe_down[i].x <= -52){
			pipe_down[i].x =288;
			game_engine->pipe_offset[i] = random_pipe_offset(0);
		}

		//获取得分
		if((pipe_down[i].x+pipe_down[i].width >= (288/3-48/2-GENERAL_SPEED/2)) && (pipe_down[i].x+pipe_down[i].width <= (288/3-48/2+GENERAL_SPEED/2))){
			game_engine->score++;
		}

		//绘制管道
		pipe_down[i].x -= pipe_down[i].speed;
		pipe_rect.x = pipe_down[i].x;
		pipe_rect.y = 0 - game_engine->pipe_offset[i] - LAND_HEIGHT; 
		SDL_BlitSurface (game_engine->pipe_down, NULL, game_engine->screen, &pipe_rect);

		pipe_rect.x = pipe_down[i].x;
		pipe_rect.y = pipe_down[i].height - LAND_HEIGHT - game_engine->pipe_offset[i] + HOLE_SIZE;
		SDL_BlitSurface (game_engine->pipe_up, NULL, game_engine->screen, &pipe_rect);
			
	}
}
/*-----------------------function border------------------------------*/
void draw_background(GameEngine* game_engine){
	SDL_BlitSurface(game_engine->bg, NULL, game_engine->screen, NULL);
}
/*-----------------------function border------------------------------*/
void draw_bird(GameEngine* game_engine, Sprite* bird){

	SDL_Rect bird_rect;
	bird_rect.x = bird->x;
	bird_rect.y = bird->y + bird->y_offset;	//bird->y_offset中保存了鸟的的偏移
	SDL_BlitSurface(game_engine->bird_image[game_engine->bird_image_count/5%3], NULL, game_engine->screen, &bird_rect);
	
	if(game_engine->bird_game_over == 0){
		game_engine->bird_image_count++;
	}
}
/*-----------------------function border------------------------------*/
void draw_game_over(GameEngine* game_engine){
	SDL_Rect bird_rect;
	bird_rect.x = 288/2 - 204/2;
	bird_rect.y = 512/2 - 54/2 - 100;	//100是自己调整
	SDL_BlitSurface(game_engine->game_over, NULL, game_engine->screen, &bird_rect);
}
/*-----------------------function border------------------------------*/
void draw_tutorial(GameEngine* game_engine){
	SDL_Rect bird_rect;
	bird_rect.x = 288/2 - 114/2;
	bird_rect.y = 512/2 - 98/2;
	SDL_BlitSurface(game_engine->tutorial, NULL, game_engine->screen, &bird_rect);
}
/*-----------------------function border------------------------------*/
void draw_title(GameEngine* game_engine){
	SDL_Rect bird_rect;
	bird_rect.x = 288/2 - 178/2;
	bird_rect.y = 512 - 112 + 40;
	SDL_BlitSurface(game_engine->title, NULL, game_engine->screen, &bird_rect);
}
/*-----------------------function border------------------------------*/
void draw_ready(GameEngine* game_engine){
	SDL_Rect bird_rect;
	bird_rect.x = 288/2 - 196/2;
	bird_rect.y = 100;
	SDL_BlitSurface(game_engine->ready, NULL, game_engine->screen, &bird_rect);
}
/*-----------------------function border------------------------------*/
/**
 * 由于不知道分数的长度，所以只能通过将数字转换为字符串，
 * 然后根据数字的长度来定图片的位置绘图
 */
void draw_score(GameEngine* game_engine){
	char ch[4] = {0};
	int string_length = 0;
	SDL_Rect bird_rect;

	sprintf(ch, "%d", game_engine->score);
	string_length = strlen(ch);

	if(string_length == 1){
		bird_rect.x = 288/2 - 24/2;
		bird_rect.y = 80;
		SDL_BlitSurface(game_engine->num[ch[0]-'0'], NULL, game_engine->screen, &bird_rect);
	}else if(string_length == 2){
		bird_rect.x = 288/2 - 24;
		bird_rect.y = 80;
		SDL_BlitSurface(game_engine->num[ch[0]-'0'], NULL, game_engine->screen, &bird_rect);

		bird_rect.x = 288/2;
		bird_rect.y = 80;
		SDL_BlitSurface(game_engine->num[ch[1]-'0'], NULL, game_engine->screen, &bird_rect);
	}else if(string_length == 3){
		bird_rect.x = 288/2 - 24 - 24/2;
		bird_rect.y = 80;
		SDL_BlitSurface(game_engine->num[ch[0]-'0'], NULL, game_engine->screen, &bird_rect);

		bird_rect.x = 288/2 - 24/2;
		bird_rect.y = 80;
		SDL_BlitSurface(game_engine->num[ch[1]-'0'], NULL, game_engine->screen, &bird_rect);

		bird_rect.x = 288/2 + 24/2;
		bird_rect.y = 80;
		SDL_BlitSurface(game_engine->num[ch[2]-'0'], NULL, game_engine->screen, &bird_rect);
	}
}
