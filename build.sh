#!/bin/bash

rm -rf build
mkdir build
cd build
cmake ..
export LD_LIBRARY_PATH=/usr/local/lib
cmake --build .
