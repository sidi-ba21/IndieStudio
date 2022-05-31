#!/bin/sh

BINARY="./bomberman"
CMAKE_FILE="./build"
USAGE="error: The shell script take only 1 parameter."

if [ $# -eq 1 ]; then
    if [ $1 = "build" ]; then
        mkdir $CMAKE_FILE && cd $CMAKE_FILE && cmake .. && cmake --build . && cd ..
    elif [ $1 = "clean" ]; then
        rm -rf $CMAKE_FILE && rm -rf $BINARY
    fi
else
    echo $USAGE
fi
