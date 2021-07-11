/* Include header C++ */
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <ios>
#include <fstream>

/* Include library FGame */
#include <FGame/FGame.hpp>

/* Settings macro */
#define WIDTH     800
#define HEIGHT    640
#define FPS       60
#define ROWS      16
#define COLS      18
#define TILE_SIZE floor(HEIGHT / ROWS)

/* Struct box */
struct Box {
	FG_Rect rect;
	FG_Rect underBox;
	int     id   = 0;
};

/* Global data variable */
std::vector<Box> box_array;
std::vector<Box> box_tools_array;
std::vector<FG_Color> color_array;
FG_Rect mouseRect;
int id = 0;
std::string filePATH = "";
bool ExistFile = false;

/* Handle events */
void handleEvents(SDL_Event& event, FGameV2* fgame) {
	/* Set background */
	fgame->SetBackground({ 241, 241, 241, 1 });

	/* Handle event key */
	switch(event.type) {
		case SDL_QUIT: {
			/* Check name file isn't empty */
			if(!filePATH.empty()) {
				/* If variable name file isn't empty */
				/* Setup variable file management */
				std::ofstream fileManage;

				/* Open file */
				fileManage.open(filePATH, std::ios::trunc | std::ios::binary);
				
				/* Write box */
				for(auto& box : box_array) {
					fileManage.write((char*)&box, sizeof(Box));
				}

				/* Close file */
				fileManage.close();
			}
		}
		break;
		case SDL_KEYDOWN: {
			switch(event.key.keysym.sym) {
				case SDLK_1: {
					fgame->Run.Set.SetRectSize(fgame->System.cursor.rect, 10, 10);
				}
				break;
				case SDLK_2: {
					fgame->Run.Set.SetRectSize(fgame->System.cursor.rect, 20, 20);
				}
				break;
				case SDLK_3: {
					fgame->Run.Set.SetRectSize(fgame->System.cursor.rect, 30, 30);
				}
				break;
				case SDLK_4: {
					fgame->Run.Set.SetRectSize(fgame->System.cursor.rect, 40, 40);
				}
				break;
				case SDLK_5: {
					fgame->Run.Set.SetRectSize(fgame->System.cursor.rect, 50, 50);
				}
				break;
				case SDLK_6: {
					fgame->Run.Set.SetRectSize(fgame->System.cursor.rect, 60, 60);
				}
				break;
				case SDLK_7: {
					fgame->Run.Set.SetRectSize(fgame->System.cursor.rect, 70, 70);
				}
				break;
				case SDLK_8: {
					fgame->Run.Set.SetRectSize(fgame->System.cursor.rect, 80, 80);
				}
				break;
				case SDLK_9: {
					fgame->Run.Set.SetRectSize(fgame->System.cursor.rect, 90, 90);
				}
				break;
			}
			break;
		}
		break;
	}

	/* If cursor click box */
	for(auto& box : box_array) {
		if(fgame->Get.Cursor.Click(box.rect, FG_THIS_POINTER(fgame))) {
			box.id = id;
		}
	}

	for(auto& box : box_tools_array) {
		if(fgame->Get.Cursor.Click(box.rect, FG_THIS_POINTER(fgame))) {
			id = box.id;
		}
	}
}

/* Handle update */
void update(FGameV2* fgame) {
	/* Render Box */
	for(auto& box : box_array) {
		fgame->Run.Draw.Rect({ 17, 13, 14, 0.81 }, box.underBox, true, 
			FG_THIS_POINTER(fgame));
		fgame->Run.Draw.Rect(color_array[box.id], box.rect, true, 
			FG_THIS_POINTER(fgame));
	}

	for(auto& box : box_tools_array) {
		fgame->Run.Draw.Rect({ 17, 13, 14, 0.81 }, box.underBox, true, 
			FG_THIS_POINTER(fgame));
		fgame->Run.Draw.Rect(color_array[box.id], box.rect, true, 
			FG_THIS_POINTER(fgame));
	}

	/* Render Cursor */
	mouseRect = fgame->System.cursor.rect;
	mouseRect.width += 4;
	mouseRect.height += 4;
	mouseRect.x -= 2;
	mouseRect.y -= 2;
	fgame->Run.Draw.Rect({ 17, 13, 14, 0.81 }, mouseRect, true, 
		FG_THIS_POINTER(fgame));
	fgame->Run.Draw.Rect(color_array[id], fgame->System.cursor.rect, true, 
		FG_THIS_POINTER(fgame));
}

