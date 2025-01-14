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
    FetchContent_GetProperties(raylib)
    if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
        set(FETCHCONTENT_QUIET NO)
        FetchContent_Populate(raylib)
        set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
        add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
    endif()
endif()

# Project

add_executable(${PROJECT_NAME} 
    source/main.cpp
    source/Game.cpp
)
target_include_directories(${PROJECT_NAME} PRIVATE include)
target_include_directories(${PROJECT_NAME} PRIVATE resources)
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)