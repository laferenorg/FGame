## FGameV2 | Init Flags

| Home                     | Index                          |
|:-------------------------|:-------------------------------|
| [Home](../../index.html) | [Index](../documentation.html) |

### Description
This section aims to initialize, and one of the flags section that will be created as documentation.
The flags are as follows:

- #### FG_INIT
  this doesn't mean it's init everything, it's just to initialize the fgame and sdl2 only.
  if this init is not there it doesn't bother the others because it's just init for fgame and 
  its sdl2 only, while net, image, ttf, and mixer will have no problem.
- #### FG_MIXER_INIT
  init is as the name suggests to initialize sound, If you don't make this initialize 
  it's run time init. Well later will get `Segmentation fault (Core dumped)`
- #### FG_IMAGE_INIT
  init will initialize the image, Same problem if you don't initialize it if 
  you need these features.
- #### FG_TTF_INIT
  These flags aim to initialize ttf, if you don't know what ttf is. TTF stands for True Type Font.
  So if you want to create a font you have to use the **ttf** format font.
- #### FG_NET_INIT
  And lastly, it aims to initialize the net, it aims to network if you need it.
