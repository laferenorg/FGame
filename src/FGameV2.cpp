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
/* Include header C++ */
#include <iostream>
#include <string>
#include <fstream>
#include <ios>

/* Include header SDL2 */
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_net.h>

/* Include header from include directory in this project */
#include "FGameV2.hpp"
#include "FGFlags.hpp"
#include "FGGet.hpp"

/* Handle function contructor */
FGameV2::FGameV2(std::vector<unsigned int> flags, std::string title,
	Uint32 flagsWindow) {
	/* Setup variable flags for init window for SDL2 */
	Uint32 flagsInit = 0;

	/* Check init flags */
	for(int INIT = 0; INIT < ((int)flags.size()); INIT++) {
		switch(flags[INIT]) {
			case FG_INIT: {
				flagsInit = SDL_INIT_EVERYTHING;
			}
			break;
		}
	}

	/* Init SDL2 and check have error or not */
	ErrorEvent = (SDL_Init(flagsInit) == 0) ? false : true;

	/* If init SDl2 have error */
	if(ErrorEvent) {
		/* Get message from SDl2 */
		ErrorMessage = SDL_GetError();
	}

	/* Check if init FGame */
	for(int INIT = 0; INIT < ((int)flags.size()); INIT++) {
		switch(flags[INIT]) {
			case FG_INIT: {
				/* If not have error */
				if(!ErrorEvent) {
					/* Setup window variable */
					System.window = SDL_CreateWindow(title.c_str(), 
						SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
						800, (800 * 0.8), flagsWindow);
					
					/* Setup render variable */
					System.render = SDL_CreateRenderer(System.window, -1,
						SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);

					/* Check have error in window or render */
					if(!System.render || !System.window) {
						/* If have error set error into true */
						ErrorEvent = true;

						/* And write the message error */
						ErrorMessage = "Can't init: ";
						ErrorMessage += (!System.render) ? "render" : "window";
						ErrorMessage += " | In function FGameV2::FGameV2";
					}
				}
			}
			break;
			case FG_IMAGE: {
				/* Setup variable and init */
				int flagsInitImage = IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF;
				int initted = IMG_Init(flagsInitImage);

				/* Check if image init have error */
				if(!flagsInitImage) {
					/* If have error set error into true */
					ErrorEvent = true;

					/* And write the message error */
					ErrorMessage = "Can't init: Image, Init required JPG, PNG, TIF";
					ErrorMessage += " " + ((std::string)IMG_GetError());
					ErrorMessage += " | In function FGameV2::FGameV2";
				}
			}
			break;
			case FG_MIXER: {
				/* Setup mixer and check */
				if(Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 4096) == -1) {
					/* If have error set error into true */
					ErrorEvent = true;

					/* And write the message error */
					ErrorMessage = "Can't init: Mixer, ";
					ErrorMessage += ((std::string)Mix_GetError());
					ErrorMessage += " | In function FGameV2::FGameV2";
				} else {
					/* If no have error */
					/* Amount of channels (Max amount of sounds playing at the same time) */
					Mix_AllocateChannels(32);
				}
			}
			break;
			case FG_TTF: {
				/* Init ttf library and check it's have error */
				if(TTF_Init() == -1) {
					/* If have error set error into true */
					ErrorEvent = true;

					/* And write the message error */
					ErrorMessage = "Can't init: TTF, ";
					ErrorMessage += ((std::string)TTF_GetError());
					ErrorMessage += " | In function FGameV2::FGameV2";
				}
			}
			break;
			case FG_NET: {
				/* Init net library and check it's have error */
				if(SDLNet_Init() == -1) {
					/* If have error set error into true */
					ErrorEvent = true;

					/* And write the message error */
					ErrorMessage = "Can't init: NET, ";
					ErrorMessage += ((std::string)SDLNet_GetError());
					ErrorMessage += " | In function FGameV2::FGameV2";
				}
			}
			break;
		}
	}
}

/* Handle function decontructor */
FGameV2::~FGameV2() {
	/* Free memory */
	SDL_DestroyRenderer(System.render);
	SDL_DestroyWindow(System.window);

	/* Quit */
	SDL_Quit();
}

