# FGame

## About
Game is a 2D game framework that keeps things simple.
And it can be used on Linux and Windows platforms.
And this requires SDL2 dependencies.

## Information
For now this project is still under development and still only available on the Linux platform.
In the future, this project for the Windows platform will use Visual Studio C++.

## Platform
The platforms that can be used at this time are below the following table.
| Version | Windows |        Linux       |
|---------|---------|--------------------|
|  V1.0   |   :x:   | :white_check_mark: |

## Documentation
There are several conveniences when using this framework.
And this is arguably very easy.

- ### Flags
  there are several flags that are used at this time, namely in the following table.
  It's just like plagiarizing from SDL2.
  |             Window            |         Position       |
  |-------------------------------|------------------------|
  | FG_WINDOW_FULLSCREEN          | FG_WINDOWPOS_CENTERED  |
  | FG_WINDOW_FULLSCREEN_DESKTOP  |                        |
  | FG_WINDOW_OPENGL              |                        |
  | FG_WINDOW_VULKAN              |                        |
  | FG_WINDOW_SHOWN               |                        |
  | FG_WINDOW_HIDDEN              |                        |
  | FG_WINDOW_BORDERLESS          |                        |
  | FG_WINDOW_RESIZABLE           |                        |
  | FG_WINDOW_RESIZABLE           |                        |
  | FG_WINDOW_MINIMIZED           |                        |
  | FG_WINDOW_MAXIMIZED           |                        |
  | FG_WINDOW_INPUT_GRABBED       |                        |
  | FG_WINDOW_INPUT_FOCUS         |                        |
  | FG_WINDOW_MOUSE_FOCUS         |                        |
  | FG_WINDOW_FOREIGN             |                        |
  | FG_WINDOW_ALLOW_HIGHDPI       |                        |
  | FG_WINDOW_MOUSE_CAPTURE       |                        |
  | FG_WINDOW_ALWAYS_ON_TOP       |                        |
  | FG_WINDOW_SKIP_TASKBAR        |                        |
  | FG_WINDOW_UTILITY             |                        |
  | FG_WINDOW_TOOLTIP             |                        |
  | FG_WINDOW_POPUP_MENU          |                        |
- ### Key Event
  The keyboard events that can be used can be seen in the following table.
  And these can only be numbers, alphabets, and arrows.
  | Number | Alphabet | Arrows   |
  |--------|----------|----------|
  | FG_0   | FG_A     | FG_UP    |
  | FG_1   | FG_B     | FG_DOWN  |
  | FG_2   | FG_C     | FG_RIGHT |
  | FG_3   | FG_D     | FG_LEFT  |
  | FG_4   | FG_E     |          |
  | FG_5   | FG_F     |          |
  | FG_6   | FG_G     |          |
  | FG_7   | FG_H     |          |
  | FG_8   | FG_I     |          |
  | FG_9   | FG_J     |          |
  |        | FG_K     |          |
  |        | FG_L     |          |
  |        | FG_M     |          |
  |        | FG_N     |          |
  |        | FG_O     |          |
  |        | FG_P     |          |
  |        | FG_Q     |          |
  |        | FG_R     |          |
  |        | FG_S     |          |
  |        | FG_T     |          |
  |        | FG_U     |          |
  |        | FG_V     |          |
  |        | FG_W     |          |
  |        | FG_X     |          |
  |        | FG_Y     |          |
  |        | FG_Z     |          |
- ### Event Type
  Event types can be seen below this table.
  |         Type       | Event Type |
  |--------------------|------------|
  | FG_QUIT            | FG_KEYDOWN |
  | FG_APP_TERMINATING | FG_KEYUP   |
  | FG_APP_LOWMEMORY   |            |
- ### Color
  Variable color, to make the data as a parameter for later.
  The data will be entered sequentially in the order of Red, Green, Blue, and Alpha.
  Example Like the following.
  ```cpp
   ...
    FGameColor white = { 255, 255, 255, 0 };
   ...
  ```
- ## Rect
  Just like in SDL2, there is also a rectangle variable here.
  And how to use it as follows.
  ```cpp
   ...
    FGameRect player1;
    
    /* Filling data */
    player1.x = 0;
    player1.y = 0;
    player1.width = 100;
    player1.height = 100;
    
    /* Getting data */
    std::cout << player1.x << std::endl;
    std::cout << player1.y << std::endl;
    std::cout << player1.width << std::endl;
    std::cout << player1.height << std::endl;
   ...
  ```
  - #### Function
    ##### `set_size`
    this section to fill in the data size with the following parameters.
    ```cpp
      void set_size(float fgame_width, float fgame_height)
    ```
    ##### `set_position`
    this section to fill in the data position with the following parameters.
    ```cpp
      void set_position(float fgame_x, float fgame_y)
    ```
    ##### `get_centerx`
    This section gets the data center from x.
    With the following parameters.
    ```cpp
      float get_centerx();
    ```
    ##### `get_centery`
    This section gets the data center from y.
    With the following parameters.
    ```cpp
      float get_centery();
    ```
