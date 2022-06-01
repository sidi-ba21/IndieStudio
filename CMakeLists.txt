# Usage: 
# FIND_PACKAGE(raylib REQUIRED) 
# [...] 
# TARGET_LINK_LIBRARIES(target_name raylib) 

CMAKE_MINIMUM_REQUIRED(VERSION 3.17) 

if (NOT raylib_FOUND)
INCLUDE(FetchContent) 
FetchContent_Declare(raylib URL https://github.com/raysan5/raylib/archive/refs/tags/4.0.0.tar.gz) 
FetchContent_GetProperties(raylib) 
if (NOT raylib_POPULATED) 
SET(FETCHCONTENT_QUIET NO) 
FetchContent_Populate(raylib) 
SET(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) 
ADD_SUBDIRECTORY(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR}) 
SET(raylib_FOUND TRUE) 
endif() 
endif() 


IF (WIN32)
project(bomberman)

add_executable(${PROJECT_NAME}
  src/main.cpp)


ELSE()
project(bomberman)
set(CMAKE_CXX_STANDARD 20)
add_compile_options(-Wall -Wextra -g3)

add_executable(${PROJECT_NAME}
  src/main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE raylib GL m pthread dl)
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND mv ${PROJECT_NAME} ${PROJECT_SOURCE_DIR})
ENDIF()
