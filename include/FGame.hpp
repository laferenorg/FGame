#ifndef _FGAME_HPP_
#define _FGAME_HPP_

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

/* Include Library Of C++ */
#include <iostream>

/* Include Library Of SDL2 */
#include <SDL2/SDL.h>

#ifdef _WIN32
	extern "C" {

	#ifdef FGAME_EXPORTS_LIBRARY
		#define FGAME_FRAMEWORK __declspec(dllexport)
	#else
		#define FGAME_FRAMEWORK __declspec(dllimport)
	#endif
#endif

/* Changed Flags Window */
#define FG_WINDOWPOS_CENTERED        SDL_WINDOWPOS_CENTERED          /* Change Window Pos Centered in SDL2       */
#define FG_WINDOW_FULLSCREEN         SDL_WINDOW_FULLSCREEN           /* Changed Flags FullScreen in SDL2         */
#define FG_WINDOW_FULLSCREEN_DESKTOP SDL_WINDOW_FULLSCREEN_DESKTOP   /* Changed Flags Fullscreen in SDL2         */
#define FG_WINDOW_OPENGL             SDL_WINDOW_OPENGL               /* Chnaged Flags OPENGL in SDL2             */
#define FG_WINDOW_VULKAN             SDL_WINDOW_VULKAN               /* Changed Flags VULKAN in SDL2             */
#define FG_WINDOW_SHOWN              SDL_WINDOW_SHOWN                /* Changed Flags Shown in SDL2              */
#define FG_WINDOW_HIDDEN             SDL_WINDOW_HIDDEN               /* Changed Flags Hidden in SDL2             */
#define FG_WINDOW_BORDERLESS         SDL_WINDOW_BORDERLESS           /* Changed Flags Border in SDL2             */
#define FG_WINDOW_RESIZABLE          SDL_WINDOW_RESIZABLE            /* Changed Flags Resize in SDL2             */
#define FG_WINDOW_MINIMIZED          SDL_WINDOW_MINIMIZED            /* Changed Flags Minimized in SDL2          */
#define FG_WINDOW_MAXIMIZED          SDL_WINDOW_MAXIMIZED            /* Changed Flags Maximized in SDL2          */
#define FG_WINDOW_INPUT_GRABBED      SDL_WINDOW_INPUT_GRABBED        /* Changed Flags Input Grabbed in SDL2      */
#define FG_WINDOW_INPUT_FOCUS        SDL_WINDOW_INPUT_FOCUS          /* Changed Flags Input Focus in SDL2        */
#define FG_WINDOW_MOUSE_FOCUS        SDL_WINDOW_MOUSE_FOCUS          /* Changed Flags Mouse Focus in SDL2        */
#define FG_WINDOW_FOREIGN            SDL_WINDOW_FOREIGN              /* Changed Flags Foreign in SDL2            */
#define FG_WINDOW_ALLOW_HIGHDPI      SDL_WINDOW_ALLOW_HIGHDPI        /* Changed Flags Allow HIGHDPI in SDL2      */
#define FG_WINDOW_MOUSE_CAPTURE      SDL_WINDOW_MOUSE_CAPTURE        /* Changed Flags Mouse Capture in SDL2      */
#define FG_WINDOW_ALWAYS_ON_TOP      SDL_WINDOW_ALWAYS_ON_TOP        /* Changed Flags Always on top in SDL2      */
#define FG_WINDOW_SKIP_TASKBAR       SDL_WINDOW_SKIP_TASKBAR         /* Changed Flags Skip Task bar in SDL2      */
#define FG_WINDOW_UTILITY            SDL_WINDOW_UTILITY              /* Changed Flags Utility in SDL2            */
#define FG_WINDOW_TOOLTIP            SDL_WINDOW_TOOLTIP              /* Changed Flags Tooltip in SDL2            */
#define FG_WINDOW_POPUP_MENU         SDL_WINDOW_POPUP_MENU           /* Changed Flags Popup Menu in SDL2         */

/* Event Type */
enum _fgame_type_ {
	FG_QUIT            = SDL_QUIT,            /* Copy data into enum Quit        */
	FG_APP_TERMINATING = SDL_APP_TERMINATING, /* Copy data into enum Terminating */
	FG_APP_LOWMEMORY   = SDL_APP_LOWMEMORY,   /* Copy data into enum Low memory  */
	FG_KEYDOWN         = SDL_KEYDOWN,         /* Copy data into enum Keydown     */
	FG_KEYUP           = SDL_KEYUP            /* Copy data into enum Keyup       */
};

typedef enum _fgame_type_ FGameType;

/* Event Key */
enum _fgame_key_ {
	/* Event Number: Copy into FG_NUM */
	FG_0 = SDLK_0, FG_1 = SDLK_1, FG_2 = SDLK_2,
	FG_3 = SDLK_3, FG_4 = SDLK_4, FG_5 = SDLK_5,
	FG_6 = SDLK_6, FG_7 = SDLK_7, FG_8 = SDLK_8,
	FG_9 = SDLK_9,

	/* Event Char: Copy into FG_Char */
	FG_A = SDLK_a, FG_B = SDLK_b, FG_C = SDLK_c,
	FG_D = SDLK_d, FG_E = SDLK_e, FG_F = SDLK_f,
	FG_G = SDLK_g, FG_H = SDLK_h, FG_I = SDLK_i,
	FG_J = SDLK_j, FG_K = SDLK_k, FG_L = SDLK_l,
	FG_M = SDLK_m, FG_N = SDLK_n, FG_O = SDLK_o,
	FG_P = SDLK_p, FG_Q = SDLK_q, FG_R = SDLK_r,
	FG_S = SDLK_s, FG_T = SDLK_t, FG_U = SDLK_u,
	FG_V = SDLK_v, FG_W = SDLK_w, FG_X = SDLK_x,
	FG_Y = SDLK_y, FG_Z = SDLK_z,

	/* Event UP, DOWN, RIGHT, LEFT */
	FG_UP = SDLK_UP, FG_RIGHT = SDLK_RIGHT,
	FG_LEFT = SDLK_LEFT, FG_DOWN = SDLK_DOWN
};

typedef enum _fgame_key_ FGameKey;

/* Color 4: RED GREEN BLUE ALPHA */
typedef struct {
	unsigned int R, G, B, A;
} FGameColor;

/* Struct event for FGameEvent */
struct _fgame_event_ {
	int type;
	int key;
};

typedef struct _fgame_event_ FGameEvent;

/* Class For FGameRun */
class _fgame_run_ {
public:
	static void run(void(*handleEvent_fgame)(FGameEvent&),
					void(*callback_fgame)(), float FPS); /* Run function */
};

typedef class _fgame_run_ FGameRun;

/* Class For FGame */
class _fgame_ {
public:
	/* Public Function In FGame Class */
	static void init(Uint32 fgame_flags);                        /* Init Function From This Class                 */
	static void set_size(float fgame_width, float fgame_height); /* Set Mode Function From This Class             */
	static void set_caption(std::string fgame_title);            /* Set Title Function From This Class            */
	static void fill(FGameColor fgame_color);                    /* Set background color function from this class */
};

typedef class _fgame_ FGame;

/* Class For FGameRect */
class _fgame_rect_ {
public:
	float width, height;
	float x, y;
public:
	float get_centerx(); /* Get center x function */
	float get_centery(); /* Get center y function */
public:
	void set_size(float fgame_width,
				  float fgame_height); /* Set Size Function     */
	void set_position(float fgame_x,
					  float fgame_y);  /* Set Position Function */
};

typedef class _fgame_rect_ FGameRect;

/* Struct For Image */
struct _fgame_image_ {
	std::string _fgame_path_location_;
	float width, height;
};

typedef struct _fgame_image_ FGameImage;

/* Class For FGameImageM */
class _fgame_image_m_ {
public:
	static FGameImage load(std::string fgame_image_path);                                    /* Load function        */
	static void Render(FGameImage& fgame_image, FGameRect& fgame_rect);                      /* Render function      */
	static void RenderFlip(FGameImage& fgame_image, FGameRect& fgame_rect, bool fgame_left); /* Render Flip function */
};

typedef class _fgame_image_m_ FGameImageM;

/* Class For FGameManage */
class _fgame_manage_ {
public:
	static void Quit();                                  /* Quit Application function         */
	static Uint32 FG_GetTicks();                         /* Get Ticks function                */
	static Uint64 FG_GetPerformanceFrequency();          /* Get Performace Frequency function */
	static Uint64 FG_GetPerformanceCounter();            /* Get Performace Counter function   */
	static void FG_Delay(float fgame_delay);             /* Delay Application function        */
	static bool spritecollide(FGameRect& fgame_sprite1,
							  FGameRect& fgame_sprite2); /* Sprite Collider function          */
};

typedef class _fgame_manage_ FGameManage;

/* Class For FGameDraw */
class _fgame_draw_ {
public:
	static void line(FGameColor fgame_color,
					 float fgame_x1, float fgame_y1,
					 float fgame_x2, float fgame_y2);  /* Draw line function */
	static void rectFill(FGameColor fgame_color,
						 FGameRect& fgame_rect);       /* Draw Rect Fill     */
	static void rect(FGameColor fgame_color,
				     FGameRect& fgame_rect);           /* Draw Rect          */
};

typedef class _fgame_draw_ FGameDraw;

#ifdef _WIN32
	}
#endif

#endif // _FGAME_HPP_