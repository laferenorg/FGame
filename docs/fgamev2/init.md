## FGameV2 | INIT

| Home                     | Index                          |
|:-------------------------|:-------------------------------|
| [Home](../../index.html) | [Index](../documentation.html) |

### Description

Before you get there you have to know how to declare it.
First, let's take a look at the constructor of the fgame.
```cpp
  FGameV2(std::vector<unsigned int> flags, std::string title, Uint32 flagsWindow = 0)
```

As you can see the first parameter is a **std::vector**, and you have to fill in the appropriate flags.
You can see the flags in the documentation here: [FGame Flags](./init_flags.md).
And the second parameter is title, you have to fill in the title for the window to be created.
The third parameter is the flags of SDL2. So you have to fill in the 
appropriate flags from the SDL2 documentation: [SDL2 Flags Documentation](https://wiki.libsdl.org/SDL_WindowFlags)

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
    /* How to declared */
    FGameV2 Manage = FGameV2({ FG_INIT }, "FGameV2 Init");
    
    Manage.StartLooping(handleEvent, update, 60);
    return 0;
  }
```
