## Setup | Compile Source Code

| Home                     | Index                          |
|:-------------------------|:-------------------------------|
| [Home](../../index.html) | [Index](../documentation.html) |

### Description
This page will instruct you to compile the source code.
Before you compile you should check whether your dependencies are ready or not.

### Dependencies
- C++ Compiler (GCC (**g++**), Visual C++ (**cl**), Clang (**clang++**), Or it could be another)
- C++ Compiler (must be able to use **C++ Version 17**, and can use **filesystem** libraries)
- SDL2 (**SDL2**, **SDL2_main**, **SDL2_mixer**, **SDL2_image**, **SDL2_net**)
- And must be able to link to the **thread** library
- cmake **>= 3.7**

### Install Dependencies
If you don't have the required dependencies you just need 
to follow the instructions to install them on your computer.

#### Ubuntu
This section is for installing dependencies for the ubuntu operating system
```bash
 $ apt install g++ libsdl2-dev libsdl2-mixer-dev libsdl2-net-dev libsdl2-image-dev libsdl2-ttf-dev
```

#### Windows
This section is for installing dependencies for the Windows operating system.
What is needed is a compiler from visual studio, you can direct 
data to the website for visual studio installation [Visual Studio](https://visualstudio.microsoft.com/).

And you have to install SDL2 libraries, such as for image, net, mixer, and ttf.
I will provide the download link directly here.

| SDL2                                                                | SDL2_mixer                                                                                  | SDL2_image                                                                                  | SDL2_ttf                                                                                 | SDL2_net                                                                                |
|:--------------------------------------------------------------------|:--------------------------------------------------------------------------------------------|:--------------------------------------------------------------------------------------------|:-----------------------------------------------------------------------------------------|:----------------------------------------------------------------------------------------|
| [Downlaod](https://www.libsdl.org/release/SDL2-devel-2.0.14-VC.zip) | [Downlaod](https://www.libsdl.org/projects/SDL_mixer/release/SDL2_mixer-devel-2.0.4-VC.zip) | [Downlaod](https://www.libsdl.org/projects/SDL_image/release/SDL2_image-devel-2.0.5-VC.zip) | [Downlaod](https://www.libsdl.org/projects/SDL_ttf/release/SDL2_ttf-devel-2.0.15-VC.zip) | [Downlaod](https://www.libsdl.org/projects/SDL_net/release/SDL2_net-devel-2.0.1-VC.zip) |
