## Image | Load

| Home                     | Index                          |
|:-------------------------|:-------------------------------|
| [Home](../../index.html) | [Index](../documentation.html) |

### Description
this function is used to load the image but it still doesn't render the image you provided later. 
This is just a variable that is stored in memory. Later, if you want to display it, you will use 
a render image [Render](./render.html).
Before using it, it is better to first see the parameters used.
```cpp
  Load(FG_Image& destination_image, std::string locationImage, FGData_System& system, std::string& message_error, bool& errorEvent)
```

The first parameter is your variable references [FG_Image](../struct/fg_image.html). 
Both locations of your image. Third, Fourth and Fifth 
will be filled using macros [Macro Pointer](../macro/fgame_this_pointer.html) or [Macro Default](../macro/fgame_this_default.html).
This macro is adjusted by the main controller in the form of a pointer or or a regular form.
Once you have it loaded you can take the width and height of the image.

### Example
```cpp
  /* Include header C++ */
  #include <iostream>
  #include <string>

  /* Include header FGame */
  #include <FGame.hpp>

  int main(int argc, const char* argv[]) {
    /* Don't forget flags image */
    FGameV2 Manage = FGameV2({ FG_INIT, FG_IMAGE_INIT }, "Load Image");
    
    /* Setup variable image */
    FG_Image image;
    
    /* Load image */
    Manage.Run.Image.Load(image, "assets/img/player.png", FG_THIS_DEFAULT(Manage));
    
    std::cout << "Image Width: " << image.width << " | " << "Image Height: " << image.height << std::endl;
    return 0;
  }
```
