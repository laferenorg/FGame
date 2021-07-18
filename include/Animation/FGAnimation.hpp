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
#if !defined(_FGAME_ANIMATION_HEADER_) && \
	(defined(FGAME_IMAGE) || defined(FGAME_ALL))
#define _FGAME_ANIMATION_HEADER_

/* Include header C++ */
#include <string>
#include <vector>

/* Include header library SDL2 */
#include <SDL2/SDL.h>

/* Include header in include directory from this project */
#include "../FGBegin.hpp"
#include "../FGStruct.hpp"

class FGAME_CALL FGAnimation {
	/* Private variable for saved data */
	private:
		/* Settings */
		/* Variable for settings frame and animation */
		unsigned int animation = 0;
	
	/* Public variable for save data */
	public:
		unsigned int frame = 0;

	/* Private variable for saved data */
	private:
		/* Variable for updating time */
		float UpdateTime = SDL_GetTicks();
		float AnimationCooldown = 100;

		/* Array of animation settings */
		std::vector<std::vector<FG_Image>> AnimationData;
		std::vector<std::string> AnimationName;

	/* Public function for used */
	public:
		/* This section function for adding animation */
		/* This function for adding animation group */
		void AddAnimation(std::string name_animation,
			const FGData_System& system, std::string& message_error, bool& errorEvent);

		/* This function for adding frame in group animation using name */
		void AddFrame(std::string name_animation, const FG_Image& frame,
			const FGData_System& system, std::string& message_error, bool& errorEvent);

		/* This function for adding frame in group animation using id */
		void AddFrame(const unsigned int id_animation, const FG_Image& frame,
			const FGData_System& system, std::string& message_error, bool& errorEvent);

		/* This for get information or data, etc*/
		/* This function for get animation id from name */
		unsigned int GetAnimationID(std::string name_animation,
			const FGData_System& system, std::string& message_error, bool& errorEvent);

		/* This function for get width using frame and animation now */
		float GetWidth(const FGData_System& system, 
			std::string& message_error, bool& errorEvent);

		/* This function for get height using frame and animation now */
		float GetHeight(const FGData_System& system, 
			std::string& message_error, bool& errorEvent);

		/* This function for get Image using frame and animation now */
		FG_Image& GetFrame(const FGData_System& system, 
			std::string& message_error, bool& errorEvent);

		/* This function for update */
		void Update(const bool end_on_last,
			const FGData_System& system, std::string& message_error, bool& errorEvent);

		/* This section for remove animation */
		/* This for remove animation using name */
		void RemoveAnimation(const std::string name_animation,
			const FGData_System& system, std::string& message_error, bool& errorEvent);

		/* This for remove animation using ID */
		void RemoveAnimation(const unsigned int id_animation,
			const FGData_System& system, std::string& message_error, bool& errorEvent);
};

#endif /* _FGAME_ANIMATION_HEADER_ */