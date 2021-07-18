## Image | Render

| Home                     | Index                          |
|:-------------------------|:-------------------------------|
| [Home](../../index.html) | [Index](../documentation.html) |

### Description
This function is used to show the image and put where it will be shown.
Before using it would be nice to know the parameters used.
```cpp
  Render(FG_Image& source_image, FG_Rect& rectSprite, bool flip, FGData_System& system, std::string& message_error, bool& errorEvent)
```

The first parameter is your variable references [FG_Image](../struct/fg_image.html). 
The second parameter is this rectangle to set the width, height, x, and y [FG_Rect](../struct/fg_rect.html).
The third parameter is flip, if you give false image flip into right But if you giving true image flip into left.
Fourth, fifth and sixth will be filled using macros [Macro Pointer](../macro/fgame_this_pointer.html) or 
[Macro Default](../macro/fgame_this_default.html).
This macro is adjusted by the main controller in the form of a pointer or or a regular form.

### Example
```cpp
  /* Include header C++ */
  #include <iostream>
  #include <string>

  /* Include header FGame */
  #ifndef FGAME_IMAGE
    #define FGAME_IMAGE
  #endif
  #include <FGame.hpp>

  /* Setup variable image into global */
  FG_Image player;
  FG_Rect playerRect;

  /* Settings global variable */
  FG_Color WHITE = { 255, 255, 255 };

  int main(int argc, const char* argv[]) {
    /* Don't forget flags image */
    FGameV2 Manage = FGameV2({ FG_INIT, FG_IMAGE_INIT }, "Load Image");
    
    /* Setup Player */
    Manage.Run.Image.Load(player, "assets/img/player.png", FG_THIS_DEFAULT(Manage));
    playerRect.x = 20;
    playerRect.y = 40;
    playerRect.width = player.width * 3;
    playerRect.height = player.height * 3;
    
    Manage.StartLooping(
    /* Handle events */
    [](SDL_Event& event, FGameV2* fgame) -> void {
      /* Set background color */
      fgmae->SetBackground(WHITE);
    },
    [](FGameV2* fgame) -> void {
      /* Render Image */
      fgame->Run.Image.Render(player, playerRect, false, FG_THIS_POINTER(fgame));
    },
    /* Set fps into 60 */
    60);
    return 0;
  }
```
