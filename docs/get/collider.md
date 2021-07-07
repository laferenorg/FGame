## Get | Ticks

| Home                     | Index                          |
|:-------------------------|:-------------------------------|
| [Home](../../index.html) | [Index](../documentation.html) |

### Description
this function is to check if it has been hit by another sprite, 
my info says the sprite is to say a rectangle consisting of width, 
height, x position, and y position. Before going to the example 
you must know how the parameters of the function are.
```cpp
  Collide(FG_Rect& rectFirst, FG_Rect& rectSecond)
```

The first parameter is the first sprite or player, 
and the second sprite is an example of a bullet.
And this will return a boolean true or false.
Both parameters use the struct [FG_Rect](../struct/fg_rect.html).

### Example
```cpp
  /* Include header C++ */
  #include <iostream>
  #include <string>

  /* Include header FGame */
  #include <FGame.hpp>

  int main(int argc, const char* argv[]) {
    FGameV2 Manage = FGameV2({ FG_INIT }, "Compile You're Code");
    
    /* Make rectangle player */
    FG_Rect player;
    player.width = 96;
    player.height = 96;
    player.x = 10;
    player.y = 100;
    
    /* Make rectangle bullet */
    FG_Rect bullet;
    bullet.width = 20;
    bullet.height = 15;
    bullet.x = 12;
    bullet.y = 100;
    
    /* This function will check if the player is hit by a bullet. */
    std::cout << Manage.Get.Collide(player, bullet) << std::endl;
    return 0;
  }
```
