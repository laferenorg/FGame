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

/* This script will run if support image */
#if defined(FGAME_IMAGE) || defined(FGAME_ALL)

/* Include header C++ */
#include <iostream>
#include <string>
#include <fstream>
#include <ios>

/* Include header SDL2 */
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

/* Include header from include directory in this project */
#include "FGStruct.hpp"
#include "Run/FGImage.hpp"

/* Handle load image function */
void FGImage::Load(FG_Image& destination_image, const std::string locationImage,
	const FGData_System& system, std::string& message_error, bool& errorEvent) {
	/* Setup variable check */
	bool fileAlready = true;

	/* Check file already or not */
	std::ifstream TempCheckFile;
	TempCheckFile.open(locationImage, std::ios::binary);
	if(!TempCheckFile.is_open()) {
		/* If not defined file set variable into false */
		fileAlready = false;

		/* And Set Error Message and Make error event into true */
		errorEvent = true;
		message_error = "FGame not defined file name: ";
		message_error += locationImage + " | in function FGImage::Load";
	}
	TempCheckFile.close();

	/* If file defined */
	if(fileAlready && !errorEvent) {
		/* Setup data variable for image */
		SDL_Surface* tempSurface = IMG_Load(locationImage.c_str());

		/* Filling data in variable destination */
		destination_image.image = SDL_CreateTextureFromSurface(system.render, 
			tempSurface);
		destination_image.width = tempSurface->w;
		destination_image.height = tempSurface->h;

		/* Free memory surface */
		SDL_FreeSurface(tempSurface);
	}
}

/* Handle function Render image */
void FGImage::Render(const FG_Image& source_image, const FG_Rect& rectSprite, 
	const bool flip, const FGData_System& system, 
	std::string& message_error, bool& errorEvent) {
	/* Check if have error */
	if(errorEvent) {
		/* if have error */
		/* Write message error */
		message_error = "Can't run set Render Image because, you have error ";
		message_error += "before you running this function ";
		message_error += "| in function FGImage::Render";
	} else {
		/* If no have error */
		/* Setup rectangle variable */
		SDL_Rect rectangleVariable;

		/* Filled data into variable */
		rectangleVariable.x = rectSprite.x;
		rectangleVariable.y = rectSprite.y;
		rectangleVariable.w = rectSprite.width;
		rectangleVariable.h = rectSprite.height;

		/* Setup flip variable */
		SDL_RendererFlip flipImage = flip ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;

		/* Start rendering */
		SDL_RenderCopyEx(system.render, source_image.image, 
			NULL, &rectangleVariable, 0, NULL, flipImage);
	}
}
#endif