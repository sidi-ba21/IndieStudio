#!/bin/sh

BINARY="./bomberman"
CMAKE_FILE="./build"
USAGE="error: The shell script take only 1 parameter."

if [ $# -eq 1 ]; then
    if [ $1 = "build" ]; then
        mkdir $CMAKE_FILE && cd $CMAKE_FILE && cmake .. && cmake --build . && cd ..
        echo "Build done."
    elif [ $1 = "make" ]; then
        cd build && make && cd ..
        echo "make done."
    elif [ $1 = "clean" ]; then
        rm -r $CMAKE_FILE && rm $BINARY
        echo "Clean done."
    fi
else
    echo $USAGE
fi
