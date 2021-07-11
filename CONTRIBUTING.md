# Contributing To FGame Version 2

:+1::tada: First of all I thank you for the free time to contribute!

I thank you again for the free time you have given to contribute. With your contribution, it is hoped that this project will be better.
Please be able to maintain the language of speech and manners.

## What do I need to know to start contributing to this project?
### C++ Programming Language
All of these products are made using the C++ programming language. And I hope you can use C++ programming language. 
The C++ built in this project is simple and doesn't involve writing complicated code for beginners.
Included in this project are as follows:
- Management in memory. Because this project uses C++ then you should be able to manage the memory used to improve performance.
- Always use commands to tell people what you're doing.
- And can make the code run on Linux and Windows platforms, Architecture x32 or x64.
- C++ compiler can use C++ version 17, because this project uses filesystem library in this project code.

### Tools Used For This Project
Usually these tools are shared with their own dependencies. 
If you are a Linux user, you should be able to have the tools listed below. 
While the window will be shown brought as well.
#### Linux
- Usually I use GNU Compiler (**g++**), but you can use **clang** or something else.
- **cmake**, this is needed to generate the makefile and make it easier for you to compile the code later. The thing to remember is that cmake must be more or equal to version 3.7

#### Windows
- You must have **Visual Studio C++**. And I hope your Visual Studio C++ can support **C++17**, this is why because this project requires a filesystem library in it.

### Required dependencies
This project definitely needs dependencies, And you have to make sure you can use the dependencies that will be used in this project. 
Commonly used projects are below.
- **SDL2**, you must be able to use sdl2 because this project must use sdl2.


## Code style
You should be able to keep your code neat and not broken here and there. 
And you should make comments to tell people what you do and the logic you use.
And hope the comments do not contain words that are not expected in the development of this project.

## Pull Request
When you want to do a pull request, you have to make what you do. 
And you have to explain what you're doing, with examples of you improving something or adding a feature. 
And can be sure that your code can be run in the target platform in this project.

## Commit
For a moment, if you have completed the target or problem, you will definitely commit your code. 
Therefore you have to make the commit with the emoji in front of the dititle statement. 
And you have to make whatever you do in the decryption field.

### Emoji
Like the statement above you have to create an emoji to tell what you're doing.
And below to show you what emojis are used to tell the code what you're doing.
- :lock: `:lock:` This shows the code that you commit to tighten the code
- :bomb: `:bomb:` This shows the code that you commit to remove or delete the (**code** / **directory**)
- :memo: `:memo:` It shows the code that you commit to notify there are changes or updates to the code
- :shirt: `:shirt:` This shows the code that you committed to notify you of any additions or updates to the documentation
- :bug: `:bug:` This code tells you the commits that were made to let you know how to fix errors or bugs.
- :bangbang: `:bangbang:` This code tells you the commits that were made to let you know what's missing.
- :white_check_mark: `:white_check_mark:` This emoji is to indicate your commit to add a file or example

## Setup
### Setup in Visual Studio C++
- #### Setup Include Directory
  You must replace or use the same directory structure as the structure below.
  ```text
    - deps
    |- include
     |- SDL2
      | Header SDL2 (.h)
  ```
  for example, Currently used in include in this project's code.
  If you are a linux user you don't need it because when you install it there must be a header that is structured like that.
  That's to my knowledge.
  ```cpp
    #include <SDL2/SDL.h>
  ```
  <kbd><kbd>FGame -> Property -> C/C++ -> General</kbd> -> <kbd>Additional Include Directories</kbd></kbd>: Change `$(SolutionDir)SDL2\include;`
  
- #### Setup Library Directory
  You have to make it match the file format **.lib**. 
  And you should have the central SDL2 library, mixer, image, net, and ttf.
  You have to replace or use the structure I just said.
  <kbd><kbd>FGame -> Property -> Linker -> General</kbd> -> <kbd>Additional Library Directories</kbd></kbd>: Change `$(SolutionDir)SDL2\lib;`
