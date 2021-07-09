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
#include "Run/FGDraw.hpp"

/* Handle draw line function */
void FGDraw::Rect(const FG_Color color, const FG_Rect& rect, const bool fill,
	const FGData_System& system, std::string& message_error, bool& errorEvent) {
	/* Check if have error */
	if(errorEvent) {
		/* if have error */
		/* Write message error */
		message_error = "Can't run set Draw Rect because, you have error ";
		message_error += "before you running this function ";
		message_error += "| in function FGDraw::Rect";
	} else {
		/* If no have error */
		/* Setup Variable rectangle */
		SDL_Rect Rectangle;

		/* Filled data into rectangle */
		Rectangle.x = rect.x;
		Rectangle.y = rect.y;
		Rectangle.w = rect.width;
		Rectangle.h = rect.height;

		/* First set color */
		/* Setup Color */
		SDL_SetRenderDrawColor(system.render,
			color.R, color.G, color.B, color.A);

		/* If filled the rectangle */
		if(fill) {
			/* Draw Rect Fill */
			SDL_RenderFillRect(system.render, &Rectangle);
		} else {
			/* Draw Rect Basic */
			SDL_RenderDrawRect(system.render, &Rectangle);
		}
	}
}

/* Handle function draw line */
void FGDraw::Line(const FG_Color color, 
	const float x1, const float y1, 
	const float x2, const float y2,
	const FGData_System& system, std::string& message_error, bool& errorEvent) {
	/* Check if have error */
	if(errorEvent) {
		/* if have error */
		/* Write message error */
		message_error = "Can't run set Draw Line because, you have error ";
		message_error += "before you running this function ";
		message_error += "| in function FGDraw::Line";
	} else {
		/* If no have error */
		/* First set color */
		/* Setup Color */
		SDL_SetRenderDrawColor(system.render,
			color.R, color.G, color.B, color.A);

		/* Draw Line */
		SDL_RenderDrawLine(system.render, x1, y1, x2, y2);
	}
}