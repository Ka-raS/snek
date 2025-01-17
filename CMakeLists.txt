cmake_minimum_required(VERSION 3.11)
project(snek)
set(CMAKE_CXX_STANDARD 20)

# Dependency

find_package(raylib)
if (NOT raylib_FOUND) # If there's none, fetch and build raylib
    include(FetchContent)
    FetchContent_Declare(
	    raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG        master
    )
    FetchContent_MakeAvailable(raylib)
endif()

# Project

add_executable(${PROJECT_NAME} WIN32
    source/main.cpp
    source/Game.cpp
    source/Snake.cpp
    source/Apple.cpp
    source/Common.cpp
)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)