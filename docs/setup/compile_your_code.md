## Setup | Compile You're Code

| Home                     | Index                          |
|:-------------------------|:-------------------------------|
| [Home](../../index.html) | [Index](../documentation.html) |

### Description
This section is for compiling your code.
Sample C++ code for this framework.
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
    FGameV2 Manage = FGameV2({ FG_INIT }, "Compile You're Code");
    
    Manage.StartLooping(handleEvent, update, 60);
    return 0;
  }
```

And as usual this is divided into two operating systems 
linux and windows operating system that uses visual studio.

#### Linux
After you have installed it on your computer, you can now follow the instructions below.
```bash
 $ g++ source.cpp -lfgame -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf -lSDL2_net -o output
```

#### Windows
You just need to configure the preprocessor: `SDL_MAIN_HANDLED`. 
And also linking to static library: `fgame.lib;SDL2.lib;SDL2main.lib;SDL2_image.lib;`
`SDL2_mixer.lib;SDL2_ttf.lib;SDL2_net.lib`.
And well, you just need to compile the code. And run

### Result
![Result](https://github.com/laferenorg/FGame/blob/version-2-development/docs/setup/assets/result.png?raw=true "Result")
