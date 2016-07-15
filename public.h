#ifndef __PUBLIC_H__
	#define __PUBLIC_H__

	#include <stdio.h>
	#include <stdlib.h>
	#include <SDL/SDL.h>
	#include <SDL/SDL_image.h>
	#include <SDL/SDL_mixer.h>
	#include <time.h>
	#include <unistd.h>

	#define WIDTH			288		//窗口的宽度
	#define HEIGHT			512		//窗口的高度
	#define BPP				32		//窗口中一个像素中数据的大小

	#define WEIGHT			0.3		//重力加速度
	#define HOLE_SIZE		100		//上下管道的中间间隔
	#define LAND_HEIGHT		112		//地的高度
	#define GENERAL_SPEED	2		//通常的移动速度，主要是给管道、地面使用
	#define BIRD_SPEED		-6		//每次鸟向上的初速度

	/**
	 * 通过枚举的方式获取游戏的状态
	 */
	typedef enum GameState
	{
		GAME_START = 1,
		GAME_MENU,
		GAME_RUNNING,
		GAME_READY,
		GAME_RESET,
		GAME_OVER,
		GAME_EXIT
	} GameState;


	/**
	 * 我个人认为这是游戏引擎  :-)
	 * 里面包含了一些游戏的图片，得分等内容，详细如下：
	 *		1.screen: 游戏的图形显示窗口对应的SDL_Surface;
	 *		2.bg(background): 游戏背景;
	 *		3.num[10]: 游戏显示分数对应的数字;
	 *		4.game_over: 游戏结束显示的图片;
	 *		5.tutorial: 游戏指引;
	 *		6.title: 游戏标题，也就是游戏名字:flappy bird;
	 *		7.ready: 游戏开始的时候的ready图片;
	 *		8.land: 游戏中地面的图片;
	 *		9.bird_image: 鸟的图片，目前有3张;
	 *		10.pipe_down: 向下的管道;
	 *		11.pipe_up: 向上的管道;
	 *		12.score: 保存游戏的分数;
	 *		13.music: 游戏的背景音乐;
	 *		14.pipe_offset[2]: 两根管道的各自的偏移;
	 *		15.bird_image_count: 鸟在飞的时候换图片的索引计数;
	 *		16.bird_game_over: 当鸟撞了地、水管之后鸟的翅膀不能再震荡，
	 *			也就是不能再还图片了。
	 */
	typedef struct GameEngine
	{
		SDL_Surface *screen;
		SDL_Surface *bg;
		SDL_Surface *num[10];
		SDL_Surface *game_over;
		SDL_Surface *tutorial;
		SDL_Surface *title;
		SDL_Surface *ready;
        SDL_Surface *land;
        SDL_Surface *bird_image[3];
        SDL_Surface *pipe_down;
        SDL_Surface *pipe_up;
		Uint32 score;        
		Mix_Music *music;
		int pipe_offset[2];
		int bird_image_count;		//use for bird_image
		int bird_game_over;
	} GameEngine;

	/**
	 * 每个能够移动的东西都是一个精灵，详细说明如下：
	 *		1.width: 精灵的宽度;
	 *		2.height: 精灵的高度;
	 *		3.x: 精灵的x位置;
	 *		4.y: 精灵的y位置;
	 *		5.y_offset: 精灵的y轴的偏移，主要是在鸟身上使用;
	 *		6.speed: 精灵的移动速度;
	 */
	typedef struct Sprite
	{
		int width;
		int height;
		int x;
		int y;
		int y_offset;
		int speed;
	} Sprite;

	extern int count;
	extern Sprite bird;
	extern GameState game_state;
	extern Sprite pipe_down[2];
	extern Sprite pipe_up[2];

#endif //__PUBLIC_H__
