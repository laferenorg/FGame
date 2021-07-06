## FGameV2 | Start Looping

| Home                     | Index                          |
|:-------------------------|:-------------------------------|
| [Home](../../index.html) | [Index](../documentation.html) |

### Description
This function aims to start a loop to show the window, and start the logic to create a game.
The first parameter is a function that will return the event data and the fgame itself in the 
form of a pointer, the second is a function that will return the fgame data itself in the form 
of a pointer, and the third is fps. You can set the fps to your heart's content but the usual 
is 60 fps.
You can see the parameters of this function below:
```cpp
  StartLooping(void(*handleEvent)(SDL_Event& event, FGameV2* fgameV2), void(*update)(FGameV2* fgameV2), float fps)
```

### Example
```cpp
  /* Include header C++ */
  #include <iostream>
  #include <string>

  /* Include header FGame */
  #include <FGame/FGame.hpp>

  void handleEvent(SDL_Event& event, FGameV2* fgame) {
    /* Code you're script here */
  }

  void update(FGameV2* fgame) {
    /* Code you're script here */
  }

  int main(int argc, const char* argv[]) {
    FGameV2 Manage = FGameV2({ FG_INIT }, "FGameV2 Start Looping");
    
    /* This how to call Start Looping */
    Manage.StartLooping(handleEvent, update, 60);
    return 0;
  }
```
