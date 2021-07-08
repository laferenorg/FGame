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
#include <string>
#include <ios>
#include <fstream>

/* Include header from include directory in this project */
#include "Run/FGTTF.hpp"
#include "FGStruct.hpp"

/* Include header library SDL2 */
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

/* Handle function load ttf */
void FGTTF::load(FG_TTF& font, std::string text, std::string path_ttf,
	FG_Color color, float size, FGData_System& system, std::string& message_error, 
	bool& errorEvent) {
	/* Check if have error before */
	if(errorEvent) {
		/* if have error */
		/* Write message error */
		message_error = "Can't run set Load TTF because, you have error ";
		message_error += "before you running this function ";
		message_error += "| in function FGTTF::load";
	} else {
		/* If not have error */
		/* Check if file exist */
		std::ifstream TempCheckFile;
		TempCheckFile.open(path_ttf, std::ios::binary);

		/* Check if file not exist */
		if(!TempCheckFile.is_open()) {
			/* If file not exist */
			/* set error event into true */
			errorEvent = true;

			/* Write message error */
			message_error = "FGame not defined file name: ";
			message_error += path_ttf + " | in function FGTTF::load";
		}

		/* Close file */
		TempCheckFile.close();

		/* Check if have error */
		if(!errorEvent) {
			/* If not have error */
			/* Setup font data */
			font.color = color;
			font.text = text;
			font.fontFamily = path_ttf;
			font.size = size;

			/* Setup Color */
			uint8_t R = color.R, G = color.G, B = color.B, A = color.A;

			/* Setup Width Height */
			TTF_Font* tempFont = TTF_OpenFont(path_ttf.c_str(), size);
			SDL_Color fontColor = { R, G, B, A };
			SDL_Surface* fontSurface = TTF_RenderText_Solid(tempFont, text.c_str(), 
				fontColor);
			font.width = fontSurface->w;
			font.height = fontSurface->h;

			/* Free memory */
			SDL_FreeSurface(fontSurface);
			TTF_CloseFont(tempFont);
		}
	}
}

/* Handle function render ttf */
void FGTTF::render(FG_TTF& font, FG_Rect& rect, 
	FGData_System& system, std::string& message_error, bool& errorEvent) {
	/* Check if have error before */
	if(errorEvent) {
		/* if have error */
		/* Write message error */
		message_error = "Can't run set Render TTF because, you have error ";
		message_error += "before you running this function ";
		message_error += "| in function FGTTF::render";
	} else {
		/* If not have error */
		/* Check the font initialized */
		if(font.text.empty() || font.fontFamily.empty() ||
			(font.size == 0) || (font.width == 0) || 
			(font.height == 0)) {
			/* If this not initialized */
			/* set error event into true */
			errorEvent = true;

			/* Write message error */
			message_error = "Font has not initialized | in function FGTTF::render";
		}

		/* Check if no have error */
		if(!errorEvent) {
			/* If no have error */
			/* Setup variable rectangle */
			SDL_Rect FontRect;
			FontRect.x = rect.x;
			FontRect.y = rect.y;
			FontRect.w = rect.width;
			FontRect.h = rect.height;

			/* Setup Color */
			uint8_t R = font.color.R, G = font.color.G, 
					B = font.color.B, A = font.color.A;

			/* Setup Texture for render */
			TTF_Font* tempFont = TTF_OpenFont(font.fontFamily.c_str(), font.size);
			SDL_Color fontColor = { R, G, B, A };
			SDL_Surface* fontSurface = TTF_RenderText_Solid(tempFont, font.text.c_str(), 
				fontColor);
			SDL_Texture* Message = SDL_CreateTextureFromSurface(system.render, fontSurface);
			
			/* Free memory */
			SDL_FreeSurface(fontSurface);
			TTF_CloseFont(tempFont);
			SDL_RenderCopy(system.render, Message, NULL, &FontRect);
			SDL_DestroyTexture(Message);
		}
	}
}