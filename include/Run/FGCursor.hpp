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
#if !defined(_FGAME_RUN_CURSOR_HEADER_) && \
	(defined(FGAME_IMAGE) || defined(FGAME_ALL))
#define _FGAME_RUN_CURSOR_HEADER_

/* Include header library SDL2 */
#include <SDL2/SDL.h>

/* Include header in include directory from this project */
#include "../FGBegin.hpp"
#include "../FGStruct.hpp"

class FGAME_CALL FGRunCursor {
	/* This class no have private section */

	/* Public function for will be used for helper */
	public:
		/* This function it's for show cursor or not */
		void Show(const bool show,
			FGData_System& system, std::string& message_error, bool& errorEvent);

		/* This function for set size of cursor */
		void Sizes(const float width, const float height,
			FGData_System& system, std::string& message_error, bool& errorEvent);
	
		/* This function for set cursor into image */
		void Set(const std::string cursor_path,
			FGData_System& system, std::string& message_error, bool& errorEvent);
			
		/* This function for set into normal from image */
		void NormalFromImage(FGData_System& system, 
			std::string& message_error, bool& errorEvent);
};

#endif /* _FGAME_RUN_CURSOR_HEADER_ */