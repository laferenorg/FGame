/* Library From C++ */
#include <iostream>

/* Library From SDL2 */
#include <SDL2/SDL.h>

/* header */
#include <FGame.hpp>

/* Global Variable Of This Project */
/* Section For Checking */
extern bool _fgame_run_program_;

/* Function Quit From Class FGameManage */
void _fgame_manage_::Quit() {
	_fgame_run_program_ = false;
}

/* Function Get Ticks From Class FGameManage */
Uint32 _fgame_manage_::FG_GetTicks() {
	return SDL_GetTicks();
}

/* Function Get Performance Frequency From Class FGameManage */
Uint64 _fgame_manage_::FG_GetPerformanceFrequency() {
	return SDL_GetPerformanceFrequency();
}

/* Function Get Performace Counter From Class FGameManage */
Uint64 _fgame_manage_::FG_GetPerformanceCounter() {
	return SDL_GetPerformanceCounter();
}

/* Function Delay From Class FGameManage */
void _fgame_manage_::FG_Delay(float fgame_delay) {
	SDL_Delay(fgame_delay);
}

/* Function Delay From Class FGameManage */
bool _fgame_manage_::spritecollide(FGameRect& fgame_sprite1, FGameRect& fgame_sprite2) {
	/* Setup Variable */
	SDL_Rect rect1, rect2;

	/* Position Rect1 */
	rect1.x = fgame_sprite1.x;
	rect1.y = fgame_sprite1.y;

	/* Position Rect2 */
	rect2.x = fgame_sprite2.x;
	rect2.y = fgame_sprite2.y;

	/* Size Rect1 */
	rect1.w = fgame_sprite1.width;
	rect1.h = fgame_sprite1.height;

	/* Size Rect2 */
	rect2.w = fgame_sprite2.width;
	rect2.h = fgame_sprite2.height;
	
	return SDL_HasIntersection(&rect1, &rect2);
}