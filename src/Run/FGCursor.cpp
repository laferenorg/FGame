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
#include "Run/FGCursor.hpp"

/* This handle function for show cursor */
void FGRunCursor::Show(const bool show,
	const FGData_System& system, std::string& message_error, bool& errorEvent) {
	/* Check if have error before */
	if(errorEvent) {
		/* if have error */
		/* Write message error */
		message_error = "Can't run Show Cursor because, you have error ";
		message_error += "before you running this function ";
		message_error += "| in function FGRunCursor::Show";
	} else {
		/* If no have error */
		/* TODO: Just using sdl2 function for manage this */
		SDL_ShowCursor(show ? SDL_ENABLE : SDL_DISABLE);
	}
}

/* This handle function for set sizes cursor */
void FGRunCursor::Sizes(const float width, const float height,
	FGData_System& system, std::string& message_error, bool& errorEvent) {
	/* Check if have error before */
	if(errorEvent) {
		/* if have error */
		/* Write message error */
		message_error = "Can't run Show Cursor because, you have error ";
		message_error += "before you running this function ";
		message_error += "| in function FGRunCursor::Show";
	} else {
		/* If no have error */
		/* Set rectangle sizes */
		system.cursor.width = width;
		system.cursor.height = height;
	}
}