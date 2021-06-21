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