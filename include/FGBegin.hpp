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
#ifndef _FGAME_BEGIN_HEADER_
#define _FGAME_BEGIN_HEADER_

/* Checl OS For make shared library */
#if defined(_WIN32) || defined(_WIN64)
	/* If this using windows */
	#ifdef BUILD_LIBRARY_FGAME
		/* If macro defined */
		#define FGAME_CALL __declspec(dllexport)
	#else
		/* If macro not define */
		#define FGAME_CALL __declspec(dllimport)
	#endif
#elif defined(__linux__)
	/* If this using linux */
	#define FGAME_CALL
#else
	/* If this not in list */
	#error "Sory, this project support for: Windows and Linux"
#endif

#endif /* End of script begin */