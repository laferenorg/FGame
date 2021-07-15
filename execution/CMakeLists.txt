## Check cmake version
cmake_minimum_required(VERSION 3.7)

## Use the variable PROJECT_NAME for changing the target name
set(PROJECT_NAME "FGBinary" LANGUAGES C CXX)

## Set our project information
project(${PROJECT_NAME} VERSION 1.0.0 DESCRIPTION 
	"FGBinary it's library and exist executable for run file fgame binary")

## Set version of C++ compiler
if(NOT CMAKE_CXX_STANDARD)
	set(CMAKE_CXX_STANDARD 17)
	set(CMAKE_CXX_STANDARD_REQUIRED ON)
endif(NOT CMAKE_CXX_STANDARD)

## Set CMake module directory
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

## Check Dependencis
find_package(Threads REQUIRED)

## Include directory
include_directories("include/")

## Use all the *.cpp files we found under this folder for the project
FILE(GLOB SRCS "src/*.cpp" "src/*.c")

## Define the executable
add_executable(${PROJECT_NAME} ${SRCS})
set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION})
target_link_libraries(${PROJECT_NAME}
	${SDL2_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT} -static)