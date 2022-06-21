#!/usr/bin/env bash
set -e

wget -O proj-8.2.1.tar.gz https://download.osgeo.org/proj/proj-8.2.1.tar.gz
tar xzvf proj-8.2.1.tar.gz
cd proj-8.2.1
mkdir build && cd build
cmake .. -DENABLE_TIFF:BOOL=OFF
cmake --build .
cmake --build . --target install
