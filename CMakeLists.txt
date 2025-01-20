cmake_minimum_required(VERSION 3.11)
project(snek VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/snek)

# Dependency

message(STATUS "Fetching raylib...")
include(FetchContent)
FetchContent_Declare(
	raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG        master
)
FetchContent_MakeAvailable(raylib)

# Project

add_executable(${PROJECT_NAME} 
    ${CMAKE_SOURCE_DIR}/source/main.cpp
    ${CMAKE_SOURCE_DIR}/source/Game.cpp
    ${CMAKE_SOURCE_DIR}/source/Snake.cpp
    ${CMAKE_SOURCE_DIR}/source/Apple.cpp
    ${CMAKE_SOURCE_DIR}/source/Common.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

file(COPY ${CMAKE_SOURCE_DIR}/resources/ DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/resources)
