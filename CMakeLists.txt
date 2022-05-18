cmake_minimum_required(VERSION 3.17)

IF (WIN32)

project(game)

add_executable(game
        src/main.cpp)

ELSE()
project(game)

set(CMAKE_CXX_STANDARD 20)

add_compile_options(-Wall -Wextra -g3)

add_executable(game
        src/main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE raylib GL m pthread dl)

add_custom_command(TARGET game POST_BUILD
        COMMAND cp game ${PROJECT_SOURCE_DIR})
ENDIF()