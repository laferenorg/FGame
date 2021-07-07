## FGameV2 | Set Background Color

| Home                     | Index                          |
|:-------------------------|:-------------------------------|
| [Home](../../index.html) | [Index](../documentation.html) |

### Description
This function aims to change the color of the window background, 
which if not changed the color will definitely be black.
Before going to the discussion, this info function must be in the 
loop because otherwise it will be like a bug. If you use draw [Draw](../draw/draw.html) 
surely the background will change with the color of the draw that you gave to the draw function.
Okay after that before seeing how you have to know the parameters of the function.
```cpp
  SetBackground(FG_Color color)
```

Okay here there is only the struct color parameter [Struct Color](../struct/fg_color.html).

### Example
```cpp
  /* Include header C++ */
  #include <iostream>
  #include <string>

  /* Include header FGame */
  #include <FGame.hpp>

  void handleEvent(SDL_Event& event, FGameV2* fgame) {
    /* This function is not only to handle events but can also be used as an update loop as usual. */
    /* This function for set background below this */
    fgame->SetBackground({ 0, 255, 0 });
  }

  void update(FGameV2* fgame) {
    /* Code you're script here */
  }

  int main(int argc, const char* argv[]) {
    FGameV2 Manage = FGameV2({ FG_INIT }, "Compile You're Code");

    Manage.StartLooping(handleEvent, update, 60);
    return 0;
  }
```
