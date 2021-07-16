/* Script example: Image */

/* Include header C++ */
#include <iostream>
#include <string>

/* Include header FGame */
#include <FGame.hpp>

/* Global variable */
FG_Image Image;
FG_Rect rectImage;

void handleEventsAndExtendUpdate(SDL_Event& event, FGameV2* fgame) {
	/* Set Background */
	fgame->SetBackground({ 0, 255, 0 });
}

void update(FGameV2* fgame) {
	/* Render Image */
	fgame->Run.Image.Render(Image, rectImage, false, FG_THIS_POINTER(fgame));
}

int main(int argc, const char* argv[]) {
	/* Create manger */
	FGameV2 Manager = FGameV2({ FG_INIT, FG_IMAGE_INIT }, "Image");

	/* Load image */
	Manager.Run.Image.Load(Image, "assets/Img/icon.png",
		FG_THIS_DEFAULT(Manager));

	/* Setup rect */
	rectImage.x = 30;
	rectImage.y = 10;
	rectImage.width = Image.width;
	rectImage.height = Image.height;

	/* Start looping */
	Manager.StartLooping(handleEventsAndExtendUpdate, update, 60);
	{
		(void)argc;
		(void)argv;
	}
	return 0;
}