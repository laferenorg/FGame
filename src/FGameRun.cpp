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
#include <vector>
#include <memory>
#include <ctime>

/* Library From SDL2 */
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

/* header */
#include <FGame.hpp>
#include <FGameSound.hpp>

/* Global Variable Of This Project */
/* Section For Variable Of SDL2 */
extern SDL_Renderer *_fgame_renderer_global_;
extern SDL_Window   *_fgame_window_global_;

/* Section For Checking */
extern bool          _fgame_have_error_global_;
extern bool          _fgame_have_init_global_;
bool                 _fgame_run_program_ = false;
FGameEvent           _fgame_event_call_;
SDL_Event            _fgame_event_;

/* Function run from class FGameRun */
void _fgame_run_::run(void(*handleEvent_fgame)(FGameEvent&),
					  void(*callback_fgame)(), float FPS) {
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
	
	/* Variable setup */
	Uint32 start;

	/* Check and Set Run Program Variable */
	if(!_fgame_have_error_global_ && _fgame_have_init_global_) {
		_fgame_run_program_ = true;
	}

	/* Run program */
	while(_fgame_run_program_) {
		/* Setup start variable */
		start = FGameManage::FG_GetTicks();

		/* Start handle event */
	    SDL_PollEvent(&_fgame_event_);

	    /* Event Setup */
	    _fgame_event_call_.type = _fgame_event_.type;
	    _fgame_event_call_.key  = _fgame_event_.key.keysym.sym;

	    /* Handle Event */
	    switch(_fgame_event_.type) {
	    	case SDL_QUIT: {
	    		FGameManage::Quit();
	    	}
	    	break;
	    }
	    handleEvent_fgame(_fgame_event_call_);

	    /* Start handle render */
	    SDL_RenderClear(_fgame_renderer_global_);
	    /* Run Call Back */
	    callback_fgame();
	    /* End handle render */
	    SDL_RenderPresent(_fgame_renderer_global_);

		/* Check FPS, And Delay */
		if(1000 / FPS > FGameManage::FG_GetTicks() - start) {
			FGameManage::FG_Delay(1000 / FPS - (FGameManage::FG_GetTicks() - start));
		}
	}
	
	/* Destroy */
	SDL_DestroyRenderer(_fgame_renderer_global_);
	SDL_DestroyWindow(_fgame_window_global_);
	
	/* Quit */
	Mix_CloseAudio();
	TTF_Quit();
	SDL_Quit();
}