cmake_minimum_required(VERSION 3.17)


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
