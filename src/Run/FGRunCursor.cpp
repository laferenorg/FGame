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
#include <fstream>
#include <ios>

/* Include header SDL2 */
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

/* Include header from include directory in this project */
#include "Run/FGCursor.hpp"

/* This handle function for show cursor */
void FGRunCursor::Show(const bool show,
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
		/* If no have image cursor */
		if(!system.cursor.setImage) {
			/* Setup variable toggle for filled data enabled or disable */
			int toogle;

			/* Check if cursor it's already hidden */
			if(!system.cursor.hidden && !show) {
				/* Set into disable */
				toogle = SDL_DISABLE;

				/* Set hidden true cursor hidden or true */
				system.cursor.hidden = true;
			} else if(show) {
				/* Set into enabled */
				toogle = SDL_ENABLE;

				/* Set hidden cursor show or false */
				system.cursor.hidden = false;
			}
		
			/* TODO: Just using sdl2 function for manage this */
			SDL_ShowCursor(system.cursor.setImage ? SDL_DISABLE : toogle);
		}
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
		system.cursor.rect.width = width;
		system.cursor.rect.height = height;
	}
}

/* Handle function for set cursor */
void FGRunCursor::Set(const std::string cursor_path,
	FGData_System& system, std::string& message_error, bool& errorEvent) {
	/* Setup variable check */
	bool fileAlready = true;

	/* Check file already or not */
	std::ifstream TempCheckFile;
	TempCheckFile.open(cursor_path, std::ios::binary);
	if(!TempCheckFile.is_open()) {
		/* If not defined file set variable into false */
		fileAlready = false;

		/* And Set Error Message and Make error event into true */
		errorEvent = true;
		message_error = "FGame not defined file name: ";
		message_error += cursor_path + " | in function FGRunCursor::Set";
	}
	TempCheckFile.close();

	/* If file defined */
	if(fileAlready && !errorEvent) {
		/* Set image cursor variable boolean into true */
		system.cursor.setImage = true;

		/* Make cursor hidden */
		SDL_ShowCursor(SDL_DISABLE);

		/* Setup data variable for image */
		SDL_Surface* tempSurface = IMG_Load(cursor_path.c_str());

		/* Filling data in variable destination */
		system.cursor.image.image = SDL_CreateTextureFromSurface(system.render, 
			tempSurface);
		system.cursor.image.width = tempSurface->w;
		system.cursor.image.height = tempSurface->h;

		/* Free memory surface */
		SDL_FreeSurface(tempSurface);
	}
}
	
/* Handle function for set into normal cursor */
void FGRunCursor::NormalFromImage(FGData_System& system, 
	std::string& message_error, bool& errorEvent) {
	/* Check if have error */
	if(errorEvent) {
		/* if have error */
		/* Write message error */
		message_error = "Can't run Make Normat Cursor because, you have error ";
		message_error += "before you running this function ";
		message_error += "| in function FGRunCursor::NormalFromImage";
	} else if(system.cursor.setImage) {
		/* If not have error */
		/* Set image cursor variable boolean into true */
		system.cursor.setImage = true;

		/* Make cursor make into normal */
		SDL_ShowCursor(system.cursor.hidden ? SDL_DISABLE : SDL_ENABLE);
	}
}
