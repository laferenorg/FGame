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
#include <queue>
#include <cmath>
#include <fstream>

/* Library From SDL2 */
#include <SDL2/SDL.h>
#include <SDL2/SDL_audio.h>
#include <SDL2/SDL_mixer.h>

/* header */
#include <FGame.hpp>

/* Global Variable Of This Project */
/* Section For Checking */
extern bool _fgame_have_init_global_;

/* structure of BeepObject */
struct fgame_been_object {
    double freq;
    int samplesLeft;
};

// class for beeper
class fgame_beeper {
    private:
        double v;
        std::queue<fgame_been_object> beeps;
    public:
        fgame_beeper();
        ~fgame_beeper();
        void beep(double freq, int duration);
        void generateSamples(Sint16 *stream, int length);
        void wait();
};

/* function audio callback */
void audio_callback(void*, Uint8*, int);

// variable for settings
const int AMPLITUDE = 28000;
const int FREQUENCY = 44100;

/* function contructor prototype */
fgame_beeper::fgame_beeper() {
    SDL_AudioSpec fgame_desiredspec;

    fgame_desiredspec.freq     = FREQUENCY;
    fgame_desiredspec.format   = AUDIO_S16SYS;
    fgame_desiredspec.channels = 1;
    fgame_desiredspec.samples  = 2048;
    fgame_desiredspec.callback = audio_callback;
    fgame_desiredspec.userdata = this;

    SDL_AudioSpec fgame_obtainedspec;

    // you might want to look for errors here
    SDL_OpenAudio(&fgame_desiredspec, &fgame_obtainedspec);

    // start play audio
    SDL_PauseAudio(0);
}

/* function deconstructor prototype */
fgame_beeper::~fgame_beeper() {
    SDL_CloseAudio();
}

/* function generate sample */
void fgame_beeper::generateSamples(Sint16 *stream, int length) {
    int i = 0;
    while (i < length) {
        if (beeps.empty()) {
            while (i < length) {
                stream[i] = 0;
                i++;
            }
            return;
        }
        fgame_been_object& bo = beeps.front();

        int samplesToDo = std::min(i + bo.samplesLeft, length);
        bo.samplesLeft -= samplesToDo - i;

        while (i < samplesToDo) {
            stream[i] = AMPLITUDE * std::sin(v * 2 * M_PI / FREQUENCY);
            i++;
            v += bo.freq;
        }

        if (bo.samplesLeft == 0) {
            beeps.pop();
        }
    }
}

/* function prototype beepe */
void fgame_beeper::beep(double freq, int duration) {
    fgame_been_object fgame_bo;
    fgame_bo.freq        = freq;
    fgame_bo.samplesLeft = duration * FREQUENCY / 1000;

    SDL_LockAudio();
    beeps.push(fgame_bo);
    SDL_UnlockAudio();
}

/* function protype wait */
void fgame_beeper::wait() {
    int size;
    do {
        SDL_Delay(20);
        SDL_LockAudio();
        size = beeps.size();
        SDL_UnlockAudio();
    } while (size > 0);

}

// function prototype audio_callback
void audio_callback(void *_beeper, Uint8 *_stream, int _length)
{
    Sint16 *stream = (Sint16*) _stream;
    int length = _length / 2;
    fgame_beeper* beeper = (fgame_beeper*) _beeper;
    beeper->generateSamples(stream, length);
}

/* Global Variable */
fgame_beeper fgame_global_beep_;

/* Function play tone from class FGameSound */
void _fgame_sound_::tone(FGameTone fgame_tone) {
	/* Check it's has already in init */
	if(!_fgame_have_init_global_) {
		std::cout << "[" << &_fgame_have_init_global_ << "]: Can't play sound" << std::endl;
		return;
	}
	
	/* Play sound */
	fgame_global_beep_.beep(fgame_tone.fgame_hz, fgame_tone.fgame_duration);

	/* Check if the variable boolean true */
    fgame_global_beep_.wait();
}

/* Function WAV tone from class FGameSound */
void _fgame_sound_::wav(std::string fgame_path, int fgame_volume) {
    /* Check boolean variable */
    bool exist_sound = true;

    /* Check exist file */
    {
        std::fstream _fgame_sound_check;
        _fgame_sound_check.open(fgame_path, std::ios::in | std::ios::binary);
        if(!_fgame_sound_check.is_open()) {
            exist_sound = false;
            std::cout << "[" << &_fgame_sound_check << "]: Can't find wav" << std::endl;
            exit(-1);
        }
        _fgame_sound_check.close();
    }

    if(exist_sound) {
        /* Setup Variable */
        Uint32 points = 0;
        Uint32 frames = 0;
        int    freq   = 0;
        Uint16 fmt    = 0;
        int    chans  = 0;

        Mix_Chunk* fgame_sound = Mix_LoadWAV(fgame_path.c_str());

        if(fgame_sound == NULL) {
            std::cout << "[" << fgame_sound << "]: Can't play wav" << std::endl;
            exit(-1);
        }

        Mix_VolumeChunk(fgame_sound, fgame_volume);

        /* Play */
        if(Mix_PlayChannel(-1, fgame_sound, 0) == -1){
            std::cout << "[" << fgame_sound << "]: Can't play wav (";
            std::cout << Mix_GetError() << ")" << std::endl;
            exit(-1);
        }

        if(!Mix_QuerySpec(&freq, &fmt, &chans)) {
            std::cout << "[" << fgame_sound << "]: Can't play wav" << std::endl;
            exit(-1);
        }

        points = (fgame_sound->alen / ((fmt & 0xFF) / 8));
        frames = (points / chans);

        SDL_Delay(((frames * 1000) / freq) * 0.35);

        /* Free */
        Mix_FreeChunk(fgame_sound);
    }
}