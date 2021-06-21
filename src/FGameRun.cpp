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
FGameEvent           _fgame_event_call_;
SDL_Event            _fgame_event_;

/* Function run from class FGameRun */
void _fgame_run_::run(void(*handleEvent_fgame)(FGameEvent&),
					  void(*callback_fgame)(), float FPS) {
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
}