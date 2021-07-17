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

/* Include header C++ */
#include <iostream>
#include <string>
#include <vector>

/* Include header SDL2 */
#include <SDL2/SDL.h>

/* Include header from include directory in this project */
#include "Animation/FGAnimation.hpp"

/* Handle function add animation */
void FGAnimation::AddAnimation(const std::string name_animation,
	const FGData_System& system, std::string& message_error, bool& errorEvent) {
	/* Check if have error before */
	if(errorEvent) {
		/* if have error */
		/* Write message error */
		message_error = "Can't Add Animation because, you have error ";
		message_error += "before you running this function ";
		message_error += "| in function FGAnimation::AddAnimation";
	} else {
		/* If no have error */
		bool ExistName = false;

		/* Check name it's exist or not */
		for(unsigned int ID = 0; ID < ((unsigned int)AnimationName.size()); ID++) {
			if(AnimationName[ID] == name_animation) {
				/* If name exist on animation name */
				/* Set exist name into true */
				ExistName = true;
			}
		}

		/* Check if not exist */
		if(!ExistName) {
			/* If not exist */
			/* Setup variable */
			std::vector<FG_Image> tempVector;

			/* Push data into AnimationData */
			AnimationData.push_back(tempVector);

			/* Push data into AnimationName */
			AnimationName.push_back(name_animation);
		} else {
			/* If exist */
			/* And Set Error Message and Make error event into true */
			errorEvent = true;
			message_error = "FGame the name of the animation already exists: ";
			message_error += name_animation + " | ";
			message_error += "On function FGAnimation::AddAnimation";
		}
	}
}

/* Handle function add frame First */
void FGAnimation::AddFrame(const std::string name_animation, const FG_Image& frame,
	const FGData_System& system, std::string& message_error, bool& errorEvent) {
	/* Check if have error before */
	if(errorEvent) {
		/* if have error */
		/* Write message error */
		message_error = "Can't Add Frame because, you have error ";
		message_error += "before you running this function ";
		message_error += "| in function FGAnimation::AddFrame";
	} else {
		/* If no have error */
		bool ExistName = false;
		unsigned int ID_OF_NAME = 0;

		/* Check name it's exist or not */
		for(unsigned int ID = 0; ID < ((unsigned int)AnimationName.size()); ID++) {
			if(AnimationName[ID] == name_animation) {
				/* If name exist on animation name */
				/* Set exist name into true */
				ExistName = true;

				/* And set data on id of name using ID */
				ID_OF_NAME = ID;
			}
		}

		/* If name exist */
		if(ExistName) {
			/* if name exist on Animation Name */
			/* Push animation into animation data */
			AnimationData[ID_OF_NAME].push_back(frame);
		} else {
			/* If name not exist */
			/* And Set Error Message and Make error event into true */
			errorEvent = true;
			message_error = "FGame the name of the animation doesn't exists: ";
			message_error += name_animation + " | ";
			message_error += "On function FGAnimation::AddFrame";
		}
	}
}

/* Handle function add frame Seconds */
void FGAnimation::AddFrame(const unsigned int id_animation, const FG_Image& frame,
	const FGData_System& system, std::string& message_error, bool& errorEvent) {
	/* Check if have error before */
	if(errorEvent) {
		/* if have error */
		/* Write message error */
		message_error = "Can't Add Frame because, you have error ";
		message_error += "before you running this function ";
		message_error += "| in function FGAnimation::AddFrame";
	} else {
		/* If no have error */
		/* check id is there */
		if(((unsigned int)id_animation) > ((unsigned int)AnimationName.size() - 1)) {
			/* And Set Error Message and Make error event into true */
			errorEvent = true;
			message_error = "FGame No id is meant by number: ";
			message_error += std::to_string(id_animation) + " | ";
			message_error += "On function FGAnimation::AddFrame";
		}

		/* if no have error */
		if(!errorEvent) {
			/* If not have error */
			/* Adding frame */
			AnimationData[((unsigned int)id_animation)].push_back(frame);
		}
	}
}

/* Handle function get animation id */
unsigned int FGAnimation::GetAnimationID(const std::string name_animation,
	const FGData_System& system, std::string& message_error, bool& errorEvent) {
	/* Setup variable return */
	unsigned int ResultSearch = 0;

	/* Check if have error before */
	if(errorEvent) {
		/* if have error */
		/* Write message error */
		message_error = "Can't Get Animation ID because, you have error ";
		message_error += "before you running this function ";
		message_error += "| in function FGAnimation::GetAnimationID";
	} else {
		/* If no have error */
		bool ExistName = false;
		unsigned int ID_OF_NAME = 0;

		/* Check name it's exist or not */
		for(unsigned int ID = 0; ID < ((unsigned int)AnimationName.size()); ID++) {
			if(AnimationName[ID] == name_animation) {
				/* If name exist on animation name */
				/* Set exist name into true */
				ExistName = true;

				/* And set data on id of name using ID */
				ID_OF_NAME = ID;
			}
		}

		/* If name exist */
		if(ExistName) {
			/* if name exist on Animation Name */
			/* Set result backk into ID OF NAME */
			ResultSearch = ID_OF_NAME;
		} else {
			/* If name not exist */
			/* And Set Error Message and Make error event into true */
			errorEvent = true;
			message_error = "FGame the name of the animation doesn't exists: ";
			message_error += name_animation + " | ";
			message_error += "On function FGAnimation::GetAnimationID";
		}
	}

	/* Return result search */
	return ResultSearch;
}

