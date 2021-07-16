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

/* Include pre compile header */
#include "pch.h"

/* Include header C++ */
#include <iostream>

/* Include header SDL2 */
#include <SDL2/SDL.h>

/* Include header from include directory in this project */
#include "Get/FGGet.hpp"

/* Handle function get ticks */
Uint32 FGGet::Ticks() const {
	/* TODO: Just using SDL2 function for get ticks */
	return SDL_GetTicks();
}

/* Handle function Collide */
bool FGGet::Collide(const FG_Rect& rectFirst, const FG_Rect& rectSecond) {
	/* Setup Variable */
	SDL_Rect rect1, rect2;

	/* Position Rect1 */
	rect1.x = rectFirst.x;
	rect1.y = rectFirst.y;

	/* Position Rect2 */
	rect2.x = rectSecond.x;
	rect2.y = rectSecond.y;

	/* Size Rect1 */
	rect1.w = rectFirst.width;
	rect1.h = rectFirst.height;

	/* Size Rect2 */
	rect2.w = rectSecond.width;
	rect2.h = rectSecond.height;
	
	/* TODO: Just using function from SDL2 to check collider */
	return SDL_HasIntersection(&rect1, &rect2);
}