cmake_minimum_required(VERSION 3.30.4)
project(snek)

# Try to find preinstalled raylib
find_package(raylib QUIET)

if (NOT raylib_FOUND)
    message(STATUS "raylib not found. Fetching raylib...")

    # Try to fetch raylib from github
    include(FetchContent)
    FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG        master  
    )
        
    FetchContent_MakeAvailable(raylib)
    
    if (NOT TARGET raylib)
        message(FATAL_ERROR "Fetching raylib failed. Aborting...")
    else()
        message(STATUS "Fetching raylib succeed")
    endif()

else()
    message(STATUS "raylib found")
        
endif()

file(GLOB SOURCES source/*.cpp)
add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${SOURCES} PRIVATE include)
target_link_libraries(${PROJECT_NAME} raylib)