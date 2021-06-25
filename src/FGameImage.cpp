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

/* Section For Checking */
extern bool          _fgame_have_error_global_;
extern bool          _fgame_have_init_global_;

/* Function load from class FGameImageM */
void _fgame_image_m_::load(FGameImage& fgame_image, std::string fgame_image_path) {
	/* Check this have error */
	if(_fgame_have_init_global_ == false) {
		std::cout << "[" << &_fgame_have_init_global_ << "]: Have Not Initialize" << std::endl;
		return;
	}

	if(_fgame_have_error_global_ == true) {
		std::cout << "[" << &_fgame_have_error_global_ << "]: Have Error" << std::endl;
		return;
	}

	/* Setup */
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
		std::cout << "[" << &fgame_image << "]: Can't find image" << std::endl;
		return;
	}

	/* Setup data */
	SDL_Surface* tempSurface     = IMG_Load(fgame_image_path.c_str());
	fgame_image.image            = SDL_CreateTextureFromSurface(_fgame_renderer_global_, tempSurface);
	fgame_image.width            = tempSurface->w;
	fgame_image.height           = tempSurface->h;
	SDL_FreeSurface(tempSurface);
}

/* Function Render from class FGameImageM */
void _fgame_image_m_::Render(FGameImage& fgame_image, FGameRect& fgame_rect) {
	/* Check renderer */
	if(!_fgame_renderer_global_) {
		_fgame_have_error_global_ = true;
		std::cout << "[" << _fgame_renderer_global_ << "]: The renderer have problem" << std::endl;
	}

	/* Check this have error */
	if(_fgame_have_init_global_ == false) {
		std::cout << "[" << &_fgame_have_init_global_ << "]: Have Not Initialize" << std::endl;
		return;
	}

	if(_fgame_have_error_global_ == true) {
		std::cout << "[" << &_fgame_have_error_global_ << "]: Have Error" << std::endl;
		return;
	}

	/* Setup */
	SDL_Rect fgame_rect_dest;
	fgame_rect_dest.w = fgame_rect.width;
	fgame_rect_dest.h = fgame_rect.height;
	fgame_rect_dest.x = fgame_rect.x;
	fgame_rect_dest.y = fgame_rect.y;

    SDL_RenderCopy(_fgame_renderer_global_, fgame_image.image, NULL, &fgame_rect_dest);
}

/* Function Render Flip from class FGameImageM */
void _fgame_image_m_::RenderFlip(FGameImage& fgame_image, FGameRect& fgame_rect, bool fgame_left) {
	/* Check renderer */
	if(!_fgame_renderer_global_) {
		_fgame_have_error_global_ = true;
		std::cout << "[" << _fgame_renderer_global_ << "]: The renderer have problem" << std::endl;
	}

	/* Check this have error */
	if(_fgame_have_init_global_ == false) {
		std::cout << "[" << &_fgame_have_init_global_ << "]: Have Not Initialize" << std::endl;
		return;
	}

	if(_fgame_have_error_global_ == true) {
		std::cout << "[" << &_fgame_have_error_global_ << "]: Have Error" << std::endl;
		return;
	}

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
    SDL_RenderCopyEx(_fgame_renderer_global_, fgame_image.image, NULL, &fgame_rect_dest, 0, NULL, flip);
}

/* Function Free Image from class FGameImageM */
void _fgame_image_m_::FreeImage(FGameImage& fgame_image) {
	/* Check this have error */
	if(_fgame_have_init_global_ == false) {
		std::cout << "[" << &_fgame_have_init_global_ << "]: Have Not Initialize" << std::endl;
		return;
	}

	if(_fgame_have_error_global_ == true) {
		std::cout << "[" << &_fgame_have_error_global_ << "]: Have Error" << std::endl;
		return;
	}
	/* Free Image */
	SDL_DestroyTexture(fgame_image.image);
}