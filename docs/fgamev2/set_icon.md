## FGameV2 | Set Icon

| Home                     | Index                          |
|:-------------------------|:-------------------------------|
| [Home](../../index.html) | [Index](../documentation.html) |

### Description
From the name of the function you must already know, that this function is used to change your window icon.
Before looking at examples of usage, it would be nice to see the parameters of this function.
```cpp
  SetIcon(std::string LocationIcon)
```

There is only one parameter which is the icon file location, 
so you have to provide the icon path and icon name. And don't forget the format 
of the icon is usually `.png`

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
    FGameV2 Manage = FGameV2({ FG_INIT }, "Icon Window");
    Manage.SetSize(400, 320);

    /* Set Icon Window */
    Manage.SetIcon("assets/img/icon.png"); /* You just giving location path of file */

    Manage.StartLooping(handleEvent, update, 60);
    return 0;
  }
```
