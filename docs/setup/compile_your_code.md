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

