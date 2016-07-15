#ifndef __DRAW_H__
	#define __DRAW_H__

	#include "public.h"
	#include "init.h"

	/**
	 * 绘制地
	 *
	 * @game_engine: 传入game_engine。
	 * @land: 传入地。
	 */
	void draw_land(GameEngine* game_engine, Sprite* land);
	/**
	 * 绘制管道
	 *
	 * @game_engine: 传入game_engine。
	 * @pipe_down: 传入管道。
	 */
	void draw_pipes(GameEngine* game_engine, Sprite* pipe_down);
	/**
	 * 绘制背景
	 *
	 * @game_engine: 传入game_engine。
	 */
	void draw_background(GameEngine* game_engine);
	/**
	 * 绘制鸟
	 *
	 * @game_engine: 传入game_engine。
	 * @bird: 传入鸟
	 */
	void draw_bird(GameEngine* game_engine, Sprite* bird);
	/**
	 * 绘制游戏结束图
	 *
	 * @game_engine: 传入game_engine。
	 */
	void draw_game_over(GameEngine* game_engine);
	/**
	 * 绘制游戏指引图
	 *
	 * @game_engine: 传入game_engine。
	 */
	void draw_tutorial(GameEngine* game_engine);
	/**
	 * 绘制游戏分数
	 *
	 * @game_engine: 传入game_engine。
	 */
	void draw_score(GameEngine* game_engine);
	/**
	 * 绘制flappy bird
	 *
	 * @game_engine: 传入game_engine。
	 */
	void draw_title(GameEngine* game_engine);
	/**
	 * 绘制ready
	 *
	 * @game_engine: 传入game_engine。
	 */
	void draw_ready(GameEngine* game_engine);
#endif
