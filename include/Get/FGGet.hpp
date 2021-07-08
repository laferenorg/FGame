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
#ifndef _FGAME_GET_HEADER_
#define _FGAME_GET_HEADER_

/* Include header library SDL2 */
#include <SDL2/SDL.h>

/* Include header in include directory from this project */
#include "../FGBegin.hpp"
#include "../FGStruct.hpp"
#include "FGWindow.hpp"

class FGAME_CALL FGGet {
	/* This class no have private section */
	/* Public variable for used in future */
	public:
		/* This variable for get information of window */
		FGWindow Window;

	/* Public function for get information */
	public:
		/* Function get tick */
		Uint32 Ticks();

		/* This function for get collider */
		bool Collide(FG_Rect& rectFirst, FG_Rect& rectSecond);
};

#endif /* _FGAME_GET_HEADER_ */