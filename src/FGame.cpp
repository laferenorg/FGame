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

/* Library From SDL2 */
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

/* header */
#include <FGame.hpp>

/* Global Variable Of This Project */
/* Section For Variable Of SDL2 */
SDL_Window   *_fgame_window_global_;
SDL_Renderer *_fgame_renderer_global_;

/* Section For Checking */
bool          _fgame_have_error_global_ = false;
bool          _fgame_have_init_global_  = false;

/* Function init from Class FGame */
void _fgame_::init(Uint32 fgame_flags = 0) {
	/* Give Warning If This Function Have Been Called */
	if(_fgame_have_init_global_) {
		std::cout << "Can't init again" << std::endl;
	}

	/* Initialize SDL2  and check it's have error*/
	if(SDL_Init(SDL_INIT_EVERYTHING) == 0 && !_fgame_have_init_global_) {
		_fgame_window_global_ = SDL_CreateWindow("FGame", FG_WINDOWPOS_CENTERED, FG_WINDOWPOS_CENTERED,
						 						 800, (800 * 0.8), fgame_flags);
		/* Check the window variable have error */
		if(!_fgame_window_global_) {
			_fgame_have_error_global_ = true;
			std::cout << "[" << _fgame_window_global_ << "]: Can't Create Window" << std::endl;
		}

		/* Intialize renderer and check it's have error */
		_fgame_renderer_global_ = SDL_CreateRenderer(_fgame_window_global_, -1,
													 SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
		/* Check the renderer variable have error */
		if(!_fgame_renderer_global_) {
			_fgame_have_error_global_ = true;
			std::cout << "[" << _fgame_renderer_global_ << "]: Can't Create Renderer" << std::endl;
		}

		/* Check the audio */
	    if(Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 4096) == -1) {
	        _fgame_have_error_global_ = true;
	        std::cout << "[" << &_fgame_have_error_global_ << "]: Can't Open Audio (";
	        std::cout << Mix_GetError() << ")" << std::endl;
	    }
	}

	/* Change Init Boolean Variable */
	if(!_fgame_have_init_global_ && !_fgame_have_error_global_) {
		_fgame_have_init_global_ = true;
	}
}

/* Function Set Mode From Class FGame */
void _fgame_::set_size(float fgame_width, float fgame_height) {
	/* Check this have error */
	if(!_fgame_have_init_global_)
		std::cout << "[" << &_fgame_have_init_global_ << "]: Have Not Initialize" << std::endl;
		return;
	if(!_fgame_have_error_global_)
		std::cout << "[" << &_fgame_have_error_global_ << "]: Have Error" << std::endl;
		return;

	/* If have been check it's success */
	SDL_SetWindowSize(_fgame_window_global_, fgame_width, fgame_height);
}

/* Function Set Caption From Class FGame */
void _fgame_::set_caption(std::string fgame_title) {
	/* Check this have error */
	if(_fgame_have_init_global_ == false) {
		std::cout << "[" << &_fgame_have_init_global_ << "]: Have Not Initialize" << std::endl;
		return;
	}
	if(_fgame_have_error_global_ == true) {
		std::cout << "[" << &_fgame_have_error_global_ << "]: Have Error" << std::endl;
		return;
	}

	/* If have been check it's success */
	SDL_SetWindowTitle(_fgame_window_global_, fgame_title.c_str());
}

/* Function Set Background Color From Class FGame */
void _fgame_::fill(FGameColor fgame_color) {
	/* Check this have error */
	if(_fgame_have_init_global_ == false) {
		std::cout << "[" << &_fgame_have_init_global_ << "]: Have Not Initialize" << std::endl;
		return;
	}

	if(_fgame_have_error_global_ == true) {
		std::cout << "[" << &_fgame_have_error_global_ << "]: Have Error" << std::endl;
		return;
	}

	/* If have been check it's success */
	SDL_SetRenderDrawColor(_fgame_renderer_global_,
						   fgame_color.R, fgame_color.G,
						   fgame_color.B, fgame_color.A);
}