#!/usr/bin/env bash
set -e

wget -O gdal-3.5.0.tar.gz https://github.com/OSGeo/gdal/releases/download/v3.5.0/gdal-3.5.0.tar.gz
tar xzvf gdal-3.5.0.tar.gz
cd gdal-3.5.0
mkdir build
cd build
cmake ..
cmake --build . --target install
