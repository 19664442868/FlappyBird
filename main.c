#include "public.h"
#include "keyEvent.h"
#include "draw.h"
#include "init.h"
#include "bird.h"

GameState game_state; 				//用于存储当前游戏状态
GameEngine game_engine;				//用于保存游戏中的通用参数
Sprite land;						//创建地的精灵
Sprite bird;						//创建鸟的精灵
Sprite pipe_down[2];				//创建管道的精灵
int count = 0;						//用于循环中的计数，计算鸟的偏移的时候要用到

int main(int argc, char** argv){

	game_state = GAME_START;

	while(1){
		/**
		 * 按键、鼠标处理函数。
		 */
		dealWithEvent();
		switch(game_state){
			case GAME_START:
				/**
				 * 主要完成一下工作：
				 *		1.SDL_Init:初始化SDL。
				 *		2.SDL_WM_SetCaption:绘制窗口标题。
				 *		3.atexit:注册退出函数。
				 *		4.init_game_enigne:初始化game_engine。
				 *		4.init_land:初始化land。
				 *		4.init_pipe_down:初始化pipe_down。
				 *		4.init_bird:初始化bird。
				 *		6.game_state:设置游戏状态。
				 */
				SDL_Init(SDL_INIT_EVERYTHING);
				SDL_WM_SetCaption("flappy bird", NULL);
				atexit(SDL_Quit);

				init_game_engine(&game_engine);
				init_land(&land);
				init_pipe_down(pipe_down);
				init_bird(&bird);
				game_state = GAME_READY;
				break;

			case GAME_READY:
				/**
				 * 主要完成一下工作：
				 *		1.draw_background:绘制背景。
				 *		2.draw_land:绘制地面。
				 *		3.draw_tutorial:绘制操作指引。
				 *		4.draw_bird:绘制鸟。
				 *		5.draw_ready:绘制准备字符。
				 *		6.count++;
				 *
				 */
				draw_background(&game_engine);
				draw_land(&game_engine, &land);
				draw_tutorial(&game_engine);
				draw_bird(&game_engine, &bird);
				draw_ready(&game_engine);
				count++;
				break;

			case GAME_RUNNING:
				/**
				 * 主要完成一下工作：
				 *		1.calculate_bird_offset:计算掉下来的偏移。
				 *		2.draw_background:绘制背景。
				 *		3.draw_pipes:绘制管道。
				 *		4.draw_land:绘制地面。
				 *		5.draw_score:绘制分数。
				 *		6.draw_bird:绘制鸟。
				 *		7.count++;
				 *		8.check_hit_land,check_hit_pipe:检查鸟是否掉到了地上，或者撞上了管道
				 *			8.1.bird.speed:将鸟的垂直速度置为0。
				 *			8.2.bird.y+=bird.y_offset:将鸟的y轴的值加上偏移。
				 *			8.3.bird.y_offset:将鸟的垂直偏移置零。
				 *			8.4.count清零。
				 *			8.5.pipe_down[0].speed:的x轴的移动速度为0。
				 *			8.6.pipe_down[1].speed:的x轴的移动速度为0。
				 *			8.7.land.speed:的重新赋初始值为0。
				 *			8.8.game_state:设置游戏状态为结束。
				 *			8.9.game_engine.bird_game_over:设置鸟的状态为结束，主要是用于让鸟的翅膀不转换。
				 */
				calculate_bird_offset(&bird, count);

				draw_background(&game_engine);
				draw_pipes(&game_engine, pipe_down);
				draw_land(&game_engine, &land);
				draw_score(&game_engine);
				draw_bird(&game_engine, &bird); 
				count++;

				if(check_hit_land(&bird) || check_hit_pipe(&game_engine, &bird, pipe_down)){

					bird.speed  = 0;
					bird.y += bird.y_offset;
					bird.y_offset = 0;
					count = 0;
					pipe_down[0].speed = 0;
					pipe_down[1].speed = 0;
					land.speed = 0;
					game_state = GAME_OVER;
					game_engine.bird_game_over = 1;
				}
				break;

			case GAME_OVER:
				/**
				 * 主要完成一下工作：
				 *		1.bird_die_offset:鸟撞了之后还要让它掉下来，计算掉下来的偏移。
				 *		2.draw_background:绘制背景。
				 *		3.draw_pipes:绘制管道。
				 *		4.draw_land:绘制地面。
				 *		5.draw_score:绘制分数。
				 *		6.draw_bird:绘制鸟。
				 *		7.draw_game_over:绘制游戏结束图。
				 *		8.check_hit_land:检查鸟是否掉到了地上。如果已经在地上了，
				 *			就不执行count++，因为bird_die_offset计算与count有关。
				 *		9.count++;
				 */
				bird_die_offset(&bird, count);

				draw_background(&game_engine);
				draw_pipes(&game_engine, pipe_down);
				draw_land(&game_engine, &land);
				draw_score(&game_engine);
				draw_bird(&game_engine, &bird);
				draw_game_over(&game_engine);

				if(check_hit_land(&bird)){
					continue;
				}
				count++;
				break;

			case GAME_RESET:
				/**
				 * 主要完成一下工作：
				 *		1.game_engine.score:分数清零。
				 *		2.game_engine.bird_game_over:清零，主要是为了让鸟能够挥动翅膀。
				 *		3.bird.speed:清零，鸟的初始速度为0；
				 *		4.bird.y=512/2-112+40:鸟在垂直方向上的初始位置。
				 *		5.bird.y_offset:清零，鸟初始偏移为0。
				 *		6.count:值清空。
				 *		7.pipe_down[0]:的x轴初始位置。
				 *		8.pipe_down[1]:的x轴初始位置。
				 *		9.pipe_down[0]:的x轴的移动速度。
				 *		10.pipe_down[1]:的x轴的移动速度。
				 *		11.land.speed:的重新赋初始值。
				 *		12.将游戏状态设置为GAME_READY。
				 */
				game_engine.score = 0;
				game_engine.bird_game_over = 0;
				bird.speed  = 0;
				bird.y = 512/2 - 112 + 40; //112 was the land height, 20 just for adapte
				bird.y_offset = 0;
				count = 0;

				pipe_down[0].x = 288+200;
				pipe_down[1].x = 288+200+288/2+20;
				pipe_down[0].speed = GENERAL_SPEED;
				pipe_down[1].speed = GENERAL_SPEED;
				land.speed = GENERAL_SPEED;

				game_state = GAME_READY;
				break;
		}

		
		/**
		 * 主要完成一下工作：
		 *		1.draw_title:绘制flappy bird。
		 *		2.SDL_Flip:刷新game_engine.screen到窗口。
		 *		3.SDL_Delay:采用SDL延时，时间是10ms。
		 */
		draw_title(&game_engine);
		SDL_Flip(game_engine.screen); 
		SDL_Delay(10);
	}
	return 0;
}
