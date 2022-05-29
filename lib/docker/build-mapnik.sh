#!/usr/bin/env bash

if [[ ! -d mapnik ]]
then
    git clone https://github.com/mapnik/mapnik.git
fi
cd mapnik
#git checkout v3.1.0
git submodule update --init
mkdir build && cd build
cmake .. -DUSE_JPEG:BOOL=OFF -DUSE_TIFF:BOOL=OFF -DUSE_WEBP:BOOL=OFF
cmake --build . --target install