/* Handle function Start Looping */
void FGameV2::StartLooping(void(*handleEvent)(SDL_Event& event, FGameV2* fgameV2),
	void(*update)(FGameV2* fgameV2), float fps) {
	/* Setup variable for fps */
	Uint32 startTicks;

	/* Set Start Looping Event variable into true if not have error */
	if(!ErrorEvent) {
		/* If ok, Set into true */
		StartLoopingEvent = true;
	}

	/* Start looping */
	while(StartLoopingEvent) {
		/* Set data for startTicks variable */
		startTicks = Get.Ticks();

		/* Get event type or maybe something */
		SDL_PollEvent(&System.event);

		/* Check event it's quit or not */
		switch(System.event.type) {
			case SDL_QUIT: {
				/* Set looping event into false */
				StartLoopingEvent = false;
			}
			break;
		}

		/* Call back function handle event */
		handleEvent(System.event, this);

		/* Call function from SDL2 for Clear renderer */
		SDL_RenderClear(System.render);

		/* Call back update function */
		update(this);

		/* Call function from SDL2 for show or another name present */
		SDL_RenderPresent(System.render);

		/* Proccess fps or another name set frame per seconds */
		if(1000 / fps > Get.Ticks() - startTicks) {
			Run.Delay(1000 / fps - (Get.Ticks() - startTicks));
		}
	}
}

/* Handle function Set Icon */
void FGameV2::SetIcon(std::string LocationIcon) {
	/* Setup variable for checking */
	bool fileAlready = true;

	/* Check location of file */
	std::ifstream TempCheckFile;
	TempCheckFile.open(LocationIcon, std::ios::binary);
	if(!TempCheckFile.is_open()) {
		fileAlready = false; /* If file not already, set varibale into false */
	}
	TempCheckFile.close();

	/* If file already */
	if(fileAlready && !ErrorEvent) {
		/* Setup data variable and filled the data with image */
		SDL_Surface* tempSurface = IMG_Load(LocationIcon.c_str());

		/* Set icon */
		SDL_SetWindowIcon(System.window, tempSurface);

		/* Free Memory */
		SDL_FreeSurface(tempSurface);
	} else {
		/* If file not already */
		ErrorEvent = true;
		if(ErrorEvent) {
			/* If error it's have error from the first */
			ErrorMessage = "Can't run set icon because, you have error ";
			ErrorMessage += "before you running this function ";
			ErrorMessage += "| in function FGameV2::SetIcon";
		} else {
			/* If error file it's not define */
			ErrorMessage = "FGame not defined file name: ";
			ErrorMessage += LocationIcon + " | in function FGameV2::SetIcon";
		}
	}
}

/* Handle function Set Size */
void FGameV2::SetSize(float width, float height) {
	/* Check error before set size of the window */
	if(!ErrorEvent) {
		/* If not have error, Set size of the window */
		SDL_SetWindowSize(System.window, width, height);
	} else {
		/* If have error */
		ErrorMessage = "Can't run set size because, you have error ";
		ErrorMessage += "before you running this function ";
		ErrorMessage += "| in function FGameV2::SetSize";
	}
}

/* Handle function set background */
void FGameV2::SetBackground(FG_Color color) {
	/* Check error before set size of the window */
	if(!ErrorEvent) {
		/* If not have error, Set background color of the window */
		SDL_SetRenderDrawColor(System.render, color.R, color.G, color.B, color.A);
	} else {
		/* If have error */
		ErrorMessage = "Can't run set background because, you have error ";
		ErrorMessage += "before you running this function ";
		ErrorMessage += "| in function FGameV2::SetBackground";
	}
}

/* Handle function set position of window */
void FGameV2::SetPosition(float x, float y) {
	/* Check error before set position of the window */
	if(!ErrorEvent) {
		/* If not haveerror, Set position of the window */
		SDL_SetWindowPosition(System.window, x, y);
	} else {
		/* If have error */
		ErrorMessage = "Can't run set position because, you have error ";
		ErrorMessage += "before you running this function ";
		ErrorMessage += "| in function FGameV2::SetPosition";
	}
}

/* Handle function get event error */
bool FGameV2::HaveError() {
	/* TODO: Just return variable event error */
	return ErrorEvent;
}

/* Handle function get error message */
std::string FGameV2::MessageError() {
	/* TODO: Just return message eror */
	return ErrorMessage;
}