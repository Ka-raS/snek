cmake_minimum_required(VERSION 3.11)
project(snek)
set(CMAKE_CXX_STANDARD 17)

find_package(raylib QUIET)

if (NOT raylib_FOUND)
    include(FetchContent)
    FetchContent_Declare(raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG        master
    )

    FetchContent_MakeAvailable(raylib)
endif()

set(GAME_SOURCES 
    source/main.cpp
    source/Game.cpp
)
add_executable(${PROJECT_NAME} ${GAME_SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE include) 