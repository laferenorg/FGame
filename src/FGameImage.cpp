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

/* Library From C++ */
#include <iostream>
#include <string>
#include <fstream>
#include <ios>

/* Library From SDL2 */
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

/* header */
#include <FGame.hpp>

/* Global Variable Of This Project */
/* Section For Variable Of SDL2 */
extern SDL_Renderer *_fgame_renderer_global_;

/* Function load from class FGameImageM */
FGameImage _fgame_image_m_::load(std::string fgame_image_path) {
	/* Setup */
	FGameImage image;
	bool exist_image = true;

	/* Check exist file */
	{
		std::fstream _fgame_image_check;
		_fgame_image_check.open(fgame_image_path, std::ios::in | std::ios::binary);
		if(!_fgame_image_check.is_open()) {
			exist_image = false;
		}
		_fgame_image_check.close();
	}

	/* Check exist image */
	if(!exist_image) {
		std::cout << "[" << &image << "]: Can't find image" << std::endl;
		return image;
	}

	/* Setup data */
	SDL_Surface* tempSurface    = IMG_Load(fgame_image_path.c_str());
	image._fgame_path_location_ = fgame_image_path;
	image.width                 = tempSurface->w;
	image.height                = tempSurface->h;
	SDL_FreeSurface(tempSurface);

	return image;
}

/* Function Render from class FGameImageM */
void _fgame_image_m_::Render(FGameImage& fgame_image, FGameRect& fgame_rect) {
	/* Setup */
	SDL_Rect fgame_rect_dest;
	fgame_rect_dest.w = fgame_rect.width;
	fgame_rect_dest.h = fgame_rect.height;
	fgame_rect_dest.x = fgame_rect.x;
	fgame_rect_dest.y = fgame_rect.y;

	/* Script Texture Manager For Load */
    SDL_Surface* tempSurface = IMG_Load(fgame_image._fgame_path_location_.c_str());
    SDL_Texture* tex         = SDL_CreateTextureFromSurface(_fgame_renderer_global_, tempSurface);
    SDL_FreeSurface(tempSurface);
    SDL_RenderCopy(_fgame_renderer_global_, tex, NULL, &fgame_rect_dest);
    SDL_DestroyTexture(tex);
}

/* Function Render Flip from class FGameImageM */
void _fgame_image_m_::RenderFlip(FGameImage& fgame_image, FGameRect& fgame_rect, bool fgame_left) {
	/* Setup */
	SDL_RendererFlip flip = SDL_FLIP_NONE;
	SDL_Rect         fgame_rect_dest;

	/* Setup Rectangle */
	fgame_rect_dest.w = fgame_rect.width;
	fgame_rect_dest.h = fgame_rect.height;
	fgame_rect_dest.x = fgame_rect.x;
	fgame_rect_dest.y = fgame_rect.y;

	/* Setup flip */
	if(fgame_left) flip = SDL_FLIP_HORIZONTAL;

	/* Script Texture Manager For Load */
    SDL_Surface* tempSurface = IMG_Load(fgame_image._fgame_path_location_.c_str());
    SDL_Texture* tex         = SDL_CreateTextureFromSurface(_fgame_renderer_global_, tempSurface);
    SDL_FreeSurface(tempSurface);
    SDL_RenderCopyEx(_fgame_renderer_global_, tex, NULL, &fgame_rect_dest, 0, NULL, flip);
    SDL_DestroyTexture(tex);
}