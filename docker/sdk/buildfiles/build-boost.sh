#!/usr/bin/env bash
set -e

wget -O boost_1_79_0.tar.gz https://boostorg.jfrog.io/artifactory/main/release/1.79.0/source/boost_1_79_0.tar.gz
tar xzvf boost_1_79_0.tar.gz
cd boost_1_79_0
./bootstrap.sh
./b2 install