int main(int argc, const char* argv[]) {
	/* Get location file for save */
	std::cout << "Input File: ";
	std::getline(std::cin, filePATH);
	if(!filePATH.empty()) ExistFile = true;
	
	/* Test exist file */
	if(ExistFile) {
		/* Setup variable file management */
		std::ifstream testFile;

		/* Test open file */
		testFile.open(filePATH, std::ios::binary);
		
		/* Check if file can't open */
		if(!testFile.is_open()) ExistFile = false;
		
		/* Close file */
		testFile.close();
	}

	/* Setup */
	FGameV2 Manager = FGameV2({ FG_INIT }, "Draw Pixel");
	
	/* Settings Window */
	Manager.SetSize(WIDTH, HEIGHT);
	Manager.Run.Set.SetRectSize(Manager.System.cursor.rect, 10, 10);
	Manager.Run.Cursor.Show(false, FG_THIS_DEFAULT(Manager));
	#if !defined(_WIN32)
		Manager.SetIcon("/home/jonathan/.face");
	#endif
		
	/* Load row and colum */
	if(!ExistFile) {
		/* If not exist file */
		for(int ROW = 0; ROW < ROWS; ROW++) {
			for(int COL = 0; COL < COLS; COL++) {
				/* Setup box */
				Box tempBox;
				Manager.Run.Set.SetRectSize(tempBox.rect, TILE_SIZE - 2, TILE_SIZE - 2);
				Manager.Run.Set.SetRectSize(tempBox.underBox, TILE_SIZE, TILE_SIZE);

				Manager.Run.Set.SetRectPosition(tempBox.rect, 
					TILE_SIZE * COL - 2, TILE_SIZE * ROW - 2);
				Manager.Run.Set.SetRectPosition(tempBox.underBox, 
					TILE_SIZE * COL, TILE_SIZE * ROW);

				/* Push box */
				box_array.push_back(tempBox);
			}
		}
	}

	if(ExistFile) {
		/* If file exist */
		/* Setup variable load pixel */
		std::ifstream LoadPixel;
		
		/* Open file */
		LoadPixel.open(filePATH, std::ios::binary);

		/* Load */
		for(int i = 0; i < (ROWS * COLS); i++) {
			/* Setup box */
			Box tempBox;

			/* Read */
			LoadPixel.seekg(sizeof(Box) * i);
			LoadPixel.read((char*)&tempBox, sizeof(Box));

			/* Push back */
			box_array.push_back(tempBox);
		}

		/* Close file */
		LoadPixel.close();
	}
	
	/* Load color */
	color_array.push_back({ 241, 241, 241, 1 }); /* White */
	color_array.push_back({ 0, 0, 0}); /* Black */
	color_array.push_back({ 0, 255, 0}); /* Green */
	color_array.push_back({ 255, 0, 0}); /* Red */
	color_array.push_back({ 0, 0, 255}); /* Blue */
	color_array.push_back({ 255, 255, 0, 1}); /* Yellow */
	color_array.push_back({ 192, 192, 162, 1}); /* Gray */
	color_array.push_back({ 255, 146, 0, 1}); /* Orange */
	color_array.push_back({ 183, 0, 255, 1}); /* Purple */
	color_array.push_back({ 255, 0, 141, 1}); /* Pink */


	/* Load color tools */
	for(int ROW = 0; ROW < ((int)color_array.size()); ROW++) {
		/* Setup box */
		Box tempBox;
		Manager.Run.Set.SetRectSize(tempBox.rect, TILE_SIZE, TILE_SIZE);
		Manager.Run.Set.SetRectSize(tempBox.underBox, 
			TILE_SIZE + 4, TILE_SIZE + 4);

		Manager.Run.Set.SetRectPosition(tempBox.rect, 
			TILE_SIZE * 19 + 2, TILE_SIZE * ROW + 3);
		Manager.Run.Set.SetRectPosition(tempBox.underBox, 
			TILE_SIZE * 19, TILE_SIZE * ROW + 2);

		tempBox.id = ROW;

		/* Push box */
		box_tools_array.push_back(tempBox);
	}

	/* Start looping */
	Manager.StartLooping(handleEvents, update, FPS);
	{
		(void)argc;
		(void)argv;
	}
	return 0;
}
