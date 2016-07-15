#ifndef __BIRD_H__
	#define __BIRD_H__

	#include "public.h"
	/**
	 * 计算鸟活着的时候在y轴上的偏移，采用公式：y_offset=v*t+a*t*t/2的模板
	 *
	 * @bird: 传入鸟
	 * @count: 看作时间t
	 */
	void calculate_bird_offset(Sprite* bird, int count);
	/**
	 * 计算鸟撞死的时候在y轴上的偏移，采用公式：y_offset=2*t的模板
	 *
	 * @bird: 传入鸟
	 * @count: 看作时间t
	 */
	void bird_die_offset(Sprite* bird, int count);
	/**
	 * 检查鸟是否撞击地面
	 *
	 * @land: 传入鸟
	 *
	 * return：
	 *		0：表示没有撞击地面；
	 *		1：表示撞击地面了。
	 */
	int check_hit_land(Sprite* land);
	/**
	 * 检查鸟是否撞击管道
	 *
	 * @game_engine: 传入game_engine
	 * @bird: 传入鸟
	 * @pipe: 出入管道
	 *
	 * return：
	 *		0：表示没有撞击管道；
	 *		1：表示撞击管道了。
	 */
	int check_hit_pipe(GameEngine* game_engine, Sprite* bird, Sprite* pipe);

#endif	//__BIRD_H__
