cmake_minimum_required(VERSION 3.11)
project(snek)
set(CMAKE_CXX_STANDARD 17)

# Try to find preinstalled raylib
find_package(raylib QUIET)
if (NOT raylib_FOUND)
    message(STATUS "raylib not found. Fetching raylib...")

    # Try to fetch raylib from GitHub
    include(FetchContent)
    FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG        master  # Consider using a specific version (e.g., v4.0.0)
    )
        
    FetchContent_MakeAvailable(raylib)

    if (NOT TARGET raylib)
        message(FATAL_ERROR "Fetching failed. Aborting...")
    else()
        message(STATUS "Fetching succeeded")
    endif()

else()
    message(STATUS "raylib found")
endif()

set(GAME_SOURCES 
    source/main.cpp
    source/Game.cpp
)
add_executable(${PROJECT_NAME} ${GAME_SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
target_include_directories(${PROJECT_NAME} PRIVATE include)