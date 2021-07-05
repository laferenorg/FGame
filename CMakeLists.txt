cmake_minimum_required(VERSION 3.7)

## Use the variable PROJECT_NAME for changing the target name
set(PROJECT_NAME "fgame")

## Set our project name
project(${PROJECT_NAME} VERSION 2.0.0 DESCRIPTION "FGame Framework 2D Version 2")

## Set version of C++ compiler
set(CMAKE_CXX_STANDARD 17)

## Check Dependencis
find_package(SDL2 REQUIRED)

INCLUDE(FindPkgConfig)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image >= 2.0.0)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_mixer >= 2.0.0)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_net   >= 2.0.0)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_ttf   >= 2.0.0)

## Include directory
include_directories("include/")

## Use all the *.cpp files we found under this folder for the project
FILE(GLOB SRCS "src/*.cpp")

## Adding FLags in compile
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D BUILD_LIBRARY_FGAME")

## Define the executable
add_library(${PROJECT_NAME} SHARED ${SRCS})
set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION})
TARGET_LINK_LIBRARIES(${PROJECT_NAME}
	SDL2 SDL2main SDL2_net
	SDL2_image SDL2_ttf SDL2_mixer
	pthread)