## Get | Ticks

| Home                     | Index                          |
|:-------------------------|:-------------------------------|
| [Home](../../index.html) | [Index](../documentation.html) |

### Description
this section to get ticks. Before going to the examples section, 
you should know the type to return. The type is `Uint32`

### Example
```cpp
  /* Include header C++ */
  #include <iostream>
  #include <string>

  /* Include header FGame */
  #include <FGame.hpp>

  int main(int argc, const char* argv[]) {
    FGameV2 Manage = FGameV2({ FG_INIT }, "Get Ticks");
    
    /* This section, how to get ticks */
    std::cout << Manage.Get.Ticks() << std::endl;
    return 0;
  }
```
