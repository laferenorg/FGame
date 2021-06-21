/* Library From C++ */
#include <iostream>

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
bool                 _fgame_run_program_ = false;

/* Function run from class FGameRun */
void _fgame_run_::run(void(*callback_fgame)(FGameEvent&), float FPS) {
	/* Variable setup */
	Uint32     start;
	FGameEvent event_fgame; 

	/* Check and Set Run Program Variable */
	if(!_fgame_have_error_global_ && _fgame_have_init_global_) {
		_fgame_run_program_ = true;
	}

	/* Run program */
	while(_fgame_run_program_) {
		/* Setup start variable */
		start = FGameManage::FG_GetTicks();

		/* Start handle event */
		SDL_Event event;
	    SDL_PollEvent(&event);

	    /* Setup variable event fgame */
	    event_fgame.type = event.type;
	    event_fgame.key  = event.key.keysym.sym;

	    /* Start handle render */
	    SDL_RenderClear(_fgame_renderer_global_);

	    /* Run Call Back */
	    callback_fgame(event_fgame);

	    /* End handle render */
	    SDL_RenderPresent(_fgame_renderer_global_);

		/* Check FPS, And Delay */
		if(1000 / FPS > FGameManage::FG_GetTicks() - start) {
			FGameManage::FG_Delay(1000 / FPS - (FGameManage::FG_GetTicks() - start));
		}
	}
}