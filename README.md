# FGame

## About
Game is a 2D game framework that keeps things simple.
And it can be used on Linux and Windows platforms.
And this requires SDL2 dependencies.

## Information
For now this project is still under development and still only available on the Linux platform.
In the future, this project for the Windows platform will use Visual Studio C++.

## Platform
  - The platforms that can be used at this time are below the following table.
    |  Version  |          Windows       |        Linux x32       |        Linux x64       |
    |-----------|------------------------|------------------------|------------------------|
    |  V1.0.0   |           :x:          |   :white_check_mark:   |            :x:         |
    |  V1.1.1   |   :white_check_mark:   |   :white_check_mark:   |   :white_check_mark:   |
    |  V1.2.1   |   :white_check_mark:   |   :white_check_mark:   |   :white_check_mark:   |
    |  V1.3.2   |   :white_check_mark:   |   :white_check_mark:   |   :white_check_mark:   |

## Install Dependencis
What is meant here is how to install dependencies for this game framework.
- ### Ubuntu
This is the way to install dependencies on ubuntu.
```bash
$ sudo apt install libsdl2-dev libsdl2-image-dev libsdl2-mixer-dev libsdl2-ttf-dev -y
```

- ### Windows
  If you are a windows user you can see directly in the `Release` or you can follow the way to install dependencies.
  - Download SDL2: [Visual Studio C++ x64/x32](https://www.libsdl.org/release/SDL2-devel-2.0.14-VC.zip)
  - Download SDL2 Image: [Visual Studio C++ x64/x32](https://www.libsdl.org/projects/SDL_image/release/SDL2_image-devel-2.0.5-VC.zip)
  - Download SDL2 Mixer: [Visual Studio C++ x64/x32](https://www.libsdl.org/projects/SDL_mixer/release/SDL2_mixer-devel-2.0.4-VC.zip)
  - Download SDL2 TTF: [Visual Studio C++ x64/x32](https://www.libsdl.org/projects/SDL_ttf/release/SDL2_ttf-devel-2.0.15-VC.zip)

## Build Source
This is how to compile this project.
 - Linux
   This is how to build source in Linux.
  ```bash
    $ make
  ```
  - Windows
    You log into Visual Studio by using the .sln format file. And press build

## Compile
This is how to compile your code.
You must also include this `fgame` library file.

- ### Linux
  Flags For Compile You're code:
  ```bash
    g++ source.cpp -L path/fgame/lib -lfgame \
        -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf \
        -o output.out
  ```
- ### Windows
  Linking library: `fgame.lib;SDL2.lib;SDL2main.lib;SDL2_image.lib;SDL2_mixer.lib;SDL2_ttf.lib`
  - #### Preprocessor
    You must include `SDL_MAIN_HANDLED` in preprocessor on you project
## Documentation
You can see the `DOCUMENTATION.md`
