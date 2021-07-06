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
#ifndef _FGAME_HEADER_
#define _FGAME_HEADER_

/* Include header library SDL2 */
#include <SDL2/SDL.h>

/* Include header from this include directory project */
#include "FGBegin.hpp"

/* this header for flags in init */
#include "FGFlags.hpp"

/* this header for structure */
#include "FGStruct.hpp"

/* This class it's for get information like ticks */
#include "FGGet.hpp"

/* This section header for macro, for helper */
#include "FGMacro.hpp"

/* This class it's for using in future, like load image */
#include "FGImage.hpp"

/* This class it's for using in future, for manage or variable of sound */
#include "FGSound.hpp"

/* This class for helping set any data */
#include "FGSet.hpp"

/* This class for helping in TTF */
#include "FGTTF.hpp"

/* This class for helping in Net connection */
#include "FGNet.hpp"

/* This class for helping in File Management */
#include "FGFile.hpp"

/* This class it's for using in future, like function delay */
#include "FGRun.hpp"

/* This class it's all management of this project */
#include "FGameV2.hpp"

#endif /* _FGAME_HEADER_ */