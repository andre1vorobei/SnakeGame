cmake_minimum_required(VERSION 3.22.1)

project(SnakeGame)

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

