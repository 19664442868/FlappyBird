#include "init.h"

/*-----------------------function border------------------------------*/
void init_bird(Sprite* bird){
	bird->width = 48;
	bird->height = 48;
	bird->x = 288/3-48/2;
	bird->y = 512/2 - 112 + 40; 
	bird->y_offset = 0;
	bird->speed = 0;
}

/*-----------------------function border------------------------------*/
void init_land(Sprite* land){
	land->width = 336;
	land->height = 112;
	land->x = 0;
	land->y = 512-112;
	land->y_offset = 0;
	land->speed = GENERAL_SPEED;
}

/*-----------------------function border------------------------------*/
void init_pipe_down(Sprite* pipe_down){

	int i = 0;
	for(; i < 2; i++){
		pipe_down[i].width = 52;
		pipe_down[i].height = 320;
		pipe_down[i].speed = GENERAL_SPEED;

		pipe_down[i].y = 0;
		pipe_down[i].y_offset = 0;
	}
	/**
	 * 初始化管子所在x轴的位置
	 */
	pipe_down[0].x = 288+200;
	pipe_down[1].x = 288+200+288/2+20;
}

/*-----------------------function border------------------------------*/
void init_game_engine(GameEngine* game_engine){

	game_engine->screen = SDL_SetVideoMode(WIDTH, HEIGHT,BPP, SDL_SWSURFACE|SDL_RESIZABLE);
	
	game_engine->pipe_offset[0] = random_pipe_offset(0);
	game_engine->pipe_offset[1] = random_pipe_offset(0);

	game_engine->bg = IMG_Load("./img/bg_night.png");
	SDL_SetColorKey (game_engine->bg, SDL_SRCCOLORKEY, SDL_MapRGB (game_engine->screen->format, 0, 0, 0)); 
	game_engine->bg = SDL_DisplayFormat (game_engine->bg);  

	game_engine->game_over = IMG_Load("./img/text_game_over.png");
	SDL_SetColorKey (game_engine->game_over, SDL_SRCCOLORKEY, SDL_MapRGB (game_engine->screen->format, 0, 0, 0)); 
	game_engine->game_over = SDL_DisplayFormat (game_engine->game_over);  

	game_engine->tutorial= IMG_Load("./img/tutorial.png");
	SDL_SetColorKey (game_engine->tutorial, SDL_SRCCOLORKEY, SDL_MapRGB (game_engine->screen->format, 0, 0, 0)); 
	game_engine->tutorial = SDL_DisplayFormat (game_engine->tutorial);  

	game_engine->title = IMG_Load("./img/title.png");
	SDL_SetColorKey (game_engine->title, SDL_SRCCOLORKEY, SDL_MapRGB (game_engine->screen->format, 0, 0, 0)); 
	game_engine->title= SDL_DisplayFormat (game_engine->title);  


	game_engine->num[0] = IMG_Load("./img/font_048.png");
	SDL_SetColorKey (game_engine->num[0], SDL_SRCCOLORKEY, SDL_MapRGB (game_engine->screen->format, 0, 0, 0)); 
	game_engine->num[0] = SDL_DisplayFormat (game_engine->num[0]);  
	
	game_engine->num[1] = IMG_Load("./img/font_049.png");
	SDL_SetColorKey (game_engine->num[1], SDL_SRCCOLORKEY, SDL_MapRGB (game_engine->screen->format, 0, 0, 0)); 
	game_engine->num[1] = SDL_DisplayFormat (game_engine->num[1]);  

	game_engine->num[2] = IMG_Load("./img/font_050.png");
	SDL_SetColorKey (game_engine->num[2], SDL_SRCCOLORKEY, SDL_MapRGB (game_engine->screen->format, 0, 0, 0)); 
	game_engine->num[2] = SDL_DisplayFormat (game_engine->num[2]);  

	game_engine->num[3] = IMG_Load("./img/font_051.png");
	SDL_SetColorKey (game_engine->num[3], SDL_SRCCOLORKEY, SDL_MapRGB (game_engine->screen->format, 0, 0, 0)); 
	game_engine->num[3] = SDL_DisplayFormat (game_engine->num[3]);  

	game_engine->num[4] = IMG_Load("./img/font_052.png");
	SDL_SetColorKey (game_engine->num[4], SDL_SRCCOLORKEY, SDL_MapRGB (game_engine->screen->format, 0, 0, 0)); 
	game_engine->num[4] = SDL_DisplayFormat (game_engine->num[4]);  

	game_engine->num[5] = IMG_Load("./img/font_053.png");
	SDL_SetColorKey (game_engine->num[5], SDL_SRCCOLORKEY, SDL_MapRGB (game_engine->screen->format, 0, 0, 0)); 
	game_engine->num[5] = SDL_DisplayFormat (game_engine->num[5]);  

	game_engine->num[6] = IMG_Load("./img/font_054.png");
	SDL_SetColorKey (game_engine->num[6], SDL_SRCCOLORKEY, SDL_MapRGB (game_engine->screen->format, 0, 0, 0)); 
	game_engine->num[6] = SDL_DisplayFormat (game_engine->num[6]);  
	
	game_engine->num[7] = IMG_Load("./img/font_055.png");
	SDL_SetColorKey (game_engine->num[7], SDL_SRCCOLORKEY, SDL_MapRGB (game_engine->screen->format, 0, 0, 0)); 
	game_engine->num[7] = SDL_DisplayFormat (game_engine->num[7]);  

	game_engine->num[8] = IMG_Load("./img/font_056.png");
	SDL_SetColorKey (game_engine->num[8], SDL_SRCCOLORKEY, SDL_MapRGB (game_engine->screen->format, 0, 0, 0)); 
	game_engine->num[8] = SDL_DisplayFormat (game_engine->num[8]);  

	game_engine->num[9] = IMG_Load("./img/font_057.png");
	SDL_SetColorKey (game_engine->num[9], SDL_SRCCOLORKEY, SDL_MapRGB (game_engine->screen->format, 0, 0, 0)); 
	game_engine->num[9] = SDL_DisplayFormat (game_engine->num[9]);  

	game_engine->ready = IMG_Load("./img/text_ready.png");
	SDL_SetColorKey (game_engine->ready, SDL_SRCCOLORKEY, SDL_MapRGB (game_engine->screen->format, 0, 0, 0)); 
	game_engine->ready = SDL_DisplayFormat (game_engine->ready);

	game_engine->bird_image[0] = IMG_Load("./img/bird2_0.png");
	SDL_SetColorKey (game_engine->bird_image[0], SDL_SRCCOLORKEY, SDL_MapRGB (game_engine->bird_image[0]->format, 0, 0, 0)); 
	game_engine->bird_image[0]= SDL_DisplayFormat (game_engine->bird_image[0]);  

	game_engine->bird_image[1]= IMG_Load("./img/bird2_1.png");
	SDL_SetColorKey (game_engine->bird_image[1], SDL_SRCCOLORKEY, SDL_MapRGB (game_engine->bird_image[1]->format, 0, 0, 0)); 
	game_engine->bird_image[1]= SDL_DisplayFormat (game_engine->bird_image[1]);  

	game_engine->bird_image[2]= IMG_Load("./img/bird2_2.png");
	SDL_SetColorKey (game_engine->bird_image[2], SDL_SRCCOLORKEY, SDL_MapRGB (game_engine->bird_image[2]->format, 0, 0, 0)); 
	game_engine->bird_image[2]= SDL_DisplayFormat (game_engine->bird_image[2]);  

	game_engine->land = IMG_Load("./img/land.png");
	SDL_SetColorKey (game_engine->land, SDL_SRCCOLORKEY, SDL_MapRGB (game_engine->land->format, 0, 0, 0)); 
	game_engine->land= SDL_DisplayFormat (game_engine->land);  

    game_engine->pipe_up = IMG_Load("./img/pipe_up.png");
    SDL_SetColorKey (game_engine->pipe_up, SDL_SRCCOLORKEY, SDL_MapRGB (game_engine->pipe_up->format, 0, 0, 0)); 
    game_engine->pipe_up = SDL_DisplayFormat (game_engine->pipe_up);  

    game_engine->pipe_down = IMG_Load("./img/pipe_down.png");
    SDL_SetColorKey (game_engine->pipe_down, SDL_SRCCOLORKEY, SDL_MapRGB (game_engine->pipe_down->format, 0, 0, 0)); 
    game_engine->pipe_down = SDL_DisplayFormat (game_engine->pipe_down);  

	Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);
	game_engine->music = Mix_LoadMUS("./music/life.mp3");
	Mix_PlayMusic(game_engine->music, -1);

	game_engine->bird_image_count = 0;
	game_engine->bird_game_over = 0;
}

/*-----------------------function border------------------------------*/
int random_pipe_offset(int seed){
	/**
	 * 用于获取系统us级时间
	 */
	struct timeval tmval;
	if(seed <= 0){
		gettimeofday(&tmval, NULL);
		srand(tmval.tv_usec);
	}else{
		srand(seed);
	}
	return rand()%150;
}
