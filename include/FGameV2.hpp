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
#ifndef _FGAME_VERSION_2_HEADER_
#define _FGAME_VERSION_2_HEADER_

/* Include header C++ */
#include <vector>

/* Include header in include directory from this project */
#include "FGBegin.hpp"
#include "FGStruct.hpp"
#include "Get/FGGet.hpp"
#include "Run/FGRun.hpp"

class FGAME_CALL FGameV2 {
	/* Public for setup variable */
	public:
		/* This variable for management system in SDL2 */
		FGData_System System;
		
		/* This variable for get error message */
		std::string ErrorMessage;

		/* This variable for get error */
		bool ErrorEvent = false;

	/* Private for setup run program */
	private:
		/* This variable for check condition looping */
		bool StartLoopingEvent = false;

		/* This variable for get what's the init library */
		std::vector<unsigned int> what_init;

	/* Public for helper */
	public:
		/* This variable for helper get information */
		FGGet Get;

		/* This variable for helper, This for using in future */
		FGRun Run;

	/* Public function for setup */
	public:
		/* Function Contructor */
		FGameV2(std::vector<unsigned int> flags, const std::string title,
			const Uint32 flagsWindow = 0);

		/* Function Decontructor */
		~FGameV2();

	/* Public function for settings */
	public:
		/* This function for set icon in window */
		#if defined(FGAME_IMAGE) || defined(FGAME_ALL)
			void SetIcon(const std::string LocationIcon);
		#endif

		/* This function for set size of window */
		void SetSize(const float width, const float height);

		/* This function for set background color of window */
		void SetBackground(const FG_Color color);

		/* This function for set position of window */
		void SetPosition(const float x = SDL_WINDOWPOS_CENTERED,
			const float y = SDL_WINDOWPOS_CENTERED);

	/* Public function for get information error */
	public:
		bool HaveError() const;
		std::string MessageError() const;

	/* Public function for Start Looping */
	public:
		void StartLooping(void(*handleEvent)(SDL_Event& event, FGameV2* fgameV2),
			void(*update)(FGameV2* fgameV2), const float fps);
};

#endif /* _FGAME_VERSION_2_HEADER_ */