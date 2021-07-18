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

/* This script will run if support sound */
#if defined(FGAME_MIXER) || defined(FGAME_ALL)

/* Include header C++ */
#include <iostream>
#include <fstream>
#include <string>
#include <ios>
#include <memory>

/* Include header library SDL2 */
#include <SDL2/SDL_mixer.h>

/* Include header from include directory in this project */
#include "Run/FGSound.hpp"
#include "FGStruct.hpp"

/* Handle function FGWav */
FGWav::FGWav(const std::string &path, const int volume,
	const FGData_System& system, std::string& message_error, bool& errorEvent) 
	: chunk(Mix_LoadWAV(path.c_str()), Mix_FreeChunk) {
	/* Check if have error before */
	if(errorEvent) {
		/* if have error */
		/* Write message error */
		message_error = "Can't run set Load WAV because, you have error ";
		message_error += "before you running this function ";
		message_error += "| in function FGWav::FGWav";
	} else if(!chunk.get()) {
		/* If no have error with chunck */
		/* Check if file exist */
		std::ifstream TempCheckFile;
		TempCheckFile.open(path, std::ios::binary);
		
		/* Check if file not exist */
		if(!TempCheckFile.is_open()) {
			/* If file not exist */
			/* set error event into true */
			errorEvent = true;

			/* Write message error */
			message_error = "FGame not defined file name: ";
			message_error += path + " | in function FGWav::FGWav";
		}

		/* Close file */
		TempCheckFile.close();

		/* Check if have error */
		if(!errorEvent) {
			/* If not have error */
			/* Set volume wav */
			Mix_VolumeChunk(chunk.get(), volume);
		}
	}
}

/* Handle function wav play */
void FGWav::play() const {
	/* -1 here means we let SDL_mixer pick the first channel that is free */
	/* If no channel is free it'll return an err code. */
	Mix_PlayChannel(-1, chunk.get(), 0);
}

/* Handle function FGMusic */
FGMusic::FGMusic(const std::string &path, const int volume,
	const FGData_System& system, std::string& message_error, bool& errorEvent) 
	: chunk(Mix_LoadMUS(path.c_str()), Mix_FreeMusic) {
	/* Check if have error before */
	if(errorEvent) {
		/* if have error */
		/* Write message error */
		message_error = "Can't run set Load Music because, you have error ";
		message_error += "before you running this function ";
		message_error += "| in function FGMusic::FGMusic";
	} else if(!chunk.get()) {
		/* If no have error with chunck */
		/* Check if file exist */
		std::ifstream TempCheckFile;
		TempCheckFile.open(path, std::ios::binary);
		
		/* Check if file not exist */
		if(!TempCheckFile.is_open()) {
			/* If file not exist */
			/* set error event into true */
			errorEvent = true;

			/* Write message error */
			message_error = "FGame not defined file name: ";
			message_error += path + " | in function FGMusic::FGMusic";
		}

		/* Close file */
		TempCheckFile.close();

		/* Set volume wav */
		Mix_VolumeMusic(volume);
	}
}

/* Handle function play music */
void FGMusic::play(const int loops) const {
	/* Just play music */
	Mix_PlayMusic(chunk.get(), loops);
}

/* Handle function wav */
FGWav* FGSound::wav(const std::string path, const int volume,
	const FGData_System& system, std::string& message_error, bool& errorEvent) {
	/* TODO: Just create init and return */
	return new FGWav(path, (volume > 128) ? 128 : volume, 
		system, message_error, errorEvent);
}

/* Handle function music */
FGMusic* FGSound::music(const std::string path, const int volume,
	const FGData_System& system, std::string& message_error, bool& errorEvent) {
	/* TODO: Just create init and return */
	return new FGMusic(path, (volume > 128) ? 128 : volume, 
		system, message_error, errorEvent);
}

#endif