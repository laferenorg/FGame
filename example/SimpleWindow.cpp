/* Script example: Simple Window */

/* Include header C++ */
#include <iostream>
#include <string>

/* Include header FGame */
#include <FGame.hpp>

void handleEventsAndExtendUpdate(SDL_Event& event, FGameV2* fgame) {
	/* Set Background */
	fgame->SetBackground({ 0, 255, 0 });
}

void update(FGameV2* fgame) {
	/* Code here */
}

int main(int argc, const char* argv[]) {
	/* Create manger */
	FGameV2 Manager = FGameV2({ FG_INIT }, "Simple Window");

	/* Start looping */
	Manager.StartLooping(handleEventsAndExtendUpdate, update, 60);
	{
		(void)argc;
		(void)argv;
	}
	return 0;
}