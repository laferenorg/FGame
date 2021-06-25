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

/* header */
#include <FGame.hpp>

/* Global Variable Of This Project */
/* Section For Variable Of SDL2 */
extern SDL_Renderer *_fgame_renderer_global_;

/* Section For Checking */
extern bool          _fgame_have_error_global_;
extern bool          _fgame_have_init_global_;

/* Function draw line */
void _fgame_draw_::line(FGameColor fgame_color,
						float fgame_x1, float fgame_y1,
					 	float fgame_x2, float fgame_y2) {
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
	
	/* Setup Color */
	SDL_SetRenderDrawColor(_fgame_renderer_global_,
						   fgame_color.R, fgame_color.G, fgame_color.B, fgame_color.A);
	/* Draw Line */
	SDL_RenderDrawLine(_fgame_renderer_global_,
					   fgame_x1, fgame_y1,
					   fgame_x2, fgame_y2);
}

/* Function rect fill line */
void _fgame_draw_::rectFill(FGameColor fgame_color,
						    FGameRect& fgame_rect) {
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

	/* Setup Variable */
	SDL_Rect rectTarget;

	/* Setup data */
	rectTarget.x = fgame_rect.x;
	rectTarget.y = fgame_rect.y;
	rectTarget.w = fgame_rect.width;
	rectTarget.h = fgame_rect.height;

	/* Setup Color */
	SDL_SetRenderDrawColor(_fgame_renderer_global_,
						   fgame_color.R, fgame_color.G, fgame_color.B, fgame_color.A);

	/* Draw Rect Fill */
	SDL_RenderFillRect(_fgame_renderer_global_, &rectTarget);
}

/* Function draw rect */
void _fgame_draw_::rect(FGameColor fgame_color,
				        FGameRect& fgame_rect) {
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

	/* Setup Variable */
	SDL_Rect rectTarget;

	/* Setup data */
	rectTarget.x = fgame_rect.x;
	rectTarget.y = fgame_rect.y;
	rectTarget.w = fgame_rect.width;
	rectTarget.h = fgame_rect.height;

	/* Setup Color */
	SDL_SetRenderDrawColor(_fgame_renderer_global_,
						   fgame_color.R, fgame_color.G, fgame_color.B, fgame_color.A);

	/* Draw Rect Fill */
	SDL_RenderDrawRect(_fgame_renderer_global_, &rectTarget);
}