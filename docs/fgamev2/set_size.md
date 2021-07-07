## FGameV2 | Set Size

| Home                     | Index                          |
|:-------------------------|:-------------------------------|
| [Home](../../index.html) | [Index](../documentation.html) |

### Description
And this function aims to change the size of the window, before entering the example section. 
We have to look at its parameters which you have to put data in it.
```cpp
  SetSize(float width, float height)
```

The first parameter is width with type float, This is to change the width of the window. 
The two float type heights are also the same as the previous width, this aims to change 
the height of the window.

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
    FGameV2 Manage = FGameV2({ FG_INIT }, "Set Size");
    
    /* This function for set size of window */
    Manage.SetSize(400, 320);

    Manage.StartLooping(handleEvent, update, 60);
    return 0;
  }
```
