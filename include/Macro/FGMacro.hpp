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
#ifndef _FGAME_MACRO_HEADER_
#define _FGAME_MACRO_HEADER_

/* This macro for giving version of This Project Version */
#ifndef FG_VERSION
	#define FG_VERSION "2.0.0"
#endif

/* This macro it's for giving into parameter */
#ifndef FG_THIS_POINTER
	#define FG_THIS_POINTER(This) \
				This->System, This->ErrorMessage, \
				This->ErrorEvent
#endif

#ifndef FG_THIS_DEFAULT
	#define FG_THIS_DEFAULT(This) \
				This.System, This.ErrorMessage, \
				This.ErrorEvent
#endif

#endif /* _FGAME_MACRO_HEADER_ */