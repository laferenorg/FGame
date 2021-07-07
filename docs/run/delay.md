## Run | Delay

| Home                     | Index                          |
|:-------------------------|:-------------------------------|
| [Home](../../index.html) | [Index](../documentation.html) |

### Description
This function aims to make a pause in running the application, 
It is used in the system function startloop to create fps. 
Before you use and see an example you see the parameters used.
```cpp
  Delay(Uint32 milisecond)
```

There is only one parameter that is input milliseconds.

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
    FGameV2 Manage = FGameV2({ FG_INIT }, "Run Delay");

    /* This function for delay */
    Manage.Run.Delay(1000);
    return 0;
  }
```
