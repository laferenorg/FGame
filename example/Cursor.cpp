/* Script example: Draw */

/* Include header C++ */
#include <iostream>
#include <string>

/* Include header FGame */
#include <FGame.hpp>

/* Setup variable rect */
FG_Rect rectangle;

void handleEventsAndExtendUpdate(SDL_Event& event, FGameV2* fgame) {
	/* Set Background */
	fgame->SetBackground({ 0, 255, 0 });

	/* Event */
	if(fgame->Get.Cursor.Click(rectangle, FG_THIS_POINTER(fgame))) {
		fgame->SetBackground({ 255, 0, 0 });		
	}
}

void update(FGameV2* fgame) {
	/* Render */
	fgame->Run.Draw.Rect({ 255, 255, 255 }, rectangle, true,
		FG_THIS_POINTER(fgame));
	fgame->Run.Draw.Rect({ 241, 241, 241, 1 }, fgame->System.cursor, false,
		FG_THIS_POINTER(fgame));
}

int main(int argc, const char* argv[]) {
	/* Create manger */
	FGameV2 Manager = FGameV2({ FG_INIT }, "Draw");

	/* Settings */
	Manager.Run.Cursor.Show(false, FG_THIS_DEFAULT(Manager));

	/* Setup rect */
	rectangle.x = 20;
	rectangle.y = 20;
	rectangle.width = 60;
	rectangle.height = 60;

	/* Start looping */
	Manager.StartLooping(handleEventsAndExtendUpdate, update, 60);
	{
		(void)argc;
		(void)argv;
	}
	return 0;
}