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
#ifndef _FGAME_IMAGE_HEADER_
#define _FGAME_IMAGE_HEADER_

/* Include header library SDL2 */
#include <SDL2/SDL.h>

/* Include header in include directory from this project */
#include "FGBegin.hpp"
#include "FGStruct.hpp"

class FGAME_CALL FGImage {
	/* This not have private section */

	/* Public funtion using for feature */
	public:
		/* This function for load image, width, and height */
		void Load(FG_Image& destination_image, std::string locationImage,
			FGData_System& system, std::string& message_error, bool& errorEvent);

		/* This function for render image */
		void Render(FG_Image& source_image, FG_Rect& rectSprite, bool flip,
			FGData_System& system, std::string& message_error, bool& errorEvent);
};

#endif /* _FGAME_IMAGE_HEADER_ */