cmake_minimum_required(VERSION 3.22.1)

project(SnakeGame)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")

add_executable(Snake)

target_include_directories(Snake
    PUBLIC include
)

file(GLOB_RECURSE SRCS "src/*.cpp")

target_sources(Snake
    PRIVATE
        ${SRCS}
        app/main.cpp
)

