#include "bird.h"
/*-----------------------function border------------------------------*/
/**
 * 采用公式s = v*t + a*t*t/2获取鸟的y轴偏移
 */
void calculate_bird_offset(Sprite* bird, int count){
	bird->y_offset = (int)(bird->speed*(count) +((WEIGHT+0.1)*(count)*(count))/2);
}

/*-----------------------function border------------------------------*/
/**
 * 采用公司s = v*t获取鸟的y轴偏移
 */
void bird_die_offset(Sprite* bird, int count){
	bird->y_offset = (int)(4*count);
}

/*-----------------------function border------------------------------*/
int check_hit_land(Sprite* land){
	return (land->y+land->y_offset) >= (512 - 112 - 48/2); 
}

/*-----------------------function border------------------------------*/
int check_hit_pipe(GameEngine* game_engine, Sprite* bird, Sprite* pipe){
	int i = 0;

	int pipe_hole_up = 0;
	int pipe_hole_down = 0;
	int pipe_hole_left = 0;
	int pipe_hole_right = 0;

	/**
	 * 因为图片四个边缘有一部分像素是多余的，这里通过这种
	 * 误差补偿的方式，尽量消除图片边缘对检测的影响
	 */
	int bird_left = bird->x+10;
	int bird_right = bird->x+bird->width-5;
	int bird_up = bird->y+bird->y_offset+12;
	int bird_down =bird->y+bird->y_offset+bird->height-12;

	for(; i < 2; i++){

		/**
		 * 获取管道间洞的上下、左右边界的位置，就像前面获取鸟的上下左右的位置
		 */
		pipe_hole_up = pipe[i].height - LAND_HEIGHT - game_engine->pipe_offset[i];
		pipe_hole_down = pipe[i].height - LAND_HEIGHT - game_engine->pipe_offset[i] + HOLE_SIZE;
		pipe_hole_left = pipe[i].x;
		pipe_hole_right = pipe[i].x + pipe[i].width;

		if((((bird_right > pipe_hole_left) && (bird_right < pipe_hole_right)) && ((bird_up < pipe_hole_up) || (bird_down > pipe_hole_down))) || (((bird_left > pipe_hole_left) && (bird_left < pipe_hole_right)) && ((bird_up < pipe_hole_up) || (bird_down > pipe_hole_down)))){
			//printf("bird_up = %d, bird_down = %d, bird_left = %d, bird_right = %d\n", bird_up, bird_down, bird_left, bird_right);
			//printf("pipe_hole_up = %d, pipe_hole_down = %d, pipe_hole_left = %d, pipe_hole_right = %d\n", pipe_hole_up,\
					pipe_hole_down, pipe_hole_left, pipe_hole_right);
			return 1;
		}
	}
	return 0;
}
