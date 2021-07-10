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
#ifndef _FGAME_STRUCTURE_HEADER_
#define _FGAME_STRUCTURE_HEADER_

/* Include header library SDL2 */
#include <SDL2/SDL.h>
#include <SDL2/SDL_net.h>

/* Include header in include directory from this project */
#include "FGBegin.hpp"

/* This structure for setup rectangle,
 * This data save position and size
 */
struct FGAME_CALL FG_Rect {
	float x, y;
	float width, height;
};

/* This structure for setup image,
 * This using for image management
 */
struct FGAME_CALL FG_Image {
	SDL_Texture* image;
	float width, height;
};

/* This structure for setup color for 
 * convert into SDL2 color variable
 */
struct FGAME_CALL FG_Color {
	float R, G, B, A = 0;
};

/* This structure for setup true type font
 * this will be convert into the font
 */
struct FGAME_CALL FG_TTF {
	FG_Color color;
	std::string text;
	std::string fontFamily;
	float size = 0;
	float width = 0, height = 0; 
};

/* This structure for setup data for SDL2, 
 * This using for setup or maybe management 
 * another system in future
 */
struct FGAME_CALL FGData_System {
	SDL_Window   *window;
	SDL_Renderer *render;
	SDL_Event     event;
	FG_Rect       cursor;
};

/* This structure for setup connection
 * This using SDL2 net variable
 */
struct FGAME_CALL FG_Net {
	TCPsocket socket;
	IPaddress ip;
};

#endif /* _FGAME_STRUCTURE_HEADER_ */