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
#include <SDL2/SDL_ttf.h>

/* header */
#include <FGame.hpp>

/* Global Variable Of This Project */
/* Section For Variable Of SDL2 */
extern SDL_Renderer *_fgame_renderer_global_;

void _fgame_font_m_::load(FGameFont& fgame_font, std::string fgame_text,
					 	  std::string fgame_path, FGameColor fgame_color,
					 	  int fgame_size) {
	/* Setup */
	fgame_font.color             = fgame_color;
	fgame_font.text              = fgame_text;
	fgame_font._fgame_font_path_ = fgame_path;
	fgame_font.size              = fgame_size;

	/* Color */
	uint8_t      R = fgame_font.color.R, G = fgame_font.color.G,
				 B = fgame_font.color.B, A = fgame_font.color.A;

	/* Setup Width Height */
	TTF_Font*    font            = TTF_OpenFont(fgame_path.c_str(), fgame_size);
	SDL_Color    font_color      = { R, G, B, A };
	SDL_Surface* font_surface    = TTF_RenderText_Solid(font, fgame_font.text.c_str(), font_color);
	fgame_font.width             = font_surface->w;
	fgame_font.height            = font_surface->h;
	SDL_FreeSurface(font_surface);
	TTF_CloseFont(font);
}

void _fgame_font_m_::render(FGameFont& fgame_font, FGameRect& fgame_rect) {
	/* Setup */
	SDL_Rect fgame_rect_dest;
	fgame_rect_dest.w = fgame_rect.width;
	fgame_rect_dest.h = fgame_rect.height;
	fgame_rect_dest.x = fgame_rect.x;
	fgame_rect_dest.y = fgame_rect.y;

	/* Color */
	uint8_t      R = fgame_font.color.R, G = fgame_font.color.G,
				 B = fgame_font.color.B, A = fgame_font.color.A;

	/* Setup Width Height */
	TTF_Font*    font            = TTF_OpenFont(fgame_font._fgame_font_path_.c_str(), fgame_font.size);
	SDL_Color    font_color      = { R, G, B, A };
	SDL_Surface* font_surface    = TTF_RenderText_Solid(font, fgame_font.text.c_str(), font_color);
	SDL_Texture* Message         = SDL_CreateTextureFromSurface(_fgame_renderer_global_, font_surface);
	SDL_FreeSurface(font_surface);
	TTF_CloseFont(font);
	SDL_RenderCopy(_fgame_renderer_global_, Message, NULL, &fgame_rect_dest);
	SDL_DestroyTexture(Message);
}