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
#include "Get/FGCursor.hpp"

/* Handle function if cursor click somthing */
bool FGGetCursor::Click(const FG_Rect& destination, 
	const FGData_System& system, std::string& message_error, bool& errorEvent) {
	/* Setup variable button on click */
	bool ResultClick = false;

	/* Check if have error before */
	if(errorEvent) {
		/* if have error */
		/* Write message error */
		message_error = "Can't run Get Click Cursor because, you have error ";
		message_error += "before you running this function ";
		message_error += "| in function FGGetCursor::Click";
	} else {
		/* If no have error */
		/* Check if cursor in type click button */
		if(system.event.type == SDL_MOUSEBUTTONDOWN) {
			/* Setup Variable */
			SDL_Rect rect1, rect2;

			/* Position Rect1 */
			rect1.x = destination.x;
			rect1.y = destination.y;

			/* Position Rect2 */
			rect2.x = system.cursor.x;
			rect2.y = system.cursor.y;

			/* Size Rect1 */
			rect1.w = destination.width;
			rect1.h = destination.height;

			/* Size Rect2 */
			rect2.w = system.cursor.width;
			rect2.h = system.cursor.height;
			
			/* TODO: Just using function from SDL2 to check collider */
			ResultClick = SDL_HasIntersection(&rect1, &rect2);
		}
	}

	/* Return result */
	return ResultClick;
}

/* Handle function for get sizes of cursor */
void FGGetCursor::Sizes(float& width, float& height,
	const FGData_System& system, std::string& message_error, bool& errorEvent) {
	/* Check if have error before */
	if(errorEvent) {
		/* if have error */
		/* Write message error */
		message_error = "Can't run Get Size Cursor because, you have error ";
		message_error += "before you running this function ";
		message_error += "| in function FGGetCursor::Sizes";
	} else {
		/* If no have error */
		/* Give data information size of cursor */
		width = system.cursor.width;
		height = system.cursor.height;
	}
}

/* Handle function for get position of cursor */
void FGGetCursor::Position(float& x, float& y,
	const FGData_System& system, std::string& message_error, bool& errorEvent) {
	/* Check if have error before */
	if(errorEvent) {
		/* if have error */
		/* Write message error */
		message_error = "Can't run Get Position Cursor because, you have error ";
		message_error += "before you running this function ";
		message_error += "| in function FGGetCursor::Position";
	} else {
		/* If no have error */
		/* Give data information size of cursor */
		x = system.cursor.x;
		y = system.cursor.y;
	}
}