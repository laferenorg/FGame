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

## Set CMake module directory
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

## Check Dependencis
find_package(SDL2 REQUIRED)
find_package(Threads REQUIRED)

## Check the second time
INCLUDE(FindPkgConfig)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image >= 2.0.0)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_mixer >= 2.0.0)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_net   >= 2.0.0)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_ttf   >= 2.0.0)

## Include directory
include_directories("include/")
include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${SDL2TTF_LIBRARIES})
include_directories(${SDL2NET_LIBRARIES})
include_directories(${SDL2IMAGE_LIBRARIES})
include_directories(${SDL2MIXER_LIBRARIES})

## Use all the *.cpp files we found under this folder for the project
FILE(GLOB SRCS "src/*.cpp")

## Adding FLags in compile
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D BUILD_LIBRARY_FGAME")

## Define the executable
add_library(${PROJECT_NAME} SHARED ${SRCS})
set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION})
TARGET_LINK_LIBRARIES(${PROJECT_NAME}
	${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES} ${SDL2TTF_LIBRARIES}
	${SDL2NET_LIBRARIES} ${SDL2MIXER_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})