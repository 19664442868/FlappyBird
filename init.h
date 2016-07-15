#ifndef __INIT_H__
	#define __INIT_H__
	#include "public.h"	
	#include "sys/time.h"

	/**
	 * 随机出一个水管的偏移
	 *
	 * @seed: 由于采用了rand的方式获取随机数，需要seed传入sand中，
	 *			当seed <= 0时，会调用gettimeofday()获取随机数。
	 *
	 * return：
	 *		返回一个随机数
	 */
	int random_pipe_offset(int seed);
	/**
	 * 初始化鸟
	 *
	 * ＠bird: 传入鸟
	 */
	void init_bird(Sprite* bird);
	/**
	 * 初始化地
	 *
	 * ＠land: 传入地
	 */
	void init_land(Sprite* land);
	/**
	 * 初始化管道
	 *
	 * ＠pipe_down: 传入向下的管道
	 */
	void init_pipe_down(Sprite* pipe_down);
	/**
	 * 初始化引擎
	 *
	 * ＠game_engine: 传入游戏引擎
	 */
	void init_game_engine(GameEngine* game_engine);
#endif
