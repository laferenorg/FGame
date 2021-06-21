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