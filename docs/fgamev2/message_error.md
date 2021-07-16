## FGameV2 | Message Error

| Home                     | Index                          |
|:-------------------------|:-------------------------------|
| [Home](../../index.html) | [Index](../documentation.html) |

### Description
This function aims to get an error message, 
And this function will return with type `std::string`

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
    /* imagine the file icon below does not exist. */
    Manage.SetIcon("assets/img/icon.png");
    
    /* Check have error */
    if(Manage.HaveError()) {
      /* if have error */
      std::cout << Manage.MessageError() << std::endl;
    }

    Manage.StartLooping(handleEvent, update, 60);
    return 0;
  }
```
