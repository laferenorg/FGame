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
#ifndef _FGAME_WINDOW_HEADER_
#define _FGAME_WINDOW_HEADER_

/* Include header library SDL2 */
#include <SDL2/SDL.h>

/* Include header in include directory from this project */
#include "../FGBegin.hpp"
#include "../FGStruct.hpp"

class FGAME_CALL FGWindow {
	/* This class not have private section */

	/* Public function for helper window */
	/* This class for get information of window */
	public:
		/* This function for get position of window */
		void Position(int& x, int& y,
			FGData_System& system, std::string& message_error, bool& errorEvent);

		/* This function for get Size of window */
		void Sizes(int& width, int& height,
			FGData_System& system, std::string& message_error, bool& errorEvent);
};

#endif /* _FGAME_WINDOW_HEADER_ */