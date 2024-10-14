#!/bin/bash

foldername="build"

if [ -d "$foldername" ]; then
    echo "-- folder has exist"
else
    mkdir "$foldername"
    echo "-- create folder "
fi

cmake -B build && cd build && make && cd .. && ./build/main
