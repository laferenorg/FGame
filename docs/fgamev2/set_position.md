## FGameV2 | Set Position

| Home                     | Index                          |
|:-------------------------|:-------------------------------|
| [Home](../../index.html) | [Index](../documentation.html) |

### Description
This function aims to set the position of the window. 
So you can adjust the position of the window later.
Before doing the experiment, it would be nice to see 
the parameters of the function.
```cpp
  SetPosition(float x, float y)
```

The first parameter is the x position, while the second is the y position. 
Info x it is a horizontal conversion, while y is a vertical conversion.

### Example
```cpp
  /* Include header C++ */
  #include <iostream>
  #include <string>

  /* Include header FGame */
  #include <FGame.hpp>

  void handleEvent(SDL_Event& event, FGameV2* fgame) {
    /* Code you're script here */
  }

  void update(FGameV2* fgame) {
    /* Code you're script here */
  }

  int main(int argc, const char* argv[]) {
    FGameV2 Manage = FGameV2({ FG_INIT }, "Set Position");
    
    /* This function for set position */
    /* I using macro from SDL2, i don't know this macro or variable */
    Manage.SetPosition(SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);

    Manage.StartLooping(handleEvent, update, 60);
    return 0;
  }
```
