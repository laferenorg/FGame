/* Script example: Text */

/* Include header C++ */
#include <iostream>
#include <string>

/* Include header FGame */
#include <FGame.hpp>

/* Global variable */
FG_TTF Text;
FG_Rect textRect;

void handleEventsAndExtendUpdate(SDL_Event& event, FGameV2* fgame) {
	/* Set Background */
	fgame->SetBackground({ 0, 255, 0 });
}

void update(FGameV2* fgame) {
	/* Render text */
	fgame->Run.TTF.render(Text, textRect, FG_THIS_POINTER(fgame));
}

int main(int argc, const char* argv[]) {
	/* Create manger */
	FGameV2 Manager = FGameV2({ FG_INIT, FG_TTF_INIT }, "Text");

	/* Load Text and configure */
	Manager.Run.Set.SetRectSize(textRect, 600, 100);
	Manager.Run.Set.SetRectPosition(textRect, 0, 0);
	Manager.Run.TTF.load(Text, "Example FGame", "assets/Fonts/font.ttf",
		{ 255, 255, 255 }, 24, FG_THIS_DEFAULT(Manager));

	/* Start looping */
	Manager.StartLooping(handleEventsAndExtendUpdate, update, 60);
	{
		(void)argc;
		(void)argv;
	}
	return 0;
}