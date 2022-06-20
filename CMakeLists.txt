cmake_minimum_required(VERSION 3.17)

project(bomberman)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -g3")
find_package(raylib 4.0 QUIET)

if (NOT raylib_FOUND)
    include(FetchContent)
    FetchContent_Declare(raylib URL https://github.com/raysan5/raylib/archive/refs/tags/4.0.0.tar.gz)
    FetchContent_GetProperties(raylib)
    if (NOT raylib_POPULATED)
        set(FETCHCONTENT_QUIET NO)
        FetchContent_Populate(raylib)
        set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
        add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
    endif()
endif()

include_directories(include)

add_executable(bomberman   src/core/main.cpp
src/core/Core.cpp
src/games/Player/Player.cpp
src/games/Player/Buff.cpp
src/games/Camera/Camera.cpp
src/games/Map/Map.cpp
src/games/Box/Box.cpp
src/games/Score/Score.cpp
src/games/Bomb/Bomb.cpp
src/games/AI/AI.cpp
src/graphicals/Draw/Draw.cpp
src/graphicals/Draw/Intro.cpp
src/menu/menu.cpp
src/menu/initialisation.cpp
src/menu/functionnalities.cpp
src/menu/music.cpp)
target_link_libraries(${PROJECT_NAME} raylib)


