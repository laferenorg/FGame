cmake_minimum_required(VERSION 3.7)

## Use the variable PROJECT_NAME for changing the target name
set(PROJECT_NAME "fgame" LANGUAGES CXX)

## Set our project name
project(${PROJECT_NAME} VERSION 2.0.0 DESCRIPTION "FGame Framework 2D Version 2")

## Set version of C++ compiler
if(NOT CMAKE_CXX_STANDARD)
	set(CMAKE_CXX_STANDARD 17)
	set(CMAKE_CXX_STANDARD_REQUIRED ON)
endif(NOT CMAKE_CXX_STANDARD)

## Adding settings variable
set(flags_settings "-D BUILD_LIBRARY_FGAME")
set(flags_linking "")

## Set CMake module directory
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

## Check Dependencis
find_package(SDL2 REQUIRED)
find_package(Threads REQUIRED)

## Check the second time
INCLUDE(FindPkgConfig)

if(FGAME_IMAGE OR FGAME_ALL)
	message(STATUS "Compile support image")
	PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image >= 2.0.0)
	set(flags_settings "-D FGAME_IMAGE ${flags_settings}")
	set(flags_linking "-lSDL2_image" ${flags_linking})
endif(FGAME_IMAGE OR FGAME_ALL)

if(FGAME_MIXER OR FGAME_ALL)
	message(STATUS "Compile support mixer")
	PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_mixer >= 2.0.0)
	set(flags_settings "-D FGAME_MIXER ${flags_settings}")
	set(flags_linking "-lSDL2_mixer" ${flags_linking})
endif(FGAME_MIXER OR FGAME_ALL)

if(FGAME_NET OR FGAME_ALL)
	message(STATUS "Compile support net")
	PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_net   >= 2.0.0)
	set(flags_settings "-D FGAME_NET ${flags_settings}")
	set(flags_linking "-lSDL2_net" ${flags_linking})
endif(FGAME_NET OR FGAME_ALL)

if(FGAME_TTF OR FGAME_ALL)
	message(STATUS "Compile support ttf")
	PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_ttf   >= 2.0.0)
	set(flags_settings "-D FGAME_TTF ${flags_settings}")
	set(flags_linking "-lSDL2_ttf" ${flags_linking})
endif(FGAME_TTF OR FGAME_ALL)

## Check the third time
## test that filesystem header actually is there and works
try_compile(HaveFileSystem "${CMAKE_BINARY_DIR}/temp" 
			"${CMAKE_SOURCE_DIR}/test/filesystem.cpp" 
            CMAKE_FLAGS -DCMAKE_CXX_STANDARD=17 -DCMAKE_CXX_STANDARD_REQUIRED=ON
            LINK_LIBRARIES stdc++fs)
if(HaveFileSystem)
	## The compiler support std::filesystem
    message(STATUS "Compiler has filesystem support")
    set(flags_settings "-D FGAME_FILES ${flags_settings}")
    set(flags_linking "-lstdc++fs" ${flags_linking})
endif(HaveFileSystem)

## Include directory
include_directories("include/")
include_directories("fgame/")
include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${SDL2TTF_LIBRARIES})
include_directories(${SDL2NET_LIBRARIES})
include_directories(${SDL2IMAGE_LIBRARIES})
include_directories(${SDL2MIXER_LIBRARIES})

## Use all the *.cpp files we found under this folder for the project
FILE(GLOB SRCS "src/*.cpp" "src/Get/*.cpp" 
			   "src/Run/*.cpp" "src/Animation/*.cpp")

## Adding FLags in compile
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${flags_settings}")
set(flags_linking ${SDL2_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT} ${flags_linking})

## Define the executable
add_library(${PROJECT_NAME} SHARED ${SRCS})
set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${flags_linking})