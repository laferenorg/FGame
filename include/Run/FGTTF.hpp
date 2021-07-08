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
#ifndef _FGAME_TTF_HEADER_
#define _FGAME_TTF_HEADER_

/* Include header in include directory from this project */
#include "../FGBegin.hpp"
#include "../FGStruct.hpp"

/* This class it's for management true type font or another name TTF */
class FGAME_CALL FGTTF {
	/* This class no have private section */

	/* Public function for setup or using */
	public:
		/* This for load font */
		void load(FG_TTF& font, std::string text, std::string path_ttf,
			FG_Color color, float size, FGData_System& system, std::string& message_error, 
			bool& errorEvent);

		/* This function for render the ttf */
		void render(FG_TTF& font, FG_Rect& rect,
			FGData_System& system, std::string& message_error, bool& errorEvent);
};

#endif /* _FGAME_TTF_HEADER_ */