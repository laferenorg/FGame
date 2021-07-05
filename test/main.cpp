#include <iostream>
#include <FGame.hpp>

/* Create variable global sprite image */
FG_Image player1;
FG_Rect rectPlayer;

/* Create variable global sound */
FGWav* bullet;

int main(int argc, char const *argv[])
{
	/* Setup */
	FGameV2 game({ FG_INIT, FG_IMAGE, FG_MIXER }, "FGame");
	game.SetIcon("assets/icon.png");
	game.SetSize(400, 200);
	game.SetPosition();

	/* Setup Player */
	game.Run.Image.Load(player1, "assets/icon.png", FG_THIS_DEFAULT(game));
	rectPlayer.x = 0;
	rectPlayer.y = 0;
	rectPlayer.width = player1.width;
	rectPlayer.height = player1.height;
	game.Run.Set.SetRectSize(rectPlayer, rectPlayer.width * 3, rectPlayer.height * 3);

	/* Setup sound effect */
	bullet = game.Run.Sound.wav("assets/shot.wav", 128, FG_THIS_DEFAULT(game));

	/* Start looping */
	game.StartLooping(
	/* Handle Event function */
	[](SDL_Event& event, FGameV2* back) {
		/* Set background color */
		back->SetBackground({ 0, 255, 0 });
	},
	/* Update function */
	[](FGameV2* back) {
		bullet->play();
		back->Run.Set.SetRectPosition(rectPlayer, rectPlayer.x + 2, rectPlayer.y);
		back->Run.Draw.Rect({ 255, 255, 255 }, rectPlayer, false, FG_THIS_POINTER(back));
		back->Run.Image.Render(player1, rectPlayer, false, FG_THIS_POINTER(back));
	},
	/* Settings fps */
	60);
	{
		(void)argc;
		(void)argv;
	}
	return 0;
}