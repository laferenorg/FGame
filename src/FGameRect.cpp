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

/* header */
#include <FGame.hpp>

/* Function get center x from class FGameRect */
float _fgame_rect_::get_centerx() {
	/* Return x center */
	return (this->x + (this->width / 2));
}

/* Function get center y from class FGameRect */
float _fgame_rect_::get_centery() {
	/* Return x center */
	return (this->y + (this->height / 2));
}

/* Function Set Size from class FGameRect */
void _fgame_rect_::set_size(float fgame_width,
			  				float fgame_height) {
	/* Setup Data */
	this->width  = fgame_width;
	this->height = fgame_height;
}

/* Function Set Position from class FGameRect */
void _fgame_rect_::set_position(float fgame_x,
							    float fgame_y) {
	/* Setup Data */
	this->x = fgame_x;
	this->y = fgame_y;
}