/* Handle function get width */
float FGAnimation::GetWidth(const FGData_System& system, 
	std::string& message_error, bool& errorEvent) {
	/* Setup result variable */
	float widthResult = 0;

	/* Check if have error before */
	if(errorEvent) {
		/* if have error */
		/* Write message error */
		message_error = "Can't Get Width because, you have error ";
		message_error += "before you running this function ";
		message_error += "| in function FGAnimation::GetWidth";
	} else {
		/* If no have error */
		widthResult = AnimationData[animation][frame].width;
	}

	/* Return result */
	return widthResult;
}

/* Handle function get width */
float FGAnimation::GetHeight(const FGData_System& system, 
	std::string& message_error, bool& errorEvent) {
	/* Setup result variable */
	float heightResult = 0;

	/* Check if have error before */
	if(errorEvent) {
		/* if have error */
		/* Write message error */
		message_error = "Can't Get Height because, you have error ";
		message_error += "before you running this function ";
		message_error += "| in function FGAnimation::GetHeight";
	} else {
		/* If no have error */
		heightResult = AnimationData[animation][frame].height;
	}

	/* Return result */
	return heightResult;
}

/* Handle function get frame */
FG_Image& FGAnimation::GetFrame(const FGData_System& system, 
	std::string& message_error, bool& errorEvent) {
	/* Check if have error before */
	if(errorEvent) {
		/* if have error */
		/* Write message error */
		message_error = "Can't Get Height because, you have error ";
		message_error += "before you running this function ";
		message_error += "| in function FGAnimation::GetHeight";
	}

	return AnimationData[animation][frame];
}

/* Handle function Update */
void FGAnimation::Update(const bool end_on_last,
	const FGData_System& system, std::string& message_error, bool& errorEvent) {
	/* Check if have error before */
	if(errorEvent) {
		/* if have error */
		/* Write message error */
		message_error = "Can't Update because, you have error ";
		message_error += "before you running this function ";
		message_error += "| in function FGAnimation::Update";
	} else {
		/* If no have error */
		/* Update Animation */
		if (SDL_GetTicks() - UpdateTime > AnimationCooldown) {
			UpdateTime = SDL_GetTicks();
			frame += 1;
		}

		/* Set back or stuck */
		if (frame >= ((unsigned int)AnimationData[animation].size())) {
			if ((frame == ((unsigned int)AnimationData[animation].size() - 1)) &&
				 end_on_last) {
				/* If end of list true */
				frame = ((unsigned int)AnimationData[animation].size()) - 1;
			} else {
				/* Set back into 0 */
				frame = 0;
			}
		}
	}
}

/* Handle function remove animation using id */
void FGAnimation::RemoveAnimation(const std::string name_animation,
	const FGData_System& system, std::string& message_error, bool& errorEvent) {
	/* Check if have error before */
	if(errorEvent) {
		/* if have error */
		/* Write message error */
		message_error = "Can't Remove Animation because, you have error ";
		message_error += "before you running this function ";
		message_error += "| in function FGAnimation::RemoveAnimation";
	} else {
		/* If no have error */
		bool ExistName = false;
		unsigned int ID_OF_NAME = 0;

		/* Check name it's exist or not */
		for(unsigned int ID = 0; ID < ((unsigned int)AnimationName.size()); ID++) {
			if(AnimationName[ID] == name_animation) {
				/* If name exist on animation name */
				/* Set exist name into true */
				ExistName = true;

				/* And set data on id of name using ID */
				ID_OF_NAME = ID;
			}
		}

		/* If name exist */
		if(ExistName) {
			/* if name exist on Animation Name */
			/* Remove animation */
			AnimationData.erase(AnimationData.begin() + ID_OF_NAME);
		} else {
			/* If name not exist */
			/* And Set Error Message and Make error event into true */
			errorEvent = true;
			message_error = "FGame the name of the animation doesn't exists: ";
			message_error += name_animation + " | ";
			message_error += "On function FGAnimation::RemoveAnimation";
		}
	}
}

/* Handle function remove animation using id */
void FGAnimation::RemoveAnimation(const unsigned int id_animation,
	const FGData_System& system, std::string& message_error, bool& errorEvent) {
	/* Check if have error before */
	if(errorEvent) {
		/* if have error */
		/* Write message error */
		message_error = "Can't Remove Animation because, you have error ";
		message_error += "before you running this function ";
		message_error += "| in function FGAnimation::RemoveAnimation";
	} else {
		/* If no have error */
		/* check id is there */
		if(((unsigned int)id_animation) > ((unsigned int)AnimationName.size() - 1)) {
			/* And Set Error Message and Make error event into true */
			errorEvent = true;
			message_error = "FGame No id is meant by number: ";
			message_error += std::to_string(id_animation) + " | ";
			message_error += "On function FGAnimation::RemoveAnimation";
		}

		/* if no have error */
		if(!errorEvent) {
			/* If not have error */
			/* Remove animation */
			AnimationData.erase(AnimationData.begin() + id_animation);
		}
	}
}