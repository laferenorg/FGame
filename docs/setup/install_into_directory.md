## Setup | Install Into Directory

| Home                     | Index                          |
|:-------------------------|:-------------------------------|
| [Home](../../index.html) | [Index](../documentation.html) |

### Description
This page aims to install the compiled results into your computer.
And just like this compilation will be divided into two, namely 
the Linux operating system and the Windows operating system.

#### Ubuntu
You are now in the build directory after compiling, 
and you just need to follow the instructions below.
```bash
  root@computer:~/fgame/build# cp lib* /usr/lib
  root@computer:~/fgame/build# mkdir /usr/include/FGame
  root@computer:~/fgame/build# cd ..
  root@computer:~/fgame# cp include/*.hpp /usr/include/FGame
```

#### Windows
If you are a windows user, after compiling move dynamic link library (**.dll**) , 
to a folder. And add the folder that you moved the dynamic link library (**.dll**) 
to the variable path.
While the static library (**.lib**), don't delete it, instead it will be used 
for linking to the dynamic link library (**.dll**).
Don't delete the header, this will be a bridge to the dynamic link library (**.dll**).
