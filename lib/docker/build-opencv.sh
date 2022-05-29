#!/bin/bash
set -e
if [[ ! -d opencv ]]
then
    git clone https://github.com/opencv/opencv
fi
cd opencv
git checkout 4.5.5
mkdir build
cd build
cmake ..
cmake --build . --target install
