/* Script example: Draw */

/* Include header C++ */
#include <iostream>
#include <string>

/* Include header FGame */
#include <FGame.hpp>

/* Global variable rectangle */
FG_Rect rectangleLine;
FG_Rect rectangle;

void handleEventsAndExtendUpdate(SDL_Event& event, FGameV2* fgame) {
	/* Set Background */
	fgame->SetBackground({ 0, 255, 0 });
}

void update(FGameV2* fgame) {
	/* Draw rect */
	fgame->Run.Draw.Rect({ 255, 255, 255 }, rectangle, true,
		FG_THIS_POINTER(fgame));

	/* Draw rect line */
	fgame->Run.Draw.Rect({ 255, 255, 255 }, rectangleLine, false,
		FG_THIS_POINTER(fgame));
}

int main(int argc, const char* argv[]) {
	/* Create manger */
	FGameV2 Manager = FGameV2({ FG_INIT }, "Draw");

	/* Setup rect */
	rectangle.x = 30;
	rectangle.y = 30;
	rectangle.width = 50;
	rectangle.height = 50;

	/* setup rect line */
	rectangleLine.x = 80;
	rectangleLine.y = 80;
	rectangleLine.width = 50;
	rectangleLine.height = 50;

	/* Start looping */
	Manager.StartLooping(handleEventsAndExtendUpdate, update, 60);
	{
		(void)argc;
		(void)argv;
	}
	return 0;
}