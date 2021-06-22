/* MIT License
 *
 * Copyright (c) 2021 laferenorg
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN C
 */

